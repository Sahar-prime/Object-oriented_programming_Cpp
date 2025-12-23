#include "Fraction.h"
#include <iostream>
template <typename T>
Fraction<T>::Fraction(T n, T d) : num{ n }, denom{ d } {}
template <typename T>
Fraction<T>::Fraction(T u) : Fraction{ u, 1 } {}
template <typename T>
Fraction<T>::Fraction() : Fraction{ 1,1 } {}

template <typename T>
void Fraction<T>::setNum(T u)
{
	num = u;
}
template <typename T>
void Fraction<T>::setDenom(T u)
{
	denom = u;
}

template <typename T>
T Fraction<T>::getNum()
{
	return num;
}
template <typename T>
T Fraction<T>::getDenom()
{
	return denom;
}

template <typename T>
void Fraction<T>::init()
{
	std::cout << "Введи числитель и знаменатель: ";
	std::cin >> num >> denom;
}
template <typename T>
void Fraction<T>::show()
{
	std::cout << num << "/" << denom;
}

template <typename T>
Fraction<T> Fraction<T>::summ(const Fraction<T>& d1, const Fraction<T>& d2)
{
	Fraction res;
	res.num = d1.num * d2.denom + d2.num * d1.denom;
	res.denom = d1.denom * d2.denom;
	return res;
}
template <typename T>
Fraction<T> Fraction<T>::diff(const Fraction<T>& d1, const Fraction<T>& d2)
{
	Fraction res;
	res.num = d1.num * d2.denom - d2.num * d1.denom;
	res.denom = d1.denom * d2.denom;
	return res;
}
template <typename T>
Fraction<T> Fraction<T>::mult(const Fraction<T>& d1, const Fraction<T>& d2)
{
	Fraction res;
	res.num = d1.num * d2.num;
	res.denom = d1.denom * d2.denom;
	return res;
}
template <typename T>
Fraction<T> Fraction<T>::div(const Fraction<T>& d1, const Fraction<T>& d2)
{
	Fraction res;
	res.num = d1.num * d2.denom;
	res.denom = d1.denom * d2.num;
	return res;
}

template <typename T>
Fraction<T> Fraction<T>::summ(const Fraction<T>& d2)
{
	Fraction res;
	res.num = num * d2.denom + d2.num * denom;
	res.denom = denom * d2.denom;
	return res;
}
template <typename T>
Fraction<T> Fraction<T>::diff(const Fraction<T>& d2)
{
	Fraction res;
	res.num = num * d2.denom - d2.num * denom;
	res.denom = denom * d2.denom;
	return res;
}
template <typename T>
Fraction<T> Fraction<T>::mult(const Fraction<T>& d2)
{
	Fraction res;
	res.num = num * d2.num;
	res.denom = denom * d2.denom;
	return res;
}
template <typename T>
Fraction<T> Fraction<T>::div(const Fraction<T>& d2)
{
	Fraction res;
	res.num = num * d2.denom;
	res.denom = denom * d2.num;
	return res;
}