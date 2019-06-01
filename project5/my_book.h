#ifndef MY_BOOK_H
#define MY_BOOK_H

#include<glib-object.h>

#define MY_TYPE_BOOK (my_book_get_type())

#define MY_BOOK(object) G_TYPE_CHECK_INSTANCE_CAST((object),MY_TYPE_BOOK,MyBook)

#define MY_BOOK_GET_PRIVATE(object) G_TYPE_INSTANCE_GET_PRIVATE((object),MY_TYPE_BOOK,MyBookPrivate)

typedef struct _MyBookPrivate MyBookPrivate;
struct _MyBookPrivate
{
	GString *title;
};

typedef struct _MyBook MyBook;
struct _MyBook
{
	GObject parent;

};

typedef struct _MyBookClass MyBookClass;
struct _MyBookClass
{
	GObjectClass parent_class;
};

GType my_book_get_type(void);

#endif
