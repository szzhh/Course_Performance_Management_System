#include<iostream>
#include<string>
#include "Student.h"
#include <iomanip>
#include<stdlib.h>
using namespace std;

void student::set1()
{
	cin >> num>> name>> clas>> score1>> score2 >> score3;
}
void student::show()
{
	cout << num << setw(8) << name << setw(20) << clas<< setw(10) <<score1
		<<setw(10)<< score2 << setw(10) << score3 << endl;
}

void add(student st[], int &t,course co)
{
	system("cls");
	int k = t;
	string str;
	while (true)
	{
		cout << "请依次输入以下信息" << endl;
		cout << "学号" << setw(5) << "姓名" << setw(5) << "班级" << setw(7)
			<< co.exam[0] << setw(5) << co.exam[1] << setw(5) << co.exam[2] << endl;
		st[k].set1();
		k++;
		t = k;
		cout << "是否继续输入(Y or N)?" << endl;
		cin >> str;
		if (str == "y" || str == "Y")
		{
			continue;
		}
		else
		{
			break;
		}
	}
}

void show(student st[], int t,course co)
{
	system("cls");
	if (t == 0)
		cout << "暂无学生信息" << endl;
	else
	{
		cout << "学号" << setw(10) << "姓名" << setw(14) << "班级" << setw(17) 
			<< co.exam[0] << setw(11) << co.exam[1] << setw(10) << co.exam[2] << endl;
		for (int k = 0; k < t; k++)
		{
			st[k].show();
		}
	}
}

void search(student st[], int t,course co)
{
	system("cls");
	int ch, number;
	string N;
	static char T = 'y';
	cout << "1.按学号查找" << endl;
	cout << "2.按姓名查找" << endl;
	while ((T == 'y') || (T == 'Y'))
	{
		cout << "请输入查找方式序号：";
		cin >> ch;
		if (ch == 1)
		{
			cout << "请输入要查找学生的学号：";
			cin >> number;
			for (int i = 0;i < t;i++)
			{
				if (number == st[i].num)
				{
					cout << "学号" << setw(10) << "姓名" << setw(14) << "班级" << setw(17)
						<< co.exam[0] << setw(11) << co.exam[1] << setw(10) << co.exam[2] << endl;
					st[i].show();
				}
			}
		}
		else if (ch == 2)
		{
			cout << "请输入要查找学生的姓名：";
			cin >> N;
			for (int i = 0;i < t;i++)
			{
				if (N.compare(st[i].name) == 0)
				{
					cout << "学号" << setw(10) << "姓名" << setw(14) << "班级" << setw(17)
						<< co.exam[0] << setw(11) << co.exam[1] << setw(10) << co.exam[2] << endl;
					st[i].show();
				}
			}
		}
		else
			cout << "输入序号错误！！！" << endl;
		cout << "是否继续查找（Y or N)?" << endl;
		cin >> T;
	}
}

void alter(student st[], int t,course co)
{
	system("cls");
	int number;
	static char T = 'y';
	while ((T == 'y') || (T == 'Y'))
	{
		cout << "请输入要修改信息的学生学号：";
		cin >> number;
		for (int i = 0;i < t;i++)
		{
			if (number == st[i].num)
			{
				cout << "要修改的学生信息如下" << endl;
				cout << "学号" << setw(10) << "姓名" << setw(14) << "班级" << setw(17)
					<< co.exam[0] << setw(11) << co.exam[1] << setw(10) << co.exam[2] << endl;
				st[i].show();
				cout << "请依次输入修改后的学生信息：" << endl;
				cout << "学号" << setw(5) << "姓名" << setw(5) << "班级" << setw(7)
					<< co.exam[0] << setw(5) << co.exam[1] << setw(5) << co.exam[2] << endl;
				st[i].set1();
			}

		}
		cout << "是否继续修改（Y or N)?" << endl;
		cin >> T;
	}
}

