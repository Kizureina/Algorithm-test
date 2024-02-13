#include "main.hpp"
int min_step = 100;
using namespace std;

struct city
{
	int num;
	int step;
};

// bfs适合处理图的边权值均相同的情况
void min_transfer_bfs()
{
	cout << "输入节点数和边数:";
	cin >> n >> m;

	// 初始化邻接矩阵
	int length = n;
	for (size_t i = 1; i <= length; i++)
	{
		for (size_t j = 1; j <= length; j++)
		{
			if (j == i)
			{
				e[i][j] = 0;
			}
			else
			{
				e[i][j] = 999;
			}
		}
	}

	cout << "输入连接的点：";
	length = m;
	for (size_t i = 1; i <= length; i++)
	{
		int a, b;
		cin >> a >> b;

		e[a][b] = 1;
		e[b][a] = 1;
	}

	cout << "输入起点和终点:";
	int start, end;
	cin >> start >> end;

	city queue[25];
	int head, tail;
	head = 1;
	tail = 1;

	int flag = 0;

	// 起始点入队列
	queue[tail].num = start;
	queue[tail].step = 0;
	tail++;
	book[start] = 1;

	// 开始扩展
	while (head < tail)
	{
		int cur = queue[head].num;
		
		length = n;
		for (size_t i = 1; i <= length; i++)
		{
			// 当有扩展的点有线，而且未被遍历过时
			if (e[cur][i] == 1 && book[i] == 0)
			{
				// 该点入队列
				queue[tail].num = i;
				book[i] = 1;
				// 当前点的转机数是上一个点加一(加当前这次遍历)
				queue[tail].step = queue[head].step + 1;
				tail++;
			}

			// 当扩展到的点包含终点时结束
			if (e[cur][i] == end)
			{
				// 标记flag是为了退出外层循环，减少不必要的遍历
				flag = 1;
				break;
			}
		}

		if (flag == 1)
		{
			break;
		}

		head++;
	}

	cout << "最少转机数为:" << queue[tail - 1].step;
}