#include "main.hpp"

int array[101] = { 0 };
int temp, n;

int main()
{
	std::cout << "���������ָ���:";
	std::cin >> n;

	for (size_t i = 0; i < n; i++)
	{
		std::cin >> array[i];
	}

	//quick_sorting(1, n);
	bubble_sorting();

	return 0;
}