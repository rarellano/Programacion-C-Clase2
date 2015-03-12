#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

enum {
	TAREA_ATTR_NOMBRE_TAREA = 0,
	TAREA_ATTR_DESC_TAREA,
	TAREA_ATTR_ID,
	TAREA_ATTR_USUARIO,
	TAREA_ATTR_PRIORIDAD,
	__TAREA_ATTR_MAX
};

#define TAREA_ATTR_MAX (__TAREA_ATTR_MAX - 1)

#define xfree(ptr)	free((void *) ptr);

struct tarea;

struct tarea *tarea_alloc(void);

void tarea_free(struct tarea *);


bool tarea_attr_is_set(const struct tarea *t, uint16_t attr);

void tarea_attr_unset(struct tarea *t, uint16_t attr);

void tarea_set_data(struct tarea *t, uint16_t attr, const void *data,
		    uint32_t data_len);

void tarea_attr_set_u32(struct tarea *t, uint16_t attr, uint32_t data);

void tarea_attr_set_str(struct tarea *t, uint16_t attr, const char *data);

const void *tarea_attr_get_data(struct tarea *t, uint16_t attr);

uint32_t tarea_attr_get_u32(struct tarea *t, uint16_t attr);

const char *tarea_attr_get_str(struct tarea *t, uint16_t attr);

int tarea_snprintf(char *buf, size_t size, struct tarea *t);

