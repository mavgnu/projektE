#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <cmplx.h>
#include <io.h>
#include <unistd.h>
#include <fcntl.h>

#define SAMPLE 4 //prođe cijeli signal

int main(void){
	int fd = open("/home/marko/Desktop/text1.txt", O_RDONLY);
	printf("IDFT\n");
	
	
	cmplx_t values[SAMPLE] = {0};
	cmplx_t *p1 = &values[0];
	
	for (int i = 0; i < SAMPLE; i++){
		for (int j = 0; j < 2; j++){
			int vrijednost_ieee = read_word(fd);
			//printf("word: %d\n", vrijednost_ieee);
			void *a = (void *) &vrijednost_ieee;
			float vrijednost = *((float *) a);
			//values[i][j] = vrijednost;
			values[i][j] = (float) vrijednost_ieee;
			printf("Citanje DFT iz datoteke: %f\n", values[i][j]);
		}
	}
	
	cmplx_t final[SAMPLE] = {0};
	cmplx_t *p2 = &final[0];
	
	cmplx_idft(p1, p2, 4);
	
	printf("ORIGINALA VRIJENOST INVERZOM:\n");
	
	printf("%f, %f\n", final[0][0], final[0][1]);
	printf("%f, %f\n", final[1][0], final[1][1]);
	printf("%f, %f\n", final[2][0], final[2][1]);
	printf("%f, %f\n", final[3][0], final[3][1]);
	printf("\n");
	
	return 0;
}
