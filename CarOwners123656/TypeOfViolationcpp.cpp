

#include "TypeOfViolation.h"

TypeOfViolation::TypeOfViolation()
{
	violation = "";
	sizeFine = 0;
}

TypeOfViolation::TypeOfViolation(string V, int S)
{
	violation = V;
	sizeFine = S;
}

TypeOfViolation::~TypeOfViolation()
{

}


void TypeOfViolation::SetParametrs(string V, int S)
{
	violation = V;
	sizeFine = S;
}

void TypeOfViolation::Print()
{
	cout << "Тип нарушение:" << violation << endl;
	cout << "Размер штрафа:" << sizeFine << " руб" << endl;
}