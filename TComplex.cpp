#include "./headers/TComplex.h"
#include <iostream>
#include <math.h>

#define M_PI 3.14159265358979323846
#pragma once

TComplex::TComplex()
{
	re = 0;
	im = 0;
}

TComplex::TComplex(double _re, double _im)
{
	re = _re;
	im = _im;
}

TComplex::TComplex(const TComplex& p)
{
	re = p.re;
	im = p.im;
}

double TComplex::GetRe()
{
	return re;
	return 0.0;
}

double TComplex::GetIm()
{
	return im;
	return 0.0;
}

void TComplex::SetRe(double _re)
{
	re = _re;
}

void TComplex::SetIm(double _im)
{
	im = _im;
}

double TComplex::GetModule()
{
	module = pow((pow(re, 2) + pow(im, 2)), 0.5);
	return module;
}

void TComplex::ComplexPow(double x)
{
	double argument = atan(im / re); 
	double result = 0;
	if (x >= 1)
	{
		re = pow(GetModule(), x) * cos(x * argument);
		im = pow(GetModule(), x) * sin(x * argument);
	}
	else if (0 < x < 1)
	{
		double k = 1 / x;
		re = pow(GetModule(), x) * cos(argument / k);
		im = pow(GetModule(), x) * sin(argument / k);
	}
}

void TComplex::Trig()
{
	double argument = atan(im / re);
	std::cout << GetModule() << " * (cos " << argument << ") + i * sin(" << argument << "))";
}

TComplex TComplex::operator+(TComplex& p)
{
	TComplex res;
	res.re = re + p.re;
	res.im = re + p.im;

	return res;
}

TComplex TComplex::operator*(TComplex& p)
{
	TComplex res;
	res.re = re * p.re - im * p.im;
	res.im = re * p.im - im * p.re;
	return res;
}

TComplex TComplex::operator/(TComplex& p)
{
	TComplex res;
	res.re = (re * p.re + im * p.im) * 1.0 / (p.re * p.re + p.im * p.im);
	res.im = (im * p.re - re * p.im) * 1.0 / (p.re * p.re + p.im * p.im);
	return res;
}

TComplex TComplex::operator-(TComplex& p)
{
	TComplex res;
	res.re = re - p.re;
	res.im = im - p.im;
	return res;
}

TComplex TComplex::operator=(const TComplex& p)
{
	re = p.re;
	im = p.im;
	return*this;
}

bool TComplex::operator==(TComplex& p)
{
	if ((p.re == re) && (p.im = im))
	{
		return true;
	}
	return false;
}

std::ostream& operator<<(std::ostream& B, TComplex& A)
{
	std::cout << A.re << " + " << A.im << "i" << std::endl;
	return B;
}

std::istream& operator>>(std::istream& B, TComplex& A)
{
	B >> A.re;
	B >> A.im;
	return B;
}