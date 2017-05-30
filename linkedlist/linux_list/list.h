//window��ʵ��linux��˫����

//1.�ڵ㶨�塣��Ȼ����list_head������������˫������ı�ͷ��Ҳ����˫������Ľڵ㡣  
struct list_head {  
    struct list_head *next, *prev;  
};  
  
//2.��ʼ���ڵ㣺��list�ڵ��ǰ�̽ڵ�ͺ�̽ڵ㶼��ָ��list����  
static inline void INIT_LIST_HEAD(struct list_head *list)  
{  
    list->next = list;  
    list->prev = list;  
}  
  
/* 3.��ӽڵ� 
list_add(newhead, prev, next)����������ӽڵ㣺��newhead���뵽prev��next�ڵ�֮�䡣 
list_add(newhead, head)�����������newhead�ڵ㣺��newhead��ӵ�head֮����newhead��Ϊhead�ĺ�̽ڵ㡣 
list_add_tail(newhead, head)�����������newhead�ڵ㣺��newhead��ӵ�head֮ǰ������newhead��ӵ�˫�����ĩβ�� 
*/  
static inline void __list_add(struct list_head *newhead,struct list_head *prev,struct list_head *next)  
{  
    next->prev = newhead;  
    newhead->next = next;  
    newhead->prev = prev;  
    prev->next = newhead;  
}  
//��newhead��ӵ�head֮��  
static inline void list_add(struct list_head *newhead, struct list_head *head)  
{  
    __list_add(newhead, head, head->next);  
}  
//��newhead��ӵ�head֮ǰ��Ҳ����ĩβ  
static inline void list_add_tail(struct list_head *newhead, struct list_head *head)  
{  
    __list_add(newhead, head->prev, head);  
}  
  
/* 4.ɾ���ڵ� 
list_del(prev, next) �������Ǵ�˫������ɾ��prev��next֮��Ľڵ㡣 
list_del(entry) �������Ǵ�˫������ɾ��entry�ڵ㡣 
list_del_init(entry) �������Ǵ�˫������ɾ��entry�ڵ㣬����entry�ڵ��ǰ�̽ڵ�ͺ�̽ڵ㶼ָ��entry���� 
*/  
static inline void __list_del(struct list_head * prev, struct list_head * next)  
{  
    next->prev = prev;  
    prev->next = next;  
}  
//ɾ������  
static inline void list_del(struct list_head *entry)  
{  
    __list_del(entry->prev, entry->next);  
}  
  
static inline void list_del_init(struct list_head *entry)  
{  
    list_del(entry);  
    INIT_LIST_HEAD(entry);  
}  

//5.�滻�ڵ㣺list_replace(old, newhead)����������newhead�ڵ��滻old�ڵ㡣  
static inline void list_replace(struct list_head *old,struct list_head *newhead)  
{  
	newhead->next = old->next;  
	newhead->next->prev = newhead;  
	newhead->prev = old->prev;  
	newhead->prev->next = newhead;  
}  

//6. �ж�˫�����Ƿ�Ϊ�գ�list_empty(head)���������ж�˫�����Ƿ�Ϊ�ա�����ͨ������"��ͷ�ĺ�̽ڵ�"�ǲ���"��ͷ����"�������жϵġ�  
static inline int list_empty(const struct list_head *head)  
{  
	return head->next == head;  
}  

/*7. ��ȡ�ڵ� 
list_entry(ptr, type, member) ʵ�����ǵ��õ�container_of�ꡣ 
���������ǣ�����"�ṹ��(type)����"�е�"���Ա����(member)��ָ��(ptr)"����ȡָ�������ṹ�������ָ�롣 
*/  
// ��ýṹ��(TYPE)�ı�����Ա(MEMBER)�ڴ˽ṹ���е�ƫ������  
#define offsetof(TYPE, MEMBER) ((size_t) &((TYPE *)0)->MEMBER)  
//����"�ṹ��(type)����"�е�"���Ա����(member)��ָ��(ptr)"����ȡָ�������ṹ�������ָ��  
#define container_of(PT,TYPE,MEMBER) ((TYPE *)((char *)(PT) - offsetof(TYPE,MEMBER)))  
  
#define list_entry(ptr, type, member) container_of(ptr, type, member)  
  
/*8.�����ڵ� 
list_for_each(pos, head)��list_for_each_safe(pos, n, head)�����ö��Ǳ��������������ǵ���;��һ���� 
list_for_each(pos, head)ͨ�����ڻ�ȡ�ڵ㣬�������õ�ɾ���ڵ�ĳ����� 
list_for_each_safe(pos, n, head)ͨ��ɾ���ڵ�ĳ����� 
*/  
#define list_for_each(pos, head) for (pos = (head)->next; pos != (head); pos = pos->next)  
  
#define list_for_each_safe(pos, n, head) for (pos = (head)->next, n = pos->next; pos != (head); pos = n, n = pos->next)  