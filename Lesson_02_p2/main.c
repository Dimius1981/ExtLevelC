/*
 * main.c
 *
 *  Created on: 28 сент. 2023 г.
 *      Author: Dmitriy
 */

#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

#define SIZE 10

void print_arr(int ar[], int size) {
	for (int i = 0; i < size; i++) {
		printf("%d, ", ar[i]);
	}
	printf("\n\n");
}

void print_ptr_arr(int **ptr_arr, int size) {
	for (int i = 0; i < size; i++) {
		printf("addr = %p, val = %d\n", ptr_arr[i], *ptr_arr[i]);
	}
	printf("\n\n");
}

void create_pointer_arr(int *src_arr, int **ptr_arr, int size) {
	for (int i = 0; i < size; i++) {
		ptr_arr[i] = &src_arr[i];
	}
}

void sort_pointers(int **ptr_arr, int size) {
	char unsorted = 1;
	int *temp_ptr = NULL;

	while(unsorted) {
		unsorted = 0;
		for (int i = 0; i < size - 1; i++) {
			if (*ptr_arr[i+1] < *ptr_arr[i]) {
				temp_ptr = ptr_arr[i];
				ptr_arr[i] = ptr_arr[i+1];
				ptr_arr[i+1] = temp_ptr;
				unsorted = 1;
			}
		}
	}
}

int main() {
	int *arr_on_heap = NULL;
	int **arr_pointers = NULL;

	arr_on_heap = malloc(sizeof(int)*SIZE);
	arr_pointers = malloc(sizeof(int*)*SIZE);

	//init array
	arr_on_heap[0] = 100;
	arr_on_heap[1] = 20;
	arr_on_heap[2] = 90;
	arr_on_heap[3] = 10;
	arr_on_heap[4] = 70;
	arr_on_heap[5] = 25;
	arr_on_heap[6] = 65;
	arr_on_heap[7] = 5;
	arr_on_heap[8] = 95;
	arr_on_heap[9] = 15;

	//print source array
	printf("Source array:\n");
	print_arr(arr_on_heap, SIZE);

	//create pointer array
	create_pointer_arr(arr_on_heap, arr_pointers, SIZE);

	//print pointer array
	print_ptr_arr(arr_pointers, SIZE);

	//sort pointers array
	sort_pointers(arr_pointers, SIZE);

	//print sorted pointer array
	print_ptr_arr(arr_pointers, SIZE);

	free(arr_on_heap);
	free(arr_pointers);

	return 0;
}
