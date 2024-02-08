#include "main.hpp"

point points[400];

void bomb_man_bfs(int startx, int starty)
{
	// 初始化队列
	head = 1;
	tail = 1;

	// 起始点入队列
	points[tail].x = startx;
	points[tail].y = starty;
	tail++;
	map_book[startx][starty] = 1;

	// 开始扩展
	while (head < tail)
	{
		int length = 4;
		for (size_t i = 0; i < length; i++)
		{
			// 先暂时尝试扩展，在判断边界后再入队列
			int tx = points[head].x + next_map[i][0];
			int ty = points[head].y + next_map[i][1];
			
			if (tx<0 || tx>m || ty<0 || ty>n)
			{
				continue;
			}

			if (map_book[tx][ty] == 0 && map[tx][ty] == 0)
			{
				// 标记已经走过
				map_book[tx][ty] = 1;

				// 入队列
				points[tail].x = tx;
				points[tail].y = ty;
				tail++;
			}

		}
		head++;
	}

}