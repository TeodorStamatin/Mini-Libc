#include <time.h>
#include <errno.h>
#include <internal/syscall.h>

unsigned int sleep(unsigned int seconds) {
    struct timespec req, rem;
    req.tv_sec = seconds;
    req.tv_nsec = 0;

    int ret = nanosleep(&req, &rem);

    if (ret == 0) {
        return 0;
    } else {
        if (errno == EINTR) {
            return rem.tv_sec;
        } else {
            return -1;
        }
    }
}
