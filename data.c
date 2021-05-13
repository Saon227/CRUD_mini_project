#include "crud.h"
#include "data.h"

void saveData(Class *c, int count){
    FILE *fp;
    fp = fopen("data.txt", "wt");
    for(int i=0; i<count; i++){
        if(c[i].credit == -1) continue;
        fprintf(fp, "%s %s %.1f %d\n", c[i].name, c[i].profname, c[i].credit, c[i].period);
    }
    fclose(fp);
    printf("=> 저장됨!\n");
}
int loadData(Class *c){
    FILE *fp;
    if(fp = fopen("data.txt", "rt")){
        int i;
        for(i=0; i<100; i++){
            fscanf(fp, "%[^\n]s", c[i].name);
            if(feof(fp)) break;
            fscanf(fp, "%[^\n]s", c[i].profname);
            fscanf(fp, "%f", &c[i].credit);
            fscanf(fp, "%d", &c[i].period);
        }
        printf("=> 로딩 성공!\n");
        fclose(fp);
        return i;
    }
    else{
        printf("=> 파일 없음\n");
        return 0;
    }
}