void del(student st[],student ca[] ,int &t,int& n,course co)
{
	system("cls");
	int id;
	string str;//用来判断是否继续输入的字符串
	while (true)
	{
		cout << "请输入要删除学生的学号：";
		cin >> id;
		int flag = 0;//用来统计删除后剩余的数组元素个数
		student a[30];
			for (int i = 0;i < t;i++)
			{
				if (st[i].num != id)
				{
					a[flag] = st[i];
					flag++;
				}
				else
				{
					ca[n] = st[i];
					n++;
				}
			}
			if (flag < t)
			{
				t = flag;
				for (int k = 0;k < t;k++)
				{
					st[k] = a[k];
				}
				cout << id << "号学生信息删除成功！" << endl;
			}
			else
			{
				cout << "输入学号有误！\n";
			}
			cout << "是否继续删除(Y or N)?"<<endl;
			cin >> str;
			if (str == "y" || str == "Y")
			{
				continue;
			}
			else
			{
				break;
			}
	}
}

void data(student st[], int t, course co)
{
	system("cls");
	float sum;
	int x = 0, y = 0, z = 0;
	for (int b = 0;b < t; b++)
	{
		sum = 0.3 * st[b].score1 + 0.3 * st[b].score2 + 0.4 * st[b].score3;
		if (sum >= 80)
			x++;
		else if (sum >= 60)
			y++;
		else
			z++;
	}
	cout << "总平时成绩高于80分的有" << x << "人"<<endl;
	cout << "总平时成绩60-80分的有" << y << "人" << endl;
	cout << "总平时成绩低于60分的有" << z << "人" << endl;
	cout << co.exam[0] << "不及格的学生信息如下：" << endl;
	cout << "学号" << setw(10) << "姓名" << setw(14) << "班级" << setw(17)
		<< co.exam[0] << setw(11) << co.exam[1] << setw(10) << co.exam[2] << endl;
	for (int b = 0;b < t; b++)
	{
		if(st[b].score1<60)
			st[b].show();
	}
	cout << co.exam[1] << "不及格的学生信息如下" << endl;
	cout << "学号" << setw(10) << "姓名" << setw(14) << "班级" << setw(17)
		<< co.exam[0] << setw(11) << co.exam[1] << setw(10) << co.exam[2] << endl;
	for (int b = 0;b < t; b++)
	{
		if (st[b].score2 < 60)
			st[b].show();
	}
	cout << co.exam[2] << "不及格的学生信息如下" << endl;
	cout << "学号" << setw(10) << "姓名" << setw(14) << "班级" << setw(17)
		<< co.exam[0] << setw(11) << co.exam[1] << setw(10) << co.exam[2] << endl;
	for (int b = 0;b < t; b++)
	{
		if (st[b].score3 < 60)
			st[b].show();
	}
}

void regain(student st[], student ca[], int& t, int& n)
{
	system("cls");
	int id,b,flag;
	int c;
	string str;
	student a[30];
	while (true)
	{
		cout << "请输入要恢复学生的学号：";
		cin >> id;
		flag = 0;
		c = n;
		for (b = 0;b < c;b++)
		{
			if (ca[b].num == id)
			{
				st[t] = ca[b];
				t++;
				n--;
			}
			else
			{
				a[flag] = ca[b];
				flag++;
			}
		}
		for (int d = 0;d < n;d++)
		{
			ca[d] = a[d];
		}
		if (flag == c)
			cout << "输入的学号不存在！" << endl;
		else
			cout << "恢复成功！" << endl;
		cout << "是否继续恢复(Y or N)?"<<endl;
		cin >> str;
		if (str == "y" || str == "Y")
		{
			continue;
		}
		else
		{
			break;
		}
	}
}

void ADD(pass pa[], int& p)
{
	system("cls");
	string str;
	int k = p;
	while (true)
	{
		pa[k].Set();
		k++;
		p = k;
		cout << "是否继续输入(Y or N)?" << endl;
		cin >> str;
		if (str == "y" || str == "Y")
		{
			continue;
		}
		else
		{
			break;
		}
	}
}

