#ifndef __TIME_H__
#define __TIME_H__	1

#ifdef __cplusplus
extern "C" {
#endif

struct timespec {
    long tv_sec;
    long tv_nsec;
};

unsigned int nanosleep(const struct timespec *req, struct timespec *rem);


#ifdef __cplusplus
}
#endif

#endif
