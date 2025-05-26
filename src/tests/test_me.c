#include "test_me.h"

int main(void) {
  int failed = 0;
  Suite *s21_string_test[] = {test_memchr(),   test_memcmp(),
                              test_memcpy(),   test_memset(),
                              test_strchr(),   test_strncat(),
                              test_strncmp(),  test_strncpy(),
                              test_strcspn(),  test_strerror(),
                              test_strlen(),   test_strpbrk(),
                              test_strrchr(),  test_strstr(),
                              test_strtok(),   test_sscanf(),
                              test_sprintf(),  test_to_upper(),
                              test_to_lower(), test_insert(),
                              test_trim(),     NULL};

  for (int i = 0; s21_string_test[i] != NULL; i++) {
    SRunner *sr = srunner_create(s21_string_test[i]);

    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);

    failed += srunner_ntests_failed(sr);
    srunner_free(sr);
  }
  printf("========= FAILED: %d =========\n", failed);

  return failed == 0 ? 0 : 1;
}