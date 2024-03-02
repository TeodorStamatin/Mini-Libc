#include <time.h>
#include <errno.h>
#include <internal/syscall.h>

unsigned int nanosleep(const struct timespec *req, struct timespec *rem) {
    int ret = syscall(__NR_nanosleep, req, rem);

    if  (ret < 0)
    {
        errno = -ret;
        return -1;
    }

    return ret;
}
