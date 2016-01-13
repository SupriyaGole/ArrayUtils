typedef struct element{
	void *value;
	struct element *next;
} ELEMENT;

typedef struct list{
	ELEMENT *first;
	ELEMENT *last;
	int length;
} LinkedList;

typedef void (*ElementProcessor)(void *);
LinkedList createList(void); 
int add_to_list(LinkedList *list,void *element);
void *get_first_element(LinkedList list);
void *get_last_element(LinkedList list);
void forEach(LinkedList *list,ElementProcessor processor);
void storeValue(LinkedList list,int *destination);
void increment(void *);
void printValue(LinkedList list);
void *getElementAt(LinkedList list,int index);
int indexOf(LinkedList list,void *value);
void * deleteElementAt(LinkedList *, int);
