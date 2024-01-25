#include "main.hpp"

// �������򡪡���������ð����ͬ��ƽ��ʱ�临�Ӷ�ΪO(n*logn)
void quick_sorting(int left, int right)
{
	int i, j, base;
	if (left > right)
	{
		return;
	}

	// base��ÿ�ν���ʱ�ġ���׼��
	base = array[left];
	i = left;
	j = right;

	while (i != j)
	{
		// ��array[j]���ڻ�׼ʱ��������һ����(��Ϊ�������������Դ��������轻������ҪѰ�Ҳ�����ȷλ�õ�С�ڻ�׼����)
		while (array[j] >= base && i < j)
		{
			j--;
		}

		// ��array[i]С�ڻ�׼ʱ��������һ����
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

	// i��j���ʱ������׼��������ȷ��λ��
	array[left] = array[i];
	array[i] = base;

	// �ݹ鴦���׼��ߵ���
	quick_sorting(left, i - 1);
	// �ݹ鴦���׼�ұߵ���
	quick_sorting(i + 1, right);
}