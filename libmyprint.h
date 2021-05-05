/*******************************************************
 * Autor: Gabriel Capp Kopper (gckopper)
 * Data: 23/04/2021
 * Versão: 1.1
********************************************************/

// Utiliza de algumas regras do compilador para impedir que o codigo seja adicionado múltiplas vezes
#ifndef _MYPRINT_ 
#define _MYPRINT_

// Inclui as bibliotecas necessárias para a execução do código
#include <stdarg.h>
#include <stdio.h>
#include <time.h>

// Declara o protótipo das funções como externas para que elas sejam acessíveis por fora da biblioteca
extern void print(const char *format, ...); 

extern void tprint(const char *format, ...);

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

#endif