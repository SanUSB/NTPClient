#TEMPORIZADORES E RELÓGIOS EM TEMPO REAL
Nesse material didático é proposta uma breve revisão sobre os temporizadores e relógios/calendários em tempo real (RTC) disponíveis para famílias de microcontroladores ESP32 e ESP8266. Com excessão do exemplo do RTC interno, que é um periférico disponível apenas no ESP32, todos os outros exemplos didáticos do repositório foram testados e funcionam tanto no ESP32 quanto no ESP8266, sendo uma característica relevante para diversas aplicações reais. Mais detalhes em: https://youtu.be/vyq2sJE_DwM .
Geralmente, para operações automáticas de IoT são utilizados temporizadores e/ou relógios em tempo real (real time clock - RTC) para tarefas agendadas do processo. Esse tópico é muito relevante em projetos práticos reais. 
Nesse sentido, segundo o próprio github em https://help.github.com/pt/github/getting-started-with-github/fork-a-repo, foi bifurcado (fork) um projeto e modificado para dar suporte aos exemplos práticos sobre temporizadores e RTCs disponíveis para os dois modelos em https://github.com/SanUSB/NTPClient. Todos os exemplos podem ser repetidos por qualquer interessado, bastando somente um computador e um microcontrolador ESP e mais nenhum outro periférico, pois até o LED utilizado é o BULTIN contido na placa do microcontrolador.
Quanto aos temporizadores nos microcontroladores, podemos classificá-los como:  
a. do Hardware: são periféricos reais contidos no hardware interno dos microcontroladores;
b. Emulados por software: são temporizadores emulados pelo processador dos microcontroladores. A biblioteca Ticker é baseada em temporizadores emulados por software.
Quantos aos relógios/calendários em tempo real (RTC) aplicados em sistemas IoT, podemos classificá-los como:
c. Online: Baseado em NTP (Network Time Protocol).
O Brasil tem o projeto NTP.br com objetivo de oferecer condições para que os servidores de Internet estejam sincronizados com a Horal Legal Brasileira. Os servidores públicos NTP no Brasil do estrato 2 do NTP.br são a.ntp.br, b.ntp.br e c.ntp.br.
Eles são alimentados por servidores primários (estrato 1), também acessíveis publicamente, entre eles, a.st1.ntp.br, b.st1.ntp.br, c.st1.ntp.br e d.st1.ntp.br.
Esses, por sua vez, são sincronizados com relógios atômicos, que são de responsabilidade do Observatório Nacional.
Existe também o servidor gps.ntp.br, ilustrado na Figura abaixo, que é utilizado para monitoramento do sistema. É um servidor ntp estrato 1, sincronizado com o Sistema de Posicionamento Global (GPS). 
 
d. Offline: 
d.i.   Utilizando RTC real interno, no caso do ESP32;
d.ii. Emulados via software, como por exemplo, utilizando a biblioteca ticker (funcional). Vale salientar que como o ESP8266 não tem um RTC interno, emular um RTC via software pode ser uma possibilidade viável, principalmente para sistemas que necessitam de muita exatidão e nível de segundos, tendo em vista que esse procedimento foi utilizado em um projeto de controle de acesso RFID de laboratório e funcionou como esperado. Um teste sobre a comparação desse sistam com o NTP é mostrado no vídeo.
d.iii.   Utilizando RTC real externo, como por exemplo, o DS1307;

e. Híbridos: Que utiliza o NTP para referenciar e/ou atualizar os relógios em tempo real (RTC) offline. Abaixo, um gráfico com resumo dos tipos sugeridos nessa pesquisa:
 
Quanto à preservação dos dados do RTC, em caso de queda de energia, se utiliza normalmente:
•	Bateria em paralelo com a fonte de alimentação do microcontrolador;
•	Memória persistente para restaurar o relógio com o último horário armazenado até a correção manual ou automática via NTP quando voltar a conexão com a Internet.
•	Aplicar redundância na atualização de relógio, como por exemplo, o RTC interno do ESP32 em paralelo com NTP. É considerado o maior valor Unix time, ou seja, o sistema mais atual;
Nos exemplos citados será utilizada as bibliotecas Ticker, Time e NTPclient.

