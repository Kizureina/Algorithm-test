#include "main.hpp"

void bomb_man_dfs(int x, int y)
{
	int num = 10240;
	// getnum(x, y）获取当前点可以消灭的敌人

	if (num < minstep) {
		minstep = num;
	}

	int length = 4;
	for (size_t i = 0; i < length; i++)
	{
		// 下一个点坐标
		int tx = x + next_map[i][0];
		int ty = y + next_map[i][1];

		if (tx<0 || tx>m || ty<0 || ty>n)
		{
			continue;
		}

		if (map_book[tx][ty] == 0 && map[tx][ty] == 0)
		{
			map_book[tx][ty] = 1;
			// 每次递归都会在尝试到边界时循环结束return，因此不需要单独return
			bomb_man_dfs(tx, ty);
			// 此处无需消除标记，因为每次都尝试到边界，被遍历过的点无需再次遍历，与寻找最短路径不同
			// map_book[tx][ty] = 0;
		}
	}
	return;
}