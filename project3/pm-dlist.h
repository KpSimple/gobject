#ifndef PM_DLIST_H
#define PM_DLIST_H

/*必须包含的基类头文件*/
#include <glib-object.h>

/*定义子类类型，其中pm_dist字段是用户可以修改的内容，表示这个类的用途，后续所有的函数都必须以pm_dist开头，pm_dlist_get_type ()函数在下边定义*/
#define PM_TYPE_DLIST (pm_dlist_get_type ())

/*定义强制转换宏，可以将基类GObject转换为本子类*/
#define PM_DLIST(object) G_TYPE_CHECK_INSTANCE_CAST ((object), PM_TYPE_DLIST, PMDList)

/*普通结构体，作为实例结构体的私有成员*/
typedef struct _PMDListNode PMDListNode;
struct  _PMDListNode {
        PMDListNode *prev;
        PMDListNode *next;
        void *data;
};

/*普通结构体，作为实例结构体的私有成员*/
typedef struct _PMDListPrivate PMDListPrivate;
struct  _PMDListPrivate {
        PMDListNode *head;
        PMDListNode *tail;
};

/*实例结构体,类似于C++中实例化时，每个实例独有的内容，比如成员函数，成员变量等*/
typedef struct _PMDList PMDList;
struct  _PMDList {
        GObject parent_instance;
};

/*类结构体,类似于C++中,属于类的部分，比如：static成员函数和static成员变量等*/
typedef struct _PMDListClass PMDListClass;
struct _PMDListClass {
        GObjectClass parent_class;
};

/*privae,定义获取类型函数,供PM_TYPE_DLIST调用，不建议直接调用*/
GType pm_dlist_get_type (void);

#endif
