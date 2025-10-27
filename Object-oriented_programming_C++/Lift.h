#pragma once
class Lift
{
	int currentFloor;
	int minFloor;
	int maxFloor;
	bool isWorking = false;

public:
	void setUp(int user);
	void setDown(int user);
	void setOn_Off();
	bool getOn_Off();
	int getCurrent();
	void setCurrent(int user);
	void show();
};
