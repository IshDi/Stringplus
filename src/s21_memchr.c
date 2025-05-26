#include "s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  const unsigned char *p = str;
  int flag = 1;

  for (; n-- && flag; p++) {
    if (*p == (unsigned char)c) {
      flag = 0;
      p--;
    }
  }
  if (flag) {
    p = s21_NULL;
  }
  return (void *)p;
}