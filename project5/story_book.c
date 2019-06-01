#include "story_book.h"

G_DEFINE_TYPE (StoryBook, story_book, STORY_TYPE_BOOK );

static void story_book_class_init(StoryBookClass *klass)
{
	g_type_class_add_private(klass,sizeof(StoryBookPrivate));
}

static void story_book_init(StoryBook *self)
{
	self->priv->author = "J.K.ROWLING";
}


