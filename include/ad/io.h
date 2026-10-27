#ifndef LIBAD_IO_H
#define LIBAD_IO_H

#include "defines.h"
#include <unistd.h>

int ad_dputs(int fd, const char *str);
void ad_puts(const char *str);

#endif
