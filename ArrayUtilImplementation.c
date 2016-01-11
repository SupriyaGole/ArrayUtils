#include <stdio.h>
#include "ArrayUtil.h"
#include <stdlib.h>
#include <string.h>

ArrayUtil create(int typeSize,int length){
	ArrayUtil sample;
	sample.base = calloc(length,typeSize);
	sample.typeSize = typeSize;
	sample.length=length;
	return sample;
}

int areEqual(ArrayUtil marks,ArrayUtil scores){
	int length=marks.length>scores.length?marks.length:scores.length;
	int takeResultOfCmp = memcmp(marks.base,scores.base,length);
	if(marks.length==scores.length && marks.typeSize == scores.typeSize && takeResultOfCmp==0)
		return 1;
	return 0;
}

ArrayUtil resize(ArrayUtil util, int length){
	int size=util.typeSize * length;
	util.base =realloc(util.base, size);
	util.length = length;
	return util;
}

int findIndex(ArrayUtil util,void *element){
	void *base = util.base;
	for(int i=0;i<util.length;i++){
		if(memcmp(base,element,util.typeSize)==0){
			return i;
		}
		base+=util.typeSize;
	};
	return -1;
}

void dispose(ArrayUtil util){
	free(util.base);
}

void *findFirst(ArrayUtil util,MatchFunc *match,void *hint){
	void *ptr = util.base;
	for(int i=0;i<util.length;i++){
		if(match(hint,ptr)==1){
			return ptr;
		}
		ptr+=util.typeSize;
	}
	return NULL;
}

void *findLast(ArrayUtil util,MatchFunc *match,void *hint){
	void *ptr = util.base;
	for(int i=0;i<util.length;i++){
		if(i==util.length-1){
			void *newPtr = ptr;
			for(int j=0;j<util.length;j++){
				if(match(hint,newPtr)==1)
					return newPtr;
				newPtr-=util.typeSize;
			}
		}
		ptr+=util.typeSize;
	}
	return NULL;
}
int count(ArrayUtil util, MatchFunc *match, void* hint){
	void *ptr = util.base;
	int count=0;
	for(int i=0;i<util.length;i++){
		if(match(hint,ptr)==1){
			count++;
		}
		ptr+=util.typeSize;
	}
	return count;
}

int filter(ArrayUtil util, MatchFunc *match, void *hint, void **destination, int maxItems){
	void *base = util.base;
	int count=0,answer=0;
	for(int i=0;i<util.length;i++){
		if(maxItems>0){
			if(match(hint,base)==1){
				*(destination+count)=base;
				answer++;
				count+=util.typeSize;
			}
			maxItems--;
			base+=util.typeSize;
		}
	}
	return answer;
}

void map(ArrayUtil source,ArrayUtil destination,ConvertFunc *convert,void *hint){
	void *sourceBase = source.base;
	void *destinationBase = destination.base;
	for(int i=0;i<source.length;i++){
		convert(hint,sourceBase,destinationBase);
		sourceBase+=source.typeSize;
		destinationBase+=destination.typeSize;
	};
}

void forEach(ArrayUtil util, OperationFunc* operation, void* hint){
	void *base = util.base;
	for(int i=0;i<util.length;i++){
		operation(hint,base);
		base+=util.typeSize;
	}
}

void *reduce(ArrayUtil util, ReducerFunc* reducer, void* hint, void* initialValue){
	void *base = util.base;
	for(int i=0;i<util.length;i++){
		void *value = reducer(hint,initialValue,base);
		initialValue = value;
		base+=util.typeSize;
	}
	return initialValue;
}

void square(void *hint,void *sourceEle,void *destinationEle){
	int Number = *(int *)sourceEle;
	int power = *(int *)hint;
	*((int *)destinationEle) = Number * Number;
};

void addNoWithHint(void *hint,void *item){
	int number = *(int *)item;
	int Hint = *(int *)hint;
	*(int *)item= number+Hint;
}

void *greaterNumber(void *hint,void *previousItem,void *item){
	int previous = *(int *)previousItem;
	int current = *(int *)item;
	return previous>current ? previousItem : item;
}

int isEven(void* hint, void* item){
	int *passedItem = (int *)item;
	return !(*passedItem%2);
};

int isDivisible(void *hint,void *item){
	int *passedItem = (int *)item;
	int *passedHint=(int *)hint;
	return !(*passedItem % *passedHint);
};





