#include <stdio.h>
#include "../include/random.h"



int main(){
	randomize();
	printf("this is a test, hello world!\n");

	int number;
	for (int i = 0; i < 10; i++){
		number = randInt(0, 100);
		printf("this random number is %d\n", number);
	}
}