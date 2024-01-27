#include "main.hpp"
#include <string.h>

struct stack
{
	char string[101] = { 0 };
	int top = 0;
};

// 使用栈判断回文

bool stack_test_echo_word()
{
	struct stack s;
	char str[101] = { 0 };

	s.top = 0;
	std::cin >> str;

	int len = strlen(str);
	int mid = len / 2 - 1;

	// 将到中间字符为止的字符入栈
	for (size_t i = 0; i <= mid; i++)
	{
		// 此处的先栈顶加一再入栈不能交换顺序，否则下面的s.string[s.top]会取到空值
		s.top++;
		s.string[s.top] = str[i];
	}

	int next; // next为开始匹配比较的字符
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