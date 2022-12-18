#ifndef __UTILS_H__
#define __UTILS_H__

#define N_MONTHS 12


#define REC_NOT_FOUND -1


#define ANSWER_YES 's'
#define ANSWER_NO  'n'

typedef struct {
  int year, month, day;
} DATE;

void cls();
void wait(const char*caption);

int file_exists(const char*filename);
int read_integer(const char*prompt, int min, int max);
char* read_string(const char*prompt, char*s, int min_len);

DATE read_date(const char* prompt);

char get_menu_option(const char *menu[]);
int confirm(const char*prompt);

#endif // __UTILS_H__


