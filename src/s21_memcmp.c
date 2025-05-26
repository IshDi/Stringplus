#include "s21_string.h"

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  const char *s1 = str1, *s2 = str2;
  int res;

  for (; n-- && *s1 == *s2; s1++, s2++)
    ;
  n++;
  if (n == 0) {
    res = 0;
  } else if (*s1 > *s2) {
    res = 1;
  } else {
    res = -1;
  }

  return res;
}