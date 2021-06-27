// Inclui as bibliotecas necessárias para a execução do código
#include <stdarg.h>
#include <stdio.h>
#include <time.h>

// A função print é igual a função printf sendo a única diferença que ele adiciona uma nova linha no final de cada chamada da função
// Isso é feito para tornar a  programação em C/C++ mais parecida com Python
void print(const char *format, ...)
{
    // Cria "agrs" como uma lista de argumentos
    va_list args; 
    // Inicializa "args" com os valores de "format"
    va_start(args, format); 

    // Usa a função vfprintf para formatar uma sequencia de caracteres ("format") baseado na lista de 
    // argumentos ("args") e enviar essa sequencia para a stdout
    vfprintf(stdout, format, args); 

    // Todo o uso de uma "va_list" termina com "va_end"
    va_end(args);

    // Adiciona uma nova linha no final
    fprintf(stdout, "\n");
}

// A função printt é igual a função printf sendo a única diferença que ele adiciona uma 
// 'timestamp' de quando a função é executada  uma nova linha no final de cada chamada da função
// Isso é feito para tornar a  programação em C/C++ mais parecida com Python
void printt(const char *format, ...)
{
    // Tipo especial para armazenar o tempo desde a "epoch" (1970-01-01 00:00:00 +0000 (UTC))
    time_t rawtime;
    // Cria um ponteiro do tipo "broken-down time" (o mesmo tipo que é retornado pela função "localtime") 
    // que contem a data dividida em em variaveis do tipo "int" para hora, minutos, segundos, etc.
    struct tm *info;
    // Calcula o tempo desde a "epoch" e amazena o valor na variavel
    time( &rawtime );
    // Separa a data em dia, mes, ano, etc... e armazena esses valores na struct info
    info = localtime( &rawtime );

    // A função asctime transforma a struct "info" em uma string com todas as informações
    // Escreve a data na stdout com um ": " no final para deixar a data separada da mensagem
    char a[25];
    snprintf(a, 25, "%s", asctime(info));
    printf("%s: ", a);

    // Cria "agrs" como uma lista de argumentos
    va_list args;
    // Inicializa "args" com os valores de "format"
    va_start(args, format);

    // Usa a função vfprintf para formatar uma sequencia de caracteres ("format") baseado na lista de 
    // argumentos ("args") e enviar essa sequencia para a stdout
    vfprintf(stdout, format, args);

    // Todo o uso de uma "va_list" termina com "va_end"
    va_end(args);

    // Adiciona uma nova linha no final
    fprintf(stdout, "\n");
}

// A função printerr é igual a função printt sendo a única diferença que ele envia a
// saída para a stderr para reportar erros
void printerr(const char *format, ...)
{
    // Tipo especial para armazenar o tempo desde a "epoch" (1970-01-01 00:00:00 +0000 (UTC))
    time_t rawtime;
    // Cria um ponteiro do tipo "broken-down time" (o mesmo tipo que é retornado pela função "localtime") 
    // que contem a data dividida em em variaveis do tipo "int" para hora, minutos, segundos, etc.
    struct tm *info;
    // Calcula o tempo desde a "epoch" e amazena o valor na variavel
    time( &rawtime );
    // Separa a data em dia, mes, ano, etc... e armazena esses valores na struct info
    info = localtime( &rawtime );

    // A função asctime transforma a struct "info" em uma string com todas as informações
    // Escreve a data na stderr com um ": " no final para deixar a data separada da mensagem
    char a[25];
    snprintf(a, 25, "%s", asctime(info));
    fprintf(stderr, "%s ERRO: ", a);

    // Cria "agrs" como uma lista de argumentos
    va_list args;
    // Inicializa "args" com os valores de "format"
    va_start(args, format);

    // Usa a função vfprintf para formatar uma sequencia de caracteres ("format") baseado na lista de 
    // argumentos ("args") e enviar essa sequencia para a stderr
    vfprintf(stderr, format, args);

    // Todo o uso de uma "va_list" termina com "va_end"
    va_end(args);

    // Adiciona uma nova linha no final
    fprintf(stderr, "\n");
}