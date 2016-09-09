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
	int maxIndex = 0;
	int loopNum = 0;

	for(int i = index1; i >= 0; i--) {
//		printf("This is loop number %d\n",loopNum); 
		for(int j = index2; j >= 0; j--) {
//			printf("Indices: %d %d\n", i, j);
			temp = (int)(num1[i]-'0') *(int)(num2[j]-'0') + carry;
		//	printf("Value: %c %c %d Total: %d \n",num1[i],num2[j],carry, temp);
			if(temp >= 10) {
				carry = temp / 10;
				temp = temp % 10;
			} 
			else {
				carry = 0;
			}
		//	printf("Appending: %d at index %d\n", temp, prodIndex);
			product[prodIndex] = product[prodIndex] +  temp;
			prodIndex++;
		}

		if(carry != 0) {
		//	printf("Appending: %d at index %d\n",  carry, prodIndex);
			product[prodIndex] = product[prodIndex] + carry;
			prodIndex++;
			carry = 0;
		}
//		if((prodIndex+loopNum) > maxIndex) {
			maxIndex = prodIndex;
//		}

		loopNum++;
		prodIndex = loopNum;
	}

//	printf("MaxIndex = %d\n", maxIndex);	
	product[maxIndex] = -1;


	carry = 0;
	for(int i = 0; product[i] != -1; i++){
		product[i] = product[i] + carry;
		carry = 0;
		if(product[i] >= 10) {
			carry = product[i] / 10;
			product[i] = product[i] % 10;

		}	


	}


	int endIndex; 
	// temp below here
	for(int i = maxIndex-1; i>=0; i--) {	
		printf("%d",product[i]);
	}
	free(product);
	printf("\n");
}

int main (int argc , char * argv []) {
//	FILE *file = fopen("fake.input","r");
	FILE *file = fopen("problem3.input","r");
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

