#include <omp.h>
#include <stdio.h>

static void first()
{
	puts("Задание 1");
	printf("Последовательная область 1\n");
#pragma omp parallel
	{
		printf("Параллельная область\n");
	}
	printf("Последовательная область 2\n");
}

static void second()
{
	puts("\nЗадание 2");
	int born_thread_count = 0;

#pragma omp parallel
	{

#pragma omp atomic
		born_thread_count++;

		printf("Номер потока: %d\n", omp_get_thread_num());
	}
	printf("Число порождённых потоков: %d\n", born_thread_count);
}

int main()
{
	first();
	second();
	return 0;
}
