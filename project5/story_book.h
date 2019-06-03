#ifndef STORY_BOOK_H
#define STORY_BOOK_H

#include<glib-object.h>

#include "my_book.h"

#define STORY_TYPE_BOOK (story_book_get_type())

#define STORY_BOOK_GET_PRIVATE(object) G_TYPE_INSTANCE_GET_PRIVATE((object),STORY_TYPE_BOOK,StoryBookPrivate)

typedef struct _StoryBookPrivate StoryBookPrivate;
struct _StoryBookPrivate
{
	char *author;
};

typedef struct _StoryBook StoryBook;
struct _StoryBook
{
	MyBook parent;
};

typedef struct _StoryBookClass StoryBookClass;
struct _StoryBookClass
{
	MyBookClass parent_class;
};

GType story_book_get_type(void);

#endif
