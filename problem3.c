#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define MAX_NUM_LENGTH 10000

void multiply_and_print(char* num1, char* num2) {
	int index1 = -1;
	int index2 = -1;

	for(int i = 0; num1[i] != '\0'; i++) {
		index1++;
	}
	for(int i = 0; num2[i] != '\0'; i++) {
		index2++;
	}
	
	int *product;

	product = calloc(MAX_NUM_LENGTH*MAX_NUM_LENGTH,sizeof(int));

//	printf("Index 1 is %d and Index 2 is %d\n", index1, index2);

	int temp;
	int prodIndex = 0;
	int carry = 0;


	for(index1; index1 >= 0; index1--) { 
		for(index2; index2 >= 0; index2--) { 
			temp = (int)(num1[index1]-'0') * (int)(num2[index2]-'0' + carry);
			if(temp >= 10) {
				carry = temp / 10
			} 
		}
	}
}

int main (int argc , char * argv []) {
	FILE *file = fopen("fake.input","r");
//	FILE *file = fopen("problem3.input","r");
	if (file == NULL) {
		printf("Input file not found.\n");
		return 1;
	}
	char num1[MAX_NUM_LENGTH];
	char num2[MAX_NUM_LENGTH];
	while(fscanf(file, "%s %s", num1, num2) == 2) {
		multiply_and_print(num1, num2);
	}
	fclose(file);	
	return 0 ;
}

