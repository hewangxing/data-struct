/* 
 * descrip:  a recursion exercise, fabonacciv sequence 
 * author:   xingyes
 * date:     2017-05-01
 */

#include <stdio.h>
#include <stdlib.h>

/*long long fabonacciv(int n)
{
	if(n == 0) return 0;
	else if(n == 1) return 1;
	else return fabonacciv(n-1) + fabonacciv(n-2);
}*/

long long sequence(int n, long long t0, long long t1)
{
	if(n == 0) return t0;
	else if(n == 1) return t1;
	else return sequence(n-1, t1, t0+t1);
}

long long fabonacciv(int n)
{
	return sequence(n, 0, 1);
}

int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		fprintf(stderr, "Usage: %s N.\n", argv[0]);
		return 0;
	}
	int n = atoi(argv[1]);
	fprintf(stdout, "%d  %lld\n", n, fabonacciv(n));
	return 0;
}
