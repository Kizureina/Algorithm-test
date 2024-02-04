#include "main.hpp"

int length;


// dfs的核心：完成当前这一步的所有尝试并标记，然后进入下一步(下一步一模一样，但要判断边界)
void deep_first_serach_test()
{
	cout << "请输入长度:";
	cin >> length;
	cout << "可能的组合:\n";
	dfs(0);
}

// 使用dfs模拟将牌放入盒子的全排列：盒子数组为a[]，每张牌的标记数组为book[]
void dfs(int step)
{
	// 当每个盒子都放入牌时，输出一种排列
	if (step == length)
	{
		for (size_t i = 0; i < length; i++)
		{
			cout << a[i];
		}
		cout << "\n";

		// 结束递归
		return;
	}


	for (size_t i = 0; i < length; i++)
	{
		// 当牌没有被标记时，可以
		if (book[i] == 0)
		{
			// 放入盒子中
			a[step] = i;
			// 标记
			book[i] = 1;
			// 递归处理下一个盒子
			dfs(step + 1);
			// 消除前面的标记，以让循环可以继续遍历
			book[i] = 0;
		}
	}
}