void ALTER(pass pa[], int p)
{
	system("cls");
	string str, u, pw;
	while (true)
	{
		int flag = 0;
		cout << "输入要修改的账户和密码" << endl;
		cout << "账号：";
		cin >> u;
		cout << "密码：";
		cin >> pw;
		for (int r = 0;r < p;r++)
		{
			if ((u == pa[r].user) && (pw == pa[r].passWord))
			{
				cout << "请输入修改后的账户和密码" << endl;
				cout << "账号：";
				cin >> pa[r].user;
				cout << "密码：";
				cin >> pa[r].passWord;
				cout << "修改成功！" << endl;
			}
			else
				flag++;
		}
		if (flag == p)
		{
			cout << "输入信息有误！" << endl;
		}
		cout << "是否继续修改(Y or N)?" << endl;
		cin >> str;
		if (str == "y" || str == "Y")
		{
			continue;
		}
		else
		{
			break;
		}
	}
}

void DEL(pass pa[], int& p)
{
	system("cls");
	string str,u,pw;
	int k;
	pass a[10];
	while (true)
	{
		int flag = 0;
		cout << "输入要删除的账户和密码" << endl;
		cout << "账号：";
		cin >> u;
		cout << "密码：";
		cin >> pw;
		for (int r = 0;r < p;r++)
		{
			if ((u != pa[r].user) || (pw != pa[r].passWord))
			{
				a[flag] = pa[r];
				flag++;
			}
		}
		if (flag == (p - 1))
		{
			p = flag;
			for (int k = 0;k < p;k++)
			{
				pa[k] = a[k];
			}
			cout <<"账户"<< u << "删除成功！" << endl;
		}
		else
		{
			cout << "输入信息有误！" << endl;
		}
		cout << "是否继续删除(Y or N)?" << endl;
		cin >> str;
		if (str == "y" || str == "Y")
		{
			continue;
		}
		else
		{
			break;
		}
	}
}

void Add(course co[], int &s)
{
	system("cls");
	string str;
	int k = s;
	while (true)
	{
		co[k].set();
		k++;
		s = k;
		cout << "是否继续输入(Y or N)?" << endl;
		cin >> str;
		if (str == "y" || str == "Y")
		{
			continue;
		}
		else
		{
			break;
		}

	}
}

void Show(course co[], int s)
{
	system("cls");
	if (s == 0)
		cout << "暂无课程信息" << endl;
	else
	{
		for (int k = 0;k < s;k++)
		{
			cout << "课程编号：" << co[k].Num << " 课程名称：" << co[k].Name << " 任课老师：" << co[k].teacher << " 考核方式:";
			for (int b = 0;b < 3;b++)
			{
				cout << co[k].exam[b];
				cout << " ";
			}
			cout << "信息保存位置：" << co[k].file << endl;
		}
	}
}

void Show(course co)
{
	system("cls");
	cout << "课程编号：" << co.Num << " 课程名称：" << co.Name << " 任课老师：" << co.teacher << " 考核方式:";
	for (int b = 0;b < 3;b++)
	{
		cout << co.exam[b];
		cout << " ";
	}
	cout << "信息保存位置：" << co.file << endl;
}

void Alter(course &co)
{
	system("cls");
	cout << co.Name << "的考核方式为：";
	for (int b = 0;b < 3;b++)
	{
		cout << co.exam[b];
		cout << " ";
	}
	cout << "\n输入修改后的考核方式" << endl;
	for (int b = 0;b < 3;b++)
	{
		cin >> co.exam[b];
	}
	cout << "考核方式修改成功！" << endl;
}

void course::set()
{
	cout << "课程编号：";
	cin >> Num;
	cout << "课程名称：";
	cin >> Name;
	cout << "任课老师：";
	cin >> teacher;
	cout << "考核方式：";
	for (int b = 0;b < 3;b++)
	{
		cin >> exam[b];
		cout << "\t  ";
	}
	cout << "\n信息保存位置：";
	cin >> file;
}

void pass::Set()
{
	cout << "账号：";
	cin >> user;
	cout << "密码：";
	cin >> passWord;
	cout << "课程保存地址：";
	cin >> filecourse;
	cout << "预恢复信息保存位置：";
	cin >> filecache;
}
