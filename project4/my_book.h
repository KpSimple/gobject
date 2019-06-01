#ifndef MY_BOOK_H
#define MY_BOOK_H

#include<glib-object.h>

#define MY_TYPE_BOOK (my_book_get_type())

#define MY_BOOK(object) G_TYPE_CHECK_INSTANCE_CAST((object),MY_TYPE_BOOK,MyBook)

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

void my_book_print(MyBook *self);

#endif
