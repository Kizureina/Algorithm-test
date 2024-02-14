#include "main.hpp"

void floyd_warshall_shortest_path()
{
	int infinity = 99999999999;
	cout << "����ͼ�Ķ�����:";
	cin >> n;

	int length = n;
	for (size_t i = 1; i <= length; i++)
	{
		for (size_t j = 1; j <= length; j++)
		{
			if (i == j)
			{
				// 0��־�Լ����Լ�
				e[i][j] = 0;
			}
			else
			{
				// ���������û�бߣ��ȳ�ʼ��Ϊ��û������
				e[i][j] = infinity;
			}
		}
	}

	int m;
	cout << "�������";
	cin >> m;
	cout << "�����������ӵĶ���;���(��ÿ���ߵ�Ȩֵ):";

	length = m;
	for (int i = 1; i <= length; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		e[a][b] = c;
	}

	// floyd-warshall�㷨�ĺ��ģ�����i��j��ֻ�ܾ���ǰk��������·����ÿ����ԭ��С�ģ�����Ȩֵ����
	// ���������Ծ���ÿ��������·��
	length = n;
	for (size_t k = 1; k <= length; k++)
	{
		for (size_t i = 1; i <= length; i++)
		{
			for (size_t j = 1; j <= length; j++)
			{
				if (e[i][j] > e[i][k] + e[k][j])
				{
					e[i][j] = e[i][k] + e[k][j];
				}
			}
		}
	}

	for (size_t i = 1; i <= length; i++)
	{
		for (size_t j = 1; j <= length; j++)
		{
			cout << e[i][j];
		}
		cout << "\n";
	}
}