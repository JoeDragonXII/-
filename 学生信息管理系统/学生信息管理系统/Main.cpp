#include"control.h"
#include"studentmessage.h"
int main()
{
start:;
	int x, i = 0;
	bool quit = false;
	cout << " §§§§§§§§§§§§§§§§§§§§§§§§§§" << endl;
	for (i = 0; i < 3; i++)
		cout << " ◎\t\t\t\t\t\t   ◎" << endl;
	cout << " ◎★★★★【 欢 迎 使 用Student Chorme  】★★★★◎" << endl;
	for (i = 0; i < 3; i++)
		cout << " ◎\t\t\t\t\t\t   ◎" << endl;
	cout << " §§§§§§§§§§§§§§§§§§§§§§§§§§\n" << endl<<endl<<endl;
	
	cout << "\n\t\t---------------------\n";
	cout << "\t\t|※ 1.学生身份访问  |\n\t\t|                   |\n\t\t|※ 2.管理员身份访问|";
	cout << "\n\t\t---------------------\n\t\t请选择：";
	int choose; cin >> choose; 
	switch(choose)
	{
	case 1:
	{
		Studentmassage Grade;
		cout << "\t\t点击任意键以继续……";
		_getch();
		while (!quit)//学生权限菜单
		{
			system("cls");
			Grade.StMenu();
			cin >> x;
			switch (x)
			{
			case 0:quit = true; break;
			case 1:Grade.FindPlus(); break;
			case 2:Grade.Sort(); break;
			case 3:Grade.Display(); break;
			case 4: {system("cls"); System(); break; }
			}
		}
		break;
	}
	case 2:
	{ 
		int a;
		while (a=Password())
		{
			Studentmassage Grade;
			cout << "\t\t点击任意键以继续……";
			_getch();
			while (!quit)//管理员权限菜单
			{
				system("cls");
				Grade.AdMenu();
				cin >> x;
				switch (x)
				{
				case 0:quit = true; goto ended;
				case 1:Grade.Add(); break;
				case 2:Grade.Display(); break;
				case 3:Grade.Modify(); break;
				case 4:Grade.Remove(); break;
				case 5:Grade.FindPlus(); break;
				case 6:Grade.Others(); break;
				}
			}
		}
		if (a == 0) { system("cls"); goto start; }
	}
	}
ended:;
	return 0;
}