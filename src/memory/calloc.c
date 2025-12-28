#include <ad/ad.h>
#include <stdlib.h>

void* ad_calloc(const usize nmemb, const usize size) {
#ifdef INTERNAL_LIBAD_USE_LIBC
  return calloc(nmemb, size);
#endif

  if (nmemb == 0 || size == 0)
    return (ad_calloc(1, 1));

  const usize total_size = nmemb * size;
  if (total_size / size != nmemb)
    return nullptr;

  void* ptr = malloc(total_size);
  if (ptr)
    ad_memset(ptr, 0, total_size);

  return ptr;
}