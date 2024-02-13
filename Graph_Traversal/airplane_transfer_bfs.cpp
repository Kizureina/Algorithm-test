#include "main.hpp"
int min_step = 100;
using namespace std;

struct city
{
	int num;
	int step;
};

// bfs�ʺϴ���ͼ�ı�Ȩֵ����ͬ�����
void min_transfer_bfs()
{
	cout << "����ڵ����ͱ���:";
	cin >> n >> m;

	// ��ʼ���ڽӾ���
	int length = n;
	for (size_t i = 1; i <= length; i++)
	{
		for (size_t j = 1; j <= length; j++)
		{
			if (j == i)
			{
				e[i][j] = 0;
			}
			else
			{
				e[i][j] = 999;
			}
		}
	}

	cout << "�������ӵĵ㣺";
	length = m;
	for (size_t i = 1; i <= length; i++)
	{
		int a, b;
		cin >> a >> b;

		e[a][b] = 1;
		e[b][a] = 1;
	}

	cout << "���������յ�:";
	int start, end;
	cin >> start >> end;

	city queue[25];
	int head, tail;
	head = 1;
	tail = 1;

	int flag = 0;

	// ��ʼ�������
	queue[tail].num = start;
	queue[tail].step = 0;
	tail++;
	book[start] = 1;

	// ��ʼ��չ
	while (head < tail)
	{
		int cur = queue[head].num;
		
		length = n;
		for (size_t i = 1; i <= length; i++)
		{
			// ������չ�ĵ����ߣ�����δ��������ʱ
			if (e[cur][i] == 1 && book[i] == 0)
			{
				// �õ������
				queue[tail].num = i;
				book[i] = 1;
				// ��ǰ���ת��������һ�����һ(�ӵ�ǰ��α���)
				queue[tail].step = queue[head].step + 1;
				tail++;
			}

			// ����չ���ĵ�����յ�ʱ����
			if (e[cur][i] == end)
			{
				// ���flag��Ϊ���˳����ѭ�������ٲ���Ҫ�ı���
				flag = 1;
				break;
			}
		}

		if (flag == 1)
		{
			break;
		}

		head++;
	}

	cout << "����ת����Ϊ:" << queue[tail - 1].step;
}