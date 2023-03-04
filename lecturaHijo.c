#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

int main() {
	pid_t pid;
	int integerBuffer;
	int fd;
	int n;
	int m;
	
	pid = fork();
	
	if (pid==0) {
		fd =  creat("datos.txt", 777);
		for (int i = 0; i<5; i++) {
			integerBuffer = i;
			n = write(fd, &integerBuffer, sizeof(int));
		} //end for
	} //end if
	else if (pid>0){
		fd = open("datos.txt", 0);
		printf("fd de datos.txt: %d\n", fd);
		for (int i = 1; i<6; i++) {
			m = read(fd, &integerBuffer, sizeof(int));
			printf("m de dato %d: %d\n", i, m);
			printf("dato %d: %d\n", i, integerBuffer);
		} //end for
	} //end elseif
	return 0;
} //end main
