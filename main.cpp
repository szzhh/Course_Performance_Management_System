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
	cout << "\n\n\t\t\t\t\t\t\t��===================================================��\n";
	cout << "\t\t\t\t\t\t\t?(^o^)?���ﻶӭʹ�ÿγ�ƽʱ�ɼ��������ϵͳ����?(^o^)?\n\n\n";
	cout << "\t\t\t\t\t\t\t\t\t   1.��¼�˺�\n";
	cout << "\t\t\t\t\t\t\t\t\t   2.ע���˺�\n";
	cout << "\t\t\t\t\t\t\t\t\t   3.�޸�����\n";
	cout << "\t\t\t\t\t\t\t\t\t   4.ɾ���˺�\n";
	cout << "\t\t\t\t\t\t\t\t\t   5.���ز˵�\n";
	cout << "\t\t\t\t\t\t\t\t\t   6.�˳�ϵͳ\n";
	cout << "\n\n\t\t\t\t\t\t\t��================================================��\n";
}
void welcome1()
{
	system("cls");
	cout << "\n\n\t\t\t\t\t\t\t��=================================================��\n";
	cout << "\t\t\t\t\t\t\t?(^o^)?���ﻶӭʹ�ÿγ���Ϣ����ϵͳ����?(^o^)?\n\n\n";
	cout << "\t\t\t\t\t\t\t\t\t   1.��ӿγ�\n";
	cout << "\t\t\t\t\t\t\t\t\t   2.�鿴�γ�\n";
	cout << "\t\t\t\t\t\t\t\t\t   3.����γ�\n";
	cout << "\t\t\t\t\t\t\t\t\t   4.���ز˵�\n";
	cout << "\t\t\t\t\t\t\t\t\t   5.�����ϼ��˵�\n";
	cout << "\n\n\t\t\t\t\t\t\t��================================================��\n";
}
void welcome2()
{
	system("cls");
	cout << "\n\n\t\t\t\t\t\t\t��================================================��\n";
	cout << "\t\t\t\t\t\t\t?(^o^)?���ﻶӭʹ�ÿγ���Ϣ����ϵͳ����?(^o^)?\n\n\n";
	cout << "\t\t\t\t\t\t\t\t\t   1.�鿴�γ���Ϣ\n";
	cout << "\t\t\t\t\t\t\t\t\t   2.�޸Ŀγ���Ϣ\n";
	cout << "\t\t\t\t\t\t\t\t\t   3.ѧ���ɼ���Ϣ\n";
	cout << "\t\t\t\t\t\t\t\t\t   4.���ر����˵�\n";
	cout << "\t\t\t\t\t\t\t\t\t   5.�����ϼ��˵�\n";
	cout << "\n\n\t\t\t\t\t\t\t��================================================��\n";
}
void welcome3()
{
	system("cls");
	cout << "\n\n\t\t\t\t\t\t\t��================================================��\n";
	cout << "\t\t\t\t\t\t\t?(^o^)?���ﻶӭʹ��ѧ����Ϣ����ϵͳ����?(^o^)?\n\n\n";
	cout << "\t\t\t\t\t\t\t\t\t   1.�����Ϣ\n";
	cout << "\t\t\t\t\t\t\t\t\t   2.��ʾ��Ϣ\n";
	cout << "\t\t\t\t\t\t\t\t\t   3.������Ϣ\n";
	cout << "\t\t\t\t\t\t\t\t\t   4.�޸���Ϣ\n";
	cout << "\t\t\t\t\t\t\t\t\t   5.ɾ����Ϣ\n";
	cout << "\t\t\t\t\t\t\t\t\t   6.�ָ���Ϣ\n";
	cout << "\t\t\t\t\t\t\t\t\t   7.ͳ����Ϣ\n";
	cout << "\t\t\t\t\t\t\t\t\t   8.���ز˵�\n";
	cout << "\t\t\t\t\t\t\t\t\t   9.�˳�ϵͳ\n";
	cout << "\n\n\t\t\t\t\t\t\t��================================================��\n";
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
		cout << "\n������>>";
		cin >> choice;
		e = getchar();
		switch (choice)
		{
		case 1:
		{
			if (currentN == 0)
			{
				cout << "��ǰû���û�������ע�ᣡ" << endl;
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
					cout << "\n\n\t\t\t\t\t\t\t��===============================================��\n";
					cout << "\t\t\t\t\t\t\t\t?(^o^)?�����¼�������?(^o^)?\n\n";
					cout << "\t\t\t\t\t\t\t\t�û�����";
					getline(cin, username, '\n');
					cout << "\t\t\t\t\t\t\t\t���룺";
					int z;
					for (z = 0;z < 20;z++)
					{
						a[z] = _getch();
						if (a[z] == 13) //��Ӧ�س�
						{
							break;
						}
						else if (a[z] == '\b')  //��Ӧ�˸��
						{
							if (z == 0) //�����ǰ�Ѿ�û���ַ�����ֱ������
							{
								continue;
							}
							//��Ļ��ɾ�����ַ���ɿո񣬲����˹��
							cout << "\b";
							cout << " ";
							cout << "\b";
							//��������Ӧλ�����0
							z--;
							a[z] = 0;
							//��i��ǰ��һλ����Ϊ��������ִ��forѭ����i++
							z--;
							//������뻺�壬����س��������ַ�����
							cin.clear();
						}
						else
						{
							cout << "*";
						}
					}
					cout << endl;
					//a�ַ�����β��������password
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
						cout << "��¼�ɹ���" << endl;

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
							cout << "\n������>>";
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
									cout << "��4���ز˵���" << endl;
									break;
								}
								else
								{
									cout << "������γ̱�ţ�";
									cin >> x;
									x--;
									welcome2();
									choice2 = 1;
									while (choice2 != 5)
									{
										welcome2();
										cout << "\n������>>";
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
												cout << "\n������>>";
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
													cout << "\t\t��������ر��˵�\n";
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
											cout << "\t\t��������ر��˵�\n";
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
								cout << "\t\t��������ر��˵�\n";
								welcome1();
							}
						}
						
					}
					else
					{
						cout << "\t\t\t\t\t\t\t\t�û����������������������" << "\n\t\t\t\t\t\t\t\t";
					}
					cout << "�Ƿ������¼(Y or N)?"<<endl;
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
			cout << "�˳��ɹ���" << endl;
			break;
		}
		default:
			cout << "\t\t��������ر��˵�\n";
			welcome();
		}
	}

	/*���ļ�д������*/
	ofstream outfile1(Pass[q].filecache, ios::binary);
	if (!outfile1)
	{
		cout << "�ָ��ļ����ܱ��򿪣�" << endl;
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
		cout << "�ļ�2���ܱ��򿪣�" << endl;
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
		cout << "�ļ����ܱ��򿪣�" << endl;
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
