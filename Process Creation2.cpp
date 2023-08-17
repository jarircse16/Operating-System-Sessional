#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main(int argc, char *argv[])
{


	int a=100;
	int id1=fork();
	int id2=fork();
	printf("%d\n");
	return 0;
}
