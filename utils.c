#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "includes/utils.h"


static int days_of_month[] = {0,31,28,31,30,31,30,31,31,30,31,30,31}; // posicao igual ao n. do mes

// Limpa o ecra
void cls() {

#ifdef  _WIN32
  system("cls");
#else // linux
  system("clear");
#endif
}


// Mostra uma string e aguarda que o utilizador prima ENTER para a aplicacao continuar
// 'E mostrada a string enviada 'a  funcao ou a string por defeito, caso se envie NULL
void wait(const char*caption) {
  char *alt = "\nPrima <ENTER> para continuar . . .";

  if (caption==NULL || caption[0]=='\0')
    caption = alt;

  do {
    fflush(stdin);
    printf("%s", caption);
  }
  while (getchar()!='\n');
}

// Verifica se um ficheiro existe
int file_exists(const char*filename) {
  FILE *fp = fopen(filename, "rb");
  int exist_file = (fp!=NULL);
  if (fp!=NULL) fclose(fp);
  return exist_file;
}

// Le um inteiro entre dois valores (limites incluidos)
int read_integer(const char*prompt, int min, int max){
  int value;
  do {
    fflush(stdin);
    printf("%s", prompt);
    scanf("%d", &value);
  }
  while(value<min || value>max);
  return value;
}

// Le uma string com dimensao minima
char* read_string(const char*prompt, char*s, int min_len){
  // TODO
return NULL;
}

// Verifica se um ano é bissexto
int isLeapYear(int year) {
  // TODO
  // https://www.mathsisfun.com/leap-years.html
	return 1;
}

// Verifica se uma data é valida
int isDate(DATE date) {
  // TODO
  return 1;
}

// Adiciona um dia 'a data enviada por parametro
void date_addOneDay(DATE *date)
{
  // TODO
}

// Adiciona n_dias 'a data enviada por parametro
void date_add(DATE *date, int n_days)
{
  // TODO
}


// Le e retorna uma data no formato yyyy-mm-dd. Caso a data seja invalida mostra um
// erro e volta a pedir, até que uma data valida seja introduzida.
DATE read_date(const char* prompt) {
  DATE date;
  // TODO

  return date;
}

// Solicita a confirmacao de um pedido
int confirm(const char*prompt) {
  char answer;
  do {
    printf("%s (s/n)? : ", prompt);
    fflush(stdin);
    scanf(" %c", &answer);
    answer = tolower(answer);
  }
  while (answer!=ANSWER_YES && answer!=ANSWER_NO);

  return answer==ANSWER_YES;
}

