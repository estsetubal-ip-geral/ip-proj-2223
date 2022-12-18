#ifndef __GEST_PERSON__
#define __GEST_PERSON__


#include "person.h"
#include "list_persons.h"

void manage_persons(FILE *fp, LIST_PERSONS* list_persons);

void insert_person(FILE *fp, LIST_PERSONS *list_persons);
void update_person(FILE *fp, LIST_PERSONS *list_persons);
void remove_person(FILE *fp, LIST_PERSONS *list_persons);

int save_person(FILE *fp, LIST_PERSONS *list_persons, PERSON *p, char operation);

#endif // __GEST_PERSON__

