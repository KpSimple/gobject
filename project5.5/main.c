#include "my_udisk.h"

int main (void)
{
	g_type_init ();
	MyUdisk *udisk = g_object_new (MY_TYPE_UDISK, NULL);

	my_iusb_write (MY_IUSB (udisk), "I am u-disk!");
	gchar *data = my_iusb_read (MY_IUSB (udisk));
	
	g_printf ("%s\n\n", data);
	return 0;
}
