#pragma once


#include <iostream>
#include <Windows.h>
#include <string>

#include"CarOwner.h"
#include"Func.h"
#include"TypeOfViolation.h"
#include"ViolationLog.h"

using namespace std;

int KolElFronFile( string nameFile);
void ReadFromFileAboutCarOwner(CarOwner *C, string nameFile);
void ReadFromFileAboutViolationLog(ViolationLog *V, CarOwner *C, int violationLogCount, int carOwnerCount, string nameFile);
void WriteInFileCarOwner(string nameF, CarOwner *C, int n);
void WriteInFileInputCarOwner(string nameF, CarOwner *C, int n);
void WriteInFileViolationLog(string nameF, ViolationLog  *V, int n, int m);
void WriteInFileInputCarOwner(int n, string nameF, CarOwner *C);

