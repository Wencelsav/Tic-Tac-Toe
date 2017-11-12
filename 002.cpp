#include <iostream>
#include <iomanip>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

#define SPACE ' '
char matrix[5][5] = { 
	{ SPACE, SPACE, SPACE, SPACE, SPACE },
	{ SPACE, SPACE, SPACE, SPACE, SPACE },
	{ SPACE, SPACE, SPACE, SPACE, SPACE },
	{ SPACE, SPACE, SPACE, SPACE, SPACE },
	{ SPACE, SPACE, SPACE, SPACE, SPACE }
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
		if (done != SPACE) break;
	} while (done == SPACE);
	if (done == 'X') cout <<"Player 1 won!\n";
	else cout <<"Player 2 won!!!!\n";
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
	if (x<0 || y<0 || x>4 || y>4 || matrix[x][y] != SPACE)
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
	if (x<0 || y<0 || x>4 || y>4 || matrix[x][y] != SPACE)
	{
		cout << "Invalid move, try again.\n";
		get_player2_move();
	}
	else matrix[x][y] = 'O';
}


void disp_matrix(void)
{
	for (int y = 0; y < 5; y++)
	{
		cout << "+------+------+------+------+------+" << endl << "| ";
		for (int x = 0; x < 5; x++)
		{
			if (!matrix[x][y]) cout << setw(4) << " ";
			else cout << setw(4) << matrix[x][y];
			cout << " | ";
		}
		cout << endl;
	}
	cout << "+------+------+------+------+------+" << endl << endl;

	
}


char check(void)
{
	int t;
	char *p;
	for (t = 0; t<5; t++) {
		p = &matrix[t][0];
		if (*p == *(p + 1) && * (p + 1) == *(p + 2)) return *p;
	}
	for (t = 0; t<5; t++) {
		p = &matrix[0][t];
		if (*p == *(p + 5) && *(p + 5) == *(p + 10)) return *p;
	}

	
	if (matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2])
		return matrix[0][0];
	if (matrix[0][2] == matrix[1][1] && matrix[1][1] == matrix[2][0])
		return matrix[0][2];
	return SPACE;
}
/* bool CheckIsWin(string symbol)
        { 
            //Проверяем горизонталь и вертикаль
            int win = 0;
            int mdig, supdig, hor, ver;
 
            for (int i = 0; i < 3; i++)
            {
                hor = 0; ver = 0;
                for (int j = 0; j < 3; j++)
                {
                    if (GameBoardArr[i, j] == symbol)
                    {
                        hor++;
                    }
                    if (GameBoardArr[j, i] == symbol)
                    {
                        ver++;
                    }
                }
                if (hor == 3 || ver == 3)
                {
                    return true;
                }               
               
            }
            
            mdig = 0; supdig = 0;
            //Диагонали
            for (int i = 0; i < 3; i++)
            {
                if (GameBoardArr[i, i] == symbol)
                {
                    mdig++;
                }
                if (GameBoardArr[i,2 - i] == symbol )
                {
                    supdig++;
                }
            }
            if (mdig == 3 || supdig == 3)
            {
                return true;
            }
             
        }
	*/
