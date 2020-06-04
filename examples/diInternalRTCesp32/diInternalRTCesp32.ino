#include <time.h>
#include <sys/time.h>
struct tm data;//Cria a estrutura que contem as informacoes da data.
/*
Unix time é a contagem de segundos desde 01/01/1970. 
*/
void setup()
{
  timeval tv;//Cria a estrutura temporaria para funcao abaixo.
  tv.tv_sec = 1591037364;//Atribui minha data atual. Voce pode usar o NTP
  settimeofday(&tv, NULL);//Configura o RTC para manter a data atribuida atualizada.
}

void loop()
{
    delay(1000);
    time_t tt = time(NULL);//Obtem o tempo atual em segundos. Utilize isso sempre que precisar obter o tempo atual
    data = *gmtime(&tt);//Converte o tempo atual e atribui na estrutura
    
    char data_formatada[64];
    strftime(data_formatada, 64, "%d/%m/%Y %H:%M:%S", &data);//Cria uma String formatada da estrutura "data"
    printf("\nUnix Time: %d\n", int32_t(tt));//Mostra na Serial o Unix time
    printf("Data formatada: %s\n", data_formatada);//Mostra na Serial a data formatada

    if (tt >= 1591037374 && tt < 1591037379)//Use sua data atual, em segundos, para testar o acionamento por datas e horarios
    {
      printf("Alarm!!!\n");
    }
}
