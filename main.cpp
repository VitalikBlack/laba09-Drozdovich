#include <stdlib.h>
#include <time.h>
#include "Array.h" 
#include<Windows.h>
 
int main()
{
	SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand ( time ( NULL ) );
 
    double **matrix;
 
	std::cout<<" Ввести  квадратную  матрицу  и  число  k.  Разделить  k-ю  строку  на "
		<<"диагональный элемент этой строки. Вывести исходную и полученную матрицы. \n";

    std::cout << "Введите размер матрицы (N x N): ";
    int N;
    std::cin >> N;
 
    matrix = new double * [N];
    for ( int i = 0; i < N; i ++ )
	{
        matrix[i] = new double [N];
	}
    input   ( matrix, N );
    output  ( matrix, N );
 
    std::cout << "\nВведите номер строки, которой хотите оперировать:" ;
    int k;
    std::cin >> k;
    k -= 1;
 
    divall  ( matrix, N, k );
    output  ( matrix, N );
    std::cin.get();
    std::cin.get();
    return 0;
}
 
