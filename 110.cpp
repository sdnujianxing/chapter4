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
	cout << "����: " <<name<<endl;
	cout << "���֤: " << ID << endl;
	cout << "ѧ��: " << number << endl;
	cout << "רҵ: " << specialty << endl;
	cout << "����: " << age << endl << endl;

}

void student::Input()
{
	char na[10];
	cout << "s������ ��: ";
	cin >> na;
	if (name)
	{
		delete []name;
	}
	name = new char[strlen(na) + 1];
	strcpy(name, na);
	cout << "�������֤: ";
	cin >> ID;
	cout << "������ ��: ";
	cin >> age;
	cout << "����ר ҵ: ";
	cin >> specialty;
	cout << "����ѧ ��: ";
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
					cout << "���޴���!\n" << endl;
				}
				else
				{
					array[i].Display();

				}
				break;
			case 3:outputstu(array); break;
			case 4:if (insertstu(array))
				cout << "�ɹ�����һ����¼\n";
				   else
					   cout << "����ʧ��!\n";
			case 5:
				cout << "Input the name deleted: " << endl;
				cin >> na;
				if (deletestu(array, na))
				{
					cout << "�ɹ�ɾ��һ����¼\n";
				}
				else
				{
					cout << "ɾ��ʧ��!\n";
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
		cout << "******1.¼����Ϣ******" << endl;
		cout << "******2.��ѯ��Ϣ******" << endl;
		cout << "******3.�����Ϣ******" << endl;
		cout << "******4.������Ϣ******" << endl;
		cout << "******5.ɾ����Ϣ******" << endl;
		cout << "******0.��    ��******" << endl;

	}

	void outputstu(const student * array)
	{
		cout << "ѧ��������=" << student::GetCount() << endl;
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
				cout << "��������!" << endl;
			}
			if (!array[i].GetAge())
			{
				array[i++].Input();
			}
			cout << "����������?( Y or N )\n" << endl;
			cin >> ch;
		} while (ch == 'Y');
	}

	bool insertstu(student * array)
	{
		if (student::GetCount() == N)
		{
			cout << "��������!\n" << endl;
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
			cout << "û�м�¼���޷�ɾ��!\n" << endl;
			return false;
		}
		int i = searchstu(array, na);
		if (i == N)
		{
			cout << "���޴��ˣ��޷�ɾ��!\n";
			return false;
		}
		array[i].Delete();
		return true;
	}
