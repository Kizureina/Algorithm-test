#include "main.hpp"

// 快速排序——最坏情况下与冒泡相同，平均时间复杂度为O(n*logn)
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
		// 当array[j]大于基准时，跳到下一个数(因为我们是正序，所以大于则无需交换，需要寻找不在正确位置的小于基准的数)
		while (array[j] >= base && i < j)
		{
			j--;
		}

		// 当array[i]小于基准时，跳到下一个数
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