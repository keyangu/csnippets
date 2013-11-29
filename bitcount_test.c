#include <stdio.h>

/**
 * 立っているビットの数を数える
 *
 * 高速らしい
 */
int numofbits(long bits)
{
	bits = (bits & 0x55555555) + (bits >> 1 & 0x55555555);
	printf("1:%08lX\r\n", bits);
	bits = (bits & 0x33333333) + (bits >> 2 & 0x33333333);
	printf("2:%08lX\r\n", bits);
	bits = (bits & 0x0f0f0f0f) + (bits >> 4 & 0x0f0f0f0f);
	printf("3:%08lX\r\n", bits);
	bits = (bits & 0x00ff00ff) + (bits >> 8 & 0x00ff00ff);
	printf("4:%08lX\r\n", bits);
	bits = (bits & 0x0000ffff) + (bits >> 16 & 0x0000ffff);
	printf("5:%08lX\r\n", bits);
	return bits;
}

int main(void)
{
	long bits[] = {
		0xFFFFFFFF,
		0x00001000,
		0x55555555,
		0x12345678
	};
	int i;

	for (i = 0; i < sizeof(bits) / sizeof(bits[0]); i++) {
		printf("c[%d]%08lX -> %d\r\n", i, bits[i], numofbits(bits[i]));
	}

	return 0;
}
