#include "pm-dlist.h"


/*此宏有三个功能：
1，函数GType pm_dlist_get_type (void)的实现，GObject帮我们具体实现
2，注册函数前缀pm_dlist到GObject
3，注册实例结构体名称PMDList到GObject
通过此宏的调用，GObject知道了我们的三个信息：类型，类名称，函数前缀
*/
G_DEFINE_TYPE (PMDList,pm_dlist,G_TYPE_OBJECT);

/*
将私有成员PMDListPrivate注册到GObject中，后续通过宏PM_DLIST_GET_PRIVATE作为获取私有成员变量的唯一入口，如果需要生效，需要在class_init中注册此变量
*/
#define PM_DLIST_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE(obj,PM_TYPE_DLIST,PMDListPrivate))


/*普通结构体，作为实例结构体的私有成员*/
typedef struct _PMDListNode PMDListNode;
struct _PMDListNode
{
        PMDListNode *prev;
        PMDListNode *next;
        void *data;
};


/*普通结构体，作为实例结构体的私有成员*/
typedef struct _PMDListPrivate PMDListPrivate;
struct _PMDListPrivate
{
        PMDListNode *head;
        PMDListNode *tail;
};

/*类结构体的初始化，类似于C++中的static变量的初始化，函数地址分配等，此函数只会在第一次类实例化的时候被调用，后续类实例化不再调用*/
static void pm_dlist_class_init(PMDListClass *klass)
{
	g_printf("class struct init! \n");
	g_type_class_add_private(klass,sizeof(PMDListPrivate));
}

/*实例结构体的初始化，类似于C++中的构造函数*/
static void pm_dlist_init(PMDList *self)
{
	g_printf("instance struct init! \n");
	PMDListPrivate * priv = PM_DLIST_GET_PRIVATE(self);
	priv->head = NULL;
	priv->tail = NULL;
}



