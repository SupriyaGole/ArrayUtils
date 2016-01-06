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
		ptr+=util.typeSize;
		if(i==util.length-1){
			void *newPtr = ptr;
			for(int j=0;j<util.length;j++){
				if(match(hint,newPtr)==1)
					return newPtr;
				newPtr-=util.typeSize;
			}
		}
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
		if(match(hint,base)==1){
			*(destination+count)=base;
			answer++;
			count+=util.typeSize;
		}
		base+=util.typeSize;
	}
	// int size=0;
	// for(int i=0;i<answer;i++){
	// 	void *ptr = *(destination+size);
	// 	int p=*(int *)ptr;
	// 	printf("%d\n", p);
	// 	size+=util.typeSize;
	// }
	return answer;
}




