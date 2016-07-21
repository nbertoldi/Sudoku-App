#ifndef A_H
#define A_H

#include <vector>
#include <iostream>
class Row
{
	public:
	Row();
	bool pos [9];
};

class Col
{
	public:
	Col();
	bool pos [9];
};

class Box
{
	public:
	Box();
	bool pos [9];
};

class Square
{
	public:
	Square();
	Square (bool g, int v);
	bool given;
	int val;
};

class Puzzle
{
	public:
	Puzzle();
	Square squares [9] [9];
	Row rows [9];
	Col cols [9];
	Box boxes [3][3];
	bool solved;
	friend std::ostream& operator<<(std::ostream& os, const Puzzle & p);
	void given(int row, int col, int val);
	void update_square(int row, int col, int val);
};

#endif
