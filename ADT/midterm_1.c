#include<stdio.h>
#include<stdlib.h>

typedef struct info {
    char name[20];
    int age;
} info_type; // 24 bytes

typedef union data {
    int myInt;
    char myString[100];
} data_type; // 100 bytes

typedef struct myStruct {
    info_type myInfo[15];
    data_type myData[20];
} type_abc; // 24*15 + 100*20 = 2,360 bytes

int main(){
	type_abc *p = (type_abc*)calloc(sizeof(type_abc), 50);
	int *init_p_position = p;
	printf("sizeof(p) = %d\n", sizeof(*p));
	printf("&p[0] = %p (%d)\n", &p[0], &p[0]);
	printf("&p[1] = %p (%d)\n", &p[1], &p[1]);
	printf("&p[1]-&p[0] = %p (%d)\n", (int)&p[1]-(int)&p[0], (int)&p[1]-(int)&p[0]);
    printf("p[13] -> myInfo[2] -> name is %d(250 added)\n",(int)&p[13].myInfo[2].name-(int)&p[0]+250);
    printf("p[21] -> myData[12] -> myString[18] is %d(250 added)\n",(int)&p[21].myData[12].myString[18]-(int)&p[0]+250);

}
