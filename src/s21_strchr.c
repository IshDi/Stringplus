#include "s21_string.h"

char *s21_strchr(const char *str, int c) {
  char *res = s21_NULL;
  do {
    if (*str == (unsigned char)c) {
      res = (char *)str;
    }
  } while (*str && *str++ != (unsigned char)c);
  return res;
}