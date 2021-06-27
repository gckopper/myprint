/*******************************************************
 * Autor: Gabriel Capp Kopper (gckopper)
 * Data: 23/04/2021
 * Versão: 1.1
********************************************************/

// Utiliza de algumas regras do compilador para impedir que o codigo seja adicionado múltiplas vezes
#ifndef _MYPRINT_ 
#define _MYPRINT_

// Inclue seu próprio arquivo de cabeçalho
#include "libmyprint.c"

// Declara o protótipo das funções como externas para que elas sejam acessíveis por fora da biblioteca
extern void print(const char *format, ...); 

extern void printt(const char *format, ...);

extern void printerr(const char *format, ...);

#endif