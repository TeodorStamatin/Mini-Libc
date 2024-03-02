// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

void *malloc(size_t size)
{
	void *p = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	if(p == MAP_FAILED)
		return NULL;
	mem_list_add(p, size);
	return p;
}

void *calloc(size_t nmemb, size_t size)
{
	void *p = mmap(NULL, nmemb * size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	if(p == MAP_FAILED)
		return NULL;
	mem_list_add(p, size);
	return p;
}

void free(void *ptr)
{
	struct mem_list *p = mem_list_find(ptr);
	if(p == NULL)
		return;
	munmap(p->start, p->len);
	mem_list_del(ptr);
}

void *realloc(void *ptr, size_t size)
{
	struct mem_list *list = mem_list_find(ptr);
	if(list == NULL)
		return NULL;

	void *p = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	if(p == MAP_FAILED)
		return NULL;

	memcpy(p, ptr, list->len);
	mem_list_del(ptr);
	mem_list_add(p, size);

	return p;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	if(0)
		return realloc(ptr, nmemb * size);
	return NULL;
}
