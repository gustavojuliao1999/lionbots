# Li-on Bots


![GitHub repo size](https://img.shields.io/github/repo-size/iuricode/README-template?style=for-the-badge)
![GitHub language count](https://img.shields.io/github/languages/count/iuricode/README-template?style=for-the-badge)
![GitHub forks](https://img.shields.io/github/forks/iuricode/README-template?style=for-the-badge)
![Bitbucket open issues](https://img.shields.io/bitbucket/issues/iuricode/README-template?style=for-the-badge)
![Bitbucket open pull requests](https://img.shields.io/bitbucket/pr-raw/iuricode/README-template?style=for-the-badge)

<img src="exemplo-image.png" alt="exemplo imagem">


O projeto ainda está em desenvolvimento e as próximas atualizações serão voltadas nas seguintes tarefas:

- [x] Comunicação com O NODEMCU
- [x] DESING DO SOFTWARE
- [x] AJUSTE DE RESOLUÇÃO
- [ ] CORRRIGIR PROBLEMAS DE COMUNICAÇÃO
- [ ] MELHORAR SISTEMA DE SALVAMENTO

## 💻 Abrindo Projeto Unity

* Baixar software Unity que foi ultilizado para desenvolver e baixar junto o modulo Android Build Suport.
* Apos você abre o Projeto que esta na pasta Unity.

## 💻 Instalar e Editar NodeMcu

Configurando IDE

* Baixe Arduno Ide https://www.arduino.cc/en/software.
* Abra Ide Arduno.
* Clique Arquivo - Preferencias.
* Em "URL Adicionais" coloque essa URL "http://arduino.esp8266.com/stable/package_esp8266com_index.json" clique OK.
* Clique em Sketch - Incluir Biblioteca - Gerenciar Biblioteca.
* Pesquise "esp8266 by ESP8266 Community", INSTALAR e Fechar a Janela.
* Clique em Ferramentas - Placa - ESP8266 - NODEMCU 1.0.
* Agora Selecionar a porta da Placa clique Ferramentas - Porta e seleciona a placa.


Configurando Para enviar placa

* Abra o Arquivo do Robo pasta Arduino Li-on_Bots.ino.
* Aconselho usar em como Roteador onde o telefone conecta diretamente a ele.
* Caso modo roteador deixar ap = "ON" se for conectar a um wifi colocque ap = "OFF".
* ssid Coloque o nome do Wifi que Vai gerar ou Connectar entre "" exemplo "WifiRobo01".
* Senha coloque entre "" a senha que vai se conectar minimo 8 caracteres e maximo 32.
* O ip caso for conectar a um wifi pesquise qual faixa de ip o roteador usa e coloque um ip na mesma faixa.
* Agora só clicar na -> e carregar na Placa NODEMCU conectado ao SHIELD de Motor.

## ☕ Usando Li-on Bots

Para Executar o Controle Li-On Bots, siga estas etapas:

Android:

* O Telefone precisar esta conectado ao wifi do NODEMCU ou na mesma rede que ele estiver conectado.
* Baixe na PlayStore o app https://bit.ly/304XZLM ou instale o APK na pasta Android.
* Na Parte ip Coloque o mesmo ip que foi colocado na Placa e clique salvar e conectar.
* Pronto está conectado e funcionando a placa.



Windows:

* O computador precisar esta conectado ao wifi do NODEMCU ou na mesma rede que ele estiver conectado.
* Após Abra o software na pasta Windows e Abra Control LionBots.exe.
* Na Parte ip Coloque o mesmo ip que foi colocado na Placa e clique salvar e conectar.
* Pronto está conectado e funcionando a placa.

