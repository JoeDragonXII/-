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
	void Modify();//�޸ĺ���
	void AddItem()
	{
		End->Input();
		End->Next = new Student;
		End = End->Next;
		cout << "\t\t";
		slowout(cout, "��ӳɹ�!\n");
		cout << "\t\t���������Լ�������";
		_getch();
	}
	void AddLesson();
	void Add();//���Ӻ���
	void RemoveItem();
	void RemoveLesson();
	void Remove();//ɾ������
	void DisplayStudent()//��������
	{
		if (Head->Next == End)slowout(cout, "\t\tϵͳδ����ѧ������\n");
		else for (Student * p = Head->Next; p != End; p = p->Next)
		{
			p->Show(); Sleep(500);
		}
		cout << "\t\t���������Լ�������";
		_getch();
	}
	void DisplayLesson();
	void Display();//չʾ����
	void Find();
	void Statistics();
	void FindPlus();//���Һ���
	void Sort();//����
	void Others();//��������
	void Swap(Student *, Student *);
	int ListCount();//��¼���ݸ���
	Student * Head, *End;
	ifstream in;
	ofstream out;
	Student *FindItem(string name)
	{
		for (Student* p = Head; p != End; p = p->Next)//ƥ��ɹ��򷵻���һ��ָ�룬���ɹ��ͷ��ؿ�
			if (p->Next->name == name)return p;
		return NULL;
	}
	Student *FindID(string Id)
	{
		for (Student* p = Head; p != End; p = p->Next)//ƥ��ɹ��򷵻���һ��ָ�룬���ɹ��ͷ��ؿ�
			if (p->Next->Id == Id)return p;
		return NULL;
	}
};
//�k�k�k�k�k�k�k�k�k�k�k�k���캯���k�k�k�k�k�k�k�k�k�k�k�k
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
		slowout(cout, "��ȡѧ����Ϣ�С���\n");
		cout << "\t\tϵͳ������ѧ����Ϣ��" << endl;
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
		slowout(cout, "��ȡѧ����Ϣ�С���\n");
		cout << "\t\t��ȡ�ɹ���\n";
	}
}//���ı��е����ݶ��룬���ı�Ϊ�գ���Ϊ��ϵͳ
//�k�k�k�k�k�k�k�k�k�k�k�k���������k�k�k�k�k�k�k�k�k�k�k�k
Studentmassage::~Studentmassage()//��ȫ�ͷſռ�
{
	for (Student * temp; Head->Next != End;)
	{
		temp = Head->Next;
		Head->Next = Head->Next->Next;
		delete temp;
	}
	delete Head, End;
}
//�k�k�k�k�k�k�k�k�k�k�k�kѧ���˵��k�k�k�k�k�k�k�k�k�k�k
void Studentmassage::StMenu()
{
		cout << "��������������������  ��        Student Chorme         ��  ��������������������" << endl;
		cout << "��������������������          ͬѧ�����           �������������������" << endl;
		cout << "��������������������  ��          1.��������           ��  �������������������" << endl;
		cout << "��������������������  ��          2.��������           ��  �������������������" << endl;
		cout << "��������������������  ��          3.չʾ����           ��  �������������������" << endl;
		cout << "��������������������  ��          4.����ϵͳ           ��  �������������������" << endl;
		cout << "��������������������  ��          0.�˳�ϵͳ           ��  �������������������" << endl;
		cout << "��������������������  ��      �ú�ѧϰ���������ϣ�     ��  �������������������" << endl;
		cout << "\n\t\t\n\t\t��ѡ��";

}
//�k�k�k�k�k�k�k�k�k�k�k�k����Ա�˵��k�k�k�k�k�k�k�k�k�k�k
void Studentmassage::AdMenu()
{
	cout << "��������������������  ��         Student Chorme        ��  ��������������������" << endl;
	cout << "��������������������         ��������        �������������������" << endl;
	cout << "��������������������         ����Ա�����ã�        �������������������" << endl;
	cout << "��������������������  ��          1.��������           ��  �������������������" << endl;
	cout << "��������������������  ��          2.չʾ����           ��  �������������������" << endl;
	cout << "��������������������  ��          3.�޸�����           ��  �������������������" << endl;
	cout << "��������������������  ��          4.ɾ������           ��  �������������������" << endl;
	cout << "��������������������  ��          5.��������           ��  �������������������" << endl;
	cout << "��������������������  ��          6.��������           ��  �������������������" << endl;
	cout << "��������������������  ��          0.�˳�ϵͳ           ��  �������������������" << endl;
	cout << "\n\t\t\n\t\t��ѡ��";
}
//�k�k�k�k�k�k�k�k�k�k�k�k���Һ����k�k�k�k�k�k�k�k�k�k�k�k
void Studentmassage::Find()
{
	string name;
	string Id;
	int x;
	Student * p = NULL;
	cout << "\n\t\t*********************************\n";
	cout << "\t\t�� 1.��ѧ������������\n\t\t�� 2.��ѧ��ѧ�Ų���";
	cout << "\n\t\t*********************************\n��ѡ��";
	cin >> x;
	switch (x)
	{
	case 1:
	{
		cout << "\t\t������Ҫ���ҵ�ѧ����������"; cin >> name;
		if (p = FindItem(name))
		{
			p->Next->Show();
			cout << "\t\t���������Լ�������";
			_getch();
		}
		else
		{
			cout << "\t\t";
			slowout(cout, "û���ҵ���������ѧ����\n");
			cout << "\t\t���������Լ�������";
			_getch();
		}
	}break;
	case 2:
	{
		cout << "\t\t������Ҫ���ҵ�ѧ����ѧ�ţ�"; cin >> Id;
		if (p = FindID(Id))
		{
			p->Next->Show();
			cout << "\t\t���������Լ�������";
			_getch();
		}
		else
		{
			cout << "\t\t";
			slowout(cout, "û���ҵ���ѧ�ŵ�ѧ����\n");
			cout << "\t\t���������Լ�������";
			_getch();
		}
	}break;
	}
}
//�k�k�k�k�k�k�k�k�k�k�k�޸�ѧ����Ϣ�k�k�k�k�k�k�k�k�k�k�k
void Studentmassage::ModifyItem()    //�޸���Ϣ
{
	string name;
	Student * p = NULL;
	cout << "\t\t������Ҫ�޸ĵ��˵�����:"; cin >> name;
	if (p = FindItem(name))
	{
		cout << "\t\t���ҵ�ѧ������Ϣ���������µ���Ϣ!" << endl;
		p->Next->Input();
		cout << "\t\t�޸ĳɹ���" << endl;
		cout << "\t\t���������Լ�������";
		_getch();
	}
	else
	{
		cout << "\t\tû���ҵ�!" << endl;
		cout << "\t\t���������Լ�������";
		_getch();
	}
}
//�k�k�k�k�k�k�k�k�k�k�kɾ��ѧ����Ϣ�k�k�k�k�k�k�k�k�k�k�k
void Studentmassage::RemoveItem()        // ɾ����Ϣ
{
	string name;
	Student * p = NULL, *temp = NULL;
	cout << "\t\t������Ҫɾ����ѧ��������:" << endl; cin >> name;
	if (p = FindItem(name))
	{
		temp = p->Next;
		p->Next = p->Next->Next;
		delete temp;
		cout << "\t\t";
		slowout(cout, "ɾ���ɹ�!");
		cout << "\n\t\t���������Լ�������";
		_getch();
	}
	else
	{
		cout << "\t\tû���ҵ�!" << endl;
		cout << "\n\t\t���������Լ�������";
		_getch();
	}
}
//�k�k�k�k�k�k�k�k�k�k�k�k�������ݩk�k�k�k�k�k�k�k�k�k�k�k
void Studentmassage::Swap(Student *p1, Student *p2)//��������combox������������
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
//�k�k�k�k�k�k�k�k�k�k�k�kͳ�����ݩk�k�k�k�k�k�k�k�k�k�k�k
int Studentmassage::ListCount()//ͳ�Ƶ�ǰ����ļ�¼����������һ������
{
	if (!Head)return 0;
	int n = 0;
	for (Student * p = Head->Next; p != End; p = p->Next)n++;
	return n;
}
//�k�k�k�k�k�k�k�k�k�k�k�k��������k�k�k�k�k�k�k�k�k�k�k�k
void Studentmassage::Sort()//�Ե�ǰ�����������
{
	cout << "\n\t\t*********************************\n";
	cout << "\t\t�� 1.����ѧ������\n\t\t�� 2.���ռ�������";
	cout << "\n\t\t*********************************\n��ѡ��";
	int x; cin >> x;
	if (x < 1 || x>2)
	{
		cout << "\t\tѡ�����!\n\t\t���������Լ�������";
		_getch();
		return;
	}
	Student *p = NULL, *k = NULL;
	int n = Studentmassage::ListCount();
	slowout(cout, "\t\t����"); cout << n; slowout(cout, "��ѧ������\n");
	if (n < 2)
	{
		cout << "\t\t�޷����򣡣���" << endl;
		cout << "\t\t���������Լ�������";
		_getch();
		return;
	}
	slowout(cout, "\t\t������......\n");
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
	cout << "\t\t������ɣ�\n\t\t���������Լ�������";
	_getch();
	return;
}
//�k�k�k�k�k�k�k�k�k�k�k�k�������ݩk�k�k�k�k�k�k�k�k�k�k�k
void Studentmassage::Save()//�����ݱ�����Message�ļ���
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
//�k�k�k�k�k�k�k�k�k�k�k�k���ӿγ̩k�k�k�k�k�k�k�k�k�k�k�k
void Studentmassage::AddLesson()
{
	string n; int c;
	cout << "\t\t���������ӵĿγ����ƣ�"; cin >> n;
	cout << "\t\t���������ӵĿγ�ѧ�֣�"; cin >> c;
	for (Student * p = Head; p != End; p = p->Next)
		p->AddLesson(n,c); 
	End->AddLesson(n, c);//��End���Ҳ���»�
	ofstream out("Lesson.txt", ios::app);
	out<< n << '\t' << c << '\t';
	cout << "\t\t������ɡ���"<<endl;
	cout << "\t\t���������Լ�������"<<endl;
	_getch();
}
//�k�k�k�k�k�k�k�k�k�k�k�k�޸Ŀγ̩k�k�k�k�k�k�k�k�k�k�k�k
void Studentmassage::ModifyLesson()
{
	string n1,n2; int c;
	cout << "\t\t������Ҫ�޸ĵĿγ����ƣ�"; cin >> n1;
	cout << "\t\t�������޸ĺ�Ŀγ����ƣ�"; cin >> n2;
	cout << "\t\t�������޸ĺ�Ŀγ�ѧ�֣�"; cin >> c;
	for (Student * p = Head; p != End; p = p->Next)
		p->ModifyLesson(n1,n2, c);
	End->ModifyLesson(n1,n2, c);//��End���Ҳ���»�
	ofstream out("Lesson.txt");
	Student *Newlist = Head->Next;
	for (Lesson* p = Newlist->Head->Next; p != Newlist->End; p = p->Next)
		out << p->name << '\t' << p->credit << '\t';
	cout << "\t\t�޸���ɡ���" << endl;
	cout << "\t\t���������Լ�������" << endl;
	_getch();
}
//�k�k�k�k�k�k�k�k�k�k�kɾ���γ���Ϣ�k�k�k�k�k�k�k�k�k�k�k
void Studentmassage::RemoveLesson()
{
	string n; 
	cout << "\t\t������ɾ���Ŀγ����ƣ�"; cin >> n;
	for (Student * p = Head; p != End; p = p->Next)
		p->RemoveLesson(n);
	End->RemoveLesson(n);//��End���Ҳ���»�
	ofstream out("Lesson.txt");
	Student *Newlist = Head->Next;
	for (Lesson* p = Newlist->Head->Next; p != Newlist->End; p = p->Next)
		out << p->name << '\t' << p->credit << '\t';
	cout << "\t\tɾ����ɡ���" << endl;
	cout << "\t\t���������Լ�������" << endl;
	_getch();
}
//�k�k�k�k�k�k�k�k�k�k�k�kͳ�ƿγ̩k�k�k�k�k�k�k�k�k�k�k�k
void Studentmassage::Statistics()
{
	cout << "\t\tϵͳ�д��ڵĿγ��У�" << endl;
	Student *Newlist = Head->Next;
	for (Lesson* p = Newlist->Head->Next; p != Newlist->End; p = p->Next)
	{
		cout <<"\t\t"<< p->name << endl;
	}
	cout << "\t\t��ѡ��Ҫͳ�ƵĿγ̣�" << endl;
	string l; double max=0, min=100, sum=0;
	int n = 0; int c;
	cin >> l;	
	Student *find = new Student;
	Lesson *s = find->FindLesson(l);
	if (s == NULL)
	{
		cout << "\t\tû�иÿγ�" << endl;
		cout << "\t\t���������Լ�������" << endl;
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
				cout << "������" << P->name << " �÷֣�" << s->score << endl;
				sum += s->score; n++;
				if (s->score > max)max = s->score;
				if (s->score < min)min = s->score;
			}
		}
		cout << l <<" ѧ�֣�"<<c<< " ��߷֣�" << max << " ��ͷ֣�" << min << " ƽ���֣�" << sum / n << endl;
		cout << "\t\t���������Լ�������" << endl;
		_getch();
	}
}
//�k�k�k�k�k�k�k�k�k�k�k�kչʾ�γ̩k�k�k�k�k�k�k�k�k�k�k�k
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
				cout << l << " ѧ�֣�" << c << endl;
				for (Student * P = Head; P != End; P = P->Next)
				{
					Lesson *s = P->FindLesson(l);
						s = s->Next;
					if (s->score != 0)
					{
						cout << "������" << P->name << " �÷֣�" << s->score << endl;
						sum += s->score; n++;
						if (s->score > max)max = s->score;
						if (s->score < min)min = s->score;
					}
				}
			cout << "��߷֣�" << max << " ��ͷ֣�" << min << " ƽ���֣�" << sum / n << endl;
			cout << endl; Sleep(500);
		}
	}
	else 
	{
		slowout(cout , "\t\tϵͳ��δ����γ�����\n" );
	}
	cout << "\t\t���������Լ�������" << endl;
	_getch();
}
//�k�k�k�k�k�k�k�k�k�k�k�k�k�����k�k�k�k�k�k�k�k�k�k�k�k�k
void Studentmassage::Add()
{
	system("cls");
	cout << "\n\t\t*********************************\n";
	cout << "\t\t�� 1.����ѧ����Ϣ\n\t\t�� 2.�����γ���Ϣ";
	cout << "\n\t\t*********************************\n��ѡ��";
	int x; cin >> x;
	if (x < 1 || x>2)
	{
		cout << "\t\tѡ�����!\n\t\t���������Լ�������";
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
//�k�k�k�k�k�k�k�k�k�k�k�k�kչʾ�k�k�k�k�k�k�k�k�k�k�k�k�k
void Studentmassage::Display()
{
	system("cls");
	cout << "\n\t\t*********************************\n";
	cout << "\t\t�� 1.��ѧ��Ϊ��λչʾ\n\t\t�� 2.�Կγ�Ϊ��λչʾ";
	cout << "\n\t\t*********************************\n��ѡ��";
	int x; cin >> x;
	if (x < 1 || x>2)
	{
		cout << "\t\tѡ�����!\n\t\t���������Լ�������";
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
//�k�k�k�k�k�k�k�k�k�k�k�k�k�޸ĩk�k�k�k�k�k�k�k�k�k�k�k�k
void Studentmassage::Modify()
{
	system("cls");
	cout << "\n\t\t*********************************\n";
	cout << "\t\t�� 1.�޸�ѧ����Ϣ\n\t\t�� 2.�޸Ŀγ���Ϣ";
	cout << "\n\t\t*********************************\n��ѡ��";
	int x; cin >> x;
	if (x < 1 || x>2)
	{
		cout << "\t\tѡ�����!\n\t\t���������Լ�������";
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
//�k�k�k�k�k�k�k�k�k�k�k�k�kɾ���k�k�k�k�k�k�k�k�k�k�k�k�k
void Studentmassage::Remove()
{
	system("cls");
	cout << "\n\t\t*********************************\n";
	cout << "\t\t�� 1.ɾ��ѧ����Ϣ\n\t\t�� 2.ɾ���γ���Ϣ";
	cout << "\n\t\t*********************************\n��ѡ��";
	int x; cin >> x;
	if (x < 1 || x>2)
	{
		cout << "\t\tѡ�����!\n\t\t���������Լ�������";
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
//�k�k�k�k�k�k�k�k�k�k�k�k�k���ҩk�k�k�k�k�k�k�k�k�k�k�k�k
void Studentmassage::FindPlus()
{
	system("cls");
	cout << "\n\t\t*********************************\n";
	cout << "\t\t�� 1.����ѧ����Ϣ\n\t\t�� 2.ͳ�ƿγ���Ϣ";
	cout << "\n\t\t*********************************\n��ѡ��";
	int x; cin >> x;
	if (x < 1 || x>2)
	{
		cout << "\t\tѡ�����!\n\t\t���������Լ�������";
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
//�k�k�k�k�k�k�k�k�k�k�k�k�k�����k�k�k�k�k�k�k�k�k�k�k�k�k
void Studentmassage::Others()
{
	system("cls");
	cout << "\n\t\t*********************************\n";
	cout << "\t\t�� 1.����ɼ���Ϣ\n\t\t�� 2.�޸Ĺ���Ա����\n\t\t�� 3.��ʽ��ϵͳ\n\t\t�� 4.����ϵͳ";
	cout << "\n\t\t*********************************\n��ѡ��";
	int x; cin >> x;
	if (x < 1 || x>4)
	{
		cout << "\t\tѡ�����!\n\t\t���������Լ�������";
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