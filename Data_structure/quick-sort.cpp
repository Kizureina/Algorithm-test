#include "main.hpp"

// 快速排序
void quick_sorting(int left, int right)
{
	int i, j, base;
	if (left > right)
	{
		return;
	}

	// base即每次交换时的【基准】
	base = array[left];
	i = left;
	j = right;

	while (i != j)
	{
		while (array[j] >= base && i < j)
		{
			j--;
		}

		while (array[i] <= base && i < j)
		{
			i++;
		}

		if (i < j)
		{
			temp = array[j];
			array[j] = array[i];
			array[i] = temp;
		}
	}

	// i与j相等时，将基准交换到正确的位置
	array[left] = array[i];
	array[i] = base;

	// 递归处理基准左边的数
	quick_sorting(left, i - 1);
	// 递归处理基准右边的数
	quick_sorting(i + 1, right);
}