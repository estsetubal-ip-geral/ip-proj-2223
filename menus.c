#include <stdio.h>
#include <stdio.h>
#include <ctype.h>
#include "includes/utils.h"

// Verifica se o char é uma das opcoes do menu (1a letra de alguma das strings)
static int is_valid_option(char option, const char*menu[]) {
  option = tolower(option);
  for (int i=0; menu[i]!=NULL; i++)
    if (option==tolower(menu[i][0]))
      return 1;
  return 0;
}

// Devolve a opao (1a letra) do descritivo do menu que foi seleccionado pelo utilizador (em minusculas)
char get_menu_option(const char *menu[])
{
  char opcao;

  do {
    int i=0;

    cls();
    puts("\n\n\n");
    // Apresentar as opcoes
    while (menu[i]!=NULL)
      printf("\t\t\t%s\n", menu[i++]);

    // Ler a escolha do utilizador
    fflush(stdin);
    printf("\n\t\t\t\tOpao: ");
    opcao = tolower(getchar());
  }
  while(!is_valid_option(opcao, menu));

  return opcao;
}


