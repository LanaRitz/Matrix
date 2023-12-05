#include <iostream>
#include <iomanip>

using namespace std;

void Header();
void DataInput();
void PrintMatrix();
void Solution(int row, int col);

int rows, cols, i, j;
char CONTINUE;
double constant[10][10];


int main()
{
    start:
    Header();

    cout << "Enter the number of equations to be solved: ";
    cin >> rows;
    cols = rows + 1;

    cout << setprecision(3); // 3 значащих цифр после запятой

    DataInput();
    PrintMatrix();
    cout << endl;

    cout << "|--------------------------------SOLVE...-----------------------|" << endl;
    Solution(0, 0);

    cout << endl << "Type 'Y' to restart, otherwise exit." << endl;
    cin >> CONTINUE;

    if(CONTINUE == 'Y'  || CONTINUE == 'y')
    {
        goto start;
    }
    else
    {
        return 0;
    }
}

void Header()
{
    cout <<" ________________________________________________________________ " << endl;
    cout <<"|                                                                 |" << endl;
    cout <<"|                       Gauss-Jordan Method                       |" << endl;
    cout <<"|_________________________________________________________________|" << endl;

    cout << endl << endl;
}

void DataInput()
{
    cout << "Enter the constants." << endl;

    for (i = 0; i < rows; ++i)
    {
        for (j = 0; j < cols; ++j)
        {
            cin >> constant[i][j];
        }
    }
}

void PrintMatrix()
{
    for (i = 0; i < rows; ++i)
    {
        for (j = 0; j < cols; ++j)
        {
            if(j == cols - 1)
            {
                cout << "| ";
            }

            if(j == cols - 1)
            {
                cout << constant[i][j] << endl;
            }
            else
            {
                cout << "\t" << constant[i][j] << "\t";
            }
        }
    }
}


void Solution(int row, int col)
{
    if (row == rows)  // Все строки обработаны
    {
        cout << "|--------------------------------RESULT--------------------------|" << endl;
        PrintMatrix();
        cout << endl << endl;

        double x = constant[0][cols - 1];
        double y = constant[1][cols - 1];
        double z = constant[2][cols - 1];

        cout << "\t" << "x = " << x << "\t";
        cout << "\t" << "y = " << y << "\t";
        cout << "\t" << "z = " << z << endl;

        cout << "|----------------------------------------------------------------|" << endl;

        return;
    }

    // Приводим текущую строку к единичному виду
    double pivot = constant[row][col];
    for (int j = col; j < cols; j++)
    {
        constant[row][j] /= pivot;
    }

    // Обновляем остальные строки
    for (int i = 0; i < rows; i++)
    {
        if (i != row)
        {
            double factor = constant[i][col];
            for (int j = col; j < cols; j++)
            {
                constant[i][j] -= factor * constant[row][j];
            }
        }
    }

    PrintMatrix();
    cout << endl << endl;

    // Рекурсивно обрабатываем следующую строку и столбец
    Solution(row + 1, col + 1);
}






