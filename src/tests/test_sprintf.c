#include "test_me.h"

START_TEST(sprintf_1) {
  char str1[100];
  char str2[100];
  char *str3 = "Integer: %d, Positive Integer: %+d, DispInteger: %5d";
  int a = -42;
  int b = 42;
  int c = 7;

  ck_assert_int_eq(sprintf(str1, str3, a, b, c),
                   s21_sprintf(str2, str3, a, b, c));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_2) {
  char str1[100];
  char str2[100];
  char *str3 = "Float: %+f";
  float f = 3.14;

  ck_assert_int_eq(sprintf(str1, str3, f), s21_sprintf(str2, str3, f));
  ck_assert_pstr_eq(str1, str2);
}

START_TEST(sprintf_3) {
  char str1[100];
  char str2[100];
  char *str3 = "String: %s, Limited Precision String: %.3s";
  char *s1 = "Hello, World";
  char *s2 = "Proverka";
  ck_assert_int_eq(sprintf(str1, str3, s1, s2),
                   s21_sprintf(str2, str3, s1, s2));
  ck_assert_pstr_eq(str1, str2);
}

START_TEST(sprintf_4) {
  char str1[100];
  char str2[100];
  char *str3 = "Multiple Specifiers: %d, %.2f, %s";
  int a = 42;
  float b = 3.14;
  char *c = "testing";
  ck_assert_int_eq(sprintf(str1, str3, a, b, c),
                   s21_sprintf(str2, str3, a, b, c));
  ck_assert_pstr_eq(str1, str2);
}

START_TEST(sprintf_5) {
  char str1[100];
  char str2[100];
  char *str3 = "Width and Precision: %10.3f, %-10s";
  float a = 1234.456789;
  char *b = "Disp";

  ck_assert_int_eq(sprintf(str1, str3, a, b), s21_sprintf(str2, str3, a, b));
  ck_assert_pstr_eq(str1, str2);
}

START_TEST(sprintf_6) {
  char str1[100];
  char str2[100];
  char *str3 = "long %ld";
  long a = 11234567890123456;

  ck_assert_int_eq(sprintf(str1, str3, a), s21_sprintf(str2, str3, a));
  ck_assert_pstr_eq(str1, str2);
}

START_TEST(sprintf_7) {
  char str1[100];
  char str2[100];
  char *str3 = "unsigned long %lu";
  unsigned long a = 4294967295;

  ck_assert_int_eq(sprintf(str1, str3, a), s21_sprintf(str2, str3, a));
  ck_assert_pstr_eq(str1, str2);
}

START_TEST(sprintf_8) {
  char str1[100];
  char str2[100];
  char *str3 = "unsigned short %hu";
  unsigned short a = 65535;

  ck_assert_int_eq(sprintf(str1, str3, a), s21_sprintf(str2, str3, a));
  ck_assert_pstr_eq(str1, str2);
}

START_TEST(sprintf_9) {
  char str1[100];
  char str2[100];
  char *str3 = "short %hd";
  short a = -32678;

  ck_assert_int_eq(sprintf(str1, str3, a), s21_sprintf(str2, str3, a));
  ck_assert_pstr_eq(str1, str2);
}

START_TEST(sprintf_10) {
  char str1[100];
  char str2[100];
  char *str3 = "double %.2lf";
  long double a = 3.14159265358979323846264338327950288;

  ck_assert_int_eq(sprintf(str1, str3, a), s21_sprintf(str2, str3, a));
  ck_assert_pstr_eq(str1, str2);
}

START_TEST(sprintf_11) {
  char str1[100];
  char str2[100];
  char *str3 = "Formatted string: %d, %+f, %s";
  int a = 42;
  double b = 3.14;
  char *c = "Hello";
  ck_assert_int_eq(sprintf(str1, str3, a, b, c),
                   s21_sprintf(str2, str3, a, b, c));
  ck_assert_pstr_eq(str1, str2);
}

START_TEST(sprintf_12) {
  char str1[100];
  char str2[100];
  char *str3 = "System: %+.2f %%";
  double a = 365289.3462865487;
  ck_assert_int_eq(sprintf(str1, str3, a), s21_sprintf(str2, str3, a));
  ck_assert_pstr_eq(str1, str2);
}

START_TEST(sprintf_13) {
  char str1[100];
  char str2[100];
  char str3[] = "%%Test Test";
  ck_assert_int_eq(sprintf(str1, str3, NULL), s21_sprintf(str2, str3));
  ck_assert_pstr_eq(str1, str2);
}

START_TEST(sprintf_14) {
  char str1[100];
  char str2[100];
  char str3[] = "Test char '%c' = %d";
  char a = 'a';
  ck_assert_int_eq(sprintf(str1, str3, a, a), s21_sprintf(str2, str3, a, a));
  ck_assert_pstr_eq(str1, str2);
}

START_TEST(sprintf_15) {
  char str1[100];
  char str2[100];
  char str3[] = "2 char: %-c %c";
  char a = 'H';
  char b = 'i';
  ck_assert_int_eq(sprintf(str1, str3, a, b), s21_sprintf(str2, str3, a, b));
  ck_assert_pstr_eq(str1, str2);
}

START_TEST(sprintf_16) {
  char str1[100];
  char str2[100];
  char str3[] = "%+.2f % f";
  float a = 341.4512;
  float b = 1.32;
  ck_assert_int_eq(sprintf(str1, str3, a, b), s21_sprintf(str2, str3, a, b));
  ck_assert_pstr_eq(str1, str2);
}

START_TEST(sprintf_17) {
  char str1[100];
  char str2[100];
  char str3[] = "negative double: %.3lf";
  double a = -341.6512;
  ck_assert_int_eq(sprintf(str1, str3, a), s21_sprintf(str2, str3, a));
  ck_assert_pstr_eq(str1, str2);
}

START_TEST(sprintf_18) {
  char str1[100];
  char str2[100];
  char str3[] = "test: %+lf";
  double a = 34.97;
  ck_assert_int_eq(sprintf(str1, str3, a), s21_sprintf(str2, str3, a));
  ck_assert_pstr_eq(str1, str2);
}

Suite *test_sprintf(void) {
  Suite *s = suite_create("\033[45m-=S21_SPRINTF=-\033[0m");
  TCase *tc = tcase_create("sprintf_tc");

  tcase_add_test(tc, sprintf_1);
  tcase_add_test(tc, sprintf_2);
  tcase_add_test(tc, sprintf_3);
  tcase_add_test(tc, sprintf_4);
  tcase_add_test(tc, sprintf_5);
  tcase_add_test(tc, sprintf_6);
  tcase_add_test(tc, sprintf_7);
  tcase_add_test(tc, sprintf_8);
  tcase_add_test(tc, sprintf_9);
  tcase_add_test(tc, sprintf_10);
  tcase_add_test(tc, sprintf_11);
  tcase_add_test(tc, sprintf_12);
  tcase_add_test(tc, sprintf_13);
  tcase_add_test(tc, sprintf_14);
  tcase_add_test(tc, sprintf_15);
  tcase_add_test(tc, sprintf_16);
  tcase_add_test(tc, sprintf_17);
  tcase_add_test(tc, sprintf_18);
  suite_add_tcase(s, tc);
  return s;
}
