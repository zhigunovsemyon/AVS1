#include <omp.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

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

static void third()
{
	puts("\nЗадание 3");
	printf("OMP_NUM_THREADS = %s\n", getenv("OMP_NUM_THREADS"));

#pragma omp parallel // OMP_NUM_THREADS
	puts("Параллельный регион 1");

#pragma omp parallel num_threads(3)
	puts("Параллельный регион 2");

	omp_set_num_threads(4);
#pragma omp parallel // fn ^^^
	puts("Параллельный регион 3");
}

static void fourth(bool dynamic)
{
	printf("\nЗадание 4. Динамический режим %s\n",
	       dynamic ? "включен" : "выключен");

	omp_set_dynamic(dynamic);
#pragma omp parallel num_threads(128)
	{
#pragma omp master
		printf("Число потоков: %d\n", omp_get_num_threads());
	}
}

int main()
{
	first();
	second();
	third();
	fourth(false);
	fourth(true);
	return 0;
}
