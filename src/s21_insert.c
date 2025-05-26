#include <stdlib.h>

#include "s21_string.h"

void *input_char(char *result, const char *str, const char *src, int total_len,
                 s21_size_t start_index, int len_str);

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  char *result = s21_NULL;
  if (src && str && (int)start_index >= 0) {
    int len_src = s21_strlen(src);
    int len_str = s21_strlen(str);
    int total_len = len_src + len_str + 1;
    if ((int)start_index <= len_src) {
      result = calloc(total_len, sizeof(char));
      if (result) {
        result = input_char(result, str, src, total_len, start_index, len_str);
      }
    }
  }
  return result;
}

void *input_char(char *result, const char *str, const char *src, int total_len,
                 s21_size_t start_index, int len_str) {
  int j = 0;
  int n = start_index;
  for (int i = 0; i < total_len; i++) {
    result[i] = src[i];
    if (i >= (int)start_index && j < len_str) {
      result[i] = str[j];
      j++;
    }
    if (i >= (int)start_index + len_str && i < total_len) {
      result[i] = src[n];
      n++;
    }
  }
  result[total_len] = '\0';
  return result;
}
