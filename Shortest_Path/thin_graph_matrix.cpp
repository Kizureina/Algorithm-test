#include "main.hpp"

// ����ʵ���ڽӱ�洢ͼ
void near_contact_matrix()
{
	// ����������Ĵ�С�Ǳȱ�����һ
	int u[6], v[6], w[6];
	// ����������Ĵ�С�Ǳȶ�������һ
	int first[5], next[5];
	
	cin >> n >> m;

	// ��ʼ����-1��ʾû�б�����
	int length = n;
	for (size_t i = 1; i <= length; i++)
	{
		first[i] = -1;
	}

	for (size_t i = 1; i <= m; i++)
	{
		// ���붥���Ȩֵ
		cin >> u[i] >> v[i] >> w[i];

		// �ؼ�
		next[i] = first[u[i]];
		// next[i]�洢���Ϊi�ıߵġ���һ���ߡ��ı��

		first[u[i]] = i;
		// first[u[i]]�洢����u[i]��һ���ߵı��
	}

	// ��ʱ�ڽӱ��Ѿ��������

	// �����ڽӱ�
	for (size_t i = 1; i <= length; i++)
	{
		int k = first[i];
		while (k != -1)
		{
			cout << u[k] << " " << v[k] << " " << w[k] << "\n";
			k = next[k];
		}
	}
}