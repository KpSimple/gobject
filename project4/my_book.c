#include "my_book.h"

G_DEFINE_TYPE (MyBook, my_book, G_TYPE_OBJECT );

#define MY_BOOK_GET_PRIVATE(object) G_TYPE_INSTANCE_GET_PRIVATE((object),MY_TYPE_BOOK,MyBookPrivate)

enum PROPERTY_BOOK
{
	PROPERTY_0,
	PROPERTY_TITLE,
	PROPERTY_AUTHOR,
	PROPERTY_PUBLISHER,
	PORPERTY_YEAR,
	N_PROPERTIES
};

typedef struct _MyBookPrivate MyBookPrivate;
struct _MyBookPrivate
{
	GString *title;
	GString *author;
	GString *Publisher;
	guint year;
};

static void my_book_set_property(GObject*object,guint property_id,const GValue *value,GParamSpec *pspec)
{
        MyBook *self = MY_BOOK(object);
        MyBookPrivate *priv = MY_BOOK_GET_PRIVATE(self);

        switch(property_id)
        {
                case PROPERTY_TITLE:
                        if(priv->title)
                                g_string_free(priv->title,TRUE);
                        priv->title = g_string_new(g_value_get_string(value));
                default:
                        break;
        }
}

static void my_book_get_property(GObject*object,guint property_id,GValue *value,GParamSpec *pspec)
{
        MyBook *self = MY_BOOK(object);
        MyBookPrivate *priv = MY_BOOK_GET_PRIVATE(self);

        switch(property_id)
        {
                case PROPERTY_TITLE:
                        g_value_set_string(value,priv->title->str);
                        break;
                default:
                        break;
        }
}


static void my_book_class_init(MyBookClass *klass)
{
	g_type_class_add_private(klass,sizeof(MyBookPrivate));

	GObjectClass *base_class = G_OBJECT_CLASS(klass);
	base_class->set_property = my_book_set_property;
	base_class->get_property = my_book_get_property;

	GParamSpec *properties[N_PROPERTIES] = {NULL,};
	properties[PROPERTY_TITLE] =
		g_param_spec_string("title",
				"Title",
				"Bibliography title",
				NULL,
				G_PARAM_READWRITE);
	g_object_class_install_properties(base_class,2,properties);
}

static void my_book_init(MyBook *self)
{
}

void my_book_print(MyBook *self)
{
	gchar *title;
	g_object_get(G_OBJECT(self),
			"title",&title,
			NULL);
	
	g_printf("Title:%s\n",title);

	g_free(title);
}


