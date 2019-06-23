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
	if (p == q) { cout << "\n\t\t密码正确!\n";  return 1; }
	else
	{
		cout << "\n\t\t密码错误，访问被限制" << endl;
		cout << "\t\t请选择下一步：" << endl;
		cout << "\t\t0：返回上一级  1：再次输入密码\n\t\t";
		int c; cin >> c;
		switch (c)
		{
		case 0:return 0;
		case 1: {Password(); break; }
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
		while (Password())
		{
			cout << "\t\t请输入新的6位数字管理密码：\n\t\t" ;
			string New; 
			New = PasswordInput();
			cout << endl;
			ofstream out("PassWord.dat",ios::binary||ios::out);
			out << New;
			cout << "\t\t新管理密码为：" << New << "\n\t\t重置成功!\n\t\t点击任意键以继续……";
			out.close();
			_getch(); break;
		}
	}
}
void Initialization()//格式化系统
{
	cout << "\t\t确定要格式化系统么？？？Y/N\n\t\t请考虑清楚！\n\t\t";
	char c; cin >> c;
	if (c == 'Y' || c == 'y')
	{
		while (Password())
		{
			ofstream out1("Lesson.txt");
			out1.close();
			ofstream out2("Message.txt");
			out2.close();
			ofstream out3("PassWord.dat", ios::binary || ios::out);
			char newp[7] = "000000";
			out3.write((char*)newp, sizeof(char[7]));
			out3.close();
			slowout(cout, "\t\t系统格式化中……", 250);
			slowout(cout, "\n\t\t系统格式化完成！\n\t\t管理员密码重置为000000");
			cout << "\n\t\t点击任意键以退出系统……";
			_getch(); 
			exit(0);
		}
	}
	
}
void System()
{
	cout << "\t关于Student Chrome" << endl<<endl;
	cout << "            *********             *********         " << endl;
	cout << "         *****************   *****************       Student Chrome已是最新版本" << endl;
	cout << "       *****************************************     版本  19.0.0505.129 （x86）" << endl;
	cout << "     *********************************************  " << endl;
	cout << "    *********************************************** " << endl;
	cout << "    ***********************************************" << endl;
	cout << "    ***********************************************" << endl;
	cout << "    ***********************************************" << endl;
	cout << "    ***********************************************" << endl;
	cout << "    *********************************************** " << endl;
	cout << "     *********************************************  " << endl;
	cout << "      *******************************************   " << endl;
	cout << "       *****************************************    " << endl;
	cout << "        ***************************************     " << endl;
	cout << "         *************************************      " << endl;
	cout << "           *********************************        " << endl;
	cout << "             *****************************          " << endl;
	cout << "               *********Student*********            " << endl;
	cout << "                 *******Chorme********           版权所有 2019 Joe Dra.保留所有权利" << endl;
	cout << "                   ***11111001111***             Student Chrome 的诞生离不开华南理工大学和微软公司的开源项目" << endl;
	cout << "                      **11001011*                点击任意键以返回…… " << endl;
	cout << "                         *ptr*                      " << endl;
	cout << "                          mov                       " << endl;
	_getch();
}

