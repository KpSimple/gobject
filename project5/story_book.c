#include "story_book.h"

G_DEFINE_TYPE (StoryBook, story_book, MY_TYPE_BOOK );

static void story_book_class_init(StoryBookClass *klass)
{
	g_print("story_book_class_init\n");
	g_type_class_add_private(klass,sizeof(StoryBookPrivate));
}

static void story_book_init(StoryBook *self)
{
	g_print("story_book_init\n");
	StoryBookPrivate *StoryPriv = STORY_BOOK_GET_PRIVATE(self);
	StoryPriv->author = "J.K.ROWLING";
}


