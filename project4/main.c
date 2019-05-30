#include"my_book.h"
int main(void)
{
	g_type_init();
	MyBook *entry = g_object_new(MY_TYPE_BOOK,
				"title","The New Book",
				NULL);
	
	my_book_print(entry);

	g_object_unref(entry);

	return 0;
}
