#include "A.h"

Row::Row()
{
	for(int i = 0; i < 9; i++)
		pos[i] = false;
};

Col::Col()
{
	for(int i = 0; i < 9; i++)
		pos[i] = false;
};

Box::Box()
{
	for(int i = 0; i < 9; i++)
		pos[i] = false;
};

Square::Square() : given(false), val(0){};

Square::Square(bool g, int v) : given(g), val(v){};

Puzzle::Puzzle()
{
	solved = false;
	for(int i = 0; i < 9; i++)
	{
		rows[i] = Row();
		cols[i] = Col();
		boxes[i/3][i%3] = Box();
	}	
};

void Puzzle::update_square(int row, int col, int val)
{
	int prev = squares[row][col].val;
	if(prev > 0)
	{
		rows[row].pos[prev-1] = false;
		cols[col].pos[prev-1] = false;
		boxes[row/3][col/3].pos[prev-1] = false;
	}
	squares[row][col].val = val;
	if(val > 0)
	{ 
		rows[row].pos[val-1] = true;
		cols[col].pos[val-1] = true;
		boxes[row/3][col/3].pos[val-1] = true;
	}
}

void Puzzle::given(int row, int col, int val)
{
	update_square(row, col, val);
	squares[row][col].given = true;
}
