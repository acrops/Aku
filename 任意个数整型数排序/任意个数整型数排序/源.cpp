#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

void show(vector<int>&x, vector<int>::iterator&p)
{
	int i = 0;
	auto MaxPosition = max_element(x.begin(), x.end());//求最大值
	int s(*MaxPosition);
	int temp = 1;
	while (s>1)//计算最大值数值位数
	{
		s = s / 10;
		temp++;
	}
	temp++;
	for (p = x.begin(); p < x.end(); p++)//每十个一行进行输出，输出格式右对齐，输出宽度按最大值位数+1
	{
		cout << setiosflags(ios::right) << setw(temp) << *p;
		i++;
		if (i == 10)
		{
			cout << endl;
			i = 0;
		}
	}
	cout << endl;
}
bool comp(const int&a, const int&b)
{
	return a > b;
}
//降序值
int main()
{
	vector<int> x;
	int temp;
	cout << "输入任意整数，系统将进行排序" << endl<<"输入0进行升序排列"<<endl<<"输入1进行降序排列"<<endl;
	int ans=0;
	cin >> ans;
	cout << "请输入数据(以任意字母结束）:" << endl;
	while (cin >> temp)//数据输入
	{
		x.push_back(temp);
	}
	vector<int>::iterator p;
	if(ans==0)	sort(x.begin(), x.end());//默认升序
	else sort(x.begin(), x.end(), comp);//降序排列
	show(x, p);
	return 0;
}