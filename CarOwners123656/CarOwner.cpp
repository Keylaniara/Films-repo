

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
		//cout << "���:" << surname << " " << name << " " << patronymic << endl;
		cout << "��������: " << surname << endl;
		//cout << "�����" << address.street << ", ��.," << address.house << "�," << address.apatment << "��.\n";
		cout << "�������� ������: " << title << endl;
		cout << "������������ ������� �����: " << actors << endl;
		cout << "�����:" << number << endl;
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
		//fout << "���" << surname << " " << name << " " << patronymic << endl;
		fout << "��������: " << surname << endl;
		//fout << "�����: " << address.street << ", ��.," << address.house << "�," << address.apatment << "��.\n";
		fout << "�������� ������: " << title << endl;
		fout << "����������� ������� �����: " << actors << endl;
		fout << "�����: " << number << endl;
		fout << "_______________\n";
	}
	else
		cout << "������ �������� �����.\n";

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
		cout << "������ �������� �����.\n";

	fout.close();
}