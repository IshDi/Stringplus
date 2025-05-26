#include "s21_string.h"

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  int res = 0;
  for (; n-- && *str1 == *str2; str1++, str2++)
    ;
  n++;
  if (n) {
    res = *str1 - *str2;
  }
  return res;
}