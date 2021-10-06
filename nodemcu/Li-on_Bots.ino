#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#define CMDBUFFER_SIZE 32

//Modo acess point/Roteador ON
//Modo conectar rede OFF
const char *ap = "on";//on/off

const char *ssid = "LionBots02"; // Nome do wifi
const char *password = "12345678"; // Senha de 8 a 32 caracteres

IPAddress ip(192, 168, 4, 1); // IP
IPAddress netmask(255, 255, 255, 0); // Mascara rede
const int port = 80; // Porta
WiFiServer server(port);

const int max_string_length = 100;
char inData[max_string_length];

const char end_char = '\n';

char oldx;//maximo 1000
char oldy;//maximo 1000
int x = 0;
int y = 0;
int m = 0;

// Motors pins
static const uint8_t pwm_A = 5 ;
static const uint8_t pwm_B = 4;
static const uint8_t pwm_M = 12;
static const uint8_t turbo = 13;
static const uint8_t dir_A = 0;
static const uint8_t dir_B = 2;

void setup() {
  Serial.begin(115200);
  Serial.println("Iniciando...");
  if (ap == "on") {
    Serial.println("Modo Acess Point/Roteador");
    WiFi.mode(WIFI_AP); //Entrando modo Acess Poit/Roteador
    WiFi.softAPConfig(ip, ip, netmask);
    WiFi.softAP(ssid, password);
  } else if (ap == "off") {
    Serial.println("Modo Conectando WIFI");
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password); //Preparando conexão

    // Conectando WIFI
    Serial.println("Conectando WIFI");
    while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
      delay(500);
    }
    Serial.println("Conectado IP:");
    Serial.print(WiFi.localIP());
  }

  // Definindo Motores
  pinMode(pwm_A, OUTPUT); // PMW A
  pinMode(pwm_B, OUTPUT); // PMW B
  pinMode(pwm_M, OUTPUT); // PMW M
  pinMode(dir_A, OUTPUT); // DIR A
  pinMode(dir_B, OUTPUT); // DIR B
  pinMode(turbo, OUTPUT); // DIR B
  server.begin();

}

void loop() {
  static char cmdBuffer[CMDBUFFER_SIZE] = "";
  String nx = "0";

  WiFiClient client = server.available();
  if (Serial.available() > 0) {
    if (Serial.read() == '#') {
      Serial.write("\n Restart");
      ESP.restart();
    }
  }
  if (client) {
    while (client.connected()) {
      String conc = "";
      int i = 0;
      while ( client.available()) {
        char val = client.read();
        String sval = String(val);
        if (sval.equals("m")) {
          Serial.write("\n M VAL");
          inData[i] = '\0';
          client.write("val m:");
          client.write(inData);
          m = conc.toInt();
          arma();
        } else if (sval.equals("y")) {
          Serial.write("\n Y VAL");
          inData[i] = '\0';
          client.write("val y:");
          client.write(inData);
          y = conc.toInt();
          rodas();
        } else if (sval.equals("x")) {
          Serial.write("\n X VAL");
          inData[i] = '\0';
          client.write("val x:");
          client.write(inData);
          x = conc.toInt();
          rodas();
        } else {
          Serial.write("\n ADD VAL");
          nx = "0";
          conc.concat(String(val));
          inData[i] = val;
          i++;
        }

      }

      delay(10);
    }

    client.stop();
    Serial.println("Desconectado");

  }

}
void arma() {
    if(m > 500){
    analogWrite(pwm_M, HIGH);
    }else{
    analogWrite(pwm_M, LOW);
    }
}
void rodas() {
  // Motor speed = [0-1024]
  int motorA;
  int motorB;
  byte dmotorA = HIGH;
  byte dmotorB = HIGH;
  motorA = (x + y);
  motorB = (x - y);
  if (motorA <= 0) {
    dmotorA = LOW;
    motorA = motorA * -1;
  }
  if (motorB <= 0) {
    dmotorB = LOW;
    motorB = motorB * -1;
  }
  if (motorA > 1000) {
    motorA = 1024;
  }
  if (motorB > 1000) {
    motorB = 1024;
  }
  analogWrite(pwm_A, motorA);
  analogWrite(pwm_B, motorB);
  digitalWrite(dir_A, dmotorA );
  digitalWrite(dir_B, dmotorB );
}
