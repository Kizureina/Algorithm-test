#include "main.hpp"
#include <string.h>

struct stack
{
	char string[101] = { 0 };
	int top = 0;
};

// ʹ��ջ�жϻ���

bool stack_test_echo_word()
{
	struct stack s;
	char str[101] = { 0 };

	s.top = 0;
	std::cin >> str;

	int len = strlen(str);
	int mid = len / 2 - 1;

	// �����м��ַ�Ϊֹ���ַ���ջ
	for (size_t i = 0; i <= mid; i++)
	{
		// �˴�����ջ����һ����ջ���ܽ���˳�򣬷��������s.string[s.top]��ȡ����ֵ
		s.top++;
		s.string[s.top] = str[i];
	}

	int next; // nextΪ��ʼƥ��Ƚϵ��ַ�
	len % 2 == 0 ? next = mid + 1 : next = mid + 2;

	for (size_t i = next; i < len; i++)
	{
		if (s.string[s.top] != str[i])
		{
			break;
		}
		s.top--;
	}

	if (s.top == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}