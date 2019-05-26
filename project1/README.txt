使用 GObject 库模拟类的数据封装形式

在 GObject 世界里，类是两个结构体的组合，一个是实例结构体，另一个是类结构体。

PMDList 类的实例结构体的第一个成员是 GObject 结构体，PMDList 类的类结构体的第一个成员是 GObjectClass 结构体。
其实，GObject 结构体与 GObjectClass 结构体分别是 GObject 类的实例结构体与类结构体，
当它们分别作为 PMDList 类的实例结构体与类结构体的第一个成员时，这意味着 PMDList 类继承自 GObject 类。
