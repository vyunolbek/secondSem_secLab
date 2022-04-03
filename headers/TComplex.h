#pragma once
#include <iostream>


class TComplex
{
public:
	TComplex();
	TComplex(double _re, double _im);
	TComplex(const TComplex& p);
	double GetRe();
	double GetIm();
	void SetRe(double _re);
	void SetIm(double _im);
	double GetModule();
	void ComplexPow(double x);
	void Trig();
	TComplex operator + (TComplex& p);
	TComplex operator * (TComplex& p);
	TComplex operator / (TComplex& p);
	TComplex operator - (TComplex& p);
	TComplex operator = (const TComplex& p);
	bool operator == (TComplex& p);
	friend std::ostream& operator << (std::ostream& B, TComplex& A);
	friend std::istream& operator >> (std::istream& B, TComplex& A);

private:
	double module;
	double re;
	double im;
};