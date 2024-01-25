#include "main.hpp"

// ц╟ещеепР
void bubble_sorting()
{
	for (size_t i = 0; i <= n - 1; i++)
	{
		for (size_t j = 0; j <= n - i; j++)
		{
			if (array[j + 1] < array[j])
			{
				temp = array[j + 1];
				array[j + 1] = array[j];
				array[j] = temp;
			}
		}
	}

	for (size_t i = 0; i < n; i++)
	{
		std::cout << array[i] << " ";
	}
}