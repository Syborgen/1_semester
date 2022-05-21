#include "conio.h" //подключаем для getch()
#include "Math.h" //подключаем для sqrt()
#include "Windows.h" //подключаем для system("cls")
#include <locale.h> // для подключения русского языка
#include <ctime>
#include<cstdlib>
#include <iostream>
using namespace std;

//GNU
int main() 
{
	setlocale(LC_ALL, "Rus");

	const int size = 10;
	
	int a[size];
	
	int i, j;
		
	srand(time(NULL));
		
	i = 0;
	
	for (int i = 0; i < size; i++)
	
		a[i] = rand() % 11 - 5;
	
	for (i = 0; i < size; i++)
	
		std::cout << a[i] << " ";
	
	for (i = 0; i < size; i++)
	
		for (int j = i + 1; j < size; j++)
		
			if (a[i] < a[j])
			{
			
				int buf = a[i];
				
				a[i] = a[j];
				
				a[j] = buf;
			
			}
	
	std::cout << std::endl << std::endl;
	
	for (i = 0; i < size; i++)
		
		std::cout << a[i] << " ";
	
	_getch();
	
	return 0;
}