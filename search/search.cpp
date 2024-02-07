#include "main.hpp"

//声明多个源文件都可以使用的全局变量
int a[10], book[10];
int map_book[50][50], map[50][50];
int m, n;
int head, tail;
int minstep = 10000;

// 方便模拟移动坐标，定义一个方向数组以获取下一步的坐标
int next_map[4][2] = {
	{0, 1}, // 向右
	{1, 0}, // 向下
	{0, -1}, // 向左
	{-1, 0} // 向上
};


int main()
{
	cout << "导入迷宫的行列数：";
	cin >> m;
	cin >> n;

	cout << "输入地图";
	for (size_t i = 0; i < m; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			cin >> map[i][j];
		}
	}

	/*
	 0 0 1 0
	 0 0 0 0
	 0 0 1 0
	 0 1 0 0
	 0 0 0 1
	*/

	int startx, starty;
	cout << "给出起始点坐标:";
	cin >> startx;
	cin >> starty;

	find_path_by_bfs(startx, starty);

	cout << "最短步数为:" << minstep;
    
    return 0;
}
