#include "main.hpp"

using namespace std;

void linkedList_by_array()
{
	int data[100], right[100];
	
	cout << "����������";
	int length;
	cin >> length;

	for (size_t i = 1; i <= length; i++)
	{
		cin >> data[i];
	}

	// ��ʼ���������飨��1��ʼ��������**�����0��ʼ**�����Ը������ȡ������
	for (size_t i = 1; i <= length; i++)
	{
		i != length ? right[i] = i + 1 : right[i] = 0;
	}

	// ������ĩβ���һ����
	length++;
	cin >> data[length];

	int temp = 1;
	while (temp != 0)
	{
		// ���뵽��ȷ��λ��
		if (data[right[temp]] > data[length]) 
		{
			// ����λ��ԭ�������ŵ������β�����޸Ķ�Ӧ����������
			right[length] = right[temp];
			right[temp] = length;
			break;
		}

		// ������
		temp = right[temp];
	}

	temp = 1;
	while (temp != 0)
	{
		cout << data[temp];
		// �൱������ƶ�ָ��(p=p->next)
		temp = right[temp];
	}

}