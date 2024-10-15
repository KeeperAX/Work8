#include <iostream>

using namespace std;

void powmatrix(int** matrix, int col, int row) {
    cout << "В какую степень вы хотите возвести матрицу?" << endl;
    int pow;
    cin >> pow;

    if (pow < 0) {
        cout << "Отрицательная степень не поддерживается." << endl;
        return;
    }

    int** resultmatrix = new int* [row];
    for (short i = 0; i < row; i++) {
        resultmatrix[i] = new int[col];
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            resultmatrix[i][j] = (i == j) ? 1 : 0;
        }
    }

    for (int n = 0; n < pow; n++) {
        int** tempmatrix = new int* [row];
        for (short i = 0; i < row; i++) {
            tempmatrix[i] = new int[col];
        }

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                tempmatrix[i][j] = 0;
                for (int k = 0; k < col; k++) {
                    tempmatrix[i][j] += resultmatrix[i][k] * matrix[k][j];
                }
            }
        }

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                resultmatrix[i][j] = tempmatrix[i][j];
            }
        }

        for (short i = 0; i < row; i++) {
            delete[] tempmatrix[i];
        }
        delete[] tempmatrix;
    }

    cout << "Результат возведения матрицы в степень: " << pow << endl;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << resultmatrix[i][j] << "\t";
        }
        cout << endl;
    }

    for (short i = 0; i < row; i++) {
        delete[] resultmatrix[i];
    }
    delete[] resultmatrix;
    system("pause");
}

void addnums2(int** matrixfirst, int col, int row) {
    cout << "Заполните матрицу" << endl;
    for (short i = 0; i < row; i++) {
        for (short j = 0; j < col; j++) {
            cin >> matrixfirst[i][j];
        }
    }
}

void creatematrix2() {
    int row, col;

    while (true) {
        cout << "Введите размерность матрицы: ";
        cin >> row;
        col = row;

        if (row > 0 && col > 0) {
            break;
        }
        else {
            cout << "Количество строк и столбцов должно быть положительным. Попробуйте снова." << endl;
        }
    }

    int** matrix = new int* [row];
    for (short i = 0; i < row; i++) {
        matrix[i] = new int[col];
    }

    addnums2(matrix, col, row);
    powmatrix(matrix, col, row);

    for (short i = 0; i < row; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int localmain() {
    setlocale(LC_ALL, "RU");
    creatematrix2();
    return 0;
}
