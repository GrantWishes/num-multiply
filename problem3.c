#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define MAX_NUM_LENGTH 10000

void multiply_and_print(char* num1, char* num2) {
	int index1 = -1;  // length of num1 -1 for indexing
	int index2 = -1;  // length of num2 -1 for indexing

	for(int i = 0; num1[i] != '\0'; i++) { // get the lengths
		index1++;
	}
	for(int i = 0; num2[i] != '\0'; i++) {
		index2++;
	}
	
	int *product; // the array the product will be put in. once again, doing it this way because I know it works

	product = calloc(MAX_NUM_LENGTH+MAX_NUM_LENGTH,sizeof(int));  // I think 20000 digits is the maximum I can get 

	int temp;                                  // holds the number to be added
	int prodIndex = 0;                         // the index of where the number goes in product[]
	int carry = 0;                             // how much the carry from the previous number is
	int maxIndex = 0;                          // so I know the end of the number
	int loopNum = 0;                           // for "adding zeros" for all iterations after #0

	// This monster does the work. Multiplies the numbers, adds them to the final product
	for(int i = index1; i >= 0; i--) {
		for(int j = index2; j >= 0; j--) {
			temp = (int)(num1[i]-'0') *(int)(num2[j]-'0') + carry; // still casting black magic
			if(temp >= 10) {                                       // if we need a carry
				carry = temp / 10;
				temp = temp % 10;
			} 
			else {                                                // otherwise we're fine
				carry = 0;
			}
			product[prodIndex] = product[prodIndex] +  temp;      // add the number to the final total (if it's > 10 we'll fix it later)
			prodIndex++;
		}

		if(carry != 0) {                                              // tacking on the carry of it's there
			product[prodIndex] = product[prodIndex] + carry;
			prodIndex++;
			carry = 0;
		}
			maxIndex = prodIndex;

		loopNum++;
		prodIndex = loopNum;
	}

	product[maxIndex] = -1;                                               // here's the end of the number


	// this takes care of any of the numbers in the array that got >10
	// moves the carry to the next number and updates the current value
	carry = 0;
	for(int i = 0; product[i] != -1; i++){
		product[i] = product[i] + carry;
		carry = 0;
		if(product[i] >= 10) {
			carry = product[i] / 10;
			product[i] = product[i] % 10;
		}	
	}

	// print the number in the corect order!
	for(int i = maxIndex-1; i>=0; i--) {	
		printf("%d",product[i]);
	}

	free(product);
	printf("\n");

}

int main (int argc , char * argv []) {
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

