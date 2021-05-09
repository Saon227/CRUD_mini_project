#include "crud.h"
#include "manager.h"

void listClass(Class *c, int count){
    printf("No ClassName          Professor   Credit Period\n============================================\n");
    for(int i=0; i<count; i++){
        if(c[i].credit == -1) continue;
	printf("%2d ", i+1);
	readClass(c[i]);
    }
}

int selectDataNo(Class *c, int count){
    listClass(c, count);
    int num;
    printf("\n번호는 (취소 :0)? ");
    scanf("%d", &num);
    return num;
}
