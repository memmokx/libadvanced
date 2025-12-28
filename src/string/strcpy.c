#include <ad/ad.h>

#ifdef INTERNAL_LIBAD_USE_LIBC
#include <string.h>
#endif

char* ad_strcpy(char* dest, const char* src) {
#ifdef INTERNAL_LIBAD_USE_LIBC
  strcpy(dest, src);
  return;
#endif
  void* d = dest;
  while (*src)
    *dest++ = *src++;
  return d;
}