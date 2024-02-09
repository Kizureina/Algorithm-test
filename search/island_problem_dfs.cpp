#include "main.hpp"
int island_sum;

void find_width_dfs(int startx,int starty)
{
	island_sum = 1;
	island_dfs(startx, starty);
}


void island_dfs(int x, int y)
{
	int length = 4;
	for (size_t i = 0; i < length; i++)
	{
		int tx = x + next_map[i][0];
		int ty = y + next_map[i][1];

		if (tx > m || tx<1 || ty>n || ty < 1)
		{
			continue;
		}

		if (map[tx][ty] == 0 && map_book[tx][ty] == 0)
		{
			island_sum++;
			map_book[tx][ty] == 1;
			island_dfs(tx, ty);
		}
	}
	return;
}
