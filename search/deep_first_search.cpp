#include "main.hpp"

int a[10], book[10], length;

void deep_first_serach_test()
{
	cout << "�����볤��:";
	cin >> length;
	dfs(1);

}

void dfs(int step)
{
	if (step == length + 1)
	{
		// ��ʱǰstep��������������������һ������
		for (size_t i = 0; i < length; i++)
		{
			cout << a[i];
		}
		cout << "\n";
		return;
	}


	for (size_t i = 0; i < length; i++)
	{
		if (book[i] == 0)
		{
			a[step] = i;
			book[i] = 1;
		}
	}
}