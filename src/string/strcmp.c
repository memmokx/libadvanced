#include <ad/string.h>

#ifdef INTERNAL_LIBAD_USE_LIBC
#include <string.h>
#endif

int ad_strcmp(const char* a, const char* b) {
#ifdef INTERNAL_LIBAD_USE_LIBC
  return strcmp(a, b);
#endif

  while (*a && (*a == *b)) {
    a++;
    b++;
  }
  return *(const u8*)a - *(const u8*)b;
}
