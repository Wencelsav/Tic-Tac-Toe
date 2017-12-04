#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

void delete_matrix(char** matrix, unsigned int rows) {
	for (unsigned int i = 0; i<rows; i++) {
		delete[]matrix[i];
	}
	delete[]matrix;
}

char** create_matrix(char** matrix, unsigned int rows, unsigned int columns) {
	matrix = new char *[rows];
	for (unsigned int i = 0; i < rows; ++i) {
		matrix[i] = new char[columns];
		for (unsigned int j = 0; j < columns; ++j) {
			matrix[i][j] = ' ';
		}
	}
	return matrix;
}

void disp_matrix(char **array)
{
	for (int i = 0; i < 3; i++)
	{
		cout << "+------+------+------+" << endl << "| ";
		for (int x = 0; x < 3; x++)
		{
			if (!array[x][i]) cout << setw(4) << " ";
			else cout << setw(4) << array[x][i];
			cout << " | ";
		}
		cout << endl;
	}
	cout << "+------+------+------+" << endl << endl;


}

void show_available_moves(char **array, char op) {
	unsigned int k = 0;
	for (unsigned int i = 0; i<3; i++) {
		for (unsigned int j = 0; j<3; j++) {
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
			}
		}
	}
	cout << ++k << ". quit" << endl;
}

bool making_move(char **array, short move, char op) {
	unsigned int k = 0;
	for (unsigned int i = 0; i<3; i++) {
		for (unsigned int j = 0; j<3; j++) {
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
	unsigned int k = 0, t = 0;
	for (unsigned j = 0; j<3; j++) {
		for (unsigned int i = 0; i<2; i++) {
			if ((array[i][j] == 'X' || array[i][j] == 'O') && array[i][j] == array[i + 1][j]) k++;
			if (k == 2) return true;
		}
		k = 0;
	}
	for (unsigned int i = 0; i<3; i++) {
		for (unsigned int j = 0; j<2; j++) {
			if ((array[i][j] == 'X' || array[i][j] == 'O') && array[i][j] == array[i][j + 1]) k++;
			if (k == 2) return true;
		}
		k = 0;
	}
	for (unsigned int i = 0; i<2; i++) {
		if ((array[i][i] == 'X' || array[i][i] == 'O') && array[i][i] == array[i + 1][i + 1]) k++;
		if ((array[i][2 - i] == 'X' || array[i][2 - i] == 'O') && array[i][2 - i] == array[i + 1][2 - (i + 1)]) t++;
		if (k == 2 || t == 2) return true;
	}
	return false;
}

bool proverka(char** array) {
	unsigned int k = 0;
	for (unsigned int i = 0; i<3; i++) {
		for (unsigned int j = 0; j<3; j++) {
			if (!(array[i][j] == 'X' || array[i][j] == 'O')) {
				k++;
			}
			if (k>0) return true;
		}
	}
	return false;
}

int main() {
	unsigned int i = 0;
	char **array = create_matrix(array, 3, 3);
	char op;
	short move;
	bool ok = true, letter = true;

	disp_matrix(array);

	while (proverka(array)) {
		if (letter == true) op = 'X';
		else op = 'O';
		show_available_moves(array, op);
		cin >> move;
		if (move == 10 - i) {
			break;
		}
		while (move<1 || move>(9 - i)) {
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
	delete_matrix(array, 3);
	cin.get();
	return 0;
}
