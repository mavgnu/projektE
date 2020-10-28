#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <stddef.h>
#include <cmplx.h>

typedef float cmplx_t[2];

int main(void){
        cmplx_t a = {4, 2};
        cmplx_t b = {0, -4};
        cmplx_t c = {5, 0};
	cmplx_t d = {-2, -3};

	cmplx_t e;
	cmplx_t f;
	cmplx_t g;
	cmplx_t h;

	cmplx_t *p1 = &a;
	cmplx_t *p2 = &e;

        cmplx_idft(p1, p2, 4);

	for (int i=0; i < 2; i++){
                printf("%f ", e[i]);
        }
	printf("i\n");
	for (int i=0; i < 2; i++){
                printf("%f ", f[i]);
        }
	printf("i\n");
	for (int i=0; i < 2; i++){
                printf("%f ", g[i]);
        }
	printf("i\n");
	for (int i=0; i < 2; i++){
                printf("%f ", h[i]);
        }
	printf("i\n");
	printf("\n");
        return 0;
}
