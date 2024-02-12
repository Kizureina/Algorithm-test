#include "main.hpp"


void gragh_basic_concept()
{
	int m;
	sum = 0;

	cout << "输入图的顶点数:";
	cin >> n;

	// 初始化二维矩阵以存储图(邻接矩阵存储法)
	for (size_t i = 1; i <= n; i++)
	{
		for (size_t j = 1; j <= n; j++)
		{
			if (i == j)
			{
				e[i][j] = 0;
			}
			else
			{
				// 用作正无穷，即标记两个点之间没有连接
				e[i][j] = 99999999999;
			}
		}
	}

	cout << "输入图的边数:";
	cin >> m;

	// 读入图的边数
	cout << "输入边的两个顶点";
	for (size_t i = 0; i < m; i++)
	{
		int a, b;
		cin >> a;
		cin >> b;
		e[a][b] = 1;
		e[b][a] = 1;
	}

	book[1] = 1;
	gragh_dfs(1);

}

// cur为顶点所在编号
void gragh_dfs(int cur)
{
	cout << "编号为:" << cur << endl;
	sum++;
	
	if (sum == n)
	{
		cout << "所有顶点均已遍历过";
		return;
	}

	int length = n;
	for (size_t i = 1; i <= length; i++)
	{
		// 判断当前顶点cur是否有边
		if (e[cur][i] == 1 && book[i] == 0)
		{
			book[i] = 1;
			gragh_dfs(i);
		}
	}
	return;
}