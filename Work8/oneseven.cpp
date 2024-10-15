#include <iostream>

using namespace std;

void multiplimtrix(int** matrixfirst, int colf, int rowf, int** matrixsecond, int cols, int rows) {
    cout << "Результат перемножения матриц: " << endl;
    int** rslt = new int* [rowf];
    for (int i = 0; i < rowf; i++) {
        rslt[i] = new int[cols];
    }

    for (int i = 0; i < rowf; i++) {
        for (int j = 0; j < cols; j++) {
            rslt[i][j] = 0;

            for (int k = 0; k < colf; k++) {
                rslt[i][j] += matrixfirst[i][k] * matrixsecond[k][j];
            }

            cout << rslt[i][j] << "\t";
        }
        cout << endl;
    }

    for (int i = 0; i < rowf; i++) {
        delete[] rslt[i];
    }
    delete[] rslt;
    system("pause");
}

void addnums(int** matrixfirst, int colf, int rowf, int** matrixsecond, int cols, int rows) {
    cout << "Заполните 1 матрицу" << endl;
    for (short i = 0; i < rowf; i++) {
        for (short j = 0; j < colf; j++) {
            cin >> matrixfirst[i][j];
        }
    }

    cout << "Заполните 2 матрицу" << endl;
    for (short i = 0; i < rows; i++) {
        for (short j = 0; j < cols; j++) {
            cin >> matrixsecond[i][j];
        }
    }
}

void creatematrix() {
    int rowf, colf;
    int rows, cols;

    while (true) {
        cout << "Введите количество строк матрицы 1: ";
        cin >> rowf;
        cout << "Введите количество столбцов матрицы 1: ";
        cin >> colf;

        cout << "Введите количество строк матрицы 2: ";
        cin >> rows;
        cout << "Введите количество столбцов матрицы 2: ";
        cin >> cols;

        if (colf == rows) {
            break;
        }
        else {
            cout << "Матрицы не могут быть перемножены.\nКоличество столбцов первой матрицы должны равняться количеству строк второй матрицы.\nПопробуйте снова" << endl;
        }
        system("pause");
        system("cls");
    }

    int** matrixfirst = new int* [rowf];
    for (short i = 0; i < rowf; i++) {
        matrixfirst[i] = new int[colf];
    }

    int** matrixsecond = new int* [rows];
    for (short i = 0; i < rows; i++) {
        matrixsecond[i] = new int[cols];
    }

    addnums(matrixfirst, colf, rowf, matrixsecond, cols, rows);
    multiplimtrix(matrixfirst, colf, rowf, matrixsecond, cols, rows);

    for (short i = 0; i < rowf; i++) {
        delete[] matrixfirst[i];
    }
    delete[] matrixfirst;

    for (short i = 0; i < rows; i++) {
        delete[] matrixsecond[i];
    }
    delete[] matrixsecond;
}

int mainone() {
    setlocale(LC_ALL, "RU");
    creatematrix();
    return 0;
}
