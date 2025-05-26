#include "s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
  s21_size_t i = 0;
  int flag = 1;
  char *res = s21_NULL;
  for (i = 0; flag && i < s21_strlen(str1); i++) {
    if (s21_strchr(str2, str1[i])) {
      flag = 0;
      res = (char *)str1 + i;
    }
  }
  return res;
}