#ifndef __LIST_PERSONS_H__
#define __LIST_PERSONS_H__

#define MAX_PERSONS 100
#include "person.h"

typedef struct {
  PERSON person[MAX_PERSONS];
  int count;
} LIST_PERSONS;


void list_persons_inic(LIST_PERSONS *list);
int list_persons_isFull(LIST_PERSONS *list);
int list_persons_isEmpty(LIST_PERSONS *list);
void list_persons_add(LIST_PERSONS *list, PERSON *record);
int list_persons_getIndex(LIST_PERSONS *list, int id);
void list_persons_loadFromFile(FILE *fp, LIST_PERSONS *list);

#endif // __LIST_PERSONS_H__
