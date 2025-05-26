#include <stdio.h>

#include "s21_string.h"

char *s21_strtok(char *str, const char *delim) {
  static char *next = s21_NULL;
  if (str == s21_NULL && next == s21_NULL) {
    return str;
  }
  if (str == s21_NULL) {
    str = next;
  }

  int i = 0;
  int ok = 1;
  while (s21_strchr(delim, i) && ok) {
    i = *str++;
    if (i == '\0') {
      ok = 0;
    }
  }
  --str;
  if (ok) {
    next = str + s21_strcspn(str, delim);
    if (*next != '\0') {
      *next++ = '\0';
    }
  } else {
    str = s21_NULL;
  }
  return str;
}