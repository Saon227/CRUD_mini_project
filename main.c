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
    Class clist[20];
    int count = loadData(clist);
    int index = count;
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
	else if (menu == 5){
            saveData(clist, index);
        }
        else if(menu==6){
            int type;
            printf("어느 타입으로 검색하시겠습니까?(1: 수업명, 2: 교수명, 3: 학점) ");
            scanf("%d", &type);
            if(type==1) searchClass(clist, index);
            else if(type==2) searchProf(clist, index);
            else if(type==3) searchCredit(clist, index);
            else printf("잘못 입력하셨습니다.\n");
        }
    }
    printf("종료됨!\n");

    return 0;
}
