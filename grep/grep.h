#ifndef SRC_GREP
#define SRC_GREP

#include <getopt.h>
#include <pcre.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_grep {
  int e;
  int f;
  int i;
  int v;
  int c;
  int l;
  int n;
  int h;
  int s;
  int o;
  int count;
  int check;
  int flag;
  int incr;
  int incr_f;
  int out;
  int incr_e;
  int start;
  int enter;
  int next;
} grep_flags;

void getopt_func(int argc, char *argv[], grep_flags *elements, char *pattern,
                 char *name_file[]);
void get_pattern_e(grep_flags *elements, char *pattern, char *optarg, int *a);
void get_pattern_all(char *argv[], grep_flags *elements, char *pattern,
                     int optind);
void clear_memory(grep_flags *elements, char *name_file[]);
void check_file_flags(int argc, char *argv[], grep_flags *elements,
                      char *name_file[], char *pattern);
void read_file(grep_flags *elements, char *name_file[], char *pattern);
void pcre_func(char *buff, grep_flags *elements, char *pattern,
               char *name_file[], int i);
void get_pattern_file(char *optarg, char *pattern, int *a,
                      grep_flags *elements);
void flag_o(int pairs_o, pcre *temp, pcre_extra *f_ext, char *buff, int *vector,
            int vecsize, const char *errstr, grep_flags *elements,
            char *nale_file[], int i);
void check_enter(char *buff);
void func_no_lc(int pairs_o, pcre *temp, pcre_extra *f_ext, char *buff,
                int *vector, int vecsize, const char *errstr,
                grep_flags *elements, char *name_file[], int i);

#endif