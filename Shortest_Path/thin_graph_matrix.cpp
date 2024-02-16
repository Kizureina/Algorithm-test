#include "main.hpp"

// 数组实现邻接表存储图
void near_contact_matrix()
{
	// 这三个数组的大小是比边数大一
	int u[6], v[6], w[6];
	// 这两个数组的大小是比顶点数大一
	int first[5], next[5];
	
	cin >> n >> m;

	// 初始化，-1表示没有边连接
	int length = n;
	for (size_t i = 1; i <= length; i++)
	{
		first[i] = -1;
	}

	for (size_t i = 1; i <= m; i++)
	{
		// 读入顶点和权值
		cin >> u[i] >> v[i] >> w[i];

		// 关键
		next[i] = first[u[i]];
		// next[i]存储编号为i的边的“下一条边”的编号

		first[u[i]] = i;
		// first[u[i]]存储顶点u[i]第一条边的编号
	}

	// 此时邻接表已经建立完成

	// 遍历邻接表
	for (size_t i = 1; i <= length; i++)
	{
		int k = first[i];
		while (k != -1)
		{
			cout << u[k] << " " << v[k] << " " << w[k] << "\n";
			k = next[k];
		}
	}
}