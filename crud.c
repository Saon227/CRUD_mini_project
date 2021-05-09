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
    printf("%8s %8s %.1f %4d\n",
    c.name, c.profname, c.credit, c.period);
}

int updateClass(Class *c){
    printf("수업의 이름은? ");
    scanf("%s",c->name);
    printf("교수님 섬함은? ");
    scanf("%s", c->profname);
    printf("학점은? ");
    scanf("%f", &c->credit);
    printf("교시는? ");
    scanf("%d", &c->period);
    printf("=> 수정됨!\n");
    return 1;
}

int deleteClass(Class *c){
    c->name = 'NULL';
    c->profname = 'NULL';
    c->credit = -1;
    c->period = -1;
    return 1;
}
