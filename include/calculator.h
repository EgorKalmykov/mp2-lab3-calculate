#ifndef __TCALCULATOR_H__
#define __TCALCULATOR_H__

#include "stack.h"
#include <string>

class Calculator
{
	string infix;
	string postfix;
public:
	Calculator() 
	{
		infix = "2+(3+4*2)-5";
	}
	Calculator(string s)
	{
		infix = s;
	}

	string GetInfix() { return infix; }
	string GetPostfix() { return postfix; }

	void CreatePostfix();
	double Calculate();

};

#endif