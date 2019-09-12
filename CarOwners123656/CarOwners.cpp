// CarOwners.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include "func.h"


using namespace std;

int stateM;
void MainMenu()
{
	cout << "Меню\n"
		<< "(0)Выход из программы.\n"
		<< "(1)Добавить\n"
		<< "(2)Удалить\n"
		<< "(3)Изменить параметры\n"
		<< "(4)Сортировать по алфавиту\n"
		<< "(5)сумма штрафов\n"
		<< "(6)самый худший водитель\n"
		<< "(7)вывод информации об автовладельцах\n"
		<< "(8)вывод журнала нарушений\n"
		<< "Ваш выбор: ";
	cin >> stateM;
}

void main()
{
	//руссификация ввода\вывода
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string InputCarOwner = { "InputCarOwner.txt" }, InputViolationLog = { "InputViolationLog.txt" };
	string OutputCarOwner = { "OutputCarOwner.txt" }, OutputViolationLog = { "OutputViolationLog.txt" };

	//из файла считываем, сколько элементов в нем находится, чтоб выделить память
	int kolCarOwner = KolElFronFile(InputCarOwner), kolViolationLog = KolElFronFile(InputViolationLog);

	//выделяем память для массива объектов
	CarOwner *C = new CarOwner[kolCarOwner];
	ViolationLog *V = new ViolationLog[kolViolationLog];

	//считываем из файла
	ReadFromFileAboutCarOwner(C, InputCarOwner);
	ReadFromFileAboutViolationLog(V, C, kolViolationLog, kolCarOwner, InputViolationLog);

	system("pause");
	system("cls");//удалить все записи в консоли
	MainMenu();//вызов меню

	while (stateM != 0)
	{

		if (stateM == 1) 
		{
			system("cls");

			//временные переменные
			string S, N, P;
			//Address A;
			string M;
			int Num;
			int newKolCarOwner = kolCarOwner + 1;//увеличиваем кол-во элементов
			CarOwner *C1 = new CarOwner[newKolCarOwner];
			ReadFromFileAboutCarOwner(C1, InputCarOwner);
			cout << "Введите Режиссера: ";
			cin.ignore();
			getline(cin, S);
			//cout << "Введите ФИО";
			//getline(cin, N);
			//cout << "Введите ФИО";
			//getline(cin, P);
			cout << "Название фильма :";
			getline(cin, N);
			//cin >> A.street >> A.house >> A.apatment;
			cout << "Введите актеров: ";
			getline(cin, M);
			cout << "введите номер авто";
			cin >> Num;

			//C1[newKolCarOwner - 1].SetParametrs(S, N, P, A, M, Num);
			C1[newKolCarOwner - 1].SetParametrs(S, M, N, Num);
			WriteInFileInputCarOwner(newKolCarOwner, InputCarOwner, C1);

			//по новой считываем все данные из файла и выделяем память
			kolCarOwner = KolElFronFile(InputCarOwner);
			CarOwner *C = new CarOwner[kolCarOwner];
			ReadFromFileAboutCarOwner(C, InputCarOwner);

			system("pause");
			system("cls");
			MainMenu();//вызов меню
			system("cls");
		}

		if (stateM == 2)
		{
			system("cls");
			kolCarOwner = KolElFronFile(InputCarOwner);
			CarOwner *C = new CarOwner[kolCarOwner];
			ReadFromFileAboutCarOwner(C, InputCarOwner);

			string S = "", N = "", P = "";
			//Address A; A.apatment = 0; A.house = 0; A.street = "";
			string M = "";
			int Num = 0;

			int indexDel;
			cout << "Выберите номер фильма, который нужно удалить от 1 до " << kolCarOwner << ":";
			cin >> indexDel;

			//C[indexDel - 1].SetParametrs(S, N, P, A, M, Num);
			C[indexDel - 1].SetParametrs(S, M, N, Num);
			WriteInFileInputCarOwner(InputCarOwner, C, kolCarOwner);

			kolCarOwner = KolElFronFile(InputCarOwner);
			C = new CarOwner[kolCarOwner];
			ReadFromFileAboutCarOwner(C, InputCarOwner);

			system("pause");
			system("cls");
			MainMenu();
			system("cls");
			


		}

		if (stateM == 3)
		{
			system("cls");

			string S, N, P;
			//Address A;
			string M;
			int Num;

			int index;
			cout << "Введите номер авовладельца у которого нужно поменять параметры от 1 до " << kolCarOwner<< ":";
			cin >> index;

			cout << "Введите ФИО";
			cin >> S >> N >> P;
			cout << "введите адрес улицу -> доm -> квартиру) :";
			//cin >> A.street >> A.house >> A.apatment;
			cout << "введите марку машины";
			cin >> M;
			cout << "введите номер авто";
			cin >> Num;

			//C[index - 1].SetParametrs(S, N, P, A, M, Num);
			C[index - 1].SetParametrs(S, M, N, Num);

			system("pause");
			system("cls");
			MainMenu();
			system("cls");
		}

		if (stateM == 4)
		{
			system("cls");

			for (int i = 0; i < kolCarOwner; i++)
			{
				for (int j = i + 1; j < kolCarOwner; j++)
				{
					if (C[i].GetSurname() > C[j].GetSurname())
					{
						//CarOwner Buf(C[i].GetSurname(), C[i].GetName(), C[i].GetPatronymic(), C[i].GetAddress(), C[i].GetModelCAr(), C[i].GetNum());
						CarOwner Buf(C[i].GetSurname(), C[i].GetTitle(), C[i].GetPatronymic(), C[i].GetModelCAr(), C[i].GetNum());
						//C[i].SetParametrs(C[j].GetSurname(), C[j].GetName(), C[j].GetPatronymic(), C[j].GetAddress(), C[j].GetModelCAr(), C[j].GetNum());
						C[i].SetParametrs(C[j].GetSurname(), C[j].GetTitle(), C[j].GetModelCAr(), C[j].GetNum());
						//C[j].SetParametrs(Buf.GetSurname(), Buf.GetName(), Buf.GetPatronymic(), Buf.GetAddress(), Buf.GetModelCAr(), Buf.GetNum());
						C[j].SetParametrs(Buf.GetSurname(), Buf.GetModelCAr(), Buf.GetTitle(), Buf.GetNum());

					}
				}
			}

			WriteInFileInputCarOwner(kolCarOwner, InputCarOwner, C);
			
			cout << "Сортировка закончена.\n";
			system("pause");
			system("cls");
			MainMenu();
			system("cls");
		}
		if (stateM == 5)
		{
			system("cls");

			int index, sum = 0;
			bool fS = false, fN = false, fP = false, f = false;
			cout << "введите номер автовладельца, сумму штрафоф которого от 1 до " << kolCarOwner << " ";
			cin >> index;

			for (int i = 0; i < kolViolationLog; i++)
			{
				for (int j = 0; j < kolCarOwner; j++)
				{
					bool isNameEqual = C[index - 1].GetTitle() == V[i].GetName()[j];
					bool isSurnameEqual = C[index - 1].GetSurname() == V[i].GetSurname()[j];
					bool isPatronymicEqual = C[index - 1].GetPatronymic() == V[i].GetPatronymic()[j];
					if (isNameEqual && isSurnameEqual && isPatronymicEqual)
					{
						f = true;
						sum += V[i].GetType().GetSF();
					}
				}
			}

			if (f)
				cout << "сумма штрафов равна" << sum << "рубле\n";
			else
				cout << "совпадений не найдено или штрафы не найдены\n";

			system("pause");
			system("cls");
			MainMenu();
			system("cls");
		
		}

		if (stateM == 6)
		{
			system("cls");
			int *max = new int[kolCarOwner];
			for (int i = 0; i < kolCarOwner; i++)
				max[i] = 0;
			bool f = false;

			for (int i = 0; i < kolViolationLog; i++)
			{
				for (int j = 0; j < kolCarOwner; j++)
				{
					if (V[i].GetSurname()[j] != "")
					{
						max[j] += V[i].GetType().GetSF();
						f = true;
					}
				}
			}
			int maxSF = max[0], index = 0;
			for (int i = 0; i< kolCarOwner; i++)
				if (maxSF < max[i])
				{
					maxSF = max[i];
					index = 1;
				}
			if (f)
				cout << "самый злостный нарушитель с суммой штрафоф равно " << max[index] << "\n";
			C[index].print();
			system("pause");
			system("cls");
			MainMenu();
			system("cls");
		}

		if (stateM == 7)
		{
			system("cls");
			bool w;
			cout << "вывести в консоль/в файл(1/0): ";
			cin >> w;
			system("cls");

			kolCarOwner = KolElFronFile(InputCarOwner);
			CarOwner *C = new CarOwner[kolCarOwner];
			ReadFromFileAboutCarOwner(C, InputCarOwner);

			if (w)
			{
				for (int i = 0; i < kolCarOwner; i++)
				{
					cout << "Фильм №" << i + 1 << ":\n";
					C[i].print();
					cout << "********************\n";
				}
			}
			else
			{
				WriteInFileCarOwner(OutputCarOwner, C, kolCarOwner);
				cout << "Информация записана в файл\"" << OutputCarOwner << "\"\n";
			}
			system("pause");
			system("cls");
			MainMenu();
			system("cls");
		}

		if (stateM == 8)
		{
			system("cls");
			bool w;
			cout << "вывести в консоль/в файл(1/0):";
			cin >> w;
			system("cls");

			kolCarOwner = KolElFronFile(InputCarOwner);
			CarOwner *C = new CarOwner[kolCarOwner];
			ReadFromFileAboutCarOwner(C, InputCarOwner);

			if (w)
			{
				for (int i = 0; i < kolViolationLog; i++)
				{
					cout << "нарушение №" << i + 1 << ":\n";
					V[i].print(kolCarOwner);
					cout << "******************\n";
				}
			}
			else
			{
				WriteInFileViolationLog(OutputViolationLog, V, kolViolationLog, kolCarOwner);
				cout << "Информация записана в файл \"" << OutputViolationLog << "\"\n";
			}

			system("pause");
			system("cls");
			MainMenu();
			system("cls");
		}

	}
	system("cls");
	cout << "работа завершена. \n";
	system("pause");
}