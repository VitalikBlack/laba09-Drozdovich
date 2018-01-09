#include <stdlib.h>
#include <time.h>
#include "Array.h" 
#include<Windows.h> // библиотека для работы с динамическим подключением дллки, а так же для кодировки.
 
int main()
{
	SetConsoleCP(1251); // кодировка, шрифты
    SetConsoleOutputCP(1251);
	int w = 10, h = 10, multi;
    DWORD err; // переменная в случае ошибки
	// подключаем динамически нашу библиотеку
    HINSTANCE hDll = LoadLibrary("DLL_Array.dll"); // DLL_Array.dll - название подключаемой библиотеки
    if (hDll == NULL)
    { // если успешно загрузилось
        printf("Библиотека успешно загружена \n");
    }
    else
    { // иначе ошибка
        err = GetLastError();
        printf("Бибилотека не найдена. Ошибка кода.  %d\n", err);
		std::cin.get();
		std::cin.get();
        return 0;
    }
    // получение указателя на функцию библиотеки
    string lpTestFunction = "TestFunction";
    // освобождение дескриптора
    FreeLibrary(hDll);

    srand ( time ( NULL ) ); // заполнение матрицы рандомом
 
    double **matrix;
 
	std::cout<<"Ввести  квадратную  матрицу  и  число  k.  Разделить  k-ю  строку  на "
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
 
