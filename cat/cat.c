#include "cat.h"

int main(int argc, char *argv[]) {
  cat_flags elements = {0};
  int i = 0;
  if (argc < 2) {
    printf("illegal option");
  } else {
    parsing(argc, argv, &elements, &i);
  }

  return 0;
}

void parsing(int argc, char *argv[], cat_flags *elements, int *i) {
  elements->check = 2;
  for (*i = 1; *i < argc; (*i)++) {
    if (elements->check == 0) {
      printf("cat: illegal option -- %c", elements->sym);
      printf("\nusage: cat [-benstuv] [file ...]");
      break;
    } else if (argv[*i][0] == '-' && argv[*i][1] != '-' &&
               elements->check != 0 && elements->check != 3) {
      if (pars_argv(argv, elements, i) == 0) {
        elements->check = 0;
      } else {
        elements->check = 1;
      }
    } else if (argv[*i][0] == '-' && argv[*i][1] == '-' &&
               elements->check != 0 && elements->check != 3) {
      if (flags_GNU(argv, elements, i) == 0) {
        elements->check = 0;
      } else {
        elements->check = 1;
      }
    } else if (argv[*i][0] != '-' && argv[*i][1] != '-' &&
               elements->check != 0) {
      elements->check = 2;
      read_file(argv, elements, i);
      elements->incr = 3;
    }
    if (argv[*i][0] == '-' && elements->incr == 3) {
      read_file(argv, elements, i);
    }
  }
}

int pars_argv(char *argv[], cat_flags *elements, int *i) {
  int j = 0;
  char c = '\0';
  for (j = 1; argv[*i][j] != '\0' && elements->check != 0; j++) {
    c = argv[*i][j];
    get_flags(c, elements);
  }
  return elements->check;
}

int get_flags(char c, cat_flags *elements) {
  elements->check = 0;

  if (c == 'b') {
    elements->b = 1;
    elements->check = 1;
  }
  if (c == 'e') {
    elements->v = 1;
    elements->e = 1;
    elements->check = 1;
  }
  if (c == 'E') {
    elements->e = 1;
    elements->check = 1;
  }
  if (c == 'n') {
    elements->n = 1;
    elements->check = 1;
  }
  if (c == 's') {
    elements->s = 1;
    elements->check = 1;
  }
  if (c == 'T') {
    elements->T = 1;
    elements->check = 1;
  }
  if (c == 't') {
    elements->t = 1;
    elements->check = 1;
  }
  if (c == 'v') {
    elements->v = 1;
    elements->check = 1;
  }

  elements->sym = c;

  return elements->check;
}

void read_file(char *argv[], cat_flags *elements, int *i) {
  FILE *cat_text = fopen(argv[*i], "rb");
  if (cat_text == NULL) {
    fprintf(stderr, "No such file or directory\n");
  } else {
    int count_1 = 1;
    int count_2 = 1;
    int k = 0;
    char ch = '\0';
    if (elements->check == 2) {
      for (ch = getc(cat_text); !feof(cat_text); ch = getc(cat_text)) {
        if (elements->s == 1) {
          flag_s(&ch, elements, &k);
          if (ch == '\n' && k > 2) {
            k--;
            continue;
          }
        }
        if (elements->b == 1) {
          elements->n = 0;
          flag_b(&ch, &count_1, &count_2);
        }
        if (elements->n == 1) {
          flag_n(&ch, &count_1, &count_2);
        }
        if (elements->t == 1) {
          elements->v = 1;
          flag_t(&ch);
        }
        if (elements->e == 1) {
          flag_e(&ch);
        }
        if (elements->v == 1) {
          flag_v(&ch);
        }
        if (elements->T == 1) {
          flag_t(&ch);
        }
        putchar(ch);
      }
    }

    if (ch != '\n') {
      ch = EOF;
    } else {
      ch = '\n';
    }
    fclose(cat_text);
  }
}

void flag_s(char *ch, cat_flags *elements, int *k) {
  if (elements->s == 1) {
    if (*ch == '\n') {
      (*k)++;
    }
    if (*ch != '\n') {
      *k = 0;
    }
  }
}

void flag_b(char *ch, int *count_1, int *count_2) {
  if (*ch != '\n') {
    if (*count_1 == 1) {
      printf("%6d\t", (*count_2)++);
      (*count_1)++;
    }
  } else {
    *ch = '\n';
    *count_1 = 1;
  }
}

void flag_n(char *ch, int *count_1, int *count_2) {
  if (*count_1 == 1) {
    printf("%6d\t", (*count_2)++);
    (*count_1)++;
  }
  if (*ch == '\n') {
    *count_1 = 1;
  }
}

void flag_t(char *ch) {
  if (*ch == '\t') {
    putchar('^');
    *ch = 'I';
  }
}

void flag_e(char *ch) {
  if (*ch == '\n') {
    printf("$");
  }
  if (*ch == '\0') {
    printf("$");
  }
}

void flag_v(char *ch) {
  if (*ch <= 31 && *ch != 10 && *ch != 9) {
    putchar('^');
    *ch += 64;
  } else if (*ch == 127) {
    putchar('^');
    *ch -= 64;
  }
}

int flags_GNU(char *argv[], cat_flags *elements, int *i) {
  elements->check = 0;
  if (strcmp(argv[*i], "--number-nonblank") == 0) {
    elements->check = 1;
    elements->b = 1;
  }
  if (strcmp(argv[*i], "--number") == 0) {
    elements->check = 1;
    elements->n = 1;
  }
  if (strcmp(argv[*i], "--squeeze-blank") == 0) {
    elements->check = 1;
    elements->s = 1;
  }

  return elements->check;
}
