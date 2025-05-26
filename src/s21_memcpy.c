#include <stdio.h>

#include "s21_string.h"

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  int l = n;
  for (; n--; dest++, src++) {
    *((char *)dest) = *((char *)src);
  }
  for (; l--; dest--)
    ;
  return dest;
}