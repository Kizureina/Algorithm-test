#include "main.hpp"
int min_dis = 99999;

// 城市地图中的最短路径
void city_map()
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
	cout << "输入两个连接的顶点和距离(即每个边的权值):";

	length = m;
	for (int i = 1; i <= length; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		e[a][b] = c;
	}

	// 从一号城市出发
	book[1] = 1;
	city_map_dfs(1, 0);
	cout << "最短路径为" << min_dis;
}


void city_map_dfs(int cur, int dis)
{
	// 优化时间复杂度，当路径已经比最短要长时，停止当前遍历
	if (dis > min_dis) 
	{
		return;
	}

	// 当到达目标地点时，比较最短距离，如果更短则更新
	if (cur == n)
	{
		if (dis < min_dis)
		{
			min_dis = dis;
		}
		return;
	}

	int length = n;
	// 遍历每个点寻找最短路径
	for (size_t i = 1; i <= length; i++)
	{
		if (e[cur][i] != 99999999999 && book[i] == 0)
		{
			book[i] = 1;
			city_map_dfs(i, dis + e[cur][i]);
			// 为下次路径尝试消除标记
			book[i] = 0;
		}
	}

	return;
}