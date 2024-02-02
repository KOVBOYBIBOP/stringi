#include "s21_string.h"

int s21_sprintf(char* str, const char* form, ...) {
  format format = {0};
  va_list ap;
  va_start(ap, form);
  char* str_start = str;
}

const char* getwidth(const char* form, format* format, va_list ap) {
  if (*form == '*') {
    form++;
    format->width = va_arg(ap, int);
  } else if (s21_isdigit(*form)) {
    char tmp[BUFF_SIZE] = {'\0'};
    for (int i = 0; s21_isdigit(*form); i++, form++) {
      tmp[i] = *form;
    }
    format->width = s21_atoi(tmp);
  }
  return form;
}


int s21_isdigit(char c) { return (c >= '0' && c <= '9'); }

int s21_atoi(const char* str) {
  int res = 0;
  int sign = 1;
  int over = 0;

  while (*str == ' ') str++;

  switch (*str) {
    case '-':
      sign = -1;
      str++;
      break;
    case '+':
      str++;
  }

  while (*str && '0' <= *str && *str <= '9') {
    res = res * 10 + (*str - '0');

    if (res < 0) {
      over = 1;
      break;
    }
    str++;
  }

  if (over)
    res = -1;
  else
    res *= sign;

  return res;
}

const char* getprecision(const char* form, format* format, va_list ap) {
  if (*form == '.') {
    format->is_p_set = 1;
    form++;
  }
  if (*form == '*') {
    form++;
    format->precision = va_arg(ap, int);
  }
  if (s21_isdigit(*form)) {
    char tmp[BUFF_SIZE] = {'\0'};
    for (int i = 0; s21_isdigit(*form); i++, form++) tmp[i] = *form;
    format->precision = s21_atoi(tmp);
  }
  return form;
}
