#include <iostream>

// ��ʹ�� extern �ؼ�������һ������ʱ������ʾ�ñ������������ط��Ѿ�����ģ���ǰ�ļ���ֻ�Ƕ���������á��������Ա����ڶ���ļ����ظ�����ͬһ�����������ǹ���ͬһ��������ʵ����
// extern ����ͨ��������ͷ�ļ�������ȫ�ֱ������Ա�����Դ�ļ����Թ���ʹ�á�
// ע��:�����extern����ʡ�ԣ������ڶ��Դ�ļ��������ⲿȫ�ֱ���
extern int array[128];
extern int n, temp;

int book_sorting();
void bubble_sorting();
void quick_sorting(int left, int right);