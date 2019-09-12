

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
	cout << "Дата нарушения: " << date.day << "дд. " << date.month << "мм." << date.yers << "гг. " << endl;
	for (int i = 0; i < n; i++)
	{
		if (surname[i] != "")
			cout << "ФИО нарушителя №" << i + 1 << " :" << surname[i] << " " << name[i] << " " << patronymic[i] << endl;
	}
	type.Print();
}

void ViolationLog::AddToFile(string nameF, int n)
{
	ofstream fout(nameF, std::ios::app);

	if (fout.is_open())
	{
		fout << "Дата нарушения: " << date.day << "дд. " << date.month << "мм." << date.yers << "гг. " << endl;
		for (int i = 0; i < n; i++)
		{
			if (surname[i] != "")
				fout << "ФИО нарушителя №" << i + 1 << " :" << surname[i] << " " << name[i] << " " << patronymic[i] << endl;
		}
		fout << "Тип нарушения:" << type.GetViolation() << endl;
		fout << "размер штрафа:" << type.GetSF() << "руб" << endl;
		fout << "__________________\n";
	}
	else
		cout << "ошибка открытия файла. \n";

	fout.close();
}