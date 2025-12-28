#include <ad/ad.h>

#ifdef INTERNAL_LIBAD_USE_LIBC
#include <string.h>
#endif

char* ad_strdup(const char* str) {
#ifdef INTERNAL_LIBAD_USE_LIBC
  return strdup(str);
#endif
  const usize n = ad_strlen(str) + 1;
  char* dup = ad_calloc(n, sizeof(char));
  if (!dup)
    return nullptr;

  ad_memcpy(dup, str, n);
  return dup;
}