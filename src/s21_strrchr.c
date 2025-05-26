#include "s21_string.h"

char *s21_strrchr(const char *str, int c) {
  char *res = s21_NULL;
  while (*str++) {
    if (*str == (unsigned char)c) {
      res = (char *)str;
    }
  }
  return res;
}