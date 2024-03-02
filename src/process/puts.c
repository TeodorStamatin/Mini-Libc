#include <stdio.h>
#include <errno.h>
#include <internal/syscall.h>
#include <string.h>

int puts(const char *str) {
    for (size_t i = 0; i < strlen(str); i++) {
        write(1, str + i, 1);
    }
    write(1, "\n", 1);

    return strlen(str);
}
