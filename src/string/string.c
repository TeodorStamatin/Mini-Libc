// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source)
{
	char *d;

	for (d = destination; *source != '\0'; source++, d++)
		*d = *source;
	*d = '\0';
	*d = *source;
	return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	char *d;
	size_t n = 0;

	for (d = destination; *source != '\0' && n < len; n++, source++, d++)
		*d = *source;
	*d = '\0';
	*d = *source;

	return destination;
}

char *strcat(char *destination, const char *source)
{
	char *d;

    for (d = destination; *d != '\0'; d++) { }

    for (; *source != '\0'; source++, d++) {
        *d = *source;
    }
    *d = '\0';

	return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	char *d;
	size_t n = 0;

    for (d = destination; *d != '\0'; d++) { }

    for (; *source != '\0' && n < len; n++, source++, d++) {
        *d = *source;
    }
    *d = '\0';

	return destination;
}

int strcmp(const char *str1, const char *str2)
{
	const char *s1 = str1;
	const char *s2 = str2;

	while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2) {
        s1++;
        s2++;
    }

    if (*s1 < *s2)
        return -1;
    else if (*s1 > *s2)
        return 1;

    return 0;
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	const char *s1 = str1;
	const char *s2 = str2;
	size_t n = 0;

	while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2 && n < len) {
        s1++;
        s2++;
		n++;
    }

	if(n == len)
		return 0;

    if (*s1 < *s2)
        return -1;
    else if (*s1 > *s2)
        return 1;

    return 0;
}

size_t strlen(const char *str)
{
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c)
{
	char *s = (char *)str;
	char *first = NULL;

	while (*s != '\0') {
		if (*s == c) {
			first = s;
			break;
		}
		s++;
	}

	return first;
}

char *strrchr(const char *str, int c)
{
	char *s = (char *)str;
	char *last = NULL;

	while (*s != '\0') {
		if (*s == c)
			last = s;
		s++;
	}

	return last;
}

char *strstr(const char *haystack, const char *needle)
{
	char *s = (char *)haystack;
	char *n = (char *)needle;
	char *first = NULL;

	while (*s != '\0') {
		if (*s == *n) {
			first = s;
			while(*s == *n && *s != '\0' && *n != '\0') {
				s++;
				n++;
			}
			if (*n == '\0')
				return first;
		}
		s++;
	}

	return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
	char *s = (char *)haystack;
	char *n = (char *)needle;
	char *last = NULL;
	char *aux1 = NULL;
	char *aux2 = NULL;

	while (*s != '\0') {
		if (*s == *n) {
			aux1 = s;
			aux2 = n;

			while(*aux1 == *aux2 && *aux1 != '\0' && *aux2 != '\0') {
				aux1++;
				aux2++;
			}
			if (*aux2 == '\0')
				last = s;
		}
		s++;
	}

	return last;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	char *csrc = (char *)source;
	char *cdest = (char *)destination;

	for (size_t i = 0; i < num; i++)
		cdest[i] = csrc[i];
	return destination;

	// source : https://www.geeksforgeeks.org/write-memcpy/
}

void *memmove(void *destination, const void *source, size_t num)
{
	char *csrc = (char *)source;
	char *cdest = (char *)destination;

	for (size_t i = 0; i < num; i++)
		cdest[i] = csrc[i];
	return destination;

	// source : https://www.geeksforgeeks.org/write-memcpy/
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	char *p = (char *)ptr1;
	char *q = (char *)ptr2;
	int charCompareStatus = 0;

	if(q == p)
		return charCompareStatus;

	while(num > 0) {
		if(*p != *q) {
			charCompareStatus = (*p > *q) ? 1 : -1;
			break;
		}
		p++;
		q++;
		num--;
	}
	return charCompareStatus;

	// source: https://aticleworld.com/memcmp-in-c/
}

void *memset(void *source, int value, size_t num)
{
	char *p = source;
	while(num--) {
		*p++ = (char)value;
	}
	return source;

	// source: https://aticleworld.com/memcmp-in-c/
}
