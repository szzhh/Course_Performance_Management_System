#pragma once
#include<iostream>
#include<string>
using namespace std;

class pass
{
public:
	string user, passWord, filecourse, filecache;
	void Set();
	friend void ADD(pass pa[], int& p);
	friend void ALTER(pass pa[], int p);
	friend void DEL(pass pa[], int& p);
};

class student
{
public:
	int num;//学号
	string name, clas;//姓名,班级
	float score1, score2, score3;//三门平时成绩
	void set1();//输入学号
	void show();//输出信息
};
class course
{
public:
	int Num;
	string Name, teacher, exam[3], file;
	void set();
	friend void Add(course co[], int& s);//添加课程信息
	friend void Show(course co[], int s);//显示全部课程信息
	friend void Show(course co);//显示当前课程信息
	friend void Alter(course& co);//修改当前课程信息
};

void add(student st[], int& t, course co);//输入学生成绩
void show(student st[], int t,course co);//显示全部学生成绩
void search(student st[], int t,course co);//查询学生信息
void alter(student st[], int t,course co);//修改学生信息
void del(student st[],student ca[], int& t,int& n,course co);//删除学生信息
void data(student st[], int t, course co);//统计成绩信息
void regain(student st[], student ca[], int& t, int& n);//恢复学生信息