# if 0
#include "includes.h"

/*
void main(){
	int arr[0]; // ����ü������ ������ main�� �ȵȴ�
}*/
typedef struct {
	int age;
	char name[1];
}PERSON;

struct TEST{
	int arr[0];
};


void main(){
	PERSON *p = (PERSON*)malloc(sizeof(PERSON));
	//p->name = (char*)malloc(sizeof(strlen("kkk") + 1));
	strcpy(p->name,"KKK");
	p->age = 1;
	printf("%s, %d \n", p->name,p->age);


	//free(p->name);
	free(p);
}
#endif
#include "includes.h"

/*
void main(){
	int arr[0]; // ����ü������ ������ main�� �ȵȴ�
}*/
typedef struct {
	int age;
	char name[];
}PERSON;

struct TEST{
	int arr[0]; // C99, flexible array member : �ݵ�� ���� �������� ��ġ
};


void main(){
	PERSON *p = (PERSON*)malloc(sizeof(PERSON) + strlen("kkk") + 1);
	//p->name = (char*)malloc(sizeof(strlen("kkk") + 1));
	strcpy(p->name,"KKK");
	p->age = 1;
	printf("%s, %d \n", p->name,p->age);


	//free(p->name);
	free(p);
}
