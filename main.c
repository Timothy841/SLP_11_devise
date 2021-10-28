#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <time.h>
#include <fcntl.h>
#include <unistd.h>

void random_int(int *a, int size){
	int f = open("/dev/random", O_RDONLY);
	read(f, a, size*sizeof(a[0]));
}

void print_array(int *a, int size){
	for (int i = 0; i<size; i++){
		printf("random %d: %d\n", i, a[i]);
	}
	printf("\n");
}


int main(){
	srand(time(NULL));
	int file;
	unsigned int a[10];
	random_int(a, 10);
	printf("Original numbers\n");
	print_array(a, 10);
	file = open("foo.txt", O_WRONLY, 0700);
	if (file == -1){
		printf("Cannot open file.\n");
	}
	printf("Writing to file\n\n");
	if (write(file, a, 40) == -1){
		printf("Cannot write to file\n");
	}
	close(file);
	unsigned int b[10];
	file = open("foo.txt", O_RDONLY, 0700);
	if (file == -1){
		printf("Cannot open file.\n");
	}
	printf("Reading file\n\n");
	if (read(file, b, 40) == -1){
		printf("Cannot read file\n");
	}
	printf("Second array\n");
	print_array(b, 10);
	close(file);
}
