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

typedef int (*MatchFunc)(void *,void *);

typedef void (ConvertFunc)(void *,void *,void *);

typedef void *(*Reducer)(void *,void *,void *);

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

int asArray(LinkedList list, void **destination, int maxElements);

LinkedList  filter(LinkedList, MatchFunc,void *);

int isDivisible(void *,void *);

LinkedList reverse(LinkedList);

LinkedList map(LinkedList, ConvertFunc, void * );

void * reduce(LinkedList, Reducer func, void *hint, void *initialValue);

void square(void *,void *,void *);

void initializeList(LinkedList *marks_of_student);

void *sum(void *,void *,void *);

void initializeListOfChar(LinkedList *marks_of_student);

void printString(LinkedList);

void printChar(LinkedList);

void getNextChar(void *);

void toLowerCase(void *);

int isCapitalLetter(void *,void *);
int hasLetter(void *,void *);