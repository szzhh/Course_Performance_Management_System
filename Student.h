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
	int num;//ѧ��
	string name, clas;//����,�༶
	float score1, score2, score3;//����ƽʱ�ɼ�
	void set1();//����ѧ��
	void show();//�����Ϣ
};
class course
{
public:
	int Num;
	string Name, teacher, exam[3], file;
	void set();
	friend void Add(course co[], int& s);//��ӿγ���Ϣ
	friend void Show(course co[], int s);//��ʾȫ���γ���Ϣ
	friend void Show(course co);//��ʾ��ǰ�γ���Ϣ
	friend void Alter(course& co);//�޸ĵ�ǰ�γ���Ϣ
};

void add(student st[], int& t, course co);//����ѧ���ɼ�
void show(student st[], int t,course co);//��ʾȫ��ѧ���ɼ�
void search(student st[], int t,course co);//��ѯѧ����Ϣ
void alter(student st[], int t,course co);//�޸�ѧ����Ϣ
void del(student st[],student ca[], int& t,int& n,course co);//ɾ��ѧ����Ϣ
void data(student st[], int t, course co);//ͳ�Ƴɼ���Ϣ
void regain(student st[], student ca[], int& t, int& n);//�ָ�ѧ����Ϣ