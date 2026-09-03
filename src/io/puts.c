#include <ad/io.h>

void ad_puts(const char* str) {
  ad_dputs(STDOUT_FILENO, str);
}

void ad_dputs(int fd, const char* str) {
  usize i = 0;
  while (str[i])
    i++;

  (void)write(fd, str, i);
}
