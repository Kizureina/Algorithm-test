#include "main.hpp"

void gragh_search_bfs()
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
				e[i][j] = 99999999999;
			}
		}
	}

	int m;
	cout << "输入边数";
	cin >> m;
	cout << "输入两个连接的顶点:";

	length = m;
	for (int i = 1; i <= length; i++)
	{
		int a, b;
		cin >> a >> b;

		e[a][b] = 1;
		e[b][a] = 1;
	}
	
	int queue[20];
	int tail = 1;
	int head = 1;

	queue[tail] = 1;
	tail++;
	book[1] = 1;
	
	while (head < tail)
	{
		int cur = queue[head];
		length = n;
		
		// 遍历当前点所有的边
		for (size_t i = 1; i <= length; i++)
		{
			if (e[cur][i] == 1 && book[i] == 0)
			{
				queue[tail] = i;
				tail++;
				book[i] = 1;
			}

			// 当遍历过的点大于所有点时，说明已经全部遍历完成；
			if (tail > n)
			{
				break;
				cout << "已全部遍历";
			}
		}

		head++;
	}

	length = tail;
	for (size_t i = 1; i < length; i++)
	{
		cout << queue[i] << " ";
	}
}