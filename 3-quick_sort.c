#include "sort.h"

/**
 * swap - the positions of two elements into an array
 *
 * @array: array
 * @size: the size of array
 * @a: array element
 * @b: array element
 *
 * Return: void
 */
void swap(int *array, size_t size, int *a, int *b)
{
	if (*a != *b)
	{
		*a = *a + *b;
		*b = *a - *b;
		*a = *a - *b;
		print_array((const int *)array, size);
	}
}

/**
 * lomuto_partition - lomuto partition sorting scheme implementation
 *
 * @array: array
 * @size: size of array
 * @lo: first array element
 * @hi: last array element
 *
 * Return: size_t
 */
int lomuto_partition(int *array, size_t size, ssize_t lo, ssize_t hi)
{
	int i, j, pivot = array[hi];

	for (i = j = lo; j < hi; j++)
		if (array[j] < pivot)
			swap(array, size, &array[j], &array[i++]);
	swap(array, size, &array[i], &array[hi]);

	return (i);
}

/**
 * quicksort - quicksorts algorithm implementation
 *
 * @array: array
 * @lo: first array element
 * @hi: last array element
 * @size: array size
 *
 * Return: void
 */
void quicksort(int *array, size_t size, ssize_t lo, ssize_t hi)
{
	if (lo < hi)
	{
		size_t p = lomuto_partition(array, size, lo, hi);

		quicksort(array, size, lo, p - 1);
		quicksort(array, size, p + 1, hi);
	}
}

/**
 * quick_sort - prepare the terrain to quicksort algorithm
 *
 * @array: array
 * @size: array size
 *
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (!array || !size)
		return;
	quicksort(array, size, 0, size - 1);
}
