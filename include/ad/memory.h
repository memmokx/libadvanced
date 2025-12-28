#ifndef LIBAD_MEMORY_H
#define LIBAD_MEMORY_H

#include "defines.h"

void* ad_memcpy(void* dest, const void* src, usize n);
void* ad_memmove(void* dest, const void* src, usize n);
void ad_memset(void* s, int c, usize n);

void* ad_calloc(usize nmemb, usize size);

#endif