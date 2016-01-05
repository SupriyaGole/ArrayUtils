typedef struct array{
	void *base;
	int typeSize;
	int length;
} ArrayUtil;

typedef int(MatchFunc)(void *,void *);

ArrayUtil create(int typeSize,int length);
int areEqual(ArrayUtil marks,ArrayUtil scores);
ArrayUtil resize(ArrayUtil util, int length); 
int findIndex(ArrayUtil util,void *element);
void dispose(ArrayUtil util);
void *findFirst(ArrayUtil util,MatchFunc *match,void *hint);
void *findLast(ArrayUtil util,MatchFunc *match,void *hint);
int count(ArrayUtil util, MatchFunc* match, void* hint);