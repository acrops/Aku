#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

void show(vector<int>&x, vector<int>::iterator&p)
{
	int i = 0;
	auto MaxPosition = max_element(x.begin(), x.end());//�����ֵ
	int s(*MaxPosition);
	int temp = 1;
	while (s>1)//�������ֵ��ֵλ��
	{
		s = s / 10;
		temp++;
	}
	temp++;
	for (p = x.begin(); p < x.end(); p++)//ÿʮ��һ�н�������������ʽ�Ҷ��룬�����Ȱ����ֵλ��+1
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
//����ֵ
int main()
{
	vector<int> x;
	int temp;
	cout << "��������������ϵͳ����������" << endl<<"����0������������"<<endl<<"����1���н�������"<<endl;
	int ans=0;
	cin >> ans;
	cout << "����������(��������ĸ������:" << endl;
	while (cin >> temp)//��������
	{
		x.push_back(temp);
	}
	vector<int>::iterator p;
	if(ans==0)	sort(x.begin(), x.end());//Ĭ������
	else sort(x.begin(), x.end(), comp);//��������
	show(x, p);
	return 0;
}