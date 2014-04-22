#include "includes.h"

/*1¹ø*/
#define MAKE_SWAP(T) void T##_swap(T *a, T *b){ T t=*a; *a = *b; *b = t;}
typedef struct{
	char name[32];
	int age;
}PERSON;
MAKE_SWAP(int);

void swap(int *a, int *b){
	int t = *a;
	*a = *b;
	*b = t;
}


/*2¹ø*/
enum{CHAR,INT,FLOAT,DOUBLE};


/*3¹ø*/

void swap(void *a, void *b, int size){
	char *aa = (char*)a;
	char *bb = (char*)b;
	char t;
	for(int i=0;i<size;i++,aa++,bb++){
		t = *aa;
		*aa = *bb;
		*bb = t;
	}
}

int asc_int(void* a,void* b){ return *(int*)a > *(int*)b ? 1 : 0; }
int dsc_int(void* a,void* b){ return *(int*)a < *(int*)b ? 1 : 0; }
int asc_age(void *a,void *b){ 
	PERSON *p = (PERSON *)a;
	PERSON *q = (PERSON *)b;
	return p->age > q->age;
}
int asc_name(void *a,void *b){
	PERSON *p = (PERSON *)a;
	PERSON *q = (PERSON *)b;
	return strcmp(p->name, q->name) > 0;
}
void sort(void *ar, int len, int esize, int(*cmp)(void*,void*)){
	char* arr = (char*)ar;
	for(int i=0;i<len-1;i++){
		for(int j=0;j<len-1-i;j++){
			if(cmp(arr+esize*j,arr+esize*(j+1))){
				swap(arr+esize*j,arr+esize*(j+1),esize);
			}
		}
	}
}

void asc_sort(int *arr, int len){
	
	for(int i=0;i<len-1;i++){
		for(int j=0;j<len-1-i;j++){
			if(arr[j] > arr[j+1]){
				int t=0;
				t = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = t;
			}
		}
	}
}


void dsc_sort(int *arr, int len){
	
	for(int i=0;i<len-1;i++){
		for(int j=0;j<len-1-i;j++){
			if(arr[j] < arr[j+1]){
				int t=0;
				t = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = t;
			}
		}
	}
}


void display(int *arr, int len){
	for(int i = 0;i<len;i++){
		printf("%d",arr[i]);
	}
	getchar();
}

void main(){
	PERSON ar[5] = {{"aaa",1},{"iaa",9},{"haa",3},{"daa",6},{"ega",7}};

	sort(ar,5,sizeof(PERSON),asc_name);
	for(int i=0;i<5;i++){
		printf("%s,%d   ",ar[i].name,ar[i].age);
	}

	/*
	PERSON a = {"ggg",2};
	PERSON b = {"eee",3};
	int arr[10] = {5,3,6,8,3,2,1,3,4,6};


//	display(arr,10);
//	sort(arr,10,sizeof(int),asc_int);
//	display(arr,10);
//	sort(arr,10,sizeof(int),dsc_int);
//	display(arr,10);
	printf("a=%s,%d, b=%s,%d \n",a.name,a.age,b.name,b.age);
	swap(&a,&b,sizeof(PERSON));
	printf("a=%s,%d, b=%s,%d \n",a.name,a.age,b.name,b.age);
	*/


}