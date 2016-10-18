#include<stdio.h>

struct test
{
	int id;
	char *name;
};


int main()
{
	struct test stud1;
	struct test *pStud1;
	pStud1=&stud1;
	stud1.id=12345;
	stud1.name="Muhammad";
	printf("id :%d \n",pStud1->id);
	printf("name :%s \n",pStud1->name);
}
