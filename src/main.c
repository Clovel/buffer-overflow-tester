#include "buffer_overflow.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main(const unsigned int argc, const char const * const * const argv) {
    volatile int modified;

    // if(argc != 1) {
    //     printf("please specify an argument (%d)\n", argc);
    //     exit(1);
    // }

    modified = 0;

    printf("Starting buffer overflow test...\n");
    buffer_overflow(argv[1]);
    printf("Buffer overflow test completed.\n");

    if(modified == 0x61626364) {
        printf("you have correctly got the variable to the right value\n");
    } else {
        printf("Try again, you got 0x%08x\n", modified);
    }

    return 0;
}
