#include "pm-dlist.h"


int
main (void)
{
        
		//GObject 库的类型管理系统的初始化 
        g_type_init ();

        PMDList *list1,*list2;
		PMDListNode Node1,Node2;
		
		//创建两个节点的指针
		GValue node1 = {0};
		GValue node2 = {0};
		g_value_init (&node1, G_TYPE_POINTER);
		g_value_init (&node2, G_TYPE_POINTER);
		g_value_set_pointer (&node1, &Node1);
		g_value_set_pointer (&node2, &Node2);
		
		g_printf("\t Node1 addr: %x\n",&Node1);
		g_printf("\t Node2 addr: %x\n",&Node2);
		
		//实例化
        list1 = g_object_new (PM_TYPE_DLIST,
                             "head", NULL,
                             "tail", &node1,
                             NULL);
							 
		list2 = g_object_new (PM_TYPE_DLIST,
                             "head", &node2,
                             "tail", NULL,
                             NULL);
		
		//设置
		//list1->tail->next = list2->head
		//list2->head->prev = list1->tail
		GValue list1_tail = {0};
		GValue list2_head = {0};

		g_value_init (&list1_tail, G_TYPE_POINTER);
		g_value_init (&list2_head, G_TYPE_POINTER);

		g_object_get_property (G_OBJECT(list1), "tail", &list1_tail);
		g_object_set_property (G_OBJECT(list2), "head-prev", &list1_tail);

		g_object_get_property (G_OBJECT(list2), "head", &list2_head);
		g_object_set_property (G_OBJECT(list1), "tail-next", &list2_head);
		/*
		GValue node = {0};
		g_value_init (&node, G_TYPE_POINTER);
		g_object_get_property (G_OBJECT(list1), "tail-next", &node);
		g_printf("\t list1->tail->next addr: %x\n",&node);
		*/					 
		//释放实例
		g_object_unref (list1);
		g_object_unref (list2);
		
		//释放变量
		//g_value_unset (&node1);
		//g_value_unset (&node2);
		//g_value_unset (&list2_head);
		//g_value_unset (&list1_tail);	
		
        return 0;
}
