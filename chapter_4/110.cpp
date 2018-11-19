#include <iostream>
#include <cstring>
using namespace std;
#pragma warning(disable:4996)
#define SIZE 80
class student
{
	char *name;
	char ID[19];
	char number[10];
	char specialty[20];
	int age;
	static int count;
public:
	student();
	student(char *na, char *id, char *num, char *spec, int age);
	student(const student &per);
	~student();
	char *GetName() const;
	char *GetID();
	char *GetNumber();
	char *Getspec();
	int GetAge() const;
	void Display() const;
	void Input();
	void Insert();
	void Delete();
	static int GetCount();
};

int student::count = 0;
student::student()
{
	name = NULL;
	age = 0;
}
student::student(char *na, char *id, char *num, char *spec, int ag)
{
	if (na)
	{
		name = new char[strlen(na) + 1];
		strcpy(name, na);
	}
	strcpy(ID, id);
	strcpy(number, num);
	strcpy(specialty, spec);
	age = ag;
	count++;
}

student::student(const student & per)
{
	if (per.name)
	{
		name = new char[strlen(per.name) + 1];
		strcpy(name, per.name);
	}
	strcpy(ID, per.ID);
	strcpy(number, per.number);
	strcpy(specialty, per.specialty);
	age = per.age;
	count++;
}

student::~student()
{
	cout << "disCon" << endl;
	if (name)
	{
		delete [] name;
		count--;
	}
}

char *student::GetName() const
{
	return name;
}
char *student::GetID()
{
	return ID;
}
int student::GetAge() const
{
	return age;
}

char *student::Getspec()
{
	return specialty;
}
char *student::GetNumber()
{
	return number;
}
void student::Display() const
{
	cout << "姓名: " <<name<<endl;
	cout << "身份证: " << ID << endl;
	cout << "学号: " << number << endl;
	cout << "专业: " << specialty << endl;
	cout << "年龄: " << age << endl << endl;

}

void student::Input()
{
	char na[10];
	cout << "s输入姓 名: ";
	cin >> na;
	if (name)
	{
		delete []name;
	}
	name = new char[strlen(na) + 1];
	strcpy(name, na);
	cout << "输入身份证: ";
	cin >> ID;
	cout << "输入年 龄: ";
	cin >> age;
	cout << "输入专 业: ";
	cin >> specialty;
	cout << "输入学 号: ";
	cin >> number;
	count++;
}

void student::Insert()
{
	if (!age)
	{
		Input();
	}

}

void student::Delete()
{
	age = 0;
	count--;
}

int student::GetCount()
{
	return count;
}

const int N = 10;
void menu();
void outputstu(const student * array);
void inputstu(student * array);
int searchstu(const student * array, char *na);
bool insertstu(student * array);
bool deletestu(student *array, char *na);

int main()
{
	student array[N];
	int choice;
	char na[20];
	do
	{
		menu();
		cout << "Please input your choice:";
		cin >> choice;
		if (choice >= 0 && choice <= 5)
		{
			switch (choice)
			{
			case 1:inputstu(array); break;
			case 2:
				cout << "Input the name searched:" << endl;
				cin >> na;
				int i;
				i = searchstu(array, na);
				if (i == N)
				{
					cout << "查无此人!\n" << endl;
				}
				else
				{
					array[i].Display();

				}
				break;
			case 3:outputstu(array); break;
			case 4:if (insertstu(array))
				cout << "成功插入一条记录\n";
				   else
					   cout << "插入失败!\n";
			case 5:
				cout << "Input the name deleted: " << endl;
				cin >> na;
				if (deletestu(array, na))
				{
					cout << "成功删除一条记录\n";
				}
				else
				{
					cout << "删除失败!\n";
				}
				break;
			default:
				break;
			}
		}

	} while (choice);
		return 0;
}
	void menu()
	{
		cout << "******1.录入信息******" << endl;
		cout << "******2.查询信息******" << endl;
		cout << "******3.浏览信息******" << endl;
		cout << "******4.插入信息******" << endl;
		cout << "******5.删除信息******" << endl;
		cout << "******0.退    出******" << endl;

	}

	void outputstu(const student * array)
	{
		cout << "学生总人数=" << student::GetCount() << endl;
		for (int i = 0; i < N; i++)
		{
			if (array[i].GetAge())
			{
				array[i].Display();
			}
		}
	}

	int  searchstu(const student*array, char * na)
	{
		int i, j = N;
		for (i = 0; i < N; i++)
		{
			if (array[i].GetAge())
			{
				if (strcmp(array[i].GetName(), na) == 0)
				{
					j = i;
					break;
				}
			}
		}
		return j;
	}

	void inputstu(student * array)
	{
		char ch;
		int i = 0;
		do
		{
			if (student::GetCount() == N)
			{
				cout << "人数已满!" << endl;
			}
			if (!array[i].GetAge())
			{
				array[i++].Input();
			}
			cout << "继续输入吗?( Y or N )\n" << endl;
			cin >> ch;
		} while (ch == 'Y');
	}

	bool insertstu(student * array)
	{
		if (student::GetCount() == N)
		{
			cout << "人数已满!\n" << endl;
			return false;
		}
		for (int i = 0; array[i].GetAge(); i++)
		{
			array[i].Insert();
		}
		return true;
	}

	bool deletestu(student * array, char *na)
	{
		if (student::GetCount() == 0)
		{
			cout << "没有记录，无法删除!\n" << endl;
			return false;
		}
		int i = searchstu(array, na);
		if (i == N)
		{
			cout << "查无此人，无法删除!\n";
			return false;
		}
		array[i].Delete();
		return true;
	}
