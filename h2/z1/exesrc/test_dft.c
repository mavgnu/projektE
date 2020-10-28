#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <cmplx.h>
#include <io.h>
#include <unistd.h>
#include <fcntl.h>

#define SAMPLE 4 //prođe cijeli signal

int main(void){
	cmplx_t values[SAMPLE] = {0};
	cmplx_t *p1 = &values[0];
	for (int i = 0; i < SAMPLE; i++){
		*(p1 + i)[0] = sin(2 * M_PI * 50 * i / 200);
	}
	
	printf("ORIGINALNE VRIJEDNOSTI:\n");
	for (int i = 0; i < SAMPLE; i++){
		for (int j = 0; j < 2; j++){
			printf("%f ", values[i][j]);
		}
		printf("\n");
	}
	
	printf("DFT\n");
	
	cmplx_t final[SAMPLE] = {0};
	cmplx_t *p2 = &final[0];
	
	cmplx_dft(p1, p2, SAMPLE);
	
	
	
	int fd = open("/home/marko/Desktop/text1.txt", O_WRONLY | O_APPEND);
	
	for (int i = 0; i < SAMPLE; i++){
		for (int j = 0; j < 2; j++){
			float vrijednost = final[i][j];
			printf("Vrijednost DFT: %f\n", vrijednost);
			void *a = (void *) &vrijednost;
			int vrijednost_ieee = *((int *) a);
			int vr = (int)vrijednost;
			//printf("Vrijednost vr: %d\n", vr);
			//printf("Vrijednost int: %d\n", vrijednost_ieee);
			//printf("Pisem vrijednost\n");
			//write_word(fd, vrijednost_ieee);
			write_word(fd, vr);
		}
	}
	return 0;
}	

	
	
