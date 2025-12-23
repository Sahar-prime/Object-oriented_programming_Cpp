#pragma once
template <typename T>
class Fraction
{
	T num, denom;
public:
	Fraction();
	Fraction(T u);
	Fraction(T n, T d);

	void setNum(T u);
	void setDenom(T u);

	T getNum();
	T getDenom();

	void init();
	void show();

	static Fraction<T> summ(const Fraction<T>& d1, const Fraction<T>& d2);
	static Fraction<T> diff(const Fraction<T>& d1, const Fraction<T>& d2);
	static Fraction<T> mult(const Fraction<T>& d1, const Fraction<T>& d2);
	static Fraction<T> div(const Fraction<T>& d1, const Fraction<T>& d2);

	Fraction<T> summ(const Fraction<T>& d2);
	Fraction<T> diff(const Fraction<T>& d2);
	Fraction<T> mult(const Fraction<T>& d2);
	Fraction<T> div(const Fraction<T>& d2);
};
//Создать шаблон класса