#pragma once
class Drob_2
{
	int num, den;
public:
	Drob_2(); // 1/1
	Drob_2(int u); // u/1
	Drob_2(int n, int d); // n/d

	void setNum(int u);
	void setDenom(int u);

	int getNum()const;
	int getDenom()const;

	void init();
	void show()const;

	friend bool operator==(const Drob_2& d1, const Drob_2& d2);
	friend bool operator!=(const Drob_2& d1, const Drob_2& d2);
	friend bool operator<=(const Drob_2& d1, const Drob_2& d2);
	friend bool operator>=(const Drob_2& d1, const Drob_2& d2);
	friend bool operator<(const Drob_2& d1, const Drob_2& d2);
	friend bool operator>(const Drob_2& d1, const Drob_2& d2);

	friend Drob_2 operator+(const Drob_2& d1, const Drob_2& d2);

	Drob_2 operator*(const Drob_2& other) const 
	{
		float new_numerator = this->num * other.num;
		float new_denominator = this->den * other.den;
		return Drob_2(new_numerator, new_denominator);
	}

	friend Drob_2 operator/(const Drob_2& d1, const Drob_2& d2);

	//(++ и --)
	Drob_2 operator++()
	{
		num += den;
		return *this;
	};
	Drob_2 operator--() 
	{
		num -= den;
		return *this;
	};

	const Drob_2 operator++(int)
	{
		Drob_2 temp{ num, den };
		num += den;
		return temp;
	};
	const Drob_2 operator--(int)
	{
		Drob_2 temp{ num, den };
		num -= den;
		return temp;
	};
};

// Определение дружественных функций операторов сравнения
inline bool operator==(const Drob_2& d1, const Drob_2& d2)
{
	return d1.num / d1.den == d2.num / d2.den;
}
inline bool operator!=(const Drob_2& d1, const Drob_2& d2)
{
	return d1.num / d1.den != d2.num / d2.den;
}
inline bool operator<=(const Drob_2& d1, const Drob_2& d2)
{
	return d1.num / d1.den <= d2.num / d2.den;
}
inline bool operator>=(const Drob_2& d1, const Drob_2& d2)
{
	return d1.num / d1.den >= d2.num / d2.den;
}
inline bool operator<(const Drob_2& d1, const Drob_2& d2)
{
	return d1.num / d1.den < d2.num / d2.den;
}
inline bool operator>(const Drob_2& d1, const Drob_2& d2)
{
	return d1.num / d1.den > d2.num / d2.den;
}

inline Drob_2 operator+(const Drob_2& d1, const Drob_2& d2)
{
	float new_numerator = d1.num * d2.den + d2.num * d1.den;
	float new_denominator = d1.den * d2.den;
	return Drob_2(new_numerator, new_denominator);
}
inline Drob_2 operator-(const Drob_2& d1, const Drob_2& d2)
{
	float new_numerator = d1.getNum() * d2.getDenom() + d2.getNum() * d1.getDenom();
	float new_denominator = d1.getDenom() * d2.getDenom();
	return Drob_2(new_numerator, new_denominator);
}
inline Drob_2 operator/(const Drob_2& d1, const Drob_2& d2) {
	float new_numerator = d1.num * d2.den;
	float new_denominator = d1.den * d2.num;
	return Drob_2(new_numerator, new_denominator);
}