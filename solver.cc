#include <iostream>
#include <fstream>
#include "A.h"

using namespace std;


std::ostream& operator<<(std::ostream &os, const Puzzle &p)
{
	for(int i = 0; i < 9; i++)
	{
		for(int j = 0; j < 9; j++)
		{
			if(p.squares[i][j].val== 0)
				cout << " x ";
			else
				cout << " " <<  p.squares[i][j].val << " ";
		}
		cout << endl;
	}
	return os;
}

bool promising(Puzzle &p, int row, int col, int value)
{
	bool isPromising = value <= 9;

	if(isPromising && !p.squares[row][col].given)
	{
		isPromising &= !(p.rows[row].pos[value-1]);
		isPromising &= !(p.cols[col].pos[value-1]);
		isPromising &= !(p.boxes[row/3][col/3].pos[value-1]);
	}
	return isPromising;
}

bool isComplete(Puzzle &p, int &row, int &col)
{
	for(int i = 0; i < 9; i++)
	{
		row = i;
		for(int j = 0; j < 9; j++)
		{
			col = j;
			if(p.squares[row][col].val == 0)
				return false;
		}
	}
	return true;
}

bool genPerms(Puzzle &p)
{
	/*
	static int num = 0;
	cout << p << endl;
	cout << num++ << endl;
	*/
	if(p.solved)
		return true;

	int row = 0;
	int col = 0;

	if(isComplete(p, row, col))
	{
		p.solved = true;
		return true;
	}
	
	for(int i = 0; i < 9; i++)
	{
		if(!p.solved)
		{
			if(promising(p, row, col, i+1))
			{
				p.update_square(row,col,i+1);
				if(genPerms(p))
					return true;
			}

			p.update_square(row,col,0);	
		}

	}

	return false;
}
int main(int argc, char* argv[])
{
	ifstream infile;

	string filename = argv[argc-1];
	filename = filename.substr(0,filename.find_first_of('.'));
	infile.open(filename + ".sudoku", ifstream::in);

	if(!infile)
	{
		cout << "File Error\n";
		return 1;
	}
	Puzzle p;	

	while(!infile.eof())
	{
		int row;
		int col;
		int val;

		infile >> row >> col >> val;
		p.given(row, col, val);
	}
	infile.close();
	//cout << p << endl;
	ofstream outfile;
	outfile.open(filename + ".solution");
	
	if(genPerms(p))
	{
		//cout << p << endl;
		outfile << 1 << endl;
		for(int i = 0; i < 9; i++)
		{
			for(int j = 0; j < 9; j++)
			{
				outfile << p.squares[i][j].val;
			}
		}
	}
	else
		//cout << "No Solution\n" << p;
		outfile << 0;
	return 0;
}

