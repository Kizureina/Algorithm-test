#include "main.hpp"

void find_shortest_path_by_dfs()
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

	int startx, starty;
	cout << "给出起始点坐标:";
	cin >> startx;
	cin >> starty;

	find_path_dfs(startx, starty, 0);

	cout << "最短步数为:" << minstep;
	return;
}



void find_path_dfs(int x,int y, int step)
{
	if (x == P && y == Q)
	{
		if (step < minstep)
		{
			minstep = step;
		}
		return;
	}


	int length = 4;
	for (size_t i = 0; i < length; i++)
	{
		// 根据右-下-左-上的顺序移动坐标
		int tx = x + next_map[i][0];
		int ty = y + next_map[i][1];

		// 判断越界
		if (tx < 1 || tx > m || ty < 1 || ty > n)
		{
			continue;
		}

		// 判断障碍物 或 已被标记
		if (map[tx][ty] == 0 && map_book[tx][ty] == 0)
		{
			map_book[tx][ty] = 1;
			// 递归尝试下一个点，并将步数加一(实际上这里标记的是tx和ty，step与之前的例子含义不同)
			find_path_dfs(tx, ty, step + 1);
			map_book[tx][ty] = 0;
		}

	}
	return;
}