#include "grep.h"

int main(int argc, char *argv[]) {
  grep_flags elements = {0};
  char pattern[1000] = {0};
  char *name_file[1000] = {NULL};
  if (argc < 3) {
    fprintf(stderr, "no valid argument\n");
  } else {
    getopt_func(argc, argv, &elements, pattern, name_file);
  }
  return 0;
}

void getopt_func(int argc, char *argv[], grep_flags *elements, char *pattern,
                 char *name_file[]) {
  int a = 0;
  int b = 0;
  int res = 0;
  elements->out = 0;
  elements->incr_f = 0;
  elements->incr_e = 0;
  elements->incr = 0;
  const char *short_options = "e:f:ivclnhso";

  while ((res = getopt_long(argc, argv, short_options, NULL, NULL)) != -1) {
    switch (res) {
      case 'e': {
        elements->e = 1;
        if (elements->incr_e != 0 || elements->incr_f != 0) {
          int i = strlen(pattern);
          pattern[i] = '|';
        }
        get_pattern_e(elements, pattern, optarg, &a);
        int o = strlen(pattern);
        if (pattern[o - 1] == '|') {
          pattern[o - 1] = '\0';
        }
        elements->incr_e++;
        break;
      }
      case 'f': {
        elements->f = 1;
        if (elements->incr_f != 0 || elements->incr_e != 0) {
          int g = strlen(pattern);
          pattern[g] = '|';
        }
        get_pattern_file(optarg, pattern, &b, elements);
        elements->incr_f++;
        break;
      }
      case 'i': {
        elements->i = 1;
        break;
      }
      case 'v': {
        elements->v = 1;
        break;
      }
      case 'c': {
        elements->c = 1;
        elements->start = 1;
        break;
      }
      case 'l': {
        elements->l = 1;
        elements->start = 1;
        break;
      }
      case 'n': {
        elements->n = 1;
        elements->start = 1;
        break;
      }
      case 'h': {
        elements->h = 1;
        break;
      }
      case 's': {
        elements->s = 1;
        break;
      }
      case 'o': {
        elements->o = 1;
        elements->start = 1;
        break;
      }

      default: {
        if (NULL == optarg) {
          if (elements->s != 1) {
            fprintf(stderr, "no valid argument\n");
          }
          exit(0);
        }
        break;
      }
    }
  }
  check_file_flags(argc, argv, elements, name_file, pattern);
}

void check_file_flags(int argc, char *argv[], grep_flags *elements,
                      char *name_file[], char *pattern) {
  if (elements->e == 1 || elements->f == 1) {
    int o = optind;
    while (o < argc && argv[o][0] != '-') {
      name_file[elements->out] =
          (char *)malloc((strlen(argv[o]) + 1) * sizeof(char));
      strcpy(name_file[elements->out], argv[o]);
      int i = 0;
      i = strlen(name_file[elements->out]);
      name_file[elements->out][i] = '\0';
      elements->out++;
      o++;
    }
  }

  if (elements->e != 1 && elements->f != 1) {
    int o = optind + 1;
    while (o < argc && argv[o][0] != '-') {
      name_file[elements->out] =
          (char *)malloc((strlen(argv[o]) + 1) * sizeof(char));
      strcpy(name_file[elements->out], argv[o]);
      int i = 0;
      i = strlen(name_file[elements->out]);
      name_file[elements->out][i] = '\0';
      elements->out++;
      o++;
    }
    get_pattern_all(argv, elements, pattern, optind);
  }
  read_file(elements, name_file, pattern);
}

void get_pattern_e(grep_flags *elements, char *pattern, char *optarg, int *a) {
  strcat(pattern, optarg);
  *a = strlen(pattern);
  if (pattern[*a] == '\0' && elements->incr_e > 0) {
    pattern[*a] = '|';
  }
}

void get_pattern_file(char *optarg, char *pattern, int *b,
                      grep_flags *elements) {
  FILE *file_pattern = fopen(optarg, "rb");
  if (file_pattern == NULL) {
    if (elements->s != 1) {
      fprintf(stderr, "No such file or directory-%s\n", optarg);
    }
    exit(0);
  } else {
    char buff[10000] = {0};
    while (fgets(buff, 10000, file_pattern) != NULL) {
      strcat(pattern, buff);
      *b = strlen(pattern);
      if (pattern[(*b) - 1] == '\n') {
        pattern[(*b) - 1] = '|';
      }
    }
  }
  fclose(file_pattern);
}

void get_pattern_all(char *argv[], grep_flags *elements, char *pattern,
                     int optind) {
  if (elements->e != 1 && elements->f != 1) {
    strcpy(pattern, argv[optind]);
    int y = 0;
    y = strlen(pattern);
    pattern[y] = '\0';
    elements->incr++;
  }
}

void read_file(grep_flags *elements, char *name_file[], char *pattern) {
  for (int i = 0; i < elements->out; i++) {
    FILE *grep_text = fopen(name_file[i], "rb");
    if (grep_text == NULL) {
      if (elements->s != 1) {
        fprintf(stderr, "No such file or directory-%s\n", name_file[i]);
      }
    } else {
      elements->flag = 0;
      elements->count = 1;  // номер строки
      elements->check = 0;  // количество строк
      char buff[10000] = {0};
      while (fgets(buff, 10000, grep_text) != NULL) {
        elements->next = 0;
        pcre_func(buff, elements, pattern, name_file, i);
        elements->count++;  // номер строки
      }
      if (elements->c == 1) {
        if (elements->out > 1 && elements->l != 1 && elements->h != 1) {
          printf("%s:%d\n", name_file[i], elements->check);
        } else if (elements->l != 1) {
          printf("%d\n", elements->check);
        } else if (elements->out > 1 && elements->l == 1 && elements->h != 1) {
          printf("%s:%d\n", name_file[i], elements->flag);
        } else if (elements->l != 1) {
          printf("%d\n", elements->flag);
        } else {
          printf("%d\n", elements->flag);
        }
      }
      if (elements->l == 1 && elements->flag == 1) {
        printf("%s\n", name_file[i]);
        elements->flag = 0;
      }
      fclose(grep_text);
    }
    free(name_file[i]);
  }
}

