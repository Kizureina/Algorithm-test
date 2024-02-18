#include "main.hpp"
int sum, n, m;
int book[101], e[101][101];
int infinity = 99999999999;

void io()
{
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
}

int main()
{
	Bellman_ford_shortest_path();

    return 0;
}
