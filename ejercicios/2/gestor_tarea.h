#include <stdio.h>
#include <stdin.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

enum {
	GESTOR_TAREA_ATTR_TAREAS = 0,
	GESTOR_TAREA_ATTR_NUMERO_TAREAS,
	__GESTOR_TAREA_ATTR_MAX
};

#define GESTOR_TAREA_ATTR_MAX (__GESTOR_TAREA_ATTR_MAX - 1)

#define xfree(ptr)	free((void *) ptr);

struct gestor_tarea;

struct gestor_tarea *gestor_tarea_alloc(void);

void gestor_tarea_free(struct gestor_tarea *);

bool gestor_tarea_attr_is_set(const struct gestor_tarea *gt, uint16_t attr);

void gestor_tarea_attr_unset(struct gestor_tarea *gt, uint16_t attr);

void gestor_tarea_set_data(struct gestor_tarea *gt, uint16_t attr, 
			const void *data, uint32_t data_len);

void gestor_tarea_attr_set_u32(struct gestor_tarea *gt, uint16_t attr, 
			uint32_t data);

void gestor_tarea_attr_set_str(struct gestor_tarea *gt, uint16_t attr, 
			const char *data);

const void *gestor_tarea_attr_get_data(struct gestor_tarea *gt, uint16_t attr);

uint32_t gestor_tarea_attr_get_u32(struct gestor_tarea *gt, uint16_t attr);

const char *tarea_attr_get_str(struct gestor_tarea *gt, uint16_t attr);

int gestor_tarea_snprintf(char *buf, size_t size, struct gestor_tarea *gt);
