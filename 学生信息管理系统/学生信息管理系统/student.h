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
	Student()//student�Ĺ��캯����ͬʱ����һ���γ�������̬����γ̳ɼ�
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
	}//����ˢ��GPA����ֵ����ÿ���������֮�����
	void Input()//ֱ������ѧ����Ϣ
	{
		int x;
		cout << "\t\t������ѧ����������";  cin >> name;
		cout << "\t\t������ѧ����ѧ�ţ�";  cin >> Id;
		for (Lesson* p = Head->Next; p != End; p = p->Next)
		{
			cout << "\t\t������" << p->name << "�ĳɼ���";
			while (cin >> x)
			{
				if (x <= 100 && x >= 0) { p->score = x; break; }
				else { cout << "\t\t�ɼ��������������룺"; }
			}//ֻ������Ч�ĳɼ�
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
		cout << "����:" << name << endl << "ѧ��:" << Id << endl;
		for (Lesson* p = Head->Next; p!= End; p = p->Next)
			if (p->score > 0)
				cout << p->name << "�ɼ���" << p->score << endl;//0�ֵ���Ϊûѡ�Σ���ͳ��
		cout << "���㣺" << setprecision(3) << GPA << endl<<endl<<endl;
	}
	void AddLesson(string n,int c)//����ѧ��������ĳ���γ�
	{
		End->name=n;
		End->credit = c;
		End->score = 0;
		End->Next = new Lesson;
		End = End->Next;
	}
	Lesson *FindLesson(string n)
	{
		for (Lesson* p= Head; p != End; p = p->Next)//ƥ��ɹ��򷵻���һ��ָ�룬���ɹ��ͷ��ؿ�
			if (p->Next->name == n)return p;
		return NULL;
	}
	void RemoveLesson(string n)//����ѧ����ɾ��ĳ���γ�
	{
		Lesson * p = NULL, *temp = NULL;
		p = FindLesson(n);
		temp = p->Next;
		p->Next = p->Next->Next;
		delete  temp;
		RefreshGPA();
	}
	void ModifyLesson(string n1, string n2,int c)//����ѧ�����޸�ĳ���γ�
	{
		Lesson * p = NULL;
		p = FindLesson(n1);
		p->Next->name = n2;
		p->Next->credit = c;
		p->Next->score = 0;
		RefreshGPA();
	}
};