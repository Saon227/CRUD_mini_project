#include "crud.h"
#include "data.h"

void saveData(Class *c, int count){
    FILE *fp;
    fp = fopen("data.txt", "wt");
    for(int i=0; i<count; i++){
        if(c[i].score == -1) continue;
        fprintf(fp, "%s %s %.1f %d\n", c[i].name, c[i].profname, c[i].credit, c[i].period);
    }
    fclose(fp);
    printf("=> 저장됨!\n");
}
int loadData(Class *c){

}
