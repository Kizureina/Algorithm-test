#include "main.hpp"

void bomb_man_dfs(int x, int y)
{
	int num = 10240;
	// getnum(x, y����ȡ��ǰ���������ĵ���

	if (num < minstep) {
		minstep = num;
	}

	int length = 4;
	for (size_t i = 0; i < length; i++)
	{
		// ��һ��������
		int tx = x + next_map[i][0];
		int ty = y + next_map[i][1];

		if (tx<0 || tx>m || ty<0 || ty>n)
		{
			continue;
		}

		if (map_book[tx][ty] == 0 && map[tx][ty] == 0)
		{
			map_book[tx][ty] = 1;
			// ÿ�εݹ鶼���ڳ��Ե��߽�ʱѭ������return����˲���Ҫ����return
			bomb_man_dfs(tx, ty);
			// �˴�����������ǣ���Ϊÿ�ζ����Ե��߽磬���������ĵ������ٴα�������Ѱ�����·����ͬ
			// map_book[tx][ty] = 0;
		}
	}
	return;
}