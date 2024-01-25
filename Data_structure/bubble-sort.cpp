#include "main.hpp"

// 冒泡排序
void bubble_sorting()
{
	// 外循环从第一个数到最后一个数
	for (size_t i = 0; i < n; i++)
	{
		// 内循环的边界是关键，到最后一个没有被排好的数即可(比较的是+1，所以-1)
		for (size_t j = 0; j < n - i - 1; j++)
		{
			if (array[j + 1] < array[j])
			{
				temp = array[j + 1];
				array[j + 1] = array[j];
				array[j] = temp;
			}
		}
	}
}