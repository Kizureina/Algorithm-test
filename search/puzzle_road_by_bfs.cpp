#include "main.hpp"

// ʹ�ö���ģ����Թ�·���Ĺ�����ȱ���
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
	// ��ʼ������
	head = 1;
	tail = 1;

	// ��ʼ�������
	que[tail].x = startx;
	que[tail].y = starty;
	que[tail].step = 0;
	tail++;

	// ���������Ѿ���������
	map_book[1][1] = 1;

	int flag = 0;
	
	// �����в�Ϊ��ʱѭ��
	while (head < tail)
	{
		int length = 4;
		for (size_t i = 0; i < length; i++)
		{
			// �������ĸ��������
			int tx = que[head].x + next_map[i][0];
			int ty = que[head].y + next_map[i][1];

			// �ж�Խ��
			if (tx < 1 || tx > m || ty < 1 || ty > n)
			{
				continue;
			}

			// �ж��Ƿ��Ѿ��������������ϰ���
			if (map_book[tx][ty] == 0 && map[tx][ty] == 0)
			{
				// �ѵ�ǰ�����ĵ���
				map_book[tx][ty] = 1;

				// �����
				que[tail].x = tx;
				que[tail].y = ty;
				que[tail].step = que[head].step + 1;
				tail++;
			}

			// �ж��Ƿ񵽴�Ŀ���
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

		// �ĸ����������ɣ�˵����ǰ�����չ��ɣ��ƶ�����������һ������б���
		head++;
	}
	
	//cout << "��̲���Ϊ:" << que[tail - 1].step;
	minstep = que[tail - 1].step;
}
