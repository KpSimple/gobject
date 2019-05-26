#include "pm-dlist.h"
int main(void)
{
	g_type_init();
	
	int i;
	PMDList *list;
	//创建实例
	list = g_object_new(PM_TYPE_DLIST,NULL);
	//销毁实例
	g_object_unref(list);

	return 0;
}	
