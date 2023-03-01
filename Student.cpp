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
		cout << "����������������Ϣ" << endl;
		cout << "ѧ��" << setw(5) << "����" << setw(5) << "�༶" << setw(7)
			<< co.exam[0] << setw(5) << co.exam[1] << setw(5) << co.exam[2] << endl;
		st[k].set1();
		k++;
		t = k;
		cout << "�Ƿ��������(Y or N)?" << endl;
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
		cout << "����ѧ����Ϣ" << endl;
	else
	{
		cout << "ѧ��" << setw(10) << "����" << setw(14) << "�༶" << setw(17) 
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
	cout << "1.��ѧ�Ų���" << endl;
	cout << "2.����������" << endl;
	while ((T == 'y') || (T == 'Y'))
	{
		cout << "��������ҷ�ʽ��ţ�";
		cin >> ch;
		if (ch == 1)
		{
			cout << "������Ҫ����ѧ����ѧ�ţ�";
			cin >> number;
			for (int i = 0;i < t;i++)
			{
				if (number == st[i].num)
				{
					cout << "ѧ��" << setw(10) << "����" << setw(14) << "�༶" << setw(17)
						<< co.exam[0] << setw(11) << co.exam[1] << setw(10) << co.exam[2] << endl;
					st[i].show();
				}
			}
		}
		else if (ch == 2)
		{
			cout << "������Ҫ����ѧ����������";
			cin >> N;
			for (int i = 0;i < t;i++)
			{
				if (N.compare(st[i].name) == 0)
				{
					cout << "ѧ��" << setw(10) << "����" << setw(14) << "�༶" << setw(17)
						<< co.exam[0] << setw(11) << co.exam[1] << setw(10) << co.exam[2] << endl;
					st[i].show();
				}
			}
		}
		else
			cout << "������Ŵ��󣡣���" << endl;
		cout << "�Ƿ�������ң�Y or N)?" << endl;
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
		cout << "������Ҫ�޸���Ϣ��ѧ��ѧ�ţ�";
		cin >> number;
		for (int i = 0;i < t;i++)
		{
			if (number == st[i].num)
			{
				cout << "Ҫ�޸ĵ�ѧ����Ϣ����" << endl;
				cout << "ѧ��" << setw(10) << "����" << setw(14) << "�༶" << setw(17)
					<< co.exam[0] << setw(11) << co.exam[1] << setw(10) << co.exam[2] << endl;
				st[i].show();
				cout << "�����������޸ĺ��ѧ����Ϣ��" << endl;
				cout << "ѧ��" << setw(5) << "����" << setw(5) << "�༶" << setw(7)
					<< co.exam[0] << setw(5) << co.exam[1] << setw(5) << co.exam[2] << endl;
				st[i].set1();
			}

		}
		cout << "�Ƿ�����޸ģ�Y or N)?" << endl;
		cin >> T;
	}
}

