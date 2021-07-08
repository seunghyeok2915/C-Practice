#pragma once

class Missile 
{
private:

	bool bMoveLeft;

public:
	int x;
	int y;

	void setMissile(int _y);

	void moveMissile();
	void drawMissile();

	bool checkEnd();
};	
	