#include <stdlib.h>
#include <time.h>
#include "Array.h" 
#include<Windows.h> // ���������� ��� ������ � ������������ ������������ �����, � ��� �� ��� ���������.
 
int main()
{
	SetConsoleCP(1251); // ���������, ������
    SetConsoleOutputCP(1251);
	int w = 10, h = 10, multi;
    DWORD err; // ���������� � ������ ������
	// ���������� ����������� ���� ����������
    HINSTANCE hDll = LoadLibrary("DLL_Array.dll"); // DLL_Array.dll - �������� ������������ ����������
    if (hDll == NULL)
    { // ���� ������� �����������
        printf("���������� ������� ��������� \n");
    }
    else
    { // ����� ������
        err = GetLastError();
        printf("���������� �� �������. ������ ����.  %d\n", err);
		std::cin.get();
		std::cin.get();
        return 0;
    }
    // ��������� ��������� �� ������� ����������
    string lpTestFunction = "TestFunction";
    // ������������ �����������
    FreeLibrary(hDll);

    srand ( time ( NULL ) ); // ���������� ������� ��������
 
    double **matrix;
 
	std::cout<<"������  ����������  �������  �  �����  k.  ���������  k-�  ������  �� "
		<<"������������ ������� ���� ������. ������� �������� � ���������� �������. \n";

    std::cout << "������� ������ ������� (N x N): ";
    int N;
    std::cin >> N;
 
    matrix = new double * [N];
    for ( int i = 0; i < N; i ++ )
	{
        matrix[i] = new double [N];
	}
    input   ( matrix, N );
    output  ( matrix, N );
 
    std::cout << "\n������� ����� ������, ������� ������ �����������:" ;
    int k;
    std::cin >> k;
    k -= 1;
 
    divall  ( matrix, N, k );
    output  ( matrix, N );
    std::cin.get();
    std::cin.get();
    return 0;
}
 
