//main.c
//
#include <stdio.h>

int main(){
	int count = 0;
	int result = 0;
	Class clist[20];
	int index =0;

	count += addClass(&clist[index++]);
	printf("번호 수업 교수님 학점 교시\n");

	for(int i =0; i <count ; i++){
		if(clist[i].credit == 0) continue;
		printf("%2d ", i+1);
		readClass(clist[i]);
	}

	printf("\n");
	updateClass(&clist[index-1]);

	for(int i =0; i <count ; i++){
		if(clist[i].credit == 0) continue;
		printf("%2d ", i+1);
		readClass(clist[i]);
	}
	return 0;
}
