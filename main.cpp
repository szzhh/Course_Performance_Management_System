#include<iostream>
#include<fstream>
#include<iomanip>
#include <conio.h>
#include<string> 
#include<stdlib.h>
#include "Student.h"
using namespace std;

void welcome()
{
	system("cls");
	cout << "\n\n\t\t\t\t\t\t\t┌===================================================┑\n";
	cout << "\t\t\t\t\t\t\t?(^o^)?★★★欢迎使用课程平时成绩密码管理系统★★★?(^o^)?\n\n\n";
	cout << "\t\t\t\t\t\t\t\t\t   1.登录账号\n";
	cout << "\t\t\t\t\t\t\t\t\t   2.注册账号\n";
	cout << "\t\t\t\t\t\t\t\t\t   3.修改密码\n";
	cout << "\t\t\t\t\t\t\t\t\t   4.删除账号\n";
	cout << "\t\t\t\t\t\t\t\t\t   5.返回菜单\n";
	cout << "\t\t\t\t\t\t\t\t\t   6.退出系统\n";
	cout << "\n\n\t\t\t\t\t\t\t┕================================================┚\n";
}
void welcome1()
{
	system("cls");
	cout << "\n\n\t\t\t\t\t\t\t┌=================================================┑\n";
	cout << "\t\t\t\t\t\t\t?(^o^)?★★★欢迎使用课程信息管理系统★★★?(^o^)?\n\n\n";
	cout << "\t\t\t\t\t\t\t\t\t   1.添加课程\n";
	cout << "\t\t\t\t\t\t\t\t\t   2.查看课程\n";
	cout << "\t\t\t\t\t\t\t\t\t   3.进入课程\n";
	cout << "\t\t\t\t\t\t\t\t\t   4.返回菜单\n";
	cout << "\t\t\t\t\t\t\t\t\t   5.返回上级菜单\n";
	cout << "\n\n\t\t\t\t\t\t\t┕================================================┚\n";
}
void welcome2()
{
	system("cls");
	cout << "\n\n\t\t\t\t\t\t\t┌================================================┑\n";
	cout << "\t\t\t\t\t\t\t?(^o^)?★★★欢迎使用课程信息管理系统★★★?(^o^)?\n\n\n";
	cout << "\t\t\t\t\t\t\t\t\t   1.查看课程信息\n";
	cout << "\t\t\t\t\t\t\t\t\t   2.修改课程信息\n";
	cout << "\t\t\t\t\t\t\t\t\t   3.学生成绩信息\n";
	cout << "\t\t\t\t\t\t\t\t\t   4.返回本级菜单\n";
	cout << "\t\t\t\t\t\t\t\t\t   5.返回上级菜单\n";
	cout << "\n\n\t\t\t\t\t\t\t┕================================================┚\n";
}
void welcome3()
{
	system("cls");
	cout << "\n\n\t\t\t\t\t\t\t┌================================================┑\n";
	cout << "\t\t\t\t\t\t\t?(^o^)?★★★欢迎使用学生信息管理系统★★★?(^o^)?\n\n\n";
	cout << "\t\t\t\t\t\t\t\t\t   1.添加信息\n";
	cout << "\t\t\t\t\t\t\t\t\t   2.显示信息\n";
	cout << "\t\t\t\t\t\t\t\t\t   3.查找信息\n";
	cout << "\t\t\t\t\t\t\t\t\t   4.修改信息\n";
	cout << "\t\t\t\t\t\t\t\t\t   5.删除信息\n";
	cout << "\t\t\t\t\t\t\t\t\t   6.恢复信息\n";
	cout << "\t\t\t\t\t\t\t\t\t   7.统计信息\n";
	cout << "\t\t\t\t\t\t\t\t\t   8.返回菜单\n";
	cout << "\t\t\t\t\t\t\t\t\t   9.退出系统\n";
	cout << "\n\n\t\t\t\t\t\t\t┕================================================┚\n";
}

