#include <stdlib.h>
#include <time.h>
#include "Array.h" 
 
int main()
{
	setlocale(LC_ALL, "Russian");
    srand ( time ( NULL ) );
 
    double **matrix;
 
    std::cout << "¬ведите размер матрицы (N x N): ";
    int N;
    std::cin >> N;
 
    matrix = new double * [N];
    for ( int i = 0; i < N; i ++ )
	{
        matrix[i] = new double [N];
	}
    input   ( matrix, N );
    output  ( matrix, N );
 
    std::cout << "\n¬ведите номер строки, которой хотите оперировать:" ;
    int k;
    std::cin >> k;
    k -= 1;
 
    divall  ( matrix, N, k );
    output  ( matrix, N );
    std::cin.get();
    std::cin.get();
    return 0;
}
 
