#include "pm-dlist.h"
int main(void)
{
	g_type_init();
	
	int i;
	PMDList *list;

	list = g_object_new(PM_TYPE_DLIST,NULL);
	g_object_unref(list);

	return 0;
}	
