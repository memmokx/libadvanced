#include <ad/string.h>
#include <string.h>

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
