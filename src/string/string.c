#include <ad/ad.h>

string string_new_capacity(const usize capacity) {
  char* ptr = ad_calloc(capacity, sizeof(char));
  if (!ptr)
    return (string){};

  return (string){
      .ptr = ptr,
      .len = 0,
      .cap = capacity,
  };
}

string string_from_cstr(const char* cstr) {
  const usize len = ad_strlen(cstr);
  string str = string_new_capacity(len + 1);
  if (!str.ptr)
    return (string){};

  ad_memcpy(str.ptr, cstr, len + 1);
  str.len = len;
  return str;
}