/*
 * main.c
 *
 *  Created on: 26 сент. 2023 г.
 *      Author: Dmitriy
 */

#include <stdio.h>
#include <inttypes.h>

#define SIZE_ARR 32

struct pack_array {
	uint32_t array; // массив из 0 и 1
	uint32_t count0 : 8; // количество 0 в массиве
	uint32_t count1 : 8; // количество 1 в массиве
};

struct pack_array my_struct;

int arr_items[SIZE_ARR] = {1, 0, 1, 0, 1, 0, 1, 0,
						   0, 1, 0, 1, 0, 1, 0, 1,
						   1, 0, 1, 0, 1, 0, 1, 0,
						   0, 1, 0, 1, 0, 1, 0, 1};


void array2struct(int ar[], struct pack_array *ps) {
	int count0 = 0;
	int count1 = 0;
	uint32_t arr_value = 0;

	for (int i = 0; i < SIZE_ARR; i++) {
		if (ar[i]) {
			arr_value |= (1 << i);
		    count1++;
		} else
		    count0++;
	}

	ps->array = arr_value;
	ps->count0 = count0;
	ps->count1 = count1;
}

void print_arr(int ar[], int size) {
	for (int i = 0; i < size; i++) {
		printf("%d, ", ar[i]);
		if ((i+1)%8 == 0)
				printf("\n");
	}
}

void print_bin_arr(uint32_t arr_value) {
	for (int i = 0; i < SIZE_ARR; i++) {
		printf("%d, ", (arr_value >> i)&1);
		if ((i+1)%8 == 0)
				printf("\n");
	}
}


int main() {
	print_arr(arr_items, SIZE_ARR);
	printf("\n");

	array2struct(arr_items, &my_struct);

	printf("my_struct.array:\n");
	print_bin_arr(my_struct.array);
	printf("\n");

	printf("my_struct.count0 = %d\n", my_struct.count0);
	printf("my_struct.count1 = %d\n", my_struct.count1);
	return 0;
}
