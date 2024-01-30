#include "main.hpp"

using namespace std;

void linkedList_by_array()
{
	int data[100], right[100];
	
	cout << "输入链表长度";
	int length;
	cin >> length;

	for (size_t i = 1; i <= length; i++)
	{
		cin >> data[i];
	}

	// 初始化索引数组（以1开始遍历，而**避免从0开始**，可以更方便获取索引）
	for (size_t i = 1; i <= length; i++)
	{
		i != length ? right[i] = i + 1 : right[i] = 0;
	}

	// 在数组末尾添加一个数
	length++;
	cin >> data[length];

	int temp = 1;
	while (temp != 0)
	{
		// 插入到正确的位置
		if (data[right[temp]] > data[length]) 
		{
			// 将该位置原本的数放到数组结尾，并修改对应的索引数组
			right[length] = right[temp];
			right[temp] = length;
			break;
		}

		// 向后遍历
		temp = right[temp];
	}

	temp = 1;
	while (temp != 0)
	{
		cout << data[temp];
		// 相当于向后移动指针(p=p->next)
		temp = right[temp];
	}

}