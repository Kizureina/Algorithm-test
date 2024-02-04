#include "main.hpp"

int total = 0;

void getAnswer_by_dfs()
{
	depth_first_search_for_answer(1);
	cout << "���еĿ�����Ϊ" << total / 2;
}

void depth_first_search_for_answer(int step)
{
	if (step == 10)
	{
		if (a[1] * 100 + a[2] * 10 + a[3] + a[4] * 100 + a[5] * 10 + a[6] == a[7] * 100 + a[8] * 10 + a[9])
		{
			total++;
			cout << a[1] << a[2] << a[3] << "+" << a[4] << a[5] << a[6] << "=" << a[7] << a[8] << a[9];
			cout << "\n";
		}
	}

	for (size_t i = 1; i <= 9; i++)
	{
		if (book[i] == 0)
		{
			// ��������������㷨�ľ���
			a[step] = i;
			book[i] = 1;
			depth_first_search_for_answer(step + 1);
			book[i] = 0;
		}
	}
}