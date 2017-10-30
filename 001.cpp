#include <iostream>

using namespace std;



int main() {
    setlocale(0, "");


    char cells[9] = {'-', '-', '-', '-', '-', '-', '-', '-', '-',};

    int cell;
    int cell1;

    cout << "------------" << "\n" << endl;
    cout << "Номера клеток:" << endl;
    cout << "-" << 1 << "-" << '|' << "-" << 2 << "-" << '|' << "-" << 3 << "-" << " |" << endl;
    cout << "-" << 4 << "-" << '|' << "-" << 5 << "-" << '|' << "-" << 6 << "-" << " |" << endl;
    cout << "-" << 7 << "-" << '|' << "-" << 8 << "-" << '|' << "-" << 9 << "-" << " |" << "\n" << endl;


    cout << "Игровое поле (--- пусто):" << endl;
    cout << "-" << cells[0] << "-" << '|' << "-" << cells[1] << "-" << '|' << "-" << cells[2] << "-" << " |" << endl;
    cout << "-" << cells[3] << "-" << '|' << "-" << cells[4] << "-" << '|' << "-" << cells[5] << "-" << " |" << endl;
    cout << "-" << cells[6] << "-" << '|' << "-" << cells[7] << "-" << '|' << "-" << cells[8] << "-" << " |" << "\n"
         << endl;

    cout << "------------\n" << endl;


    for (int o = 0; o <= 9; ++o) {
        cout << "Введите номер клетки, куда ходить  X: ";
        cin >> cell;
        cells[cell - 1] = 'x';

        cout << "-" << cells[0] << "-" << '|' << "-" << cells[1] << "-" << '|' << "-" << cells[2] << "-" << " |"
             << endl;
        cout << "-" << cells[3] << "-" << '|' << "-" << cells[4] << "-" << '|' << "-" << cells[5] << "-" << " |"
             << endl;
        cout << "-" << cells[6] << "-" << '|' << "-" << cells[7] << "-" << '|' << "-" << cells[8] << "-" << " |" << "\n"
             << endl;


        cout << "Введите номер клетки, куда ходить 0: ";
        cin >> cell1;
        cells[cell1 - 1] = '0';

        cout << "-" << cells[0] << "-" << '|' << "-" << cells[1] << "-" << '|' << "-" << cells[2] << "-" << " |"
             << endl;
        cout << "-" << cells[3] << "-" << '|' << "-" << cells[4] << "-" << '|' << "-" << cells[5] << "-" << " |"
             << endl;
        cout << "-" << cells[6] << "-" << '|' << "-" << cells[7] << "-" << '|' << "-" << cells[8] << "-" << " |" << "\n"
             << endl;


    }
    if ((cells[0] == 'x') && (cells[1] == 'x') && (cells[2] == 'x')) {
        cout << "Победа! X" << endl;

    }
    if ((cells[3] == 'x') && (cells[4] == 'x') && (cells[5] == 'x')) {
        cout << "Победа! X" << endl;

    }
    if ((cells[6] == 'x') && (cells[7] == 'x') && (cells[8] == 'x')) {
        cout << "Победа! X" << endl;

    }
    if ((cells[0] == 'x') && (cells[3] == 'x') && (cells[6] == 'x')) {
        cout << "Победа! X" << endl;

    }
    if ((cells[1] == 'x') && (cells[4] == 'x') && (cells[7] == 'x')) {
        cout << "Победа! X" << endl;

    }
    if ((cells[2] == 'x') && (cells[5] == 'x') && (cells[8] == 'x')) {
        cout << "Победа! X" << endl;

    }
    if ((cells[0] == 'x') && (cells[4] == 'x') && (cells[8] == 'x')) {
        cout << "Победа! X" << endl;

    }
    if ((cells[2] == 'x') && (cells[4] == 'x') && (cells[6] == 'x')) {
        cout << "Победа! X" << endl;

    }
    if ((cells[0] == '0') && (cells[1] == '0') && (cells[2] == '0')) {
        cout << "Победа! X" << endl;

    }
    if ((cells[3] == '0') && (cells[4] == '0') && (cells[5] == '0')) {
        cout << "Победа! X" << endl;

    }
    if ((cells[6] == '0') && (cells[7] == '0') && (cells[8] == '0')) {
        cout << "Победа! X" << endl;

        if ((cells[0] == '0') && (cells[3] == '0') && (cells[6] == '0')) {
            cout << "Победа! X" << endl;

        }
        if ((cells[1] == '0') && (cells[4] == '0') && (cells[7] == '0')) {
            cout << "Победа! X" << endl;

        }
        if ((cells[2] == '0') && (cells[5] == 'x') && (cells[8] == '0')) {
            cout << "Победа! X" << endl;

        }
        if ((cells[0] == '0') && (cells[4] == '0') && (cells[8] == '0')) {
            cout << "Победа! X" << endl;

        }
        if ((cells[2] == '0') && (cells[4] == '0') && (cells[6] == '0')) {
            cout << "Победа! X" << endl;

        }


        system("pause");
        return 0;


    }
}
