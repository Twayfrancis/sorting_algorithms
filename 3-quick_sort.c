#include "sort.h"

/**
 * swap - Swaps two integers
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * lomuto_partition - Lomuto partition scheme for Quick sort
 * @array: The array to be sorted
 * @low: The starting index of the partition
 * @high: The ending index of the partition
 *
 * Return: The index of the pivot after partitioning
 */
int lomuto_partition(int *array, int low, int high)
{
	int pivot = array[high];
	int i = low, j;

	for (j = low; j < high - 1; j++)
	{
		if (array[j] <= pivot)
		{

			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, high + 1);
			}
			i++;
		}
	}

	if (pivot != array[i])
	{
		swap(&array[i], &array[high]);
		print_array(array, high + 1);
	}

	return (i);
}

/**
 * quicksort - Recursive function to perform Quick sort
 * @array: The array to be sorted
 * @low: The starting index of the partition
 * @high: The ending index of the partition
 */
void quicksort(int *array, int low, int high)
{
	if (low < high)
	{
		int pivot = lomuto_partition(array, low, high);

		quicksort(array, low, pivot - 1);
		quicksort(array, pivot + 1, high);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick sort
 * @array: The array to be sorted
 * @size: The size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort(array, 0, size - 1);
}
