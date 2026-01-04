#include <ad/string.h>
#include <string.h>

int ad_strncmp(const char* a, const char* b, usize n) {
#ifdef INTERNAL_LIBAD_USE_LIBC
  return strncmp(a, b, n);
#endif

  i64 nn = (i64)n;
  while (nn-- && *a && *b && *a == *b) {
    a++;
    b++;
  }

  if (nn == -1)
    return 0;

  return *(const u8*)a - *(const u8*)b;
}
