#pragma once
class Reservoir
{
	char* name;
	float l, w, h;
public:
	Reservoir();
	Reservoir(const char* name, float l, float w, float h);
	Reservoir(const Reservoir& r);
	~Reservoir();

	float V() const;
	float S() const;

	bool equal(const Reservoir& r1, const Reservoir& r2); //static
	void copy(const Reservoir& r); //см. конструктор копий
	char* type(); //по объему (любые диапозоны)
};

