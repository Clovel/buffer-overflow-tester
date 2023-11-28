#include "buffer_overflow.h"
#include <string.h>

#define BUFFER_SIZE 64

static char buf[BUFFER_SIZE];

void buffer_overflow(const char const * const * const input) {
  strcpy(buf, input);

  printf("%s", buf);

  return(0);
}
