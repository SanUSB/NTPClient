#include <time.h>
#include <sys/time.h>
struct tm data;//Cria a estrutura que contem as informacoes da data.
#define led 2
int32_t hora, minuto, segundo;
/*
Unix time é a contagem de segundos desde 01/01/1970. 
*/
void setup()
{
  Serial.begin(115200);
  pinMode(led, OUTPUT);
  digitalWrite(led, 1);
  timeval tv;//Cria a estrutura temporaria para funcao abaixo.
  tv.tv_sec = 1591369604;//Atribui minha data atual. Voce pode usar o NTP
  settimeofday(&tv, NULL);//Configura o RTC para manter a data atribuida atualizada.
}

void loop()
{
    delay(1000);
    time_t tt = time(NULL);//Obtem o tempo atual em segundos. Utilize isso sempre que precisar obter o tempo atual
    data = *gmtime(&tt);//Converte o tempo atual e atribui na estrutura    
    /******************Calculate time from Unix Time*********************
    //tt = UnixTime();
    //hora = (tt  % NUMBEROFSECONDSPERDAY) / NUMBEROFSECONDSPERHOUR;
    //minuto = (tt % NUMBEROFSECONDSPERHOUR) / NUMBEROFSECONDSPERMINUTE;
    //segundo = tt % NUMBEROFSECONDSPERMINUTE;
    //******************************************************************/
    Serial.println("");
    Serial.print("A hora calculada é ");       //tt já vem no fuso 
    hora = ((tt  % 86400) / 3600); //+ fuso); - (3 * 3600));// (86400 (24 x 3600) segundos por dia). Retira-se o resto da divisão de dias 
    Serial.print(hora);                                     // e divide por 3600 seg, o inteiro do resultado é a quantidade de horas
    Serial.print(':');    
    minuto = (tt % 3600) / 60;                      
    if ( minuto < 10 ) {
      // Adiciona o caractere '0' entre os minutos 0 e 9 iniciais.
      Serial.print('0');
    }
    Serial.print(minuto); // Pega-se o resto da divisão de horas inteiras e divide por 60, o inteiro são os minutos (3600 equals secs per hour)
    Serial.print(':');
    segundo = tt % 60;
    if ( segundo < 10 ) {
      // Adiciona o caractere '0' entre os segundos 0 e 9 iniciais.
      Serial.print('0');
    }
    Serial.println(segundo); // Pega-se o resto da divisão de minutos, o que sobra são os segundos    
    //**********************************************************************************  
    if (hora == 15 && minuto == 6)//Use sua data atual, em segundos, para testar o acionamento
    {
      printf("sanusb.org alarm!!!\n");
    }
    
    char data_formatada[64];
    strftime(data_formatada, 64, "%d/%m/%Y %H:%M:%S", &data);//Cria uma String formatada da estrutura "data"
    printf("\nUnix Time: %d\n", int32_t(tt));//Mostra na Serial o Unix time
    printf("Data formatada: %s\n", data_formatada);//Mostra na Serial a data formatada
    
    digitalWrite(led, !digitalRead(led)); 
}
