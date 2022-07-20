#ifndef MEMORY_H
#define MEMORY_H

#include <stdlib.h>
#include <unistd.h>

#include "list.h"

typedef struct s_malloc t_malloc;
typedef struct s_test t_test;
typedef struct s_memory t_memory;

struct s_malloc
{
    t_malloc *prev;
    t_malloc *next;
    size_t size;
    void *ptr;
};

struct s_memory
{
    int         (*free_all)(void);
    t_malloc    **(*mallocs)(void);
    int         (*free)(void *pointer);
    void        *(*malloc)(size_t __size);
    void        *(*realloc)(void *ptr, size_t size);
    void        *(*calloc)(size_t count, size_t size);
    void        *(*set)(void *pointer, int set, size_t length);
    void        *(*copy)(void *dst, const void *src, size_t size);
};

t_memory _memory(void);

int         _memory_free_all(void);
t_malloc    **_memory_list(void);
int         _memory_free(void *ptr);
void        *_memory_malloc(size_t __size);
void        *_memory_realloc(void *ptr, size_t size);
void        *_memory_calloc(size_t count, size_t size);
void        *_memory_set(void *pointer, int set, size_t length);
void        *_memory_copy(void *dst, const void *src, size_t size);

t_malloc    *_memory_check(t_malloc **list, void *ptr);

#endif // MEMORY_H