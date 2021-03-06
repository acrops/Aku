// C++learning.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;
const int SIZE = 50;

void show(vector<int>&x, vector<int>::iterator& p);
bool comp(const int&a, const int&b);

int main()
{
	vector<int> x;
	int temp;

	cout << "输入任意整数，系统将进行排序\n如果需要以文件方式(.txt)输入，请输入T\n否则输入任意字符继续程序" << endl;
	char ans1 = 'X';
	cin.get(ans1);
	cin.clear();
	cin.get();
	cout << "输入A进行升序排序\n输入D进行降序排序\n";
	char ans2 = 'A';
	cin.get(ans2);
	cin.clear();
	cin.get();
	cin.clear();
	if (ans2 != 'A'&&ans2 != 'D') cout << "错误输入，默认升序" << endl;

	if (ans1 == 'T')
	{
		cout << "请输入文件名（例如XXX.txt)：" << endl;
		ifstream inFile;
		char filename[SIZE];
		cin.getline(filename, SIZE);
		inFile.open(filename);
		if (!inFile.is_open())
		{
			cout << "Could not open the file " << filename << endl;
			cout << "Program terminating.\n";
			exit(EXIT_FAILURE);
		}
		
		inFile >> temp;

		while (inFile.good())
		{
			x.push_back(temp);
			inFile >> temp;
		}

		if (inFile.eof())
		{
			cout << "The File has been rearched." << endl;
		}
		else if (inFile.fail())
		{
			cout << "Input terminated by data mismatch.\n";
			exit(0);
		}
		
		vector<int>::iterator p;

		if (ans2 == 'D')
		{
			sort(x.begin(), x.end(), comp);
		}
		else
		{
			sort(x.begin(), x.end());
		}
		show(x, p);
	}
	else
	{
		cout << "输入任意数据，以字母结束：\n";
		while (cin >> temp)
		{
			x.push_back(temp);
		}
		vector<int>::iterator p;
		if (ans2 == 'D')
		{
			sort(x.begin(), x.end(), comp);
		}
		else
		{
			sort(x.begin(), x.end());
		}
		show(x, p);
	}

	return 0;
}

void show(vector<int>&x, vector<int>::iterator& p)
{
	int i = 0;
	auto MaxPositioin = max_element(x.begin(), x.end());
	int s(*MaxPositioin);
	int temp = 1;
	while (s > 1)
	{
		s = s / 10;
		temp++;
	}
	temp++;
	for (p = x.begin(); p != x.end(); p++)
	{
		cout << setprecision(ios::right) << setw(temp) << *p;
		i++;
		if (i == 10)
		{
			cout << endl;
			i = 0;
		}
	}
	cout << endl;
};

bool comp(const int&a, const int&b)
{
	return a > b;
}
