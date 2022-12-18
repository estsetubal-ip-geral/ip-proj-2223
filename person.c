#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

#include "includes/person.h"
#include "includes/gestdata.h"

// Ler o registo de uma pessoa a partir do ecra
// operation = 'I' (new record) 'U' (update record)

void read_person(PERSON *p, char operation) {

   if (operation==OP_INSERT) // nunca se altera um id
     p->id = read_integer("Id         : ", 100, 999);

   // TODO

   p->is_active = 1;  // Por defeito o registo fica ativo (true)
}

void show_person_vertical(PERSON *p){

}

void show_person_horizontal(PERSON *p){

}
