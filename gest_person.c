#include <stdio.h>
#include <stdlib.h>

#include "includes/person.h"
#include "includes/list_persons.h"
#include "includes/gestdata.h"
#include "includes/gest_person.h"


static const char* menu_person[] = {
  "I - Inserir Pessoa",
  "A - Alterar Pessoa",
  "R - Remover Pessoa",
  "U - Recuperar pessoa (Undelete)",
  "",
  "L - Listar pessoas",
  "",
  "1 - Ordenar lista de pessoas",
  "2 - Pesquisar pessoa (pesquisa sequencial)",
  "3 - Pesquisar pessoa (pesquisa binaria)",
  "",
  "X - Sair",
  NULL
};



// Ecra de gestao de pessoas
void manage_persons(FILE *fp, LIST_PERSONS* list_persons){
  char opcao;

  while ((opcao = get_menu_option(menu_person))!=OP_EXIT)
    switch(opcao)
    {
      case OP_INSERT:      insert_person(fp, list_persons); break;
      case OP_UPDATE:      update_person(fp, list_persons); break;
      case OP_REMOVE:      remove_person(fp, list_persons); break;

      case OP_LIST:        wait("Listagens (Pessoas)"); break;

      case OP_EXIT:        wait("Opcao SAIR"); break;
    }

}

// Processa um novo registo de pessoa
void insert_person(FILE *fp, LIST_PERSONS *list_persons) {

  // TODO
}

// Processa um novo registo de pessoa
void update_person(FILE *fp, LIST_PERSONS *list_persons) {

  int id = read_integer("Indique o Id a alterar: ", 100, 999);

  int index = list_persons_getIndex(list_persons, id);
  if (index==REC_NOT_FOUND)
  {
    wait("Nao existe um registo de pessoa com o indicado.");
    return;
  }

  // TODO
}

void remove_person(FILE *fp, LIST_PERSONS *list_persons) {
  // TODO
}

//
// Grava um registo de pessoa no ficheiro.
// O processamento difere caso a operacao seja uma insercao ou alteracao
// Devolve um valor boolean indicando se a operacao foi realizada com uscesso
//
int save_person(FILE *fp, LIST_PERSONS *list_persons, PERSON *p, char operation) {
  // Ver se a pessoa ji existe e obter o indice da sua posicao
  int index = list_persons_getIndex(list_persons, p->id);

  // TODO

  return 1;
}

