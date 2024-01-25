#include "main.hpp"

// Õ∞≈≈–Ú(ºÚªØ∞Ê)
int book_sorting()
{
	int book[11] = { 0 };

	for (int i = 1; i <= 5; i++)
	{
		std::cin >> temp;
		book[temp]++;
	}

	for (int i = 1; i <= 10; i++)
	{
		for (int j = 1; j <= book[i]; j++)
		{
			std::cout << i << " ";
		}
	}

	return 0;
}