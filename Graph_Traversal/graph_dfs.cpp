#include "main.hpp"


void gragh_basic_concept()
{
	int m;
	sum = 0;

	cout << "����ͼ�Ķ�����:";
	cin >> n;

	// ��ʼ����ά�����Դ洢ͼ(�ڽӾ���洢��)
	for (size_t i = 1; i <= n; i++)
	{
		for (size_t j = 1; j <= n; j++)
		{
			if (i == j)
			{
				e[i][j] = 0;
			}
			else
			{
				// ��������������������֮��û������
				e[i][j] = 99999999999;
			}
		}
	}

	cout << "����ͼ�ı���:";
	cin >> m;

	// ����ͼ�ı���
	cout << "����ߵ���������";
	for (size_t i = 0; i < m; i++)
	{
		int a, b;
		cin >> a;
		cin >> b;
		e[a][b] = 1;
		e[b][a] = 1;
	}

	book[1] = 1;
	gragh_dfs(1);

}

// curΪ�������ڱ��
void gragh_dfs(int cur)
{
	cout << "���Ϊ:" << cur << endl;
	sum++;
	
	if (sum == n)
	{
		cout << "���ж�����ѱ�����";
		return;
	}

	int length = n;
	for (size_t i = 1; i <= length; i++)
	{
		// �жϵ�ǰ����cur�Ƿ��б�
		if (e[cur][i] == 1 && book[i] == 0)
		{
			book[i] = 1;
			gragh_dfs(i);
		}
	}
	return;
}