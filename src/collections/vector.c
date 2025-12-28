#include <ad/collections.h>
#include <ad/memory.h>

void* ad_vector_new(const usize elem_size, const usize capacity) {
  vector_header* hdr = malloc(sizeof(vector_header) + (elem_size * capacity));
  if (!hdr)
    return nullptr;
  *hdr = (vector_header){.cap = capacity};
  return &hdr->ptr[0];
}

static vector_header* vector_internal_realloc(vector_header* hdr,
                                              const usize elem_size,
                                              const usize new_cap) {
  vector_header* new = malloc(sizeof(vector_header) + (elem_size * new_cap));
  if (!new)
    return nullptr;
  ad_memcpy(new, hdr, sizeof(vector_header) + (elem_size * hdr->len));
  new->cap = new_cap;
  free(hdr);
  return new;
}

bool ad_vector_reserve(void** header, const usize elem_size, const usize additional) {
  if (!header)
    return false;

  if (!*header) {
    *header = ad_vector_new(elem_size, additional < 1 ? 1 : additional);
    return *header != nullptr;
  }

  const auto hdr = _ad_vector_header(*header);
  if (hdr->len + additional <= hdr->cap)
    return true;

  while (hdr->len + additional > hdr->cap)
    hdr->cap += hdr->cap / 2 + 4;

#ifdef INTERNAL_LIBAD_USE_LIBC
  vector_header* new_hdr = realloc(hdr, sizeof(vector_header) + (elem_size * hdr->cap));
#else
  vector_header* new_hdr = vector_internal_realloc(hdr, elem_size, hdr->cap);
#endif
  if (!new_hdr)
    return false;

  *header = &new_hdr->ptr[0];
  return true;
}
