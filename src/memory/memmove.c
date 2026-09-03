#include <ad/ad.h>

#ifdef INTERNAL_LIBAD_USE_LIBC
#include <string.h>
#endif

void* ad_memmove(void* dst, const void* src, usize n) {
#ifdef INTERNAL_LIBAD_USE_LIBC
  return memmove(dst, src, n);
#endif
  const u8* s = (u8*)src;
  u8* d = dst;

  if (src < dst) {
    for (i64 i = (i64)n - 1; i >= 0; i--)
      d[i] = s[i];
    return dst;
  }

  return ad_memcpy(dst, src, n);
}
