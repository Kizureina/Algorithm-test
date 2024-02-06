#include "main.hpp"

void find_shortest_path_by_dfs()
{
	cout << "�����Թ�����������";
	cin >> m;
	cin >> n;

	cout << "�����ͼ";
	for (size_t i = 0; i < m; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			cin >> map[i][j];
		}
	}

	int startx, starty;
	cout << "������ʼ������:";
	cin >> startx;
	cin >> starty;

	find_path_dfs(startx, starty, 0);

	cout << "��̲���Ϊ:" << minstep;
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
		// ������-��-��-�ϵ�˳���ƶ�����
		int tx = x + next_map[i][0];
		int ty = y + next_map[i][1];

		// �ж�Խ��
		if (tx < 1 || tx > m || ty < 1 || ty > n)
		{
			continue;
		}

		// �ж��ϰ��� �� �ѱ����
		if (map[tx][ty] == 0 && map_book[tx][ty] == 0)
		{
			map_book[tx][ty] = 1;
			// �ݹ鳢����һ���㣬����������һ(ʵ���������ǵ���tx��ty��step��֮ǰ�����Ӻ��岻ͬ)
			find_path_dfs(tx, ty, step + 1);
			map_book[tx][ty] = 0;
		}

	}
	return;
}