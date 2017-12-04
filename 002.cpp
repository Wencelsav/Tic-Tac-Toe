#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

void delete_matrix(char** matrix, int rows) {
	for (int i = 0; i<rows; i++) {
		delete[]matrix[i];
	}
	delete[]matrix;
}

char** create_matrix(char** array,int rows, int columns) {
	array = new char *[rows];
	for (int i = 0; i < rows; ++i) {
		array[i] = new char[columns];
		for (int j = 0; j < columns; ++j) {
			array[i][j] = ' ';
		}
	}
	return array;
}

void disp_matrix(char **array)
{
	for (int j = 0; j < 5; j++)
	{
		cout << "+------+------+------+------+------+" << endl << "| ";
		for (int i = 0; i < 5; i++)
		{
			if (!array[i][j]) cout << setw(4) << " ";
			else cout << setw(4) << array[i][j];
			cout << " | ";
		}
		cout << endl;
	}
	cout << "+------+------+------+------+------+" << endl << endl;


}

void show_available_moves(char **array, char op) {
	int k = 0;
	for (int i = 0; i<5; i++) {
		for (int j = 0; j<5; j++) {
			if (!(array[i][j] == 'X' || array[i][j] == 'O')) {
				if (i == 0) {
					cout << ++k << ". mark cell a" << j + 1 << " as " << op << endl;
				}
				if (i == 1) {
					cout << ++k << ". mark cell b" << j + 1 << " as " << op << endl;
				}
				if (i == 2) {
					cout << ++k << ". mark cell c" << j + 1 << " as " << op << endl;
				}
				if (i == 3) {
					cout << ++k << ". mark cell d" << j + 1 << " as " << op << endl;
				}
				if (i == 4) {
					cout << ++k << ". mark cell e" << j + 1 << " as " << op << endl;
				}
			}
		}
	}
	cout << ++k << ". quit" << endl;
}

bool making_move(char **array, short move, char op) {
    int k = 0;
	for (int i = 0; i<5; i++) {
		for (int j = 0; j<5; j++) {
			if (!(array[i][j] == 'X' || array[i][j] == 'O')) {
				k++;
			}
			if (k == move) {
				array[i][j] = op;
				return true;
			}
		}
	}
	return false;
}

bool win_game(char** array) {
	int k = 0, t = 0;
	for (int j = 0; j<5; j++) {
		for (int i = 0; i<4; i++) {
			if ((array[i][j] == 'X' || array[i][j] == 'O') && array[i][j] == array[i + 1][j]) k++;
			if (k == 4) return true;
		}
		k = 0;
	}
	for (int i = 0; i<5; i++) {
		for (int j = 0; j<4; j++) {
			if ((array[i][j] == 'X' || array[i][j] == 'O') && array[i][j] == array[i][j + 1]) k++;
			if (k == 4) return true;
		}
		k = 0;
	}
	for (int i = 0; i<4; i++) {
		if ((array[i][i] == 'X' || array[i][i] == 'O') && array[i][i] == array[i + 1][i + 1]) k++;
		if ((array[i][4 - i] == 'X' || array[i][4 - i] == 'O') && array[i][4 - i] == array[i + 1][4 - (i + 1)]) t++;
		if (k == 4 || t == 4) return true;
	}
	return false;
}

bool proverka(char** array) {
	int k = 0;
	for (int i = 0; i<5; i++) {
		for (int j = 0; j<5; j++) {
			if (!(array[i][j] == 'X' || array[i][j] == 'O')) {
				k++;
			}
			if (k>0) return true;
		}
	}
	return false;
}

int main() {
	int move,i = 0;
	char **array = create_matrix(array, 5, 5);
	char op;
	bool ok = true, letter = true;

	disp_matrix(array);

	while (proverka(array)) {
		if (letter == true) op = 'X';
		else op = 'O';
		show_available_moves(array, op);
		cin >> move;
		if (move == 26 - i) {
			break;
		}
		while (move<1 || move>25 - i) {
			cout << endl << "You can`t use this number, please, try again: ";
			cin >> move;
		}
		ok = making_move(array, move, op);
		if (ok != true) break;
		disp_matrix(array);
		if (win_game(array)) {
			cout << endl << "Player " << op << " is winner!";
			cin.get();
			return 0;
		}
		letter = !letter;
		i++;
	}

	cout << endl << "Thanks for the game!";
	delete_matrix(array, 5);
	cin.get();
	return 0;
}
