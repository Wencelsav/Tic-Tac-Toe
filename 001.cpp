
#include <iostream>
#include <iomanip>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

#define SPACE ' '
char matrix[3][3] = { 
	{ SPACE, SPACE, SPACE },
	{ SPACE, SPACE, SPACE },
	{ SPACE, SPACE, SPACE }
};
void get_player2_move(void),get_player1_move(void);
void disp_matrix(void);
char check(void);
int main()
{
	char done;
	
	
	done = SPACE;
	do {
		disp_matrix();
		get_player1_move(); 
		done = check(); 
		if (done != SPACE) break; 
		disp_matrix();
		get_player2_move();
		done = check(); 		
	} while (done == SPACE);
	if (done == 'X') cout <<'X'<< "won!\n";
	if (done == 'O') cout <<'O'<< "won!\n";
	else cout <<"Draw\n";
	disp_matrix();
	return 0;
}


void get_player1_move(void)
{
	int x,y;
	cout <<"Enter coordinates for your X.\n"<< "Row? ";
	
	cin >> x;
	cout <<"Column? ";
	cin >> y;
	x--; y--;
	if (x<0 || y<0 || x>2 || y>2 || matrix[x][y] != SPACE)
	{
		cout <<"Invalid move, try again.\n";
		get_player1_move();
	}
	else matrix[x][y] = 'X';
}


void get_player2_move(void)
{
	int x, y;
	cout << "Enter coordinates for your O.\n" << "Row? ";

	cin >> x;
	cout << "Column? ";
	cin >> y;
	x--; y--;
	if (x<0 || y<0 || x>2 || y>2 || matrix[x][y] != SPACE)
	{
		cout << "Invalid move, try again.\n";
		get_player2_move();
	}
	else matrix[x][y] = 'O';
}


void disp_matrix(void)
{
	for (int y = 0; y < 3; y++)
	{
		cout << "+------+------+------+" << endl << "| ";
		for (int x = 0; x < 3; x++)
		{
			if (!matrix[x][y]) cout << setw(4) << " ";
			else cout << setw(4) << matrix[x][y];
			cout << " | ";
		}
		cout << endl;
	}
	cout << "+------+------+------+" << endl << endl;

	
}


char check(void)
{
	int t;
	for (t = 0; t<3; t++) {
		if (matrix[t][0] == matrix[t][1] && matrix[t][1] == matrix[t][2]) return matrix[t][0];
	}
	for (t = 0; t<3; t++) {
		if (matrix[0][t] == matrix[1][t] && matrix[1][t] == matrix[2][t]) return matrix[0][t];
	}
	if (matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2])
		return matrix[0][0];
	if (matrix[0][2] == matrix[1][1] && matrix[1][1] == matrix[2][0])
		return matrix[0][2];
	return SPACE;
}
