#include"Array.h"

void output ( double **matrix, int N )
{
    std::cout << endl;
    for ( int i = 0; i < N; i ++ )
    {
           for ( int j = 0; j < N; j ++ )
                std::cout << matrix[i][j] << "\t";
           std::cout << std::endl;
    }
}
 
void input  ( double **matrix, int N )
{
    for ( int i = 0; i < N; i ++ )
            for ( int j = 0; j < N; j ++ )
                    matrix[i][j] = rand() % 10;
}
 
void divall ( double **matrix, int N, int k)
{
    for ( int j = 0; j < N; j ++ )
        {
            if ( matrix[j][j] != 0 ) matrix[k][j] /= matrix[j][j];
            else
                matrix[k][j] = 0;
        }
}