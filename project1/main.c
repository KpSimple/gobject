#include "pm-dlist.h"
int main(void)
{
	/* GObject 库的类型管理系统的初始化 */
	g_type_init();
	
	int i;
	PMDList *list;
	
	/* 进行三次对象实例化 */
	for(i=0;i<3;i++)
	{
		list = g_object_new(PM_TYPE_DLIST,NULL);
		g_object_unref(list);
	}

	list = g_object_new(PM_TYPE_DLIST,NULL);
	/* 检查实例是否为 GObject 对象 */
	if(G_IS_OBJECT(list))
		g_printf("\t this is a GObject object!\n");
	return 0;
}	
