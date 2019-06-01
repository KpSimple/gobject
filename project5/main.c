#include"my_book.h"
int main(void)
{
	g_type_init();

	StoryBook *entry = g_object_new(STORY_TYPE_BOOK,
				NULL);
	MyBook *parent = &(entry->parent);
	MyBookPrivate *BookPriv = MY_BOOK_GET_PRIVATE(parent);
	gchar *title = BookPriv->title->str;
	g_print("title:%s\n",title);

	StoryBookPrivate *StoryPriv = STORY_BOOK_GET_PRIVATE(entry);
	char *author = StoryPriv->author;
	g_print("author:%s\n",author);

	g_object_unref(entry);

	return 0;
}
