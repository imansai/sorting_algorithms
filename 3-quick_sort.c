#include "sort.h"

void swap_ints(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * swap_ints - Swaps two ints in array.
 * @a: First int to be swapped.
 * @b: Second int to be swapped.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * lomuto_partition - Partitions a subset of an array of ints using
 *                    the Lomuto Partition Scheme.
 * @array: Array of ints.
 * @size: Array size.
 * @left: Start index of the subset to be ordered.
 * @right: End index of the subset to be ordered.
 *
 * Return: Final partition index.
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *driver, up, down;

	driver = array + right;
	for (up = down = left; down < right; down++)
	{
		if (array[down] < *driver)
		{
			if (up < down)
			{
				swap_ints(array + down, array + up);
				print_array(array, size);
			}
			up++;
		}
	}

	if (array[up] > *driver)
	{
		swap_ints(array + up, driver);
		print_array(array, size);
	}

	return (up);
}

/**
 * lomuto_sort - Recursive implementation of the Lomuto Scheme.
 * @array: Array of ints to be sorted.
 * @size: Array size.
 * @left: Start index of the partition to be ordered.
 * @right: End index of the partition to be ordered.
 *
 * Description: Uses the Lomuto Partition Scheme.
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int belong;

	if (right - left > 0)
	{
		belong = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, belong - 1);
		lomuto_sort(array, size, belong + 1, right);
	}
}

/**
 * quick_sort - Sorts an array of ints in ascending
 *              order using the quicksort algorithm.
 * @array: Array of ints.
 * @size: Array size.
 *
 * Description: Uses the Lomuto Partition Scheme to print
 *              array after every swap of two elements.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}

