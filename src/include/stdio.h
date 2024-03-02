/* SPDX-License-Identifier: BSD-3-Clause */

#ifndef __STDIO_H__
#define __STDIO_H__	1

#ifdef __cplusplus
extern "C" {
#endif
#include <stddef.h>
/* TODO: Add puts() declaration. */
int puts(const char *str);
ssize_t write(int fd, const void *buf, size_t count);

#ifdef __cplusplus
}
#endif

#endif
