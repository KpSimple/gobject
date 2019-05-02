#include "pm-dlist.h"
int main(void)
{
	g_type_init();
	
	int i;
	PMDList *list;

	for(i=0;i<3;i++)
	{
		list = g_object_new(PM_TYPE_DLIST,NULL);
		g_object_unref(list);
	}

	list = g_object_new(PM_TYPE_DLIST,NULL);
	if(G_IS_OBJECT(list))
		g_printf("\t this is a GObject object!\n");
	return 0;
}	
