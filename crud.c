#include "crud.h"

int addClass(Class *c){
    printf("수업의 이름은? ");
    scanf("%s",c->name);
    printf("교수님 성함은? ");
    scanf("%s", c->profname);
    printf("학점은? ");
    scanf("%f", &c->credit);
    printf("교시는? ");
    scanf("%d", &c->period);
    return 1;
}

void readClass(Class c){

}
int updateClass(Class *c){

}
int deleteClass(Class *c){

}
