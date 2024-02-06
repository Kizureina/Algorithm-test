#include "main.hpp"

// 使用队列模拟对迷宫路径的广度优先遍历
struct note
{
	int x;
	int y;
	int step;
};
int head, tail;
note que[2500];


void find_path_by_bfs(int startx, int starty)
{
	// 初始化队列
	head = 1;
	tail = 1;

	// 起始点入队列
	que[tail].x = startx;
	que[tail].y = starty;
	que[tail].step = 0;
	tail++;

	// 标记这个点已经被遍历过
	map_book[1][1] = 1;

	int flag = 0;
	
	// 当队列不为空时循环
	while (head < tail)
	{
		int length = 4;
		for (size_t i = 0; i < length; i++)
		{
			// 尝试向四个方向遍历
			int tx = que[head].x + next_map[i][0];
			int ty = que[head].y + next_map[i][1];

			// 判断越界
			if (tx < 1 || tx > m || ty < 1 || ty > n)
			{
				continue;
			}

			// 判断是否已经遍历过或者有障碍物
			if (map_book[tx][ty] == 0 && map[tx][ty] == 0)
			{
				// 把当前遍历的点标记
				map_book[tx][ty] = 1;

				// 入队列
				que[tail].x = tx;
				que[tail].y = ty;
				que[tail].step = que[head].step + 1;
				tail++;
			}

			// 判断是否到达目标点
			if (tx == P && ty == Q)
			{
				flag = 1;
				break;
			}

			if (flag == 1)
			{
				break;
			}
		}

		// 四个方向遍历完成，说明当前点的扩展完成，移动到队列中下一个点进行遍历
		head++;
	}
	
	//cout << "最短步数为:" << que[tail - 1].step;
	minstep = que[tail - 1].step;
}
