#pragma once
class Drob
{
	int num, den;
public:
	Drob(); // 1/1
	Drob(int u); // u/1
	Drob(int n, int d); // n/d
	
	void setNum(int u);
	void setDenom(int u);
	
	int getNum()const;
	int getDenom()const;
	
	void init();
	void show()const;

	void add(const Drob& other);
	void subtract(const Drob& other);
	void multiply(const Drob& other);
	void divide(const Drob& other);
};

