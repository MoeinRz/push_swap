#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
	int i, j;
	int count = 0;
	int arr_count = 0;
	int *arr;
	
	// Count the total number of integers
	for (i = 1; i < argc; i++) {
		j = 0;
		while (argv[i][j] != '\0') {
			if (argv[i][j] == ' ' || argv[i][j] == '\t') {
				j++;
				continue;
			}
			if (argv[i][j] == '+' || argv[i][j] == '-') {
				j++;
			}
			if (argv[i][j] < '0' || argv[i][j] > '9') {
				printf("Invalid character: %c\n", argv[i][j]);
				return 1;
			}
			count++;
			while (argv[i][j] >= '0' && argv[i][j] <= '9') {
				j++;
			}
		}
	}
	
	// Allocate memory for the integer array
	arr = malloc(count * sizeof(int));
	if (arr == NULL) {
		printf("Error: Unable to allocate memory.\n");
		return 1;
	}
	
	// Copy the integers into the array
	j = 0;
	for (i = 1; i < argc; i++) 
	{
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] == ' ' || argv[i][j] == '\t') {
				j++;
				continue;
			}
			int sign = 1;
			if (argv[i][j] == '+')
			{
				j++;
			}
			else if (argv[i][j] == '-')
			{
				sign = -1;
				j++;
			}
			int num = 0;
			while (argv[i][j] >= '0' && argv[i][j] <= '9') {
				num = num * 10 + (argv[i][j] - '0');
				j++;
			}
			arr[arr_count++] = num * sign;
		}
		j = 0;
	}
	
	// Print the array
	printf("The array contains:");
	for (i = 0; i < arr_count; i++)
	{
		printf(" %d", arr[i]);
	}
	printf("\n");
	
	// Free the memory and exit
	free(arr);
	return 0;
}