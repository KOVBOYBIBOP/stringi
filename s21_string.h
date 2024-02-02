#ifndef S21_STRING_H
#define S21_STRING_H
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <check.h>
#define s21_NULL ((void *)0)
#define BUFF_SIZE 512
typedef unsigned long s21_size_t;

typedef enum w_t { NONE_WIDTH,
                       WIDTH_NUMBER,
                       WIDTH_SUP } w_t;

typedef enum l_t {
    NONE_LENGTH,
    LENGTH_SHORT,
    LENGTH_LONG,
    LENGTH_LONG_LONG,
    LENGTH_DOUBLE,
    LENGTH_LONG_DOUBLE
} l_t;

typedef struct format {
    void *address;
    w_t width;
    unsigned int width_num;
    l_t length;
    char buff[512];
    char specifier;
    int precision;
    int is_p_set;
} format;

int s21_strlen(const char *str);

void *s21_memchr(const void *str, int c, s21_size_t n);
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);
char *s21_strncat(char *dest, const char *src, s21_size_t n);
char *s21_strchr(char *str, int c);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
s21_size_t s21_strcspn(const char *str1, const char *str2);
char *s21_strerror(int errnum);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strrchr(const char *str, int c);
char *s21_strstr(const char *haystack, const char *needle);
char *s21_strtok(char *str, const char *delim);
char *s21_trim(const char *src, const char *trim_chars);
void *s21_to_upper(char *str);
void *s21_to_lower(char *str);
char *s21_insert(char *src, char *str, size_t start_index);

/* for sprintf*/
int s21_sprintf(char* str, const char* form, ...);
int s21_isdigit(char c);
int s21_atoi(const char* str);
const char* getprecision(const char* form, format* format, va_list lst);
const char* getwidth(const char* form, format* format, va_list ap);

#endif
