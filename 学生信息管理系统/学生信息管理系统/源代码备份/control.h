#pragma once
#include<iostream>
#include<string>
#include<windows.h>
#include<fstream>
#include <iomanip>
#include<conio.h>
using namespace std;
void slowout(ostream&out, string s)
{
	for (int i = 0; i < s.length(); i++)
	{
		out << s[i];
		Sleep(100);
	}
}
void slowout(ostream&out, string s,int n)
{
	for (int i = 0; i < s.length(); i++)
	{
		out << s[i];
		Sleep(n);
	}
}
string PasswordInput()
{
	char password[7];
	password[6] = '\0';
	char c;
	int i = 0;//��¼������λ��  
	while (1) {
		c = _getch();//��������ȡһ���ַ�  
		 //��Ϊ�˸�������������ǰ��  
		if (c == 8)
		{
			if (i > 0)
			{
				cout << "\b";
				i--;
			}

		}//�س������������  
		else if (c == '\r')
		{
			password[i] = '\0'; break;

		}
		//��ֹ���볬��6λ  
		else if (i < 6) {
			cout << "*";
			password[i] = c;
			i++;
		}
	}
	return password;
}
int Password()
{
	cout << "\t\t������6λ��������:\n\t\t";
	ifstream in("PassWord.dat",ios::in);
	string p;
	char q[7];
	in.read((char*)&q, sizeof(char[7]));
	in.close();
	p = PasswordInput();
	if (p == q) { cout << "\n\t\t������ȷ!\n\t\t��ӭ����Ա\n";  return 1; }
	else
	{
		cout << "\n\t\t������󣬷�������" << endl;
		cout << "\t\t��ѡ����һ����" << endl;
		cout << "\t\t0��������һ��  1���ٴ���������\n\t\t";
		int c; cin >> c;
		switch (c)
		{
		case 0:return 0;
		case 1: Password(); break;
		default:cout << "\t\tѡ�����" << endl; return 0;
		}
	}
}
void ChangePass()
{
	cout << "\t\tȷ��Ҫ��������ô��Y/N\n\t\t\n\t\t";
	char c; cin >> c;
	if (c == 'Y'||c=='y')
	{
		while (Password() == 1)
		{
			cout << "\t\t�������µ�6λ���ֹ������룺\n\t\t" ;
			string New; 
			New = PasswordInput();
			cout << endl;
			ofstream out("PassWord.dat",ios::binary||ios::out);
			out << New;
			cout << "\t\t�¹�������Ϊ��" << New << "\n\t\t���óɹ�!\n\t\t���������Լ�������";
			out.close();
			_getch();
		}
	}
}
void Initialization()//��ʽ��ϵͳ
{
	ofstream out1("Lesson.txt");
	out1.close();
	ofstream out2("Message.txt");
	out2.close();
	ofstream out3("PassWord.dat", ios::binary || ios::out);
	char newp[7] = "000000";
	out3.write((char*)newp, sizeof(char[7]));
	out3.close();
}
