#include "main.hpp"

void floyd_warshall_shortest_path()
{
	int infinity = 99999999999;
	cout << "输入图的顶点数:";
	cin >> n;

	int length = n;
	for (size_t i = 1; i <= length; i++)
	{
		for (size_t j = 1; j <= length; j++)
		{
			if (i == j)
			{
				// 0标志自己到自己
				e[i][j] = 0;
			}
			else
			{
				// 正无穷代表没有边，先初始化为都没有连接
				e[i][j] = infinity;
			}
		}
	}

	int m;
	cout << "输入边数";
	cin >> m;
	cout << "输入两个连接的顶点和距离(即每个边的权值):";

	length = m;
	for (int i = 1; i <= length; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		e[a][b] = c;
	}

	// floyd-warshall算法的核心，即从i到j且只能经过前k个点的最短路径（每到比原本小的，更新权值），
	// 遍历出可以经过每个点的最短路径
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