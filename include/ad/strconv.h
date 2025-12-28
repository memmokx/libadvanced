#ifndef LIBAD_STRCONV_H
#define LIBAD_STRCONV_H

#include "defines.h"
#include "string.h"

#define ad_atoi(x) \
  _Generic((x), const char*: ad_atoic, char*: ad_atoic, string: ad_atois)(x)

i32 ad_atoic(const char* str);
i32 ad_atois(string str);

#endif