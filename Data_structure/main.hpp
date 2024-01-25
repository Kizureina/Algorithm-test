#include <iostream>

// 当使用 extern 关键字声明一个变量时，它表示该变量是在其他地方已经定义的，当前文件中只是对其进行引用。这样可以避免在多个文件中重复定义同一个变量，而是共享同一个变量的实例。
// extern 声明通常用于在头文件中声明全局变量，以便其他源文件可以共享使用。
// 注意:这里的extern不能省略，用于在多个源文件中声明外部全局变量
extern int array[128];
extern int n, temp;

int book_sorting();
void bubble_sorting();
void quick_sorting(int left, int right);