#include "main.hpp"

// dijkstra算法求单源最短路径
void dijkstra_shortest_path()
{
	// 此时的book数组与之前含义不同，用来标记【已知最短路径】的集合
	// book[10]
	int dis[10];
	// 用来更新顶点到其他点的初始距离与最短距离

	// 初始化dis数组
	int length = n;
	for (size_t i = 1; i <= length; i++)
	{
		dis[i] = e[1][i];
	}

	// 初始化book数组
	for (size_t i = 1; i <= length; i++)
	{
		book[i] = 0;
	}
	// 1到自己本身为0，所有标记为已知最短路径
	book[1] = 1;

	int nearest = 0;
	for (size_t i = 1; i <= length - 1; i++)
	{
		int min = infinity;

		for (size_t j = 1; j <= length; j++)
		{
			// 遍历寻找一个距离源点最近(dis数组中最小的点)，存储到nearest
			if (book[j] == 0 && dis[j] < min)
			{
				min = dis[j];
				nearest = j;
			}
		}
		// 标记nearest点为已知最短距离
		book[nearest] = 1;

		// 扩展最近点的所有出点，并用这些出点连接的边判断是否可以更新dis数组（即“松弛”）
		for (size_t v = 1; v <= length; v++)
		{
			// 当该点有出点时
			if (e[nearest][v] < infinity)
			{
				// 类似Floyd-Warshall算法，判断有中间点时是否更短，如果更短则更新dis数组
				if (dis[v] > dis[nearest] + e[nearest][v])
				{
					dis[v] = dis[nearest] + e[nearest][v];
				}
			}
		}

	}

	for (size_t i = 1; i <= length; i++)
	{
		cout << dis[i] << " ";
	}
}