//window下实现linux的双链表

//1.节点定义。虽然名称list_head，但是它既是双向链表的表头，也代表双向链表的节点。  
struct list_head {  
    struct list_head *next, *prev;  
};  
  
//2.初始化节点：将list节点的前继节点和后继节点都是指向list本身。  
static inline void INIT_LIST_HEAD(struct list_head *list)  
{  
    list->next = list;  
    list->prev = list;  
}  
  
/* 3.添加节点 
list_add(newhead, prev, next)的作用是添加节点：将newhead插入到prev和next节点之间。 
list_add(newhead, head)的作用是添加newhead节点：将newhead添加到head之后，是newhead称为head的后继节点。 
list_add_tail(newhead, head)的作用是添加newhead节点：将newhead添加到head之前，即将newhead添加到双链表的末尾。 
*/  
static inline void __list_add(struct list_head *newhead,struct list_head *prev,struct list_head *next)  
{  
    next->prev = newhead;  
    newhead->next = next;  
    newhead->prev = prev;  
    prev->next = newhead;  
}  
//将newhead添加到head之后  
static inline void list_add(struct list_head *newhead, struct list_head *head)  
{  
    __list_add(newhead, head, head->next);  
}  
//将newhead添加到head之前，也就是末尾  
static inline void list_add_tail(struct list_head *newhead, struct list_head *head)  
{  
    __list_add(newhead, head->prev, head);  
}  
  
/* 4.删除节点 
list_del(prev, next) 的作用是从双链表中删除prev和next之间的节点。 
list_del(entry) 的作用是从双链表中删除entry节点。 
list_del_init(entry) 的作用是从双链表中删除entry节点，并将entry节点的前继节点和后继节点都指向entry本身。 
*/  
static inline void __list_del(struct list_head * prev, struct list_head * next)  
{  
    next->prev = prev;  
    prev->next = next;  
}  
//删除自身  
static inline void list_del(struct list_head *entry)  
{  
    __list_del(entry->prev, entry->next);  
}  
  
static inline void list_del_init(struct list_head *entry)  
{  
    list_del(entry);  
    INIT_LIST_HEAD(entry);  
}  

//5.替换节点：list_replace(old, newhead)的作用是用newhead节点替换old节点。  
static inline void list_replace(struct list_head *old,struct list_head *newhead)  
{  
	newhead->next = old->next;  
	newhead->next->prev = newhead;  
	newhead->prev = old->prev;  
	newhead->prev->next = newhead;  
}  

//6. 判断双链表是否为空：list_empty(head)的作用是判断双链表是否为空。它是通过区分"表头的后继节点"是不是"表头本身"来进行判断的。  
static inline int list_empty(const struct list_head *head)  
{  
	return head->next == head;  
}  

/*7. 获取节点 
list_entry(ptr, type, member) 实际上是调用的container_of宏。 
它的作用是：根据"结构体(type)变量"中的"域成员变量(member)的指针(ptr)"来获取指向整个结构体变量的指针。 
*/  
// 获得结构体(TYPE)的变量成员(MEMBER)在此结构体中的偏移量。  
#define offsetof(TYPE, MEMBER) ((size_t) &((TYPE *)0)->MEMBER)  
//根据"结构体(type)变量"中的"域成员变量(member)的指针(ptr)"来获取指向整个结构体变量的指针  
#define container_of(PT,TYPE,MEMBER) ((TYPE *)((char *)(PT) - offsetof(TYPE,MEMBER)))  
  
#define list_entry(ptr, type, member) container_of(ptr, type, member)  
  
/*8.遍历节点 
list_for_each(pos, head)和list_for_each_safe(pos, n, head)的作用都是遍历链表。但是它们的用途不一样！ 
list_for_each(pos, head)通常用于获取节点，而不能用到删除节点的场景。 
list_for_each_safe(pos, n, head)通常删除节点的场景。 
*/  
#define list_for_each(pos, head) for (pos = (head)->next; pos != (head); pos = pos->next)  
  
#define list_for_each_safe(pos, n, head) for (pos = (head)->next, n = pos->next; pos != (head); pos = n, n = pos->next)  