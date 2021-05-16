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

void searchClass(Class *c, int count){
    int scnt = 0;
    char search[20];
    printf("검색할 수업은? ");
    scanf("%s", search);
    printf("No ClassName          Professor   Credit Period\n============================================\n");
    for(int i =0; i <count ; i++){
        if(c[i].credit == 0) 
		continue;
        if(strstr(c[i].name, search)){
            printf("%2d ", i+1);
            readClass(c[i]);
            scnt++;
        }
    }
    if(scnt == 0) printf("=> 검색된 데이터 없음!");
    printf("\n");
}

void searchProf(Class *c, int count){
    int scnt = 0;
    char search[20];
    printf("검색할 교수님은? ");
    scanf("%s", search);
    printf("No ClassName          Professor   Credit Period\n============================================\n");
    for(int i =0; i <count ; i++){
        if(c[i].credit == 0)
                continue;
        if(strstr(c[i].profname, search)){
            printf("%2d ", i+1);
            readClass(c[i]);
            scnt++;
        }
    }
}

