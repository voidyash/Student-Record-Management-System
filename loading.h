#include<iostream>
#include<Windows.h>

void loadingBar()
{
	system("cls");
	system("color 1C");

	char a = 177, b = 219;
	std::cout << "\n\n\n\t\t\t\t\t Student's Data Management System" << std::endl;
	std::cout << "\n\t\t\t\t\t Loading......." << std::endl << std::endl;

	for (int i = 0; i < 26; i++)
	{
		std::cout << a;
	}
	std::cout << "\r";
	
	for (int i = 0; i < 26; i++)
	{
		std::cout << b;
		Sleep(200);
	}

}