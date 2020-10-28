#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <cmplx.h>

typedef float cmplx_t[2];

int main(void){
	cmplx_t a = {2, 1};
	cmplx_t b = {0, -2};
	cmplx_t c;

	cmplx_div(a,b,c);

	for (int i=0; i < 2; i++){
		printf("%f\n", c[i]);
	}
	printf("\n");
	return 0;
}
