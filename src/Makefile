CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11
LFLAGS = -lcheck
LM_FLAG = 
UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Linux)
	LFLAGS = -lcheck -lm -lpthread -lsubunit
	LM_FLAG = -lm
endif

all: s21_string.a
	
s21_string.a:
	$(CC) $(CFLAGS) -c s21*.c
	ar rc s21_string.a s21*.o
	ranlib s21_string.a

test:
	$(CC) $(CFLAGS) $(LM_FLAG) -c --coverage s21*.c
	ar rc s21_string.a *.o
	ranlib s21_string.a
	$(CC) $(CFLAGS) -c tests/test*.c $(LM_FLAG)
	$(CC) $(CFLAGS) --coverage test*.o s21_string.a -o test $(LFLAGS)
	./test

gcov_report: test
	geninfo *.gcda -o s21_cov.info
	genhtml s21_cov.info -o report
	open report/index.html

clean:
	rm -rf *.o *.a test *.gc*  *.info report

rebuild: clean all