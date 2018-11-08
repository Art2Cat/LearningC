#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <inttypes.h>

#define BUFF 128

char * encode_mem_address(void * x) {
	char * str = (char*) malloc(BUFF * sizeof(char));
	sprintf(str, "%p\n", x);
	return str;
}

void * decode_mem_address(char * str) {
	unsigned long ul;
	sscanf(str, "%lx", &ul);
	return (void *) (uintptr_t)ul;
}

int main() {

	int x = 1111;
	char tmp[BUFF];
	sprintf(tmp, "%p\n", &x);
	printf("%s\n", tmp);

	unsigned long ul;
	sscanf(tmp, "%lx", &ul);

	int * y = (int*)(uintptr_t) ul;
	printf("%d\n", *y);

	int a = 1024;
	char* buf = encode_mem_address((void*)&a);
	printf("%s\n", buf);

	void * z = decode_mem_address(buf);
	printf("%d\n", *(int *)z);


	return 0;
}

