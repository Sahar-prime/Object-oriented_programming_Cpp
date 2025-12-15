#pragma once
#include "Point_2.h"
class Rect
{
	Point_2 start;
	double a, b;
public:
	Rect();
	Rect(const Point_2& start, int a, int b); 
	Rect(const Point_2& start, const Point_2& end); 
	Rect(const Rect& r);
	Rect(Rect&& r) noexcept;
	void init();
	void show();
};