#include "../includes/allocator.h"
#include <stdlib.h>
#include <stdio.h>

#define BLOCK_SIZE (1 << 16)
#define ALIGN 8

static inline size_t get_unusing_size(t_block *block) {
	return block->capacity - block->used;
}

static inline size_t align_size(size_t size) {
	return (size + (ALIGN - 1)) & ~(ALIGN - 1);
}

static	t_block	*g_arena_block = NULL;
static	t_block	*g_current_block = NULL;

t_block	*_new_block(size_t size) {
	t_block	*block;

	block = malloc(sizeof(t_block));
	if (!block) {
		perror("failed malloc");
		exit(EXIT_FAILURE);
	}
	if (size > BLOCK_SIZE) {
		block->data = malloc(size);
		block->capacity = size;
	} else {
		block->data = malloc(BLOCK_SIZE);
		block->capacity = BLOCK_SIZE;
	}
	if (!block->data) {
		perror("failed malloc");
		exit(EXIT_FAILURE);
	}
	block->used = 0;
	block->next = NULL;
	return block;
}

void	_free_block(t_block *block) {
	free(block->data);
	free(block);
}

void	*ft_xmalloc(size_t size) {
	size_t		aligned;
	t_header	*header;

	aligned = align_size(sizeof(t_header) + size);
	if (get_unusing_size(g_current_block) < aligned) {
		g_current_block->next = _new_block(aligned);
		g_current_block = g_current_block->next;
	}
	
	header = (t_header *)(g_current_block->data + g_current_block->used);
	header->size = aligned - sizeof(t_header);
	g_current_block->used += aligned;
	return (void *)(header + 1);
}

void	*ft_realloc(void *ptr, size_t new_size) {
	void		*new_ptr;
	int			old_size;
	int			copy_size;
	t_header	*header;

	if (!ptr) {
		return ft_xmalloc(new_size);
	}

	if (new_size == 0) {
		// free(ptr);
		return NULL;
	}

	new_size = align_size(new_size);
	header = ((t_header *)ptr) - 1;
	old_size = header->size;

    // 이미 충분하면 그대로 반환 (used는 건드리지 않음)
    if (new_size <= old_size) {
        return ptr;
    }
	// 현재 할당된 block 내에서 사용가능한 메모리만 연장
	char	*end_of_alloc = (char *)ptr + old_size;
	char	*block_top = g_current_block->data + g_current_block->used;

	if (end_of_alloc == block_top \
			&& new_size - old_size < get_unusing_size(g_current_block)) {
		g_current_block->used += new_size - old_size;
		header->size = new_size;
		return ptr;
	}

	// 현재 할당된 block 내에 메모리가 부족하여
	// 새로운 block 할당 후 기존 메모리 복사 후 return
	// g_current_block->used -= old_size;
	new_ptr = ft_xmalloc(new_size);

	copy_size = (old_size < new_size) ? old_size : new_size;
	for (int i = 0; i < copy_size; i++) {
		((char *)new_ptr)[i] = ((char *)ptr)[i];
	}

	return new_ptr;
}

void	arena_init() {
	g_arena_block = _new_block(BLOCK_SIZE);
	g_current_block = g_arena_block;
}

void	arena_free() {
	t_block	*b;
	t_block	*n;

	b = g_arena_block;
	while (b) {
		n = b->next;
		_free_block(b);
		b = n;
	}
}

t_arena_cursor	get_arena_cursor() {
	t_arena_cursor	c;

	c.block = g_current_block;
	c.used = g_current_block->used;
	return c;
}

void	arena_rewind(t_arena_cursor cursor) {
	t_block	*next_block;
	t_block	*tmp;

	g_current_block = cursor.block;
	g_current_block->used = cursor.used;
	next_block = g_current_block->next;
	while (next_block) {
		tmp = next_block->next;
		_free_block(next_block);
		next_block = tmp;
	}
	g_current_block->next = NULL;
}
