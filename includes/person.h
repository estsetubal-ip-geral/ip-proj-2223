#ifndef __PERSON_H__
#define __PERSON_H__

#include "utils.h"

#define MAX_NAME_SIZE           50
#define MAX_ADDRESS_SIZE       100
#define MAX_EMAIL_SIZE          50
#define MAX_GENDER_SIZE         10
#define MAX_COUNTRY_CODE_SIZE    2
#define MAX_DEP_SIZE            50


typedef struct
{
   int  id;
   char full_name[MAX_NAME_SIZE+1];
   char address[MAX_ADDRESS_SIZE+1];

  // TODO

   int is_active;
} PERSON;


void read_person(PERSON *p, char operation);
void show_person_vertical(PERSON *p);
void show_person_horizontal(PERSON *p);

#endif // __PERSON_H__
