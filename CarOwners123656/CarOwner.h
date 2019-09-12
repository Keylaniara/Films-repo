#pragma once


#include <iostream>
#include <string>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <Windows.h>


using namespace std;

/*struct Address
{
	string street;
	int house;
	int apatment;
};*/



class CarOwner
{
private:
	string surname,
		title,
		patronymic;
	/*Address address;*/
	//string modelCar;
	string actors;
	int number;

public:
	CarOwner();
	CarOwner(string S, string N, string P, /*Address A,*/ string M, int NUM);
	~CarOwner();



	void print();
	//void SetParametrs(string S, string N, string P, Address A, string M, int NUM);
	void SetParametrs(string S, string N, /*Address A,*/ string M, int NUM);



	string GetSurname() { return surname; };
	string GetTitle() { return title; };
	string GetPatronymic() { return patronymic; };
	//Address GetAddress() { return address; };
	string GetModelCAr() { return actors; };
	int GetNum() { return number; };
	void AddToFile(string NameF);
	void AddToFile1(string NameF);
};
