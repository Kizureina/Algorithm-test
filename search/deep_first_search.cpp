#include "main.hpp"

int length;


// dfs�ĺ��ģ���ɵ�ǰ��һ�������г��Բ���ǣ�Ȼ�������һ��(��һ��һģһ������Ҫ�жϱ߽�)
void deep_first_serach_test()
{
	cout << "�����볤��:";
	cin >> length;
	cout << "���ܵ����:\n";
	dfs(0);
}

// ʹ��dfsģ�⽫�Ʒ�����ӵ�ȫ���У���������Ϊa[]��ÿ���Ƶı������Ϊbook[]
void dfs(int step)
{
	// ��ÿ�����Ӷ�������ʱ�����һ������
	if (step == length)
	{
		for (size_t i = 0; i < length; i++)
		{
			cout << a[i];
		}
		cout << "\n";

		// �����ݹ�
		return;
	}


	for (size_t i = 0; i < length; i++)
	{
		// ����û�б����ʱ������
		if (book[i] == 0)
		{
			// ���������
			a[step] = i;
			// ���
			book[i] = 1;
			// �ݹ鴦����һ������
			dfs(step + 1);
			// ����ǰ��ı�ǣ�����ѭ�����Լ�������
			book[i] = 0;
		}
	}
}