#include "main.hpp"
int min_dis = 99999;

// ���е�ͼ�е����·��
void city_map()
{
	cout << "����ͼ�Ķ�����:";
	cin >> n;

	int length = n;
	for (size_t i = 1; i <= length; i++)
	{
		for (size_t j = 1; j <= length; j++)
		{
			if (i == j)
			{
				// 0��־�Լ����Լ�
				e[i][j] = 0;
			}
			else
			{
				// ���������û�бߣ��ȳ�ʼ��Ϊ��û������
				e[i][j] = 99999999999;
			}
		}
	}

	int m;
	cout << "�������";
	cin >> m;
	cout << "�����������ӵĶ���;���(��ÿ���ߵ�Ȩֵ):";

	length = m;
	for (int i = 1; i <= length; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		e[a][b] = c;
	}

	// ��һ�ų��г���
	book[1] = 1;
	city_map_dfs(1, 0);
	cout << "���·��Ϊ" << min_dis;
}


void city_map_dfs(int cur, int dis)
{
	// �Ż�ʱ�临�Ӷȣ���·���Ѿ������Ҫ��ʱ��ֹͣ��ǰ����
	if (dis > min_dis) 
	{
		return;
	}

	// ������Ŀ��ص�ʱ���Ƚ���̾��룬������������
	if (cur == n)
	{
		if (dis < min_dis)
		{
			min_dis = dis;
		}
		return;
	}

	int length = n;
	// ����ÿ����Ѱ�����·��
	for (size_t i = 1; i <= length; i++)
	{
		if (e[cur][i] != 99999999999 && book[i] == 0)
		{
			book[i] = 1;
			city_map_dfs(i, dis + e[cur][i]);
			// Ϊ�´�·�������������
			book[i] = 0;
		}
	}

	return;
}