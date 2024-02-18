#include "main.hpp"

//Bellman-ford�㷨���Խ���и�Ȩ�ߵ�ͼ�����·������
void Bellman_ford_shortest_path()
{
	// ����������Ĵ�С�Ǳȱ�����һ
	int u[6], v[6], w[6];

	// ������dijkstra�㷨��dis����
	int dis[10];
	// �������飬���ڼ��ĳ���ɳں�dis�����Ƿ��б仯
	int back[10];

	cin >> n >> m;

	for (size_t i = 1; i <= m; i++)
	{
		// ���붥���Ȩֵ
		cin >> u[i] >> v[i] >> w[i];
	}

	// ��ʼ��dis����
	int length = n;
	for (size_t i = 1; i <= length; i++)
	{
		dis[i] = infinity;
	}

	// ��㵽�Լ�����̾���Ϊ0
	dis[1] = 0;
	int flag = 0;// ��⸺Ȩ��·

	// Bellman-Ford�㷨���ģ�ֻ������
	// ��ѭ���ǽ������б��ɳڵ�����
	// �������൱�ڽ����������ʵ�����·�� ==> ����n������ʱ������Ϊn-1
	for (size_t i = 1; i <= n - 1; i++)
	{
		// ��ѭ���Ǹ���ÿ�������ɳ�
		for (size_t j = 1; j <= m; j++)
		{
			// ���Ե�j�����������ɳڡ�
			// ��Dijkstra���õ�����ɳڱ߲�ͬ��
			// B-F�㷨���ɳ����ñߵ������㵽��ʼ���dis[1]��dis[2]+�ߵ�Ȩֵ���Ƚϣ�
			// ���������������dis[1]��С��������ɳ�
			if (dis[v[j]] > dis[u[j]] + w[j])
			{
				dis[v[j]] = dis[u[j]] + w[j];
			}
		}
	}

	// �����n - 1���ɳ��Ժ󣬻������ɳڣ���˵���и�Ȩ��·
	for (size_t i = 1; i <= m; i++)
	{
		if (dis[v[i]] > dis[u[i]] + w[i])
		{
			flag = 1;
		}
	}

	if (flag == 1)
	{
		cout << "��ͼ���и�Ȩ��·��\n";
	}

	for (size_t i = 1; i <= length; i++)
	{
		cout << dis[i] << " ";
	}

}