void del(student st[],student ca[] ,int &t,int& n,course co)
{
	system("cls");
	int id;
	string str;//�����ж��Ƿ����������ַ���
	while (true)
	{
		cout << "������Ҫɾ��ѧ����ѧ�ţ�";
		cin >> id;
		int flag = 0;//����ͳ��ɾ����ʣ�������Ԫ�ظ���
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
				cout << id << "��ѧ����Ϣɾ���ɹ���" << endl;
			}
			else
			{
				cout << "����ѧ������\n";
			}
			cout << "�Ƿ����ɾ��(Y or N)?"<<endl;
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
	cout << "��ƽʱ�ɼ�����80�ֵ���" << x << "��"<<endl;
	cout << "��ƽʱ�ɼ�60-80�ֵ���" << y << "��" << endl;
	cout << "��ƽʱ�ɼ�����60�ֵ���" << z << "��" << endl;
	cout << co.exam[0] << "�������ѧ����Ϣ���£�" << endl;
	cout << "ѧ��" << setw(10) << "����" << setw(14) << "�༶" << setw(17)
		<< co.exam[0] << setw(11) << co.exam[1] << setw(10) << co.exam[2] << endl;
	for (int b = 0;b < t; b++)
	{
		if(st[b].score1<60)
			st[b].show();
	}
	cout << co.exam[1] << "�������ѧ����Ϣ����" << endl;
	cout << "ѧ��" << setw(10) << "����" << setw(14) << "�༶" << setw(17)
		<< co.exam[0] << setw(11) << co.exam[1] << setw(10) << co.exam[2] << endl;
	for (int b = 0;b < t; b++)
	{
		if (st[b].score2 < 60)
			st[b].show();
	}
	cout << co.exam[2] << "�������ѧ����Ϣ����" << endl;
	cout << "ѧ��" << setw(10) << "����" << setw(14) << "�༶" << setw(17)
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
		cout << "������Ҫ�ָ�ѧ����ѧ�ţ�";
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
			cout << "�����ѧ�Ų����ڣ�" << endl;
		else
			cout << "�ָ��ɹ���" << endl;
		cout << "�Ƿ�����ָ�(Y or N)?"<<endl;
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
		cout << "�Ƿ��������(Y or N)?" << endl;
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
		cout << "����Ҫ�޸ĵ��˻�������" << endl;
		cout << "�˺ţ�";
		cin >> u;
		cout << "���룺";
		cin >> pw;
		for (int r = 0;r < p;r++)
		{
			if ((u == pa[r].user) && (pw == pa[r].passWord))
			{
				cout << "�������޸ĺ���˻�������" << endl;
				cout << "�˺ţ�";
				cin >> pa[r].user;
				cout << "���룺";
				cin >> pa[r].passWord;
				cout << "�޸ĳɹ���" << endl;
			}
			else
				flag++;
		}
		if (flag == p)
		{
			cout << "������Ϣ����" << endl;
		}
		cout << "�Ƿ�����޸�(Y or N)?" << endl;
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
		cout << "����Ҫɾ�����˻�������" << endl;
		cout << "�˺ţ�";
		cin >> u;
		cout << "���룺";
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
			cout <<"�˻�"<< u << "ɾ���ɹ���" << endl;
		}
		else
		{
			cout << "������Ϣ����" << endl;
		}
		cout << "�Ƿ����ɾ��(Y or N)?" << endl;
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
		cout << "�Ƿ��������(Y or N)?" << endl;
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
		cout << "���޿γ���Ϣ" << endl;
	else
	{
		for (int k = 0;k < s;k++)
		{
			cout << "�γ̱�ţ�" << co[k].Num << " �γ����ƣ�" << co[k].Name << " �ο���ʦ��" << co[k].teacher << " ���˷�ʽ:";
			for (int b = 0;b < 3;b++)
			{
				cout << co[k].exam[b];
				cout << " ";
			}
			cout << "��Ϣ����λ�ã�" << co[k].file << endl;
		}
	}
}

void Show(course co)
{
	system("cls");
	cout << "�γ̱�ţ�" << co.Num << " �γ����ƣ�" << co.Name << " �ο���ʦ��" << co.teacher << " ���˷�ʽ:";
	for (int b = 0;b < 3;b++)
	{
		cout << co.exam[b];
		cout << " ";
	}
	cout << "��Ϣ����λ�ã�" << co.file << endl;
}

void Alter(course &co)
{
	system("cls");
	cout << co.Name << "�Ŀ��˷�ʽΪ��";
	for (int b = 0;b < 3;b++)
	{
		cout << co.exam[b];
		cout << " ";
	}
	cout << "\n�����޸ĺ�Ŀ��˷�ʽ" << endl;
	for (int b = 0;b < 3;b++)
	{
		cin >> co.exam[b];
	}
	cout << "���˷�ʽ�޸ĳɹ���" << endl;
}

void course::set()
{
	cout << "�γ̱�ţ�";
	cin >> Num;
	cout << "�γ����ƣ�";
	cin >> Name;
	cout << "�ο���ʦ��";
	cin >> teacher;
	cout << "���˷�ʽ��";
	for (int b = 0;b < 3;b++)
	{
		cin >> exam[b];
		cout << "\t  ";
	}
	cout << "\n��Ϣ����λ�ã�";
	cin >> file;
}

void pass::Set()
{
	cout << "�˺ţ�";
	cin >> user;
	cout << "���룺";
	cin >> passWord;
	cout << "�γ̱����ַ��";
	cin >> filecourse;
	cout << "Ԥ�ָ���Ϣ����λ�ã�";
	cin >> filecache;
}
