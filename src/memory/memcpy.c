#include <ad/ad.h>

#ifdef INTERNAL_LIBAD_USE_LIBC
#include <string.h>
#endif

void* ad_memcpy(void* dst, const void* src, usize n) {
#ifdef INTERNAL_LIBAD_USE_LIBC
  return memcpy(dst, src, n);
#endif
  const u8* s = src;
  u8* d = dst;

  while (n--)
    *d++ = *s++;

  return dst;
}
