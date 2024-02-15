#include "main.hpp"

void floyd_warshall_shortest_path()
{
	// floyd-warshall�㷨�ĺ��ģ�����i��j��ֻ�ܾ���ǰk��������·����ÿ����ԭ��С�ģ�����Ȩֵ����
	// ���������Ծ���ÿ��������·��
	int length = n;
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