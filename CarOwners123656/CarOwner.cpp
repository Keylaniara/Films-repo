

#include"CarOwner.h"



CarOwner::CarOwner()
{
	surname = "";
	title = "";
	patronymic = "";
	//address.apatment = 0;
	// address.house = 0;
	actors = "";
	number = 0;
}

CarOwner::CarOwner(string S, string N, string P,/* Address A,*/ string M, int NUM)
{
	surname = S;
	title = N;
	patronymic = P;
	//address.apatment = A.apatment;
	//address.house = A.house;
	//address.street = A.street;
	actors = M;
	number = NUM;
}

CarOwner::~CarOwner()
{

}

void CarOwner::print() 
{
	if (surname != "")
	{
		//cout << "ФИО:" << surname << " " << name << " " << patronymic << endl;
		cout << "Режиссер: " << surname << endl;
		//cout << "фильм" << address.street << ", ул.," << address.house << "д," << address.apatment << "кв.\n";
		cout << "название фильма: " << title << endl;
		cout << "Испольнители главных ролей: " << actors << endl;
		cout << "Номер:" << number << endl;
	}
}

//void CarOwner::SetParametrs(string S, string N, string P, Address A, string M, int NUM)
void CarOwner::SetParametrs(string S, string N, /*Address A, */string M, int NUM)
{
	surname = S;
	title = N;
	//patronymic = P;
	//address.apatment = A.apatment;
	//address.house = A.house;
	//address.street = A.street;
	actors = M;
	number = NUM;
}

void CarOwner::AddToFile(string NameF)
{
	ofstream fout(NameF, std::ios::app);
	



	if (fout.is_open())
	{
		//fout << "ФИО" << surname << " " << name << " " << patronymic << endl;
		fout << "Режиссер: " << surname << endl;
		//fout << "Адрес: " << address.street << ", ул.," << address.house << "д," << address.apatment << "кв.\n";
		fout << "название фильма: " << title << endl;
		fout << "Исполнители главных ролей: " << actors << endl;
		fout << "Номер: " << number << endl;
		fout << "_______________\n";
	}
	else
		cout << "ошибка открытия файла.\n";

	fout.close();
}

/*void CarOwner::AddToFile(string NameF)
{
	vector<string> text(
		(istream_iterator<string>(ifstream(NameF))),
		istream_iterator<string>()
	);
	copy(text.begin(), text.end(), ostream_iterator(cout, " "));
}*/

void CarOwner::AddToFile1(string NameF)
{
	ofstream fout(NameF, std::ios::app);

	if (fout.is_open())
	{
		if (surname != "")
		{

			//fout << surname << " " << name << " " << patronymic << endl;
			fout << surname << endl;
			//fout << address.street << " " << address.house << " " << address.apatment << "\n";
			fout << title << endl;
			fout << actors << endl;
			fout << number << endl;
		}
	}
	else
		cout << "ошибка открытия файла.\n";

	fout.close();
}