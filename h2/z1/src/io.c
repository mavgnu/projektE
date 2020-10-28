#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <io.h>

int read_word(int fd){
	char buffer[16];
	int a = read(fd, buffer, 4);
	//printf("buff_read: %s\n", buffer);
	int rval = atoi(buffer);
	return rval;
}

short read_half(int fd){
	char buffer[8];
	read(fd, buffer, 2);
	short rsval = atoi(buffer);
	return rsval;
}

void write_word(int fd, int word){
	char buffer[16]; //buffer[4] error??
	//itoa(word, buffer, 10); no reference
	sprintf(buffer, "%d", word);
	//printf("buff_write : %s\n", buffer);
	//int bb = atoi(buffer);
	//printf("int: %d\n", bb);
	write(fd, buffer, 4);
}

void write_half(int fd, short word){
	char buffer[8];
	//itoa(word, buffer, 10); ne radi
	sprintf(buffer, "%hd", word);
	write(fd, buffer, 2);
}

