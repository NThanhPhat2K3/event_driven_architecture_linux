#include <stdio.h>
#include <stdlib.h>

#include "pthread_wrapper.h"
void *test(void *arg) {
	printf("test function\n");
	for(;;)
		;
	return NULL;
}
int main() {
	thread_wrapper_t *pthread = NULL;
	pthread = (thread_wrapper_t *)malloc(sizeof(thread_wrapper_t) * 1);
	if(NULL == pthread) {
		printf(" failt to allocate");
		return -1;
	}
	pthread->entry = test;
	if(pthread_wrapper_init(pthread)) {
		printf("[OK]\n");
	}
	pthread_wrapper_start(pthread);
	while(1)
		;
	return 0;
}