#include "pm-dlist.h"

G_DEFINE_TYPE (PMDList,pm_dlist,G_TYPE_OBJECT);

static void pm_dlist_init(PMDList *self)
{
	g_printf("instance struct init! \n");
	self->head = NULL;
	self->tail = NULL;
}

static void pm_dlist_class_init(PMDListClass *klass)
{
	g_printf("class struct init! \n");
}


