#ifndef LIBAD_STRING_H
#define LIBAD_STRING_H

#include "defines.h"

usize ad_strlen(const char* str);
char* ad_strdup(const char* str);
char* ad_strcpy(char* dest, const char* src);
int ad_strcmp(const char* a, const char* b);

typedef struct {
  char* ptr;
  usize len;
  usize cap;
} string;

#define string_new(x)                \
  _Generic((x),                      \
      const char*: string_from_cstr, \
      char*: string_from_cstr,       \
      string: string_dup,            \
      default: string_new_capacity)(x)

string string_new_capacity(usize capacity);
string string_from_cstr(const char* cstr);
string string_dup(string str);

#endif