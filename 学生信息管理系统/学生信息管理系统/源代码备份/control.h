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
	int i = 0;//记录已输入位数  
	while (1) {
		c = _getch();//先立即获取一个字符  
		 //若为退格的情况，则光标往前移  
		if (c == 8)
		{
			if (i > 0)
			{
				cout << "\b";
				i--;
			}

		}//回车，则结束输入  
		else if (c == '\r')
		{
			password[i] = '\0'; break;

		}
		//防止密码超过6位  
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
	cout << "\t\t请输入6位管理密码:\n\t\t";
	ifstream in("PassWord.dat",ios::in);
	string p;
	char q[7];
	in.read((char*)&q, sizeof(char[7]));
	in.close();
	p = PasswordInput();
	if (p == q) { cout << "\n\t\t密码正确!\n\t\t欢迎管理员\n";  return 1; }
	else
	{
		cout << "\n\t\t密码错误，访问受限" << endl;
		cout << "\t\t请选择下一步：" << endl;
		cout << "\t\t0：返回上一级  1：再次输入密码\n\t\t";
		int c; cin >> c;
		switch (c)
		{
		case 0:return 0;
		case 1: Password(); break;
		default:cout << "\t\t选项错误！" << endl; return 0;
		}
	}
}
void ChangePass()
{
	cout << "\t\t确定要重置密码么？Y/N\n\t\t\n\t\t";
	char c; cin >> c;
	if (c == 'Y'||c=='y')
	{
		while (Password() == 1)
		{
			cout << "\t\t请输入新的6位数字管理密码：\n\t\t" ;
			string New; 
			New = PasswordInput();
			cout << endl;
			ofstream out("PassWord.dat",ios::binary||ios::out);
			out << New;
			cout << "\t\t新管理密码为：" << New << "\n\t\t重置成功!\n\t\t点击任意键以继续……";
			out.close();
			_getch();
		}
	}
}
void Initialization()//格式化系统
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
