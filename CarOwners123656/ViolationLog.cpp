

#include"ViolationLog.h"

using namespace std;

ViolationLog::ViolationLog()
{
	date.day = 0;
	date.month = 0;
	date.yers = 0;
}

ViolationLog::ViolationLog(Date D, TypeOfViolation T, CarOwner *C, int n)
{
	surname = new string[n];
	name = new string[n];
	patronymic = new string[n];
	date.day = D.day;
	date.month = D.month;
	date.yers = D.yers;
	for (int i = 0; i < n; i++)
	{
		surname[i] = C[i].GetSurname();
		name[i] = C[i].GetSurname();
		patronymic[i] = C[i].GetPatronymic();
	}
	type.SetParametrs(T.GetViolation(), T.GetSF());
}

ViolationLog::~ViolationLog()
{

}

void ViolationLog::SetParametrs(Date D, TypeOfViolation T, CarOwner *C, int n)
{
	surname = new string[n];
	name = new string[n];
	patronymic = new string[n];
	date.day = D.day;
	date.month = D.month;
	date.yers = D.yers;
	for (int i = 0; i < n; i++)
	{
		surname[i] = C[i].GetSurname();
		name[i] = C[i].GetTitle();
		patronymic[i] = C[i].GetPatronymic();
	}
	type.SetParametrs(T.GetViolation(), T.GetSF());
}

void ViolationLog::print(int n)
{
	cout << "���� ���������: " << date.day << "��. " << date.month << "��." << date.yers << "��. " << endl;
	for (int i = 0; i < n; i++)
	{
		if (surname[i] != "")
			cout << "��� ���������� �" << i + 1 << " :" << surname[i] << " " << name[i] << " " << patronymic[i] << endl;
	}
	type.Print();
}

void ViolationLog::AddToFile(string nameF, int n)
{
	ofstream fout(nameF, std::ios::app);

	if (fout.is_open())
	{
		fout << "���� ���������: " << date.day << "��. " << date.month << "��." << date.yers << "��. " << endl;
		for (int i = 0; i < n; i++)
		{
			if (surname[i] != "")
				fout << "��� ���������� �" << i + 1 << " :" << surname[i] << " " << name[i] << " " << patronymic[i] << endl;
		}
		fout << "��� ���������:" << type.GetViolation() << endl;
		fout << "������ ������:" << type.GetSF() << "���" << endl;
		fout << "__________________\n";
	}
	else
		cout << "������ �������� �����. \n";

	fout.close();
}