#include "tarea.h"

struct tarea {
	char		*nombre_tarea;
	char		*desc_tarea;
	uint32_t	id;
	char		*usuario;
	uint32_t	prioridad;
	
	uint32_t	flags;
};

struct tarea *tarea_alloc(void)
{
	return (struct tarea *)malloc (sizeof(struct tarea));
}

void tarea_free(struct tarea *t)
{
	if(t->flags & (1 << TAREA_ATTR_NOMBRE_TAREA))
		xfree(t->nombre_tarea);
	if(t->flags & (1 << TAREA_ATTR_DESC_TAREA))
		xfree(t->desc_tarea);
	if(t->flags & (1 << TAREA_ATTR_USUARIO))
		xfree(t->usuario);	
}

bool tarea_attr_is_set(const struct tarea *t, uint16_t attr)
{
	return t->flags & (1 << attr);
}

void tarea_attr_unset(struct tarea *t, uint16_t attr)
{
	if (!(t->flags & (1 << attr)))
		return;

	switch (attr) {
	case TAREA_ATTR_NOMBRE_TAREA:
		if (t->nombre_tarea){
			xfree(t->nombre_tarea);
			t->nombre_tarea = NULL;
		}
		break;
	case TAREA_ATTR_DESC_TAREA:
		if (t->desc_tarea){
			xfree(t->desc_tarea);
			t->desc_tarea = NULL;
		}
		break;
	case TAREA_ATTR_USUARIO:
		if (t->usuario){
			xfree(t->usuario);
			t->usuario = NULL;
		}
		break;
	case TAREA_ATTR_ID:
		break;
	case TAREA_ATTR_PRIORIDAD:
		break;	
	}
	t->flags &= ~(1 << attr);
}

void tarea_set_data(struct tarea *t, uint16_t attr, const void *data,uint32_t data_len)
{
	if(attr > TAREA_ATTR_MAX)
		return;
	switch (attr){
	case TAREA_ATTR_NOMBRE_TAREA:
		if(t->nombre_tarea)
			xfree(t->nombre_tarea);
		t->nombre_tarea = strdup(data);
		break;
	case TAREA_ATTR_DESC_TAREA:
		if(t->desc_tarea)
			xfree(t->desc_tarea);
		t->desc_tarea = strdup(data);
		break;
	case TAREA_ATTR_USUARIO:
		if(t->usuario)
			xfree(t->usuario);
		t->usuario = strdup(data);
		break;
	case TAREA_ATTR_ID:
		t->id = *((uint32_t *)data);
		break;
	case TAREA_ATTR_PRIORIDAD:
		t->prioridad = *((uint32_t *)data);
		break;
	}
	t->flags |= (1 << attr);	
}

void tarea_attr_set_u32(struct tarea *t, uint16_t attr, uint32_t data)
{
	tarea_set_data(t, attr, &data, sizeof(uint32_t));
}

void tarea_attr_set_str(struct tarea *t, uint16_t attr, const char *data)
{
	tarea_set_data(t, attr, data, 0);
}

const void *tarea_attr_get_data(struct tarea *t, uint16_t attr)
{
	if (!(t->flags & (1 << attr)))
		return NULL;

	switch(attr) {
	case TAREA_ATTR_NOMBRE_TAREA:
		return t->nombre_tarea;
	case TAREA_ATTR_DESC_TAREA:
		return t->desc_tarea;
	case TAREA_ATTR_USUARIO:
		return t->usuario;
	case TAREA_ATTR_ID:
		return &t->id;
	case TAREA_ATTR_PRIORIDAD:
		return &t->prioridad;
	}
	return NULL;
}

uint32_t tarea_attr_get_u32(struct tarea *t, uint16_t attr)
{
	const void *ret = tarea_attr_get_data(t, attr);
	return ret == NULL ? 0 : *((uint32_t *)ret);
}

const char *tarea_attr_get_str(struct tarea *t, uint16_t attr)
{
	return tarea_attr_get_data(t, attr);	
}

int tarea_snprintf(char *buf, size_t size, struct tarea *t)
{
	return snprintf(buf, size, "Nombre: %s Descripcion: %s Usuario:%s Id: %d Prioridad: %d", t->nombre_tarea, t->desc_tarea, t->usuario, t->id, t->prioridad);
}

