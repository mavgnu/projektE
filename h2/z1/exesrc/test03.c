#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <cmplx.h>

typedef float cmplx_t[2];

int main(void){
        cmplx_t a = {23, 12};
        cmplx_t b = {42, 31};
        cmplx_t c;

        double d = cmplx_mag(a);
	double e = cmplx_mag(b);

        //for (int i=0; i < 2; i++){
          //      printf("%f\n", c[i]);
        //}
	printf("%f\n", d);
	printf("%f\n", e);
	printf("\n");
        return 0;
}
