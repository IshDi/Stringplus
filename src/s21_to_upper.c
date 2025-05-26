#include <stdlib.h>

#include "s21_string.h"
void *s21_to_upper(const char *str) {
  char *result = s21_NULL;
  if (str != s21_NULL) {
    int len = s21_strlen(str);
    result = calloc(len + 1, sizeof(char));
    if (result) {
      for (int i = 0; i < len; i++) {
        if (str[i] <= 122 && str[i] >= 97) {
          result[i] = str[i] - 32;
        } else {
          result[i] = str[i];
        }
      }

      result[len] = '\0';
    }
  }
  return result;
}