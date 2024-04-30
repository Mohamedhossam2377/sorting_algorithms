#include "sort.h"

/**
 * merge_compare - function compare merges
 *
 * @array: array of integers
 * @start: start index
 * @stop:  stop index
 * @new: output array
 *
 * Return: void
 */
void merge_compare(int *array, size_t start, size_t stop, int *new)
{
	size_t i = start, j, k, mid;

	j = mid = (start + stop) / 2;
	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + start, mid - start);
	printf("[right]: ");
	print_array(array + mid, stop - mid);
	for (k = start; k < stop; k++)
		if (i < mid && (j >= stop || array[i] <= array[j]))
		{
			new[k] = array[i++];
		}
		else
		{
			new[k] = array[j++];
		}
	printf("[Done]: ");
	print_array(new + start, stop - start);
}

/**
 * merge_sort_top_down - function that sort top down
 *
 * @array: array of integers
 * @start: start index
 * @stop:  stop index
 * @new: output array
 *
 * Return: void
 */
void merge_sort_top_down(int *array, size_t start, size_t stop, int *new)
{
	size_t mid;

	mid = (start + stop) / 2;
	if (stop - start < 2)
	{
		return;
	}
	merge_sort_top_down(new, start, mid, array);
	merge_sort_top_down(new, mid, stop, array);
	merge_compare(array, start, stop, new);
}

/**
 * merge_sort - function that sorts an array of integers
 * in ascending order using the Merge sort algorithm
 *
 * @size: size of the list
 * @array: array of integers
 *
 * Return: void
 */
void merge_sort(int *array, size_t size)
{
	int *new;
	size_t i;

	if (!array || size < 2)
		return;

	new = malloc(sizeof(int) * size);
	if (!new)
		return;
	for (i = 0; i < size; i++)
		new[i] = array[i];
	merge_sort_top_down(new, 0, size, array);
	free(new);
}
