#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

void addData(void);
void viewData(void);
void mainMenu(void);
void deleteData(void);
void adminVerification(void);
void studentFunction(void);

void adminFunction()
{
	system("cls");
	std::cout << "\n\n\t\t\t\t | LOGGED IN AS ADMIN | " << std::endl;
	std::cout << "\n\n\t\t\t\t 1. Add students detail: " << std::endl;
	std::cout << "\n\n\t\t\t\t 2. View students details: " << std::endl;
	std::cout << "\n\n\t\t\t\t 3. Main Menu " << std::endl;
	std::cout << "\n\n\t\t\t\t 4. Delete Student's data: " << std::endl;
	std::cout << "\n\n\t\t\t\t 5. Exit......... " << std::endl;

	int option;

	std::cout << "\n\n\t\t\t\t Enter Choice: " << std::endl;

	do
	{
		std::cin >> option;
		{
			switch (option)
			{	
			case 1:
				addData();
				break;
			
			case 2:
				viewData();
				break;

			case 3: 
				mainMenu();
				break;

			case 4: 
				deleteData();
				break;

			case 5:
				system("cls");
				std::cout << "\n\n\t\t\t\t QUITTING THE PROGRAM " << std::endl;

				for (int i = 0; i < 4; i++)
				{
					Sleep(1000);
					std::cout << ".";
				}
				exit(0);
				break;

			default:
				system("cls");
				std::cout << "\n\n\t\t\t\t | LOGGED IN AS ADMIN | " << std::endl;
				std::cout << "\n\n\t\t\t\t 1. Add students detail: " << std::endl;
				std::cout << "\n\n\t\t\t\t 2. View students details: " << std::endl;
				std::cout << "\n\n\t\t\t\t 3. Main Menu " << std::endl;
				std::cout << "\n\n\t\t\t\t 4. Delete Student's data: " << std::endl;
				std::cout << "\n\n\t\t\t\t 5. Exit......... " << std::endl;

				std::cout << "\n\n\t\t\t\t invalid input!" << std::endl;

				std::cout << "\n\n\t\t\t\t Enter choice: " << std::endl;
			}
		}
	} while (option!='5');
}

void mainMenu()
{
	system("cls");

	std::cout << "\n\n\n\n\t\t\t\t Login as : " << std::endl;
	std::cout << "\n\n\n\t\t\t\t 1. Admin " << std::endl;
	std::cout << "\n\n\n\t\t\t\t 2. Student " << std::endl;
	std::cout << "\n\n\n\t\t\t\t 3. Exit " << std::endl;
	std::cout << "\n\n\n\t\t\t\t Enter your choice:  " << std::endl;

	int choice;
	
	std::cin >> choice;
	
	switch (choice)
	{	
	case 1:
		adminVerification();
		break;

	case 2:
		system("cls");

		std::cout << "Welcome as student" << std::endl;
		studentFunction();
		break;

	case 3:
		system("cls");
		std::cout << "\n\n\n\t\t\t\t Quitting the program" << std::endl;

		for (int i = 0; i < 4; i++)
		{
			Sleep(1000);
			std::cout << "." << std::endl;
		}
		exit(0);
		break;

	default:
		std::cout << "Invalid Input" << std::endl;
	}

	system("pause");
}

void deleteData()
{
	system("cls");

	// Open file pointers
	std::fstream fin, fout;

	// Open the existing file
	fin.open("data.csv", std::ios::in);

	// Create a new file to store the non-deleted data
	fout.open("datanew.csv", std::ios::out);

	int rollnum, roll1, marks, count = 0, i;
	char sub;
	int index, new_marks;
	std::string line, word;
	std::vector<std::string> row;

	// Get the roll number to decide the data to be deleted
	std::cout << "Enter the roll number of the record to be deleted: " << std::endl;
	std::cin >> rollnum;

	// Check if this record exists, If exists, leave it and add all other data to the new file
	while (!fin.eof())
	{
		row.clear();

		std::getline(fin, line);
		std::stringstream s(line);

		while (std::getline(s, word, ','))
		{
			row.push_back(word);
		}

		int row_size = row.size();
		roll1 = std::stoi(row[0]);

		// writing all records, except the record to be deleted, into the new file "reportcardnew.csv"
		// using fout pointer
		if (roll1 != rollnum)
		{
			if (!fin.eof())
			{
				for ( i = 0; i < row_size; i++)
				{
					fout << row[i] << ",";
				}
				fout << row[row_size - 1] << std::endl;
			}
		}
		else
		{
			count = 1;
		}
		if (fin.eof())
		{
			break;
		}
	}

	if (count == 1)
	{
		std::cout << "Record Deleted" << std::endl;
	}
	else
	{
		std::cout << "Record not found" << std::endl;
	}

	// Close the pointers
	fin.close();
	fout.close();

	// Removing the existing file
	remove("data.csv");

	// Renaming the new file with the existing file name
	rename("datanew.csv", "data.csv");

	Sleep(2000);

	adminFunction();
}

