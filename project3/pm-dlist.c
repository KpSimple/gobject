#include "pm-dlist.h"


/*此宏有三个功能：
1，函数GType pm_dlist_get_type (void)的实现，GObject帮我们具体实现
2，注册函数前缀pm_dlist到GObject
3，注册实例结构体名称PMDList到GObject
通过此宏的调用，GObject知道了我们的三个信息：类型，类名称，函数前缀
*/
G_DEFINE_TYPE (PMDList, pm_dlist, G_TYPE_OBJECT);

/*将私有成员PMDListPrivate注册到GObject中，后续通过宏PM_DLIST_GET_PRIVATE作为获取私有成员变量的唯一入口，如果需要生效，需要在class_init中注册此变量*/
#define PM_DLIST_GET_PRIVATE(obj) \
        G_TYPE_INSTANCE_GET_PRIVATE ((obj), PM_TYPE_DLIST, PMDListPrivate)


/*属性对应的ID，真正属性ID不能为0，所以PROPERTY_DLIST_0是为了占位*/
enum PropertyDList {
        PROPERTY_DLIST_0,
        PROPERTY_DLIST_HEAD,
        PROPERTY_DLIST_HEAD_PREV,
        PROPERTY_DLIST_HEAD_NEXT,
        PROPERTY_DLIST_TAIL,
        PROPERTY_DLIST_TAIL_PREV,
        PROPERTY_DLIST_TAIL_NEXT
};


/*set属性实现*/
static void
pm_dlist_set_property (GObject *object, guint property_id,
                       const GValue *value, GParamSpec *pspec)
{
        PMDList *self = PM_DLIST (object);
        PMDListPrivate *priv = PM_DLIST_GET_PRIVATE (self);
        
        switch (property_id) {
        case PROPERTY_DLIST_HEAD:
                priv->head = g_value_get_pointer (value);
                break;
        case PROPERTY_DLIST_HEAD_PREV:
                priv->head->prev = g_value_get_pointer (value);
                break;
        case PROPERTY_DLIST_HEAD_NEXT:
                priv->head->next = g_value_get_pointer (value);
                break;
        case PROPERTY_DLIST_TAIL:
                priv->tail = g_value_get_pointer (value);
                break;
        case PROPERTY_DLIST_TAIL_PREV:
                priv->tail->prev = g_value_get_pointer (value);
                break;
        case PROPERTY_DLIST_TAIL_NEXT:
                priv->tail->next = g_value_get_pointer (value);
                break;
        default:
                G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
                break;
        }
}

/*get属性实现*/
static void
pm_dlist_get_property (GObject *object, guint property_id,
                       GValue *value, GParamSpec *pspec)
{
        PMDList *self = PM_DLIST (object);
        PMDListPrivate *priv = PM_DLIST_GET_PRIVATE (self);
        
        switch (property_id) {
        case PROPERTY_DLIST_HEAD:
                g_value_set_pointer (value, priv->head);
                break;
        case PROPERTY_DLIST_HEAD_PREV:
                g_value_set_pointer (value, priv->head->prev);
                break;
        case PROPERTY_DLIST_HEAD_NEXT:
                g_value_set_pointer (value, priv->head->next);
                break;
        case PROPERTY_DLIST_TAIL:
                g_value_set_pointer (value, priv->tail);
                break;
        case PROPERTY_DLIST_TAIL_PREV:
                g_value_set_pointer (value, priv->tail->prev);
                break;
        case PROPERTY_DLIST_TAIL_NEXT:
                g_value_set_pointer (value, priv->tail->next);
                break;
        default:
                G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
                break;
        }
}


/*类结构体的初始化，类似于C++中的static变量的初始化，函数地址分配等，此函数只会在第一次类实例化的时候被调用，后续类实例化不再调用*/
//G_PARAM_CONSTRUCT 是设定属性可以在对象示例化之时被设置
static void
pm_dlist_class_init (PMDListClass *klass)
{
        g_type_class_add_private (klass, sizeof (PMDListPrivate));

        GObjectClass *base_class = G_OBJECT_CLASS (klass);
        base_class->set_property = pm_dlist_set_property;
        base_class->get_property = pm_dlist_get_property;

        GParamSpec *pspec;
        pspec = g_param_spec_pointer ("head",
                                      "Head node",
                                      "The head node of the double list",
                                      G_PARAM_READABLE | G_PARAM_WRITABLE | G_PARAM_CONSTRUCT);
        g_object_class_install_property (base_class, PROPERTY_DLIST_HEAD, pspec);
        pspec = g_param_spec_pointer ("head-prev",
                                      "The previous node of the head node",
                                      "The previous node of the head node of the double list",
                                      G_PARAM_READABLE | G_PARAM_WRITABLE);
        g_object_class_install_property (base_class, PROPERTY_DLIST_HEAD_PREV, pspec);
        pspec = g_param_spec_pointer ("head-next",
                                      "The next node of the head node",
                                      "The next node of the head node of the double list",
                                      G_PARAM_READABLE | G_PARAM_WRITABLE);
        g_object_class_install_property (base_class, PROPERTY_DLIST_HEAD_NEXT, pspec);
        pspec = g_param_spec_pointer ("tail",
                                      "Tail node",
                                      "The tail node of the double list",
                                      G_PARAM_READABLE | G_PARAM_WRITABLE | G_PARAM_CONSTRUCT);
        g_object_class_install_property (base_class, PROPERTY_DLIST_TAIL, pspec);
        pspec = g_param_spec_pointer ("tail-prev",
                                      "The previous node of the tail node",
                                      "The previous node of the tail node of the double list",
                                      G_PARAM_READABLE | G_PARAM_WRITABLE);
        g_object_class_install_property (base_class, PROPERTY_DLIST_TAIL_PREV, pspec);
        pspec = g_param_spec_pointer ("tail-next",
                                      "The next node of the tail node",
                                      "The next node of the tail node of the double list",
                                      G_PARAM_READABLE | G_PARAM_WRITABLE);
        g_object_class_install_property (base_class, PROPERTY_DLIST_TAIL_NEXT, pspec);
}


/*实例结构体的初始化，类似于C++中的构造函数*/
static void
pm_dlist_init (PMDList *self)
{
}
