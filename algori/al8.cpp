#include "includes.h"

#if 0
typedef struct{
	char name[32];
	int age;
} PERSON;

typedef struct{
	int count;
	PERSON *p;
} MEMBER;

void input_person(MEMBER *member){
	char name[32];
	int age, count = member->count;
	PERSON *p;

	printf("input your name : "); scanf("%s",name);
	printf("input your age : "); scanf("%d",&age);

	if(count == 0){
		p = (PERSON*)malloc(sizeof(PERSON));
		strcpy(p->name,name);
		p->age = age;
		member->p = p;
		member->count++;
	}else{
		p = (PERSON*)realloc(member->p, sizeof(PERSON)*(count+1));
		strcpy(p[count].name,name);
		p[count].age = age;
		member->p = p;
		member->count++;
	}
}

void display(MEMBER *member){
	PERSON *p = member->p;
	system("cls");

	for(int i=0;i<member->count;i++){
		printf("%2d. %s(%d)\n",i+1,p[i].name,p[i].age);
	}
	getchar();
}

void main(){
	MEMBER member = {0,};

	for(int i=0;i<5;i++){
		input_person(&member);
		display(&member);
	}
}

#endif


typedef struct{
	char name[32];
	int age;
} PERSON;

typedef struct{
	int count;
	PERSON p[0];
} MEMBER;

void create_pool(MEMBER **member, int size){
	*member = (MEMBER*)malloc(size);
	(*member)->count = 0;
}

void input_person(MEMBER *member){
	/*
	char name[32];
	int age, count = member->count;
	PERSON *p;

	printf("input your name : "); scanf("%s",name);
	printf("input your age : "); scanf("%d",&age);

	
	if(count == 0){
		p = (PERSON*)malloc(sizeof(PERSON));
		strcpy(p->name,name);
		p->age = age;
		member->p = p;
		member->count++;
	}else{
		p = (PERSON*)realloc(member->p, sizeof(PERSON)*(count+1));
		strcpy(p[count].name,name);
		p[count].age = age;
		member->p = p;
		member->count++;
	}
	*/

	PERSON *p = member->p;
	int count = member->count;
	printf("input your name : "); scanf("%s",p[count].name);
	printf("input your age : "); scanf("%d",&p[count].age);
	member->count++;
}

void display(MEMBER *member){
	PERSON *p = member->p;
	system("cls");

	for(int i=0;i<member->count;i++){
		printf("%2d. %s(%d)\n",i+1,p[i].name,p[i].age);
	}
	getchar();
}

void main(){

	MEMBER *member;
	create_pool(&member, 4096); // 4k

	for(int i=0;i<5;i++){
		input_person(member);
		display(member);
	}
}