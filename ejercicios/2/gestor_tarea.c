#include "gestor_tarea.h"

struct gestor_tarea{
	struct tarea *tareas[10];
	uint32_t numero_tareas;
	
	uint32_t flags;
};

struct gestor_tarea *gestor_tarea_alloc(void)
{
	return (struct gestor_tarea *)malloc (sizeof(struct gestor_tarea));
}

void gestor_tarea_free(struct gestor_tarea *gt)
{
	int i;
	for(i = 0; i < gt->numero_tareas; i++)
		xfree(g-> tareas[i])
	xfree(gt);
}


void gestor_tarea_attr_unset_tarea(struct gestor_tarea *gt, uint16_t pos)
{
	if (pos < 0 || pos >= gt->numero_tareas)
	return;

	gt->numero_tareas--;
	tarea_free(gt->tareas[pos]);

	if (gt->numero_tareas == 0) {
		gt->flags &= ~(1 << GESTOR_TAREA_ATTR_TAREAS);
		gt->flags &= ~(1 << GESTOR_TAREA_ATTR_NUMERO_TAREAS);
	}
}

void gestor_tarea_attr_set_tarea(struct gestor_tarea *gt, uint16_t attr,struct tarea *data)
{
	if (attr != GESTOR_TAREA_ATTR_TAREAS)
	return;
	if (gt->numero_tareas > 9) {
		printf("El gestor está al máximo de tareas\n");
		return;
	}
	gt->tareas[gt->numero_tareas] = (struct tarea *)data;
	gt->numero_tareas++;
	gt->flags |= (1 << GESTOR_TAREA_ATTR_TAREAS);
	gt->flags |= (1 << GESTOR_TAREA_ATTR_NUMERO_TAREAS);
}

const void *gestor_tarea_attr_get_data(struct gestor_tarea *gt, uint16_t attr,
		uint16_t pos)
{
	if (!(gt->flags & (1 << attr)))
	return NULL;
	switch(attr) {
		case GESTOR_TAREA_ATTR_TAREAS:
			return gt->tareas[pos];
		case GESTOR_TAREA_ATTR_NUMERO_TAREAS:
			return &gt->numero_tareas;
	}
	return NULL;
}

const struct tarea *gestor_tarea_attr_get_tarea(struct gestor_tarea *gt		uint16_t attr, uint16_t pos)
{
	return (struct tarea *)gestor_tarea_attr_get_data(gt, attr, pos);
}

const uint16_t gestor_tarea_attr_get_u16(struct gestor_tarea *gt,uint16_t attr)
{
	const void * ret = gestor_tarea_attr_get_data(gt, attr, 0);
	return ret == NULL ? 0 : *((uint16_t *)ret);
}

int gestor_tarea_snprintf(char *buf, size_t size, struct gestor_tarea *gt)
{
	int i,ret = 0;
	for (i = 0; i < gt->numero_tareas; i++) {
		ret += tarea_snprintf(buf + ret, size - ret, gt->tareas[i]);
		ret += snprintf(buf + ret, size - ret, "\n");
	}
	return ret;
}
	
	
	
	
					

