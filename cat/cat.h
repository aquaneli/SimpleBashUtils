#ifndef SRC_CAT
#define SRC_CAT

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_cat {
  int b;
  int e;
  int n;
  int s;
  int t;
  int T;
  int v;
  int check;
  int incr;
  char sym;
} cat_flags;

void parsing(int argc, char *argv[], cat_flags *elements, int *i);
int pars_argv(char *argv[], cat_flags *elements, int *i);
int get_flags(char c, cat_flags *elements);
void read_file(char *argv[], cat_flags *elements, int *i);
void flag_s(char *ch, cat_flags *elements, int *k);
void flag_b(char *ch, int *count_1, int *count_2);
void flag_n(char *ch, int *count_1, int *count_2);
void flag_t(char *ch);
void flag_e(char *ch);
void flag_v(char *ch);
int flags_GNU(char *argv[], cat_flags *elements, int *i);

#endif