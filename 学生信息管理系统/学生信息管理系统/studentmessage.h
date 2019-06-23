#pragma once
#include"control.h"
#include"student.h"
class Studentmassage
{
public:
	Studentmassage();
	~Studentmassage();
	void AdMenu();
	void StMenu();
	void Save();
	void ModifyLesson();
	void ModifyItem();
	void Modify();//修改函数
	void AddItem()
	{
		End->Input();
		End->Next = new Student;
		End = End->Next;
		cout << "\t\t";
		slowout(cout, "添加成功!\n");
		cout << "\t\t点击任意键以继续……";
		_getch();
	}
	void AddLesson();
	void Add();//增加函数
	void RemoveItem();
	void RemoveLesson();
	void Remove();//删除函数
	void DisplayStudent()//陈列数据
	{
		if (Head->Next == End)slowout(cout, "\t\t系统未保存学生数据\n");
		else for (Student * p = Head->Next; p != End; p = p->Next)
		{
			p->Show(); Sleep(500);
		}
		cout << "\t\t点击任意键以继续……";
		_getch();
	}
	void DisplayLesson();
	void Display();//展示函数
	void Find();
	void Statistics();
	void FindPlus();//查找函数
	void Sort();//排序
	void Others();//其他功能
	void Swap(Student *, Student *);
	int ListCount();//记录数据个数
	Student * Head, *End;
	ifstream in;
	ofstream out;
	Student *FindItem(string name)
	{
		for (Student* p = Head; p != End; p = p->Next)//匹配成功则返回上一个指针，不成功就返回空
			if (p->Next->name == name)return p;
		return NULL;
	}
	Student *FindID(string Id)
	{
		for (Student* p = Head; p != End; p = p->Next)//匹配成功则返回上一个指针，不成功就返回空
			if (p->Next->Id == Id)return p;
		return NULL;
	}
};
//﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌构造函数﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌
Studentmassage::Studentmassage()
{
	Head = new Student;
	Head->Next = new Student;
	End = Head->Next;
	in.open("Message.txt");
	string i; getline(in, i);
	in.seekg(0, ios::beg);
	if (i.empty())
	{
		cout << "\t\t";
		slowout(cout, "读取学生信息中……\n");
		cout << "\t\t系统中暂无学生信息。" << endl;
	}
	else
	{
		while (!in.eof())
		{
			End->ReadFile(in);
			if (End->name[0] == '\0')break;
			End->Next = new Student;
			End = End->Next;
		}
		in.close();
		cout << "\t\t";
		slowout(cout, "读取学生信息中……\n");
		cout << "\t\t读取成功！\n";
	}
}//将文本中的数据读入，若文本为空，则为新系统
//﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌析构函数﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌
Studentmassage::~Studentmassage()//完全释放空间
{
	for (Student * temp; Head->Next != End;)
	{
		temp = Head->Next;
		Head->Next = Head->Next->Next;
		delete temp;
	}
	delete Head, End;
}
//﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌学生菜单﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌
void Studentmassage::StMenu()
{
		cout << "〓〓〓〓〓〓〓〓〓〓  ☆        Student Chorme         ☆  〓〓〓〓〓〓〓〓〓〓" << endl;
		cout << "〓〓〓〓〓〓〓★★★★★          同学！你好           ★★★★★〓〓〓〓〓〓〓" << endl;
		cout << "〓〓〓〓〓〓〓〓〓★  ☆          1.查找数据           ☆  ★〓〓〓〓〓〓〓〓〓" << endl;
		cout << "〓〓〓〓〓〓〓〓〓★  ☆          2.数据排序           ☆  ★〓〓〓〓〓〓〓〓〓" << endl;
		cout << "〓〓〓〓〓〓〓〓〓★  ☆          3.展示数据           ☆  ★〓〓〓〓〓〓〓〓〓" << endl;
		cout << "〓〓〓〓〓〓〓〓〓★  ☆          4.关于系统           ☆  ★〓〓〓〓〓〓〓〓〓" << endl;
		cout << "〓〓〓〓〓〓〓〓〓★  ☆          0.退出系统           ☆  ★〓〓〓〓〓〓〓〓〓" << endl;
		cout << "〓〓〓〓〓〓〓〓〓★  ☆      好好学习，天天向上！     ☆  ★〓〓〓〓〓〓〓〓〓" << endl;
		cout << "\n\t\t\n\t\t请选择：";

}
//﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌管理员菜单﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌
void Studentmassage::AdMenu()
{
	cout << "〓〓〓〓〓〓〓〓〓〓  ☆         Student Chorme        ☆  〓〓〓〓〓〓〓〓〓〓" << endl;
	cout << "〓〓〓〓〓〓〓★★★★★         ★★★★★★★        ★★★★★〓〓〓〓〓〓〓" << endl;
	cout << "〓〓〓〓〓〓〓★★★★★         管理员，您好！        ★★★★★〓〓〓〓〓〓〓" << endl;
	cout << "〓〓〓〓〓〓〓〓〓★  ☆          1.新增数据           ☆  ★〓〓〓〓〓〓〓〓〓" << endl;
	cout << "〓〓〓〓〓〓〓〓〓★  ☆          2.展示数据           ☆  ★〓〓〓〓〓〓〓〓〓" << endl;
	cout << "〓〓〓〓〓〓〓〓〓★  ☆          3.修改数据           ☆  ★〓〓〓〓〓〓〓〓〓" << endl;
	cout << "〓〓〓〓〓〓〓〓〓★  ☆          4.删除数据           ☆  ★〓〓〓〓〓〓〓〓〓" << endl;
	cout << "〓〓〓〓〓〓〓〓〓★  ☆          5.查找数据           ☆  ★〓〓〓〓〓〓〓〓〓" << endl;
	cout << "〓〓〓〓〓〓〓〓〓★  ☆          6.其他功能           ☆  ★〓〓〓〓〓〓〓〓〓" << endl;
	cout << "〓〓〓〓〓〓〓〓〓★  ☆          0.退出系统           ☆  ★〓〓〓〓〓〓〓〓〓" << endl;
	cout << "\n\t\t\n\t\t请选择：";
}
//﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌查找函数﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌
void Studentmassage::Find()
{
	string name;
	string Id;
	int x;
	Student * p = NULL;
	cout << "\n\t\t*********************************\n";
	cout << "\t\t※ 1.按学生的姓名查找\n\t\t※ 2.按学生学号查找";
	cout << "\n\t\t*********************************\n请选择：";
	cin >> x;
	switch (x)
	{
	case 1:
	{
		cout << "\t\t请输入要查找的学生的姓名："; cin >> name;
		if (p = FindItem(name))
		{
			p->Next->Show();
			cout << "\t\t点击任意键以继续……";
			_getch();
		}
		else
		{
			cout << "\t\t";
			slowout(cout, "没有找到该姓名的学生！\n");
			cout << "\t\t点击任意键以继续……";
			_getch();
		}
	}break;
	case 2:
	{
		cout << "\t\t请输入要查找的学生的学号："; cin >> Id;
		if (p = FindID(Id))
		{
			p->Next->Show();
			cout << "\t\t点击任意键以继续……";
			_getch();
		}
		else
		{
			cout << "\t\t";
			slowout(cout, "没有找到该学号的学生！\n");
			cout << "\t\t点击任意键以继续……";
			_getch();
		}
	}break;
	}
}
//﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌修改学生信息﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌
void Studentmassage::ModifyItem()    //修改信息
{
	string name;
	Student * p = NULL;
	cout << "\t\t请输入要修改的人的姓名:"; cin >> name;
	if (p = FindItem(name))
	{
		cout << "\t\t已找到学生的信息，请输入新的信息!" << endl;
		p->Next->Input();
		cout << "\t\t修改成功！" << endl;
		cout << "\t\t点击任意键以继续……";
		_getch();
	}
	else
	{
		cout << "\t\t没有找到!" << endl;
		cout << "\t\t点击任意键以继续……";
		_getch();
	}
}
//﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌删除学生信息﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌
void Studentmassage::RemoveItem()        // 删除信息
{
	string name;
	Student * p = NULL, *temp = NULL;
	cout << "\t\t请输入要删除的学生的姓名:" << endl; cin >> name;
	if (p = FindItem(name))
	{
		temp = p->Next;
		p->Next = p->Next->Next;
		delete temp;
		cout << "\t\t";
		slowout(cout, "删除成功!");
		cout << "\n\t\t点击任意键以继续……";
		_getch();
	}
	else
	{
		cout << "\t\t没有找到!" << endl;
		cout << "\n\t\t点击任意键以继续……";
		_getch();
	}
}
//﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌交换数据﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌
void Studentmassage::Swap(Student *p1, Student *p2)//交换两个combox变量的数据域
{
	Student *temp = new Student;
	temp->name = p1->name;
	temp->Id = p1->Id;
	temp->GPA = p1->GPA;
	temp->Head = p1->Head;
	temp->End = p1->End;
	p1->name = p2->name;
	p1->Id = p2->Id;
	p1->GPA = p2->GPA;
	p1->Head = p2->Head;
	p1->End = p2->End;
	p2->name = temp->name;
	p2->Id = temp->Id;
	p2->GPA = temp->GPA;
	p2->Head = temp->Head;
	p2->End = temp->End;
}
//﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌统计数据﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌
int Studentmassage::ListCount()//统计当前链表的记录总数，返回一个整数
{
	if (!Head)return 0;
	int n = 0;
	for (Student * p = Head->Next; p != End; p = p->Next)n++;
	return n;
}
//﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌数据排序﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌
void Studentmassage::Sort()//对当前链表进行排序
{
	cout << "\n\t\t*********************************\n";
	cout << "\t\t※ 1.按照学号排序\n\t\t※ 2.按照绩点排序";
	cout << "\n\t\t*********************************\n请选择：";
	int x; cin >> x;
	if (x < 1 || x>2)
	{
		cout << "\t\t选择错误!\n\t\t点击任意键以继续……";
		_getch();
		return;
	}
	Student *p = NULL, *k = NULL;
	int n = Studentmassage::ListCount();
	slowout(cout, "\t\t共有"); cout << n; slowout(cout, "个学生数据\n");
	if (n < 2)
	{
		cout << "\t\t无法排序！！！" << endl;
		cout << "\t\t点击任意键以继续……";
		_getch();
		return;
	}
	slowout(cout, "\t\t排序中......\n");
	switch (x)
	{
	case 1:
	{
		for (p = Head->Next; p != End; p = p->Next)
			for (k = p->Next; k != End; k = k->Next)
				if (p->Id > k->Id)Studentmassage::Swap(p, k);
		break;
	}
	case 2:
	{
		for (p = Head->Next; p != End; p = p->Next)
			for (k = p->Next; k != End; k = k->Next)
				if (p->GPA < k->GPA)Studentmassage::Swap(p, k);
		break;
	}
	}
	Save();
	cout << "\t\t排序完成！\n\t\t点击任意键以继续……";
	_getch();
	return;
}
//﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌保存数据﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌
void Studentmassage::Save()//把数据保存在Message文件中
{

	out.open("Message.txt");
	for (Student *p = Head->Next; p != End; p = p->Next)
	{
		out << p->name << '\t' << p->Id << '\t';
		for (Lesson* q = p->Head->Next; q != p->End; q = q->Next)
		{
			out << q->score << '\t';
		}
		out <<  setprecision(3) << p->GPA << endl;
	}
	out.close();
}
//﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌增加课程﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌
void Studentmassage::AddLesson()
{
	string n; int c;
	cout << "\t\t请输入增加的课程名称："; cin >> n;
	cout << "\t\t请输入增加的课程学分："; cin >> c;
	for (Student * p = Head; p != End; p = p->Next)
		p->AddLesson(n,c); 
	End->AddLesson(n, c);//令End结点也更新化
	ofstream out("Lesson.txt", ios::app);
	out<< n << '\t' << c << '\t';
	cout << "\t\t增加完成……"<<endl;
	cout << "\t\t点击任意键以继续……"<<endl;
	_getch();
}
//﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌修改课程﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌
void Studentmassage::ModifyLesson()
{
	string n1,n2; int c;
	cout << "\t\t请输入要修改的课程名称："; cin >> n1;
	cout << "\t\t请输入修改后的课程名称："; cin >> n2;
	cout << "\t\t请输入修改后的课程学分："; cin >> c;
	for (Student * p = Head; p != End; p = p->Next)
		p->ModifyLesson(n1,n2, c);
	End->ModifyLesson(n1,n2, c);//令End结点也更新化
	ofstream out("Lesson.txt");
	Student *Newlist = Head->Next;
	for (Lesson* p = Newlist->Head->Next; p != Newlist->End; p = p->Next)
		out << p->name << '\t' << p->credit << '\t';
	cout << "\t\t修改完成……" << endl;
	cout << "\t\t点击任意键以继续……" << endl;
	_getch();
}
//﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌删除课程信息﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌
void Studentmassage::RemoveLesson()
{
	string n; 
	cout << "\t\t请输入删除的课程名称："; cin >> n;
	for (Student * p = Head; p != End; p = p->Next)
		p->RemoveLesson(n);
	End->RemoveLesson(n);//令End结点也更新化
	ofstream out("Lesson.txt");
	Student *Newlist = Head->Next;
	for (Lesson* p = Newlist->Head->Next; p != Newlist->End; p = p->Next)
		out << p->name << '\t' << p->credit << '\t';
	cout << "\t\t删除完成……" << endl;
	cout << "\t\t点击任意键以继续……" << endl;
	_getch();
}
//﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌统计课程﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌
void Studentmassage::Statistics()
{
	cout << "\t\t系统中存在的课程有：" << endl;
	Student *Newlist = Head->Next;
	for (Lesson* p = Newlist->Head->Next; p != Newlist->End; p = p->Next)
	{
		cout <<"\t\t"<< p->name << endl;
	}
	cout << "\t\t请选择要统计的课程：" << endl;
	string l; double max=0, min=100, sum=0;
	int n = 0; int c;
	cin >> l;	
	Student *find = new Student;
	Lesson *s = find->FindLesson(l);
	if (s == NULL)
	{
		cout << "\t\t没有该课程" << endl;
		cout << "\t\t点击任意键以继续……" << endl;
		_getch();
	}
	else
	{
		c=s->Next->credit;
		for (Student * P = Head; P != End; P = P->Next)
		{
			Lesson *s = P->FindLesson(l);
			s = s->Next;
			if (s->score != 0)
			{
				cout << "姓名：" << P->name << " 得分：" << s->score << endl;
				sum += s->score; n++;
				if (s->score > max)max = s->score;
				if (s->score < min)min = s->score;
			}
		}
		cout << l <<" 学分："<<c<< " 最高分：" << max << " 最低分：" << min << " 平均分：" << sum / n << endl;
		cout << "\t\t点击任意键以继续……" << endl;
		_getch();
	}
}
//﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌展示课程﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌
void Studentmassage::DisplayLesson()
{
	string s;
	ifstream in("Lesson.txt", ios::in);
	getline(in, s);
	if(!s.empty())
	{
		Student *Newlist = Head->Next;
		for (Lesson* p = Newlist->Head->Next; p != Newlist->End; p = p->Next)
		{
			string l;
				double max = 0, min = 100, sum = 0;
				int n = 0; int c;
				l = p->name; c = p->credit;
				cout << l << " 学分：" << c << endl;
				for (Student * P = Head; P != End; P = P->Next)
				{
					Lesson *s = P->FindLesson(l);
						s = s->Next;
					if (s->score != 0)
					{
						cout << "姓名：" << P->name << " 得分：" << s->score << endl;
						sum += s->score; n++;
						if (s->score > max)max = s->score;
						if (s->score < min)min = s->score;
					}
				}
			cout << "最高分：" << max << " 最低分：" << min << " 平均分：" << sum / n << endl;
			cout << endl; Sleep(500);
		}
	}
	else 
	{
		slowout(cout , "\t\t系统中未保存课程数据\n" );
	}
	cout << "\t\t点击任意键以继续……" << endl;
	_getch();
}
//﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌新增﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌
void Studentmassage::Add()
{
	system("cls");
	cout << "\n\t\t*********************************\n";
	cout << "\t\t※ 1.新增学生信息\n\t\t※ 2.新增课程信息";
	cout << "\n\t\t*********************************\n请选择：";
	int x; cin >> x;
	if (x < 1 || x>2)
	{
		cout << "\t\t选择错误!\n\t\t点击任意键以继续……";
		_getch();
		return;
	}
	switch (x)
	{
	case 1:
	{
		AddItem();
		break;
	}
	case 2:
	{
	
		AddLesson();
		break;
	}
	}
	Save();
	return;
}
//﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌展示﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌
void Studentmassage::Display()
{
	system("cls");
	cout << "\n\t\t*********************************\n";
	cout << "\t\t※ 1.以学生为单位展示\n\t\t※ 2.以课程为单位展示";
	cout << "\n\t\t*********************************\n请选择：";
	int x; cin >> x;
	if (x < 1 || x>2)
	{
		cout << "\t\t选择错误!\n\t\t点击任意键以继续……";
		_getch();
		return;
	}
	switch (x)
	{
	case 1:
	{
		DisplayStudent();
		break;
	}
	case 2:
	{

		DisplayLesson();
		break;
	}
	}
	return;
}
//﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌修改﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌
void Studentmassage::Modify()
{
	system("cls");
	cout << "\n\t\t*********************************\n";
	cout << "\t\t※ 1.修改学生信息\n\t\t※ 2.修改课程信息";
	cout << "\n\t\t*********************************\n请选择：";
	int x; cin >> x;
	if (x < 1 || x>2)
	{
		cout << "\t\t选择错误!\n\t\t点击任意键以继续……";
		_getch();
		return;
	}
	switch (x)
	{
	case 1:
	{
		ModifyItem();
		break;
	}
	case 2:
	{

		ModifyLesson();
		break;
	}
	}
	Save();
	return;
}
//﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌删除﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌
void Studentmassage::Remove()
{
	system("cls");
	cout << "\n\t\t*********************************\n";
	cout << "\t\t※ 1.删除学生信息\n\t\t※ 2.删除课程信息";
	cout << "\n\t\t*********************************\n请选择：";
	int x; cin >> x;
	if (x < 1 || x>2)
	{
		cout << "\t\t选择错误!\n\t\t点击任意键以继续……";
		_getch();
		return;
	}
	switch (x)
	{
	case 1:
	{
		RemoveItem();
		break;
	}
	case 2:
	{

		RemoveLesson();
		break;
	}
	}
	Save();
	return;
}
//﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌查找﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌
void Studentmassage::FindPlus()
{
	system("cls");
	cout << "\n\t\t*********************************\n";
	cout << "\t\t※ 1.查找学生信息\n\t\t※ 2.统计课程信息";
	cout << "\n\t\t*********************************\n请选择：";
	int x; cin >> x;
	if (x < 1 || x>2)
	{
		cout << "\t\t选择错误!\n\t\t点击任意键以继续……";
		_getch();
		return;
	}
	switch (x)
	{
	case 1:
	{
		Find();
		break;
	}
	case 2:
	{

		Statistics();
		break;
	}
	}
	return;
}
//﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌其他﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌
void Studentmassage::Others()
{
	system("cls");
	cout << "\n\t\t*********************************\n";
	cout << "\t\t※ 1.排序成绩信息\n\t\t※ 2.修改管理员密码\n\t\t※ 3.格式化系统\n\t\t※ 4.关于系统";
	cout << "\n\t\t*********************************\n请选择：";
	int x; cin >> x;
	if (x < 1 || x>4)
	{
		cout << "\t\t选择错误!\n\t\t点击任意键以继续……";
		_getch();
		return;
	}
	switch (x)
	{
	case 1:
	{
		Sort();
		break;
	}
	case 2:
	{
		ChangePass();
		break;
	}
	case 3:
	{
		Initialization(); break;
	}
	case 4:
	{
		system("cls");
		System(); 
	}
	}
	return;
}