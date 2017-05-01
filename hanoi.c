/*
 *descrip:  a recursion exercise, solution for hanoi
 *author:   xingyes
 *date:     2017-05-01
 */
#include <stdio.h>
#include <stdlib.h>

void moveSingleStep(int disk, char A, char B, char C)
{
	static int step = 1;
	fprintf(stdout, "step%d: disk%d %c-->%c\n", step++, disk, A, C);
}

void hanoi(int n, int disk, char A, char B, char C)
{
	if(n == 1) 
		moveSingleStep(disk, A, B, C);
	else 
	{
		hanoi(n-1, disk-1, A, C, B);
		hanoi(1, disk, A, B, C);
		hanoi(n-1, disk-1, B, A, C);
	}
}

int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		fprintf(stderr, "Usage: %s N.\n", argv[0]);
		return 0;
	}
	int n = atoi(argv[1]);
	fprintf(stdout, "========hanoi(%d)\n", n);
	hanoi(n, n, 'A', 'B', 'C');
	fprintf(stdout, "========hanoi finished\n");
	return 0;
}
