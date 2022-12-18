#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "includes/gestdata.h"
#include "includes/utils.h"


#define MAX_CODE2_SIZE 2
#define MAX_CODE3_SIZE 3
#define MAX_COUNTRY_SIZE 100

#define MAX_COUNTRIES 100

typedef struct {
  char code2[MAX_CODE2_SIZE+1];
  char code3[MAX_CODE3_SIZE+1];
  char country[MAX_COUNTRY_SIZE+1];
} COUNTRY;

typedef struct {
  COUNTRY arr[MAX_COUNTRIES];
  int count;
} LIST_COUNTRIES;

int read_country_from_txt_file(FILE*fp, COUNTRY *country);
void show_country(COUNTRY country);
void show_countries(LIST_COUNTRIES list);
int compare(const void *p1, const void *p2);


// Programa de demonstracao de processamento de registos de paises

void manage_countries(){
  LIST_COUNTRIES list_countries;
  list_countries.count = 0;   // Nao ha paises na lista
  char aux[MAX_STRING];


  wait("Importar o ficheiro csv com os paises. Prima <ENTER>...\n");
  // Importar os dados do ficheiro para a lista de countries
  FILE *fp;         // Ficheiro para importar os dados.
  sprintf(aux, "%s/%s", "datasets", "countries.csv");

  if ((fp=fopen(aux, "rt"))==NULL)
  {
    wait("Problemas na abertura do ficheiro de paises.");
    return;
  }

  while (read_country_from_txt_file(fp, &list_countries.arr[list_countries.count])) // Enquanto conseguir ler um registo
  {
    printf("Ler registo de ficheiro de texto #%d\n", ++list_countries.count);
  }
  fclose(fp);


  wait("\n\nGravar num ficheiro binario os registos lidos. Prima <ENTER>...");

  FILE *fp_country;
  if ((fp_country = open_data_file(DIR_DATA, DATA_FILE_COUNTRY))==NULL)      // Abrir o ficheiro de dados
    return;
  int n_recs = fwrite(list_countries.arr, sizeof(COUNTRY), (long) list_countries.count, fp_country);

  if (n_recs!=list_countries.count)
  {
    wait("Problemas na gravacao dos registos no ficheiro binario. Prima <ENTER>...");
    return;
  }
  else
  {
    fflush(fp_country); // just in case
    fclose(fp_country);
    wait("Registos gravados com sucesso. Prima <ENTER>...");
  }


  puts("\n\nLimpar a lista de registos em memoria."); 
  list_countries.count=0; // Lista vazia.
 
 wait("Ler a lista de registos a partir do ficheiro binario. Prima <ENTER>...");

  if ((fp_country = open_data_file(DIR_DATA, DATA_FILE_COUNTRY))==NULL)      // Abrir o ficheiro de dados
    return ;
  while (fread(&list_countries.arr[list_countries.count], sizeof(COUNTRY), 1L, fp_country)==1)
  {
     list_countries.count++;
     printf("Ler registo de ficheiro binario  #%d\n", list_countries.count);
  }

  fclose(fp_country);
  wait(NULL);


  puts("------------ Registos de paises lidos a partir do ficheiro binario ------------");
  show_countries(list_countries);
  wait(NULL);

  wait("\n\nOrdenar lista de pessoas pelo nome do pais. Tome atencao as posicoes de Portugal e Espanha. Prima <ENTER>...");
  qsort(list_countries.arr, (long) list_countries.count, sizeof(COUNTRY), compare);
  puts("------------ Registos de paises apos ordenacao por nome do pais ------------");
  show_countries(list_countries);
  wait(NULL);



  puts("\n\nProcura binaria do pais [Portugal] na lista ordenada de paises.");
  COUNTRY p = {"PT","POR","Portugal"};
  COUNTRY *ptr = bsearch(&p, list_countries.arr, (long) list_countries.count, sizeof(COUNTRY), compare);
  if (ptr!=NULL)
  {
    show_country(*ptr);
    wait("Encontrado o pais [Portugal]\n\n");
  }
  else
    wait("NAO FOI ENCONTRADO pais [Portugal]\n\n");


  puts("\n\nProcura binaria do pais [Portugallo] na lista ordenada de paises.");
  strcat(p.country,"lo"); // Juntar "lo" a "Portugal" para se obter "Portugallo"
  ptr = bsearch(&p, list_countries.arr, (long) list_countries.count, sizeof(COUNTRY), compare);
  if (ptr!=NULL)
  {
    show_country(*ptr);
    wait("Encontrado o pais [Portugallo]\n\n");
  }
  else
    wait("NAO FOI ENCONTRADO pais [Portugallo]\n\n");

  wait("That's all!!!");
}



// Read one contry in file.
// Return boolean
int read_country_from_txt_file(FILE*fp, COUNTRY *country) {
  int n_fields = fscanf(fp, "%s %s %[^\n]s", country->code2, country->code3, country->country);
  return (n_fields == 3); // Sucesso se foram lidos 3 campos
}

// show one country
void show_country(COUNTRY country){
  printf("%s %s %s\n", country.code2, country.code3, country.country);
}

// show all countries in the list
void show_countries(LIST_COUNTRIES list){
  for (int i=0; i<list.count; i++)
     show_country(list.arr[i]);
}


int compare(const void*ptr1, const void* ptr2){
  COUNTRY *p1 = (COUNTRY *) ptr1;
  COUNTRY *p2 = (COUNTRY *) ptr2;

/*
  // comparar code2
  int res = strcmp(p1->code2, p2->code2);
  if (res!=0) return res;
  

  // comparar code3
  res = strcmp(p1->code3, p2->code3);
  if (res!=0) return res;
*/

  // comparar o descritivo do pais
  return strcmp(p1->country, p2->country);
}
