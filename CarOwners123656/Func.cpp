

#include "Func.h"

int KolElFronFile(string nameFile)
{
	ifstream fin(nameFile);
	int k;

	if (fin.is_open())
	{
		fin >> k;
	}
	else
		cout << "ошибка открытия файла. \n";
	fin.close();
	return k;
}

void ReadFromFileAboutCarOwner(CarOwner *C, string nameFile)
{
	ifstream fin(nameFile);

	int k;
	string S, N, P;
	//Address D;
	string M;
	int Num;

	if (fin.is_open())
	{
		fin >> k;
		fin.ignore();
		for (int i = 0; i < k; i++)
		{
			//fin >> S >> N >> P;
			//fin >> S;
			getline(fin, S);
			getline(fin, M);
			//fin >> D.street >> D.house >> D.apatment;
			getline(fin, N);
			//fin >> M;
			fin >> Num;
			


			//C[i].SetParametrs(S, string(N.c_str()), string(P.c_str()), D, string(M.c_str()), Num);
			C[i].SetParametrs(S, M, N, Num);
			fin.ignore();
		}
	}
	else
	{
		cout << "ошибка открытия файла.\n";
	}

	fin.close();

}

void ReadFromFileAboutViolationLog(ViolationLog *V, CarOwner *C, int violationLogCount, int carOwnersCount, string nameFile)
{
	ifstream fin(nameFile);

	int k;
	Date D;
	string Vi, S = "", N = "", P = "";
	int Ss;
	//Address A;
	CarOwner *c = new CarOwner[carOwnersCount];
	bool w;

	cout << "укажите какое нарушение совершил какой водитель:\n";

	if (fin.is_open())
	{
		fin >> k;
		cout << "Водители пронумерованы от 1 до" << carOwnersCount << endl;
		cout << "Дальше будут перечисленны номера всех штрафов, укажите кто их совершил. \n(1/0) -> (совершил/не совершил)\n\n";

		for (int i = 0; i < violationLogCount; i++)
		{
			cout << "*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*\n";
			cout << "Штраф №" << i + 1 << "совершил это нарушение? (1/0) : ";
			for (int j = 0; j < carOwnersCount; j++)
			{
				cout << "автовладелец №" << j + 1 << "совершил это нарушение? (1/0): ";
				cin >> w;
				if (w)
				{
					//c[j].SetParametrs(C[j].GetSurname(), C[j].GetName(), C[j].GetPatronymic(), C[j].GetAddress(), C[j].GetModelCAr(), C[j].GetNum());
					c[j].SetParametrs(C[j].GetSurname(), C[j].GetModelCAr(), C[j].GetTitle(), C[j].GetNum());

				}
				else
				{
					//A.apatment = 0; A.house = 0; A.street = "";
					//c[j].SetParametrs(S, N, P, A, S, 0);
					c[j].SetParametrs(S, N, S, 0);
				}
			}
			fin >> D.day >> D.month >> D.yers;
			fin >> Vi;
			fin >> Ss;

			TypeOfViolation T(Vi, Ss);

			V[i].SetParametrs(D, T, c, carOwnersCount);

		}
	}
	else
	{
		cout << "ошибка открытия фала. \n";
	}
	fin.close();
}

void WriteInFileCarOwner(string nameF, CarOwner *C, int n)
{
	ofstream fout(nameF, std::ios::out);
	if (fout.is_open())
	{
		for (int i = 0; i < n; i++)
		{
			C[i].AddToFile(nameF);
		}
	}
	else
		cout << "ошибка открытия файла \"outputApartment.txt\".\n";

	fout.close();
}

void WriteInFileInputCarOwner(string nameF, CarOwner *C, int n)
{
	ofstream fout(nameF, std::ios::out);
	if (fout.is_open())
	{
		fout << n - 1 << endl;
		for (int i = 0; i < n; i++)
		{
			C[i].AddToFile1(nameF);
		}
	}
	else
		cout << "\"OutputApartment.txt\".\n";

	fout.close();
}

void WriteInFileInputCarOwner(int n, string nameF, CarOwner *C)
{
	ofstream fout(nameF, std::ios::out);
	if (fout.is_open())
	{
		fout << n << endl;
		for (int i = 0; i < n; i++)
		{
			C[i].AddToFile1(nameF);
		}
	}
	else
		cout << "Ошибка открытия файла \"OutputApartment.txt\".\n";

		fout.close();
}


void WriteInFileViolationLog(string nameF, ViolationLog *V, int n, int m)
{
	ofstream fout(nameF, std::ios::app);

	if (fout.is_open())
	{
		for (int i = 0; i < n; i++)
		{
			V[i].AddToFile(nameF, m);
		}
	}
	else
		cout << "ошибка открытия файла. \n";

	fout.close();
}