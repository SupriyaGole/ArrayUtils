typedef struct array{
	void *base;
	int typeSize;
	int length;
} ArrayUtil;

typedef int(MatchFunc)(void *,void *);
typedef void (ConvertFunc)(void *,void *,void *);
typedef void (OperationFunc)(void *, void *);
typedef void *(ReducerFunc)(void *,void *,void *);

ArrayUtil create(int typeSize,int length);
int areEqual(ArrayUtil marks,ArrayUtil scores);
ArrayUtil resize(ArrayUtil util, int length); 
int findIndex(ArrayUtil util,void *element);
void dispose(ArrayUtil util);
void *findFirst(ArrayUtil util,MatchFunc *match,void *hint);
void *findLast(ArrayUtil util,MatchFunc *match,void *hint);
int count(ArrayUtil util, MatchFunc* match, void* hint);
int filter(ArrayUtil util, MatchFunc *match, void *hint, void **destination, int maxItems);
void map(ArrayUtil source,ArrayUtil destination,ConvertFunc *convert,void *hint);
void forEach(ArrayUtil util, OperationFunc* operation, void* hint);
void *reduce(ArrayUtil util, ReducerFunc* reducer, void* hint, void* initialValue);

void square(void *hint,void *sourceEle,void *destinationEle);
void addNoWithHint(void *hint,void *item);
void *greaterNumber(void *hint,void *previousItem,void *item);
int isEven(void *hint,void *num);
int isDivisible(void *hint,void *num);