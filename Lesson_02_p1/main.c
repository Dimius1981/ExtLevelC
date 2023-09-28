/*
 * main.c
 *
 *  Created on: 28 сент. 2023 г.
 *      Author: Dmitriy
 */

#include <stdio.h>
#include <inttypes.h>

void swap(int **p1, int **p2) {
	int *ptemp = *p1;
	*p1 = *p2;
	*p2 = ptemp;
}



int main() {
	int a = 100;
	int b = 200;
	int *pa = &a;
	int *pb = &b;

	printf("value a = %d, pointer pa = %p, address a = %p\n", a, pa, &a);
	printf("value b = %d, pointer pb = %p, address b = %p\n\n", b, pb, &b);

	printf("Swapping...\n\n");
	swap(&pa, &pb);

	printf("value a = %d, pointer pa = %p, address a = %p\n", a, pa, &a);
	printf("value b = %d, pointer pb = %p, address b = %p\n\n", b, pb, &b);

	return 0;
}
