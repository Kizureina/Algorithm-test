#include "main.hpp"

// ð������
void bubble_sorting()
{
	// ��ѭ���ӵ�һ���������һ����
	for (size_t i = 0; i < n; i++)
	{
		// ��ѭ���ı߽��ǹؼ��������һ��û�б��źõ�������(�Ƚϵ���+1������-1)
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