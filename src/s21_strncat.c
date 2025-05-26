#include "s21_string.h"

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  char *p = dest;
  for (; *p; p++)
    ;
  for (; n--; p++, src++) {
    *p = *src;
  }
  return dest;
}