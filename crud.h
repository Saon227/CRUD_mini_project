#ifndef _CRUD_H

#define _CRUD_H_
#include <stdio.h>

typedef struct {   
    char name[20]; // 수업명    
    char profname[20]; // 교수님 성함   
    float credit; // 학점   
    int period; // 교시   
} Class;

int addClass(Class *c);
void readClass(Class c);
int updateClass(Class *c);
int deleteClass(Class *c);

#endif
