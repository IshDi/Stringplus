#include <stdlib.h>

#include "s21_string.h"

int trim_position_left(const char *src, const char *trim_chars,
                       int position_left, int len_trim);
int trim_position_right(const char *src, const char *trim_chars,
                        int position_right, int len_trim);

void *s21_trim(const char *src, const char *trim_chars) {
  char *result = s21_NULL;
  if (src && trim_chars && trim_chars[0] != '\0') {
    int len_trim = s21_strlen(trim_chars);
    int len_src = s21_strlen(src);
    int position_left = 0;
    int position_right = len_src;

    while (trim_position_left(src, trim_chars, position_left, len_trim)) {
      position_left++;
    }
    if (position_left != position_right) {
      while (trim_position_right(src, trim_chars, position_right, len_trim)) {
        position_right--;
      }
    }

    int len_res = position_right - position_left;
    result = calloc((len_res + 1), sizeof(char));

    for (int i = 0; i < len_res + 1; i++) {
      result[i] = src[position_left];
      position_left++;
    }
    result[len_res] = '\0';

  } else if (src && !(trim_chars && trim_chars[0] != '\0')) {
    result = s21_trim(src, "\n\t ");
  }
  return result;
}

int trim_position_left(const char *src, const char *trim_chars,
                       int position_left, int len_trim) {
  int trim = 0;
  for (int i = 0; i < len_trim; i++) {
    if (src[position_left] == trim_chars[i]) {
      trim = 1;
    }
  }
  return trim;
}

int trim_position_right(const char *src, const char *trim_chars,
                        int position_right, int len_trim) {
  int trim = 0;
  position_right--;
  for (int i = 0; i < len_trim; i++) {
    if (src[position_right] == trim_chars[i]) {
      trim = 1;
    }
  }
  return trim;
}