int main()
{
	system("cls");
	system("color 3E");
	int q=0 ,currentN = 0, choice = 1,x=0;
	char e ,F;
	int currentN1 = 0, currentN2 = 0, currentN3 = 0;
	course cou[5];
	pass Pass[10];
	student stu[40];
	student cache[100];
	ifstream Filein("password.dat", ios::binary);
	if (Filein)
	{
		Filein.read((char*)&currentN, sizeof(currentN));
		for (int i = 0;i < currentN;i++)
		{
			Filein.read((char*)&Pass[i], sizeof(Pass[i]));
		}
	}
	Filein.close();
	welcome();
	while (choice != 6)
	{
		welcome();
		cout << "\n请输入>>";
		cin >> choice;
		e = getchar();
		switch (choice)
		{
		case 1:
		{
			if (currentN == 0)
			{
				cout << "当前没有用户，请先注册！" << endl;
			}
			else 
			{
				string  username;
				string  password;
				string strr;
				char g;
				char  a[20];
				while (true)
				{
					system("cls");
					cout << "\n\n\t\t\t\t\t\t\t┌===============================================┑\n";
					cout << "\t\t\t\t\t\t\t\t?(^o^)?★★★登录界面★★★?(^o^)?\n\n";
					cout << "\t\t\t\t\t\t\t\t用户名：";
					getline(cin, username, '\n');
					cout << "\t\t\t\t\t\t\t\t密码：";
					int z;
					for (z = 0;z < 20;z++)
					{
						a[z] = _getch();
						if (a[z] == 13) //响应回车
						{
							break;
						}
						else if (a[z] == '\b')  //响应退格键
						{
							if (z == 0) //如果当前已经没有字符，则直接跳出
							{
								continue;
							}
							//屏幕上删掉的字符填成空格，并回退光标
							cout << "\b";
							cout << " ";
							cout << "\b";
							//将数组响应位置填成0
							z--;
							a[z] = 0;
							//将i往前置一位，因为接下来会执行for循环的i++
							z--;
							//清空输入缓冲，避免回车等其他字符捣乱
							cin.clear();
						}
						else
						{
							cout << "*";
						}
					}
					cout << endl;
					//a字符串结尾，并赋给password
					a[z] = 0;
					password = a;
					F = 0;
					for (int r = 0;r < currentN;r++)
					{
						if ((username == Pass[r].user) && (password == Pass[r].passWord))
						{
							q = r;
						}
						else
							F++;
					}
					if (F==(currentN-1))
					{
						cout << "登录成功！" << endl;

						int  choice1, choice2, choice3;
						ifstream filein(Pass[q].filecourse, ios::binary);
						if (filein)
						{
							filein.read((char*)&currentN1, sizeof(currentN1));
							for (int i = 0;i < currentN1;i++)
							{
								filein.read((char*)&cou[i], sizeof(cou[i]));
							}
						}
						filein.close();
						welcome1();
						choice1 = 1;
						while (choice1 != 5)
						{
							welcome1();
							cout << "\n请输入>>";
							cin >> choice1;
							switch (choice1)
							{
							case 1:
								Add(cou, currentN1);
								break;
							case 2:
								Show(cou, currentN1);
								system("pause");
								break;
							case 3:
							{
								Show(cou, currentN1);
								if (currentN1 == 0)
								{
									cout << "按4返回菜单！" << endl;
									break;
								}
								else
								{
									cout << "请输入课程编号：";
									cin >> x;
									x--;
									welcome2();
									choice2 = 1;
									while (choice2 != 5)
									{
										welcome2();
										cout << "\n请输入>>";
										cin >> choice2;
										if (choice2 == 1)
										{
											Show(cou[x]);
											system("pause");
										}
										else if (choice2 == 2)
										{
											Alter(cou[x]);
										}
										else if (choice2 == 3)
										{
											
											ifstream infile(cou[x].file, ios::binary);
											if (infile)
											{
												infile.read((char*)&currentN2, sizeof(currentN2));
												for (int i = 0;i < currentN2;i++)
												{
													infile.read((char*)&stu[i], sizeof(stu[i]));
												}
											}
											infile.close();
											ifstream infile1(Pass[q].filecache, ios::binary);
											if (infile1)
											{
												infile1.read((char*)&currentN3, sizeof(currentN3));
												for (int i = 0;i < currentN3;i++)
												{
													infile1.read((char*)&cache[i], sizeof(cache[i]));
												}
											}
											infile1.close();
											welcome3();
											choice3 = 1;
											while (choice3 != 9)
											{
												welcome3();
												cout << "\n请输入>>";
												cin >> choice3;
												if (choice3 == 1)
												{
													add(stu, currentN2, cou[x]);
												}
												else if (choice3 == 2)
												{
													show(stu, currentN2, cou[x]);
													system("pause");
												}
												else if (choice3 == 3)
												{
													search(stu, currentN2, cou[x]);
												}
												else if (choice3 == 4)
												{
													alter(stu, currentN2, cou[x]);
												}
												else if (choice3 == 5)
												{
													del(stu, cache, currentN2, currentN3, cou[x]);
												}
												else if (choice3 == 6)
												{
													regain(stu, cache, currentN2, currentN3);
												}
												else if (choice3 == 7)
												{
													data(stu, currentN2, cou[x]);
													system("pause");
												}
												else if (choice3 == 8)
												{
													welcome3();
												}
												else if (choice3 == 9)
												{
													welcome2();
												}
												else
												{
													cout << "\t\t任意键返回本菜单\n";
													welcome3();
												}
											}
										}
										else if (choice2 == 4)
										{
											welcome2();
										}
										else if (choice2 == 5)
										{
											welcome1();
										}
										else
										{
											cout << "\t\t任意键返回本菜单\n";
											welcome2();
										}
									}
									break;
								}
							}
							case 4:
								welcome1();
								break;
							case 5:
								break;
							default:
								cout << "\t\t任意键返回本菜单\n";
								welcome1();
							}
						}
						
					}
					else
					{
						cout << "\t\t\t\t\t\t\t\t用户名或密码错误请重新输入" << "\n\t\t\t\t\t\t\t\t";
					}
					cout << "是否继续登录(Y or N)?"<<endl;
					cin >> strr;
					g = getchar();
					if (strr == "y" || strr == "Y")
					{
						continue;
					}
					else
					{
						break;
					}
				}
			}
			system("pause");
			break;
		}
		case 2:
			ADD(Pass, currentN);
			break;
		case 3:
			ALTER(Pass, currentN);
			break;
		case 4:
			DEL(Pass, currentN);
			break;
		case 5:
			welcome();
			break;
		case 6:
		{
			cout << "退出成功！" << endl;
			break;
		}
		default:
			cout << "\t\t任意键返回本菜单\n";
			welcome();
		}
	}

	/*往文件写入数据*/
	ofstream outfile1(Pass[q].filecache, ios::binary);
	if (!outfile1)
	{
		cout << "恢复文件不能被打开！" << endl;
		return 0;
	}
	outfile1.write((char*)&currentN3, sizeof(currentN3));
	for (int i = 0;i < currentN3;i++)
	{
		outfile1.write((char*)&cache[i], sizeof(cache[i]));
	}
	outfile1.close();
	ofstream outfile(cou[x].file, ios::binary);
	
	outfile.write((char*)&currentN2, sizeof(currentN2));
	for (int i = 0;i < currentN2;i++)
	{
		outfile.write((char*)&stu[i], sizeof(stu[i]));
	}
	outfile.close();
	ofstream fileout(Pass[q].filecourse, ios::binary);
	if (!fileout)
	{
		cout << "文件2不能被打开！" << endl;
		return 0;
	}
	fileout.write((char*)&currentN1, sizeof(currentN1));
	for (int i = 0;i < currentN1;i++)
	{
		fileout.write((char*)&cou[i], sizeof(cou[i]));
	}
	fileout.close();
	ofstream Fileout("password.dat", ios::binary);
	if (!Fileout)
	{
		cout << "文件不能被打开！" << endl;
		return 0;
	}
	Fileout.write((char*)&currentN, sizeof(currentN));
	for (int i = 0;i < currentN;i++)
	{
		Fileout.write((char*)&Pass[i], sizeof(Pass[i]));
	}
	Fileout.close();
	return 0;
}
