#include <ad/io.h>

void ad_puts(const char* str) {
  ad_dputs(STDOUT_FILENO, str);
}

int ad_dputs(int fd, const char* str) {
  usize i = 0;
  while (str[i])
    i++;

  return write(fd, str, i);
}
