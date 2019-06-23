#pragma once
#include"control.h"
class Lesson
{
public:
	Lesson *Next;
	string name;
	int score;
	int credit;
};
class Student
{
public:
	string name;
	string Id;
	double GPA;
	Student * Next;
	Lesson *Head, *End;
	Student()//student的构造函数，同时构造一个课程链表，动态储存课程成绩
	{
		Head = new Lesson;
		Head->Next = new Lesson;
		End = Head->Next;
		ifstream in("Lesson.txt");
		string i; getline(in, i);
		in.seekg(0, ios::beg);
		if (!i.empty())
		{
			while (!in.eof())
			{
				in >> End->name;
				in >> End->credit;
				if (End->name[0] == '\0')break;
				End->Next = new Lesson;
				End = End->Next;
			}
			in.close();
		}
	}
	void RefreshGPA()
	{
		GPA = 0;
		double gpa=0; int Credit=0;
		for (Lesson* p = Head->Next; p != End; p = p->Next)
		{
			if (p->score >= 90) { gpa = 4 * p->credit;  GPA += gpa; Credit += p->credit; }
			else if (p->score >= 60 && p->score <= 89) { gpa = (p->score / 10 - 5)* p->credit; GPA += gpa; Credit += p->credit; }
			else if (p->score < 60 && p->score>0) { gpa = 0; GPA += gpa; Credit += p->credit; }
		}
		GPA = GPA / Credit;
	}//用于刷新GPA的数值，在每次输入完成之后调用
	void Input()//直接输入学生信息
	{
		int x;
		cout << "\t\t请输入学生的姓名：";  cin >> name;
		cout << "\t\t请输入学生的学号：";  cin >> Id;
		for (Lesson* p = Head->Next; p != End; p = p->Next)
		{
			cout << "\t\t请输入" << p->name << "的成绩：";
			while (cin >> x)
			{
				if (x <= 100 && x >= 0) { p->score = x; break; }
				else { cout << "\t\t成绩有误，请重新输入："; }
			}//只保存有效的成绩
		}
			RefreshGPA();
	}
	void ReadFile(istream & in)
	{
		in >> name >> Id;
		for (Lesson* p = Head->Next; p!= End; p = p->Next)in >> p->score;
		in >> GPA;
	}
	void Show()
	{
		cout << "姓名:" << name << endl << "学号:" << Id << endl;
		for (Lesson* p = Head->Next; p!= End; p = p->Next)
			if (p->score > 0)
				cout << p->name << "成绩：" << p->score << endl;//0分的视为没选课，不统计
		cout << "绩点：" << setprecision(3) << GPA << endl<<endl<<endl;
	}
	void AddLesson(string n,int c)//单个学生中增加某个课程
	{
		End->name=n;
		End->credit = c;
		End->score = 0;
		End->Next = new Lesson;
		End = End->Next;
	}
	Lesson *FindLesson(string n)
	{
		for (Lesson* p= Head; p != End; p = p->Next)//匹配成功则返回上一个指针，不成功就返回空
			if (p->Next->name == n)return p;
		return NULL;
	}
	void RemoveLesson(string n)//单个学生中删除某个课程
	{
		Lesson * p = NULL, *temp = NULL;
		p = FindLesson(n);
		temp = p->Next;
		p->Next = p->Next->Next;
		delete  temp;
		RefreshGPA();
	}
	void ModifyLesson(string n1, string n2,int c)//单个学生中修改某个课程
	{
		Lesson * p = NULL;
		p = FindLesson(n1);
		p->Next->name = n2;
		p->Next->credit = c;
		p->Next->score = 0;
		RefreshGPA();
	}
};