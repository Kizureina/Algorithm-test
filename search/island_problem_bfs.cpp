#include "main.hpp"

// ʹ��ͷ�ļ��е�point�ṹ��ģ���ͼ�е�ÿ����
point points_queue[2501];

void find_island_width(int startx, int starty)
{
	// �������
	int sum = 0;

	// ��ʼ������
	tail = 1;
	head = 1;

	points_queue[tail].x = startx;
	points_queue[tail].y = starty;
	tail++;
	map_book[startx][starty] = 1;
	sum++;

	while (head < tail)
	{
		int length = 4;
		for (size_t i = 0; i < length; i++)
		{
			int tx = points_queue[head].x + next_map[i][0];
			int ty = points_queue[head].y + next_map[i][1];


		}
	}
}