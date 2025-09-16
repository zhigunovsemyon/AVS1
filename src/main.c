#include <omp.h>
#include <stdio.h>

static void first()
{
	printf("Последовательная область 1\n");
#pragma omp parallel
	{
		printf("Параллельная область\n");
	}
	printf("Последовательная область 2\n");
}

int main()
{
	first();
	return 0;
}
