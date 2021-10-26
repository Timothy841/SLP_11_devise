#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <time.h>
#include <fcntl.h>

void random_int(int *a, int size){
	for (int i = 0; i<size; i++){
		a[i] = rand();
	}
}

void print_array(int *a, int size){
	for (int i = 0; i<size; i++){
		printf("random %d: %d\n", i, a[i]);
	}
}


int main(){
	srand(time(NULL));
	int a[5];
	random_int(a, 5);
	print_array(a, 5);
	FILE *file = fopen("foo.txt", "w");
	fwrite(a,sizeof(int),5,file);
	fclose(file);
	file = fopen("foo.txt", "r");
	fread(a,sizeof(int),5,file);
	print_array(a, 5);
}