void pcre_func(char *buff, grep_flags *elements, char *pattern,
               char *name_file[], int i) {
  pcre *temp = NULL;
  pcre_extra *f_ext = NULL;
  const char *errstr = NULL;
  int errchar = 0, pairs = 0, pairs_o = 0;
  int vector[5000] = {0};
  int vecsize = 5000;
  if (elements->i == 1) {
    temp = pcre_compile(pattern, PCRE_CASELESS | PCRE_MULTILINE, &errstr,
                        &errchar, NULL);
  } else if (elements->i != 1) {
    temp = pcre_compile(pattern, 0 | PCRE_MULTILINE, &errstr, &errchar, NULL);
  }
  if (temp == NULL) {
    if (elements->s != 1) {
      printf("%s", errstr);
    }
  } else {
    pairs = pcre_exec(temp, f_ext, buff, strlen(buff), 0, PCRE_NOTEMPTY, vector,
                      vecsize);
    if (pairs > 0 && elements->v != 1) {
      if (elements->start != 1) {
        if (elements->out > 1 && elements->h != 1) {
          printf("%s:%s", name_file[i], buff);
        } else {
          printf("%s", buff);
        }
        check_enter(buff);
      }
      if (elements->c != 1 && elements->l != 1) {
        func_no_lc(pairs_o, temp, f_ext, buff, vector, vecsize, errstr,
                   elements, name_file, i);
      }
      if (elements->l == 1 && elements->flag != 1) {
        elements->flag = 1;
      }
      if (elements->c == 1) {
        elements->check++;
      }
    } else if (pairs < 0 && elements->v == 1) {
      if (elements->start != 1) {
        if (elements->out > 1 && elements->h != 1) {
          printf("%s:%s", name_file[i], buff);
        } else {
          printf("%s", buff);
        }
        check_enter(buff);
      }
      if (elements->c != 1 && elements->l != 1) {
        func_no_lc(pairs_o, temp, f_ext, buff, vector, vecsize, errstr,
                   elements, name_file, i);
      }
      if (elements->l == 1 && elements->flag != 1) {
        elements->flag = 1;
      }
      if (elements->c == 1) {
        elements->check++;
      }
    }
  }
  pcre_free(temp);
}

void func_no_lc(int pairs_o, pcre *temp, pcre_extra *f_ext, char *buff,
                int *vector, int vecsize, const char *errstr,
                grep_flags *elements, char *name_file[], int i) {
  if (elements->n == 1 && elements->o == 1 && elements->v == 1) {
    if (elements->out > 1 && elements->h != 1) {
      printf("%s:%d:%s", name_file[i], elements->count, buff);
    } else {
      printf("%d:%s", elements->count, buff);
    }
    check_enter(buff);
  }

  if (elements->o == 1 && elements->v != 1) {
    flag_o(pairs_o, temp, f_ext, buff, vector, vecsize, errstr, elements,
           name_file, i);
  }

  if (elements->o == 1 && elements->v == 1 && elements->n != 1) {
    if (elements->out > 1 && elements->h != 1) {
      printf("%s:%s", name_file[i], buff);
    } else {
      printf("%s", buff);
    }
    check_enter(buff);
  }

  if (elements->n == 1 && elements->o != 1) {
    if (elements->out > 1 && elements->h != 1) {
      printf("%s:%d:%s", name_file[i], elements->count, buff);
    } else {
      printf("%d:%s", elements->count, buff);
    }
    check_enter(buff);
  }
}

void flag_o(int pairs_o, pcre *temp, pcre_extra *f_ext, char *buff, int *vector,
            int vecsize, const char *errstr, grep_flags *elements,
            char *name_file[], int i) {
  int j = 0;
  const char *buff2 = {0}; /* буфер для функции pcre_get_substring */

  while ((pairs_o = pcre_exec(temp, f_ext, buff, strlen(buff), j, PCRE_NOTEMPTY,
                              vector, vecsize)) >= 0) {
    if ((pcre_get_substring(buff, vector, pairs_o, 0, &buff2)) < 0) {
      if (elements->s != 1) {
        printf("%s", errstr);
      }
    } else {
      if (elements->n != 1 && elements->next != 1) {
        if (elements->out > 1 && elements->h != 1) {
          printf("%s:%s\n", name_file[i], buff2);
        } else {
          printf("%s\n", buff2);
        }
        elements->next = 1;
      } else if (elements->n != 1 && elements->next == 1) {
        printf("%s\n", buff2);
      }

      if (elements->n == 1 && elements->next != 1) {
        if (elements->out > 1 && elements->h != 1) {
          printf("%s:%d:%s\n", name_file[i], elements->count, buff2);
        } else {
          printf("%d:%s\n", elements->count, buff2);
        }
        elements->next = 1;
      } else if (elements->n == 1 && elements->next == 1) {
        printf("%s\n", buff2);
      }
      pcre_free_substring(buff2);
      j = vector[0] + 1;
    }
  }
}

void check_enter(char *buff) {
  int a = 0;
  a = strlen(buff);
  if (buff[a] == '\0' && buff[a - 1] != '\n') {
    printf("\n");
  }
}