void addData()
{
	system("cls");
	std::fstream file("data.csv", std::ios::out | std::ios::app);

	if (!file)
	{
		std::cout << "\n Failed to open data.csv or data.csv file not found" << std::endl;
	}

	else
	{
		std::cout << "\t |Enter Data| \n" << std::endl;
	}
	
	std::string rollNumber, name, college, branch, attendance, physics, chemistry, maths;
	std::string moreData;

	std::cout << "\n Enter student's roll number: " << std::endl;
	std::cin >> rollNumber;
	file << "\n" << rollNumber << "," << std::endl;

	std::cout << "Enter student's name: " << std::endl;
	std::cin >> name;
	file << name << ",";

	std::cout << "\n Enter college" << std::endl;
	std::cin >> college;
	file << college << ",";

	std::cout << "\n Enter Branch" << std::endl;
	std::cin >> branch;
	file << branch << ",";

	std::cout << "\n Enter attendance" << std::endl;
	std::cin >> attendance;
	file << attendance << ",";

	std::cout << "\n Enter physics's marks" << std::endl;
	std::cin >> physics;
	file << physics << ",";

	std::cout << "\n Enter Chemistry marks" << std::endl;
	std::cin >> chemistry;
	file << chemistry << ",";

	std::cout << "\n Enter maths marks" << std::endl;
	std::cin >> maths;
	file << maths;

	file.close();

	std::cout << "\n Add more Record? (Y/N) : " << std::endl;

	std::cin >> moreData;

	if (moreData == "y" || moreData == "Y" || moreData == "yes" || moreData == "Yes")
	{
		addData();
	}

	else if (moreData == "n" || moreData == "N" || moreData == "no" || moreData == "No")
	{
		adminFunction();
	}

	else
	{
		std::cout << "Enter a valid response!!!" << std::endl;
	}

	adminFunction();
}

void viewData()
{
	system("cls");

	std::fstream file("data.csv");

	if (!file)
	{
		std::cout << "Failed to open the file!" << std::endl;
	}

	std::cout << "\n\t\t\t\t\t\t|Student's Record|" << std::endl << std::endl;

	std::cout << "\n-------------------------------------------------------------------------------------------------------" << std::endl << std::endl;
	std::cout << "Roll \t Name \t College \t Branch \t Attendance \t Physics\t Chemistry \t Maths" << std::endl;
	
	std::string rollNumber, name, college, branch, attendance, physics, chemistry, maths;

	while (!file.eof())
	{
		std::getline(file, rollNumber, ',');
		std::getline(file, name, ',');
		std::getline(file, college, ',');
		std::getline(file, branch, ',');
		std::getline(file, attendance, ',');
		std::getline(file, physics, ',');
		std::getline(file, chemistry, ',');
		std::getline(file, maths, '\n');

		std::cout << rollNumber << "\t" << name << "\t\t\t" << college << "\t\t" << branch
			<< "\t\t" << attendance << "\t\t" << physics << "\t\t" << chemistry << "\t\t" << maths
			<< std::endl << std::endl;
	}

	std::cout << "\n-------------------------------------------------------------------------------------------------------" << std::endl;
	file.close();

	std::cout << "0. Exit " << std::endl;
	std::cout << "\n Enter Choice: " << std::endl;
}

void adminVerification()
{
	system("cls");

	std::string password;

	std::cout << "\n\n\n\n\n\t\t\t\t\t";
	std::cout << "\n\n\n\t\t\t\t\tEnter Password: " << std::endl;

	do
	{
		std::cin >> password;

		if (password!="password")
		{
			system("cls");
			std::cout << "\n\n\n\n\n\t\t" << "WRONG PASSWORD!, try again or type menu to Navigate to main menu";
			std::cout << "\n\n\n\t\t\t\t\tEnter Password: " << std::endl;
		}

		if (password == "Menu" || password == "menu" || password == "MENU")
		{
			mainMenu();
		}
	} while (password != "password");
	
	adminFunction();
}

void studentFunction()
{
	system("cls");

	std::fstream file("data.csv");

	if (!file)
	{
		std::cout << "Failed in open the file!" << std::endl;
	}

	std::cout << "\n\t\t\t\t\t\t |Student's Record|" << std::endl << std::endl;

	std::cout << "\n-----------------------------------------------------------------\n\n" << std::endl;
	std::cout << "Roll \t Name \t College \t Branch \t Attendance \t Physics\t Chemistry \t Maths" << std::endl;

	std::string rollNumber, name, college, branch, attendance, physics, chemistry, maths;

	while (!file.eof())
	{
		std::getline(file, rollNumber, ',');
		std::getline(file, name, ',');
		std::getline(file, college, ',');
		std::getline(file, branch, ',');
		std::getline(file, attendance, ',');
		std::getline(file, physics, ',');
		std::getline(file, chemistry, ',');
		std::getline(file, maths, '\n');

		std::cout << rollNumber << "\t" << name << "\t\t\t" << college << "\t\t" << branch
			<< "\t\t" << attendance << "\t\t" << physics << "\t\t" << chemistry << "\t\t" << maths
			<< std::endl << std::endl;
	}

	std::cout << "\n-------------------------------------------------------------------------------------------------------" << std::endl;
	file.close();
	
	system("pause");

	mainMenu();
}