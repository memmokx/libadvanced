#include <ad/ad.h>

#ifdef INTERNAL_LIBAD_USE_LIBC
#include <string.h>
#endif

usize ad_strlen(const char* str) {
#ifdef INTERNAL_LIBAD_USE_LIBC
  return strlen(str);
#endif
  usize i = 0;
  while (str[i])
    i++;
  return i;
}
