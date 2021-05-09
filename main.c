//main.c
//

#include "crud.h"
#include "manager.h"
#include "data.h"
#include <stdio.h>

int Menu(){
    int menu;
    printf("\n*** Menu ***\n");
    printf("1. 조회\n");
    printf("2. 추가\n");
    printf("3. 수정\n");
    printf("4. 삭제\n");
    printf("5. 저장\n");
    printf("6. 검색\n");
    printf("0. 종료\n\n");
    printf("=> 원하는 메뉴는? ");
    scanf("%d", &menu);
    return menu; 
}

int main(){
    int count = 0;
    int result = 0;
    Class clist[20];
    int index =0;
    int menu;

    while(1){
        menu = Menu();
        if(menu==0) break;
        if(count > 20){
            printf("저장할 수 있는 최대 인원을 초과하였습니다.\n");
            continue;
        }
        if(menu==1 || menu==3 || menu==4)
            if(count==0){
                printf("저장된 정보가 없습니다.\n");
                continue;
            }
        if(menu==2){
            count += addClass(&clist[index++]);
        }
        else if(menu==1){
            listClass(clist, index);
        }
        else if(menu==3){
            int no = selectDataNo(clist, index);
            if(no>0) updateClass(&clist[no-1]);
            else printf("취소됨!\n");
        }
        else if(menu==4){
            int no = selectDataNo(clist, index);
            if(no>0){
                printf("정말로 삭제하시겠습니까? (삭제:1) ");
                int delok;
                scanf("%d", &delok);
                if(delok==1){
                    int isdel = deleteClass(&clist[no-1]);
                    count--;
                    if(isdel == 1) printf("삭제됨!\n");
                }
            }
            else printf("취소됨!\n");
        }
    }
    printf("종료됨!\n");

    return 0;
}
