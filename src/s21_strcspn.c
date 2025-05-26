#include "s21_string.h"

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  int res = 0;
  int flag = 1;
  for (int i = 0; i < (int)s21_strlen(str1) && flag; i++) {
    for (int j = 0; j < (int)s21_strlen(str2) && flag; j++) {
      if (str1[i] == str2[j]) {
        res = i;
        flag = 0;
      }
    }
  }
  if (flag) {
    res = s21_strlen(str1);
  }
  return (s21_size_t)res;
}