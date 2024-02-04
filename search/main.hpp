#include <iostream>

extern int a[10], book[10];
extern int map_book[50][50], map[50][50];

using namespace std;

void deep_first_serach_test();
void dfs(int step);
void getAnswer_by_dfs();
void depth_first_search_for_answer(int step);

void find_shortest_path_by_dfs();
void find_path_dfs(int x, int y, int step);