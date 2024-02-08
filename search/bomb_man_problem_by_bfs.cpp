#include "main.hpp"

point points[400];

void bomb_man_bfs(int startx, int starty)
{
	// ��ʼ������
	head = 1;
	tail = 1;

	// ��ʼ�������
	points[tail].x = startx;
	points[tail].y = starty;
	tail++;
	map_book[startx][starty] = 1;

	// ��ʼ��չ
	while (head < tail)
	{
		int length = 4;
		for (size_t i = 0; i < length; i++)
		{
			// ����ʱ������չ�����жϱ߽���������
			int tx = points[head].x + next_map[i][0];
			int ty = points[head].y + next_map[i][1];
			
			if (tx<0 || tx>m || ty<0 || ty>n)
			{
				continue;
			}

			if (map_book[tx][ty] == 0 && map[tx][ty] == 0)
			{
				// ����Ѿ��߹�
				map_book[tx][ty] = 1;

				// �����
				points[tail].x = tx;
				points[tail].y = ty;
				tail++;
			}

		}
		head++;
	}

}