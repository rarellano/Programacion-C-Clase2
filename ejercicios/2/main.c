#include "tarea.h"

int main(void){
	struct tarea *t1;
	char info[4000];
	t1 = tarea_alloc();

	tarea_attr_set_str(t1, TAREA_ATTR_NOMBRE_TAREA, "Tarea n1");
	tarea_attr_set_str(t1, TAREA_ATTR_DESC_TAREA, "Es es la descripcion de la tarea n1");
	tarea_attr_set_u32(t1, TAREA_ATTR_ID, 798);
	tarea_attr_set_str(t1, TAREA_ATTR_USUARIO, "Usuario123");
	tarea_attr_set_u32(t1, TAREA_ATTR_PRIORIDAD, 20);
	
	tarea_snprintf(info, sizeof(info), t1);
	printf("%s",info);

	tarea_free(t1);
}
