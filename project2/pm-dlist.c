#include "pm-dlist.h"

G_DEFINE_TYPE (PMDList,pm_dlist,G_TYPE_OBJECT);
#define PM_DLIST_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE(obj,PM_TYPE_DLIST,PMDListPrivate))

typedef struct _PMDListNode PMDListNode;
struct _PMDListNode
{
        PMDListNode *prev;
        PMDListNode *next;
        void *data;
};

typedef struct _PMDListPrivate PMDListPrivate;
struct _PMDListPrivate
{
        PMDListNode *head;
        PMDListNode *tail;
};

static void pm_dlist_init(PMDList *self)
{
	g_printf("instance struct init! \n");
	PMDListPrivate * priv = PM_DLIST_GET_PRIVATE(self);
	priv->head = NULL;
	priv->tail = NULL;
}

static void pm_dlist_class_init(PMDListClass *klass)
{
	g_printf("class struct init! \n");
	g_type_class_add_private(klass,sizeof(PMDListPrivate));
}


