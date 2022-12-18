#include <stdio.h>
#include "includes/list_persons.h"

// Inicializa uma lista de pessoas
void list_persons_inic(LIST_PERSONS *list) {
  list->count=0;
}

// Verifica se a lista de pessoas esta cheia
int list_persons_isFull(LIST_PERSONS *list) {
  return (list->count==MAX_PERSONS);
}

// Verifica se a lista de pessoas esta vazia
int list_persons_isEmpty(LIST_PERSONS *list) {
  // TODO
  return 1;
}

// Adiciona uma nova pessoa a lista, caso ainda exista espaco disponivel.
// Caso contrario mostra um erro.
void list_persons_add(LIST_PERSONS *list, PERSON *record) {

  // TODO

}

// Devolve a posicao onde se encontra o id no array de pessoas ou REC_NOT_FOUND, caso nao exista.
int list_persons_getIndex(LIST_PERSONS *list, int id) {

  // TODO

  return REC_NOT_FOUND;
}

// Carrega a lista de pessoas a partir do ficheiro fp que se assume aberto e
// posicionado algures
void list_persons_loadFromFile(FILE *fp, LIST_PERSONS *list) {

  // TODO

}
