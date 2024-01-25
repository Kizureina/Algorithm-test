#include "main.hpp"

int array[128] = { 0 };
int temp, n;

int main()
{
	std::cout << "请输入数字个数:";
	std::cin >> n;

	for (size_t i = 0; i < n; i++)
	{
		std::cin >> array[i];
	}

	quick_sorting(0, n - 1);

	for (size_t i = 0; i < n; i++)
	{
		std::cout << array[i] << " ";
	}

	return 0;
}