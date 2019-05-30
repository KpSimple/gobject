#include"my_book.h"
int main(void)
{
	g_type_init();
	MyBook *entry = g_object_new(MY_TYPE_BOOK,
				"title","The New Book",
				NULL);
	gchar *title;
	g_object_get(G_OBJECT(entry),
			"title",&title,
			NULL);
	
	g_printf("Title:%s\n",title);

	g_free(title);

	g_object_unref(entry);

	return 0;
}
