#include <iostream>
#define P 4
#define Q 2

extern int a[10], book[10];
extern int map_book[50][50], map[50][50];
extern int m, n, head, tail;
extern int minstep;

// 方便模拟移动坐标，定义一个方向数组以获取下一步的坐标
extern int next_map[4][2];

struct point
{
	int x;
	int y;
};

using namespace std;

void deep_first_serach_test();
void dfs(int step);
void getAnswer_by_dfs();
void depth_first_search_for_answer(int step);

void find_shortest_path_by_dfs();
void find_path_dfs(int x, int y, int step);

void find_path_by_bfs(int startx, int starty);
void bomb_man_bfs(int startx, int starty);
void bomb_man_dfs(int x, int y);

void find_island_width(int startx, int starty);