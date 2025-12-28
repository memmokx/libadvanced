#include <ad/ad.h>

#ifdef INTERNAL_LIBAD_USE_LIBC
#include <string.h>
#endif

void ad_memset(void* s, const int c, usize n) {
#ifdef INTERNAL_LIBAD_USE_LIBC
  memset(s, c, n);
  return;
#endif
  u8* p = s;
  while (n--)
    *p++ = (u8)c;
}
