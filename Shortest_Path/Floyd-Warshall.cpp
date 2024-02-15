#include "main.hpp"

void floyd_warshall_shortest_path()
{
	// floyd-warshall算法的核心，即从i到j且只能经过前k个点的最短路径（每到比原本小的，更新权值），
	// 遍历出可以经过每个点的最短路径
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