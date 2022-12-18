CC=gcc
CFLAGS= -g -Wall

gestdata: gestdata.o gest_countries.o gest_person.o list_persons.o menus.o person.o utils.o 
	$(CC) -o gestdata gestdata.o gest_countries.o gest_person.o list_persons.o menus.o person.o utils.o


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	rm -f gestdata  *.o *.obj gestdata.exe



