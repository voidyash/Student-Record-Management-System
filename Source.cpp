#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include<Windows.h>
#include"adminFunction.h"
#include"loading.h"

void passwordVerification(void);
void mainMenu(void);

void passwordVerification()
{
	system("cls");

	std::string password;

	std::cout << "\n\n\n\n\n\t\t\t\t\t";
	std::cout << "\n\n\n\t\t\t\t\tEnter Password: " << std::endl;

	do
	{
		std::cin >> password;

		if (password!= "password")
		{
			system("cls");
			std::cout << "\n\n\n\n\n\t\t" << "Wrong password TRY AGAIN! or type 'quit' or 'exit' to quit the program";
			std::cout << "\n\n\n\t\t\t\t\tEnter Password: ";
		}

		if (password == "Quit" || password == "quit" || password == "QUIT" || password == "Exit" || password == "exit" || password == "EXIT")
		{
			system("cls");
			std::cout << "\t\t\n\n\n\n\n\t\t\t\t\t Quitting The Program";

			for (int i = 0; i < 4; i++)
			{
				Sleep(1000);
				std::cout << ".";
			}
			exit(0);
		}

	} while (password!="password");

	mainMenu();
}

int main()
{
	// fast io
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	loadingBar(); // for loading animation
	system("color 1C");

	adminFunction();
	return 0;
}