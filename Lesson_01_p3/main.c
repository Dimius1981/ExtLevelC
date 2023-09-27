/*
 * main.c
 *
 *  Created on: 27 сент. 2023 г.
 *      Author: Dmitriy
 */

#include <stdio.h>
#include <inttypes.h>

int extractExp(float f) {
	union {
		float f;
		struct {
			uint32_t mantissa : 23;
			uint32_t exp : 8;
			uint32_t s : 1;
		} field;
	} fl;
	fl.f = f;
	return fl.field.exp;
}

int extractExp2(float f) {
	int exp_val = 0;
	uint32_t raw_data;

	raw_data = *(uint32_t*) &f;

	//printf("raw_data f = 0x%X\n", raw_data);

	exp_val = (raw_data >> 23) & 0xff;

	return exp_val;
}

int main() {
	// 123.456 = 0b 0 10000101 11101101110100101111001
	//              S exp=133  mantissa=7793017
	float var_float = 123.456;
	int var_exp = 0, var_exp2 = 0;

	printf("Input float = %4.3f\n", var_float);

	var_exp = extractExp(var_float);
	var_exp2 = extractExp2(var_float);

	printf("extractExp() = %d\n", var_exp);
	printf("extractExp2() = %d\n", var_exp2);

	return 0;
}
