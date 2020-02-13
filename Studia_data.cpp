

#include <iostream>
#include <fstream>
#include "Subject.h"
#include "Semestr.h"
#include "Student.h"
using namespace std;
void Pearson_find_name(string name)
{
	ifstream inFile;
	ifstream inFile1;
	string zmienna;
	inFile.open("database.txt");


	string linia;
	string linia2;
	vector <string> database_v;

	while (getline(inFile, linia))
	{
		database_v.push_back(linia);
	}
	inFile.close();

	for (int i = 0; i < database_v.size(); i++)
	{
		if (database_v[i] == name)
		{
			inFile1.open(database_v[i + 2] + ".txt");          
			while (getline(inFile1, linia2))
			{

				cout << linia2 << endl;

			}
		}
		cout << "=====================================\n";
		inFile1.close();
	}
}
void Pearson_find_ID(int ID)
{
	ifstream inFile;
	ifstream inFile1;
	string zmienna;
	inFile.open("database.txt");


	string linia;
	string linia2;
	vector <string> database_v;

	while (getline(inFile, linia))
	{
		database_v.push_back(linia);
	}
	inFile.close();

	for (int i = 0; i < database_v.size(); i++)
	{
		if (database_v[i] == to_string(ID))
		{
			inFile1.open(database_v[i] + ".txt");         

			while (getline(inFile1, linia2))
			{

				cout << linia2 << endl;

			}
		}
		inFile1.close();
		cout << "=====================================\n";
	}
}
void Pearson_find_surname(string name)
{
	ifstream inFile;
	ifstream inFile1;
	string zmienna;
	inFile.open("database.txt");


	string linia;
	string linia2;
	vector <string> database_v;

	while (getline(inFile, linia))
	{
		database_v.push_back(linia);
	}
	inFile.close();

	for (int i = 0; i < database_v.size(); i++)
	{
		if (database_v[i] == name)
		{
			inFile1.open(database_v[i + 1] + ".txt");          

			while (getline(inFile1, linia2))
			{

				cout << linia2 << endl;

			}
		}
		inFile1.close();
		cout << "=====================================\n";
	}
}
void Reading_data_menu()
{
	int choice;
	bool repeat;
	cout << "Reading Data MENU: \n";
	cout << "Find Student BY: \n";
	cout << "(1) Name\n";
	cout << "(2) Surname\n";
	cout << "(3) ID\n";
	do
	{
		cin >> choice;
		repeat = false;
		switch (choice)
		{
		case 1:
		{
			string name;
			system("cls");
			cout << "Insert Name: ";
			cin >> name;
			Pearson_find_name(name);
		}
		break;
		case 2:
		{
			string surname;
			system("cls");
			cout << "Insert Surname: ";
			cin >> surname;
			Pearson_find_surname(surname);
		}
		break;
		case 3:
		{
			int ID_find;
			system("cls");
			cout << "Insert ID: ";
			cin >> ID_find;
			Pearson_find_ID(ID_find);
		}
		break;
		default:
		{
			cout << "Choose once again \n";
			repeat = true;
		}
		break;
		}
	} while (repeat);
}
vector<Student*> Writing_data_menu()
{
	vector<Student*> database_hold;
	int count_of_students;
	cout << "Writing Data MENU: \n";
	cout << "How many students would you like to insert: \n";
	cin >> count_of_students;
	for (int i = 0; i < count_of_students; i++)
	{
		Student* object = new Student();
		ofstream outdata;
		ifstream database;
		database.open("database.txt");
		vector<string> data;
		string indiv;
		while (getline(database, indiv))
		{
			data.push_back(indiv);
		}
		database.close();
		int help = 0;
		for (int i = 0; i < data.size(); i++)
		{
			if (data[i] == to_string(object->get_ID()))
			{
				help++;
			}
		}
		outdata.open(to_string(object->get_ID()) + ".txt", ios::out | ios::app);
		if (help == 0)
		{
			if (outdata.is_open())
			{
				outdata << object->get_name() << " " << object->get_surname() << "\n";
				outdata << object->get_ID() << "\n";
				outdata << object->get_faculty() << " - " << object->get_major() << "\n";
				for (int j = 0; j < object->get_semester_list_size(); j++)
				{
					Semestr_storage ListOfSemesters = object->get_list();
					outdata << "Semester nr: " << ListOfSemesters[j]->get_sem() << "\n";
					outdata << "Sum of ECTs: " << ListOfSemesters[j]->get_ect_total() << "\n";
					outdata << "Sum of collected ECTs: " << ListOfSemesters[j]->get_ect_coll() << "\n";
					outdata << "Semester average: " << ListOfSemesters[j]->get_average() << "\n";
					Subjects ListOfSubjects = ListOfSemesters[j]->get_list_of_subjects();
					for (int k = 0; k < ListOfSubjects.size(); k++)
					{
						outdata << ListOfSubjects[k]->get_short_name() << " - " << ListOfSubjects[k]->get_full_name() << "\n";
						outdata << "ECTs: " << ListOfSubjects[k]->get_ECT() << "\n";
						outdata << "Grades: \n" << ListOfSubjects[k]->get_practice_score() << "," << ListOfSubjects[k]->get_lab_score() << "," << ListOfSubjects[k]->get_exam_score() << "\n";
						outdata << "Final Grade: " << ListOfSubjects[k]->get_final_score() << "\n";
					}
				}
			}
		}
		else
		{
			if (outdata.is_open())
			{
				for (int j = 0; j < object->get_semester_list_size(); j++)
				{
					Semestr_storage ListOfSemesters = object->get_list();
					outdata << "Semester nr: " << ListOfSemesters[j]->get_sem() << "\n";
					outdata << "Sum of ECTs: " << ListOfSemesters[j]->get_ect_total() << "\n";
					outdata << "Sum of collected ECTs: " << ListOfSemesters[j]->get_ect_coll() << "\n";
					outdata << "Semester average: " << ListOfSemesters[j]->get_average() << "\n";
					Subjects ListOfSubjects = ListOfSemesters[j]->get_list_of_subjects();
					for (int k = 0; k < ListOfSubjects.size(); k++)
					{
						outdata << ListOfSubjects[k]->get_short_name() << " - " << ListOfSubjects[k]->get_full_name() << "\n";
						outdata << "ECTs: " << ListOfSubjects[k]->get_ECT() << "\n";
						outdata << "Grades: \n" << ListOfSubjects[k]->get_practice_score() << "," << ListOfSubjects[k]->get_lab_score() << "," << ListOfSubjects[k]->get_exam_score() << "\n";
						outdata << "Final Grade: " << ListOfSubjects[k]->get_final_score() << "\n";
					}
				}
			}
		}
		if (help == 0)
		{
			ofstream database;
			database.open("database.txt", ios::out | ios::app);
			if (database.is_open())
			{
				database << object->get_name() << "\n" << object->get_surname() << "\n" << object->get_ID() << "\n";
			}
			database.close();
		}
		database_hold.push_back(object);
		outdata.close();
	}
	return database_hold;
}
void Delete_function_ID(string ID)
{
	ifstream inFile;
	string zmienna;


	inFile.open("database.txt");


	string linia;
	string ID_path;
	vector <string> database1;
	vector<string>::iterator it;

	while (getline(inFile, linia))
	{

		cout << linia << endl;
		database1.push_back(linia);
	}
	inFile.close();
	size_t rozmiar = database1.size();
	int b = 0;
	for (int i = 0; i < rozmiar - b; i++)
	{

		if (database1[i] == ID)
		{
			ID_path = database1[i] + ".txt";

			remove(ID_path.c_str());

			it = (database1.begin() + (i - 2));
			database1.erase(it + 2);
			database1.erase(it + 1);
			database1.erase(it);
			b += 3;

		}
	}

	ofstream inFile1;
	inFile1.open("database.txt");


	if (inFile1.is_open())
	{
		cout << "otwarto" << endl;
		for (int i = 0; i < database1.size(); i++)
		{
			inFile1 << database1[i] << "\n";
		}
	}

	inFile1.close();
}
void Delete_function_Name(string name,string surname)
{
	
	ifstream inFile;
	string zmienna;


	inFile.open("database.txt");


	string linia;
	string ID;
	vector <string> database1;
	vector<string>::iterator it;

	while (getline(inFile, linia))
	{

		cout << linia << endl;
		database1.push_back(linia);
	}
	inFile.close();
	size_t rozmiar = database1.size();
	int b = 0;
	for (int i = 0; i < rozmiar - b; i++)
	{

		if (database1[i] == name && database1[i + 1] == surname)
		{

			ID = database1[i + 2] + ".txt";

			remove(ID.c_str());

			it = (database1.begin() + i);
			database1.erase(it + 2);
			database1.erase(it + 1);
			database1.erase(it);
			b += 3;

		}
		
	}

	ofstream inFile1;
	inFile1.open("database.txt");


	if (inFile1.is_open())
	{
		cout << "otwarto" << endl;
		for (int i = 0; i < database1.size(); i++)
		{
			inFile1 << database1[i] << "\n";
		}
	}

	inFile1.close();
}
void Delete_menu()
{
	int choice;
	bool repeat;
	cout << "Delete menu:\n";
	cout << "(1) Find and delete student by Name+Surname\n";
	cout << "(2) Find and delete student by ID\n";
	do
	{
		repeat = false;
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			system("cls");
			string name, surname;
			cout << "Insert name: ";
			cin >> name;
			cout << "Insert surname: ";
			cin >> surname;
			Delete_function_Name(name, surname);
		}
		break;
		case 2:
		{
			system("cls");
			string ID;
			cout << "Insert ID: ";
			cin >> ID;
			Delete_function_ID(ID);

		}
		break;
		default:
		{
			cout << "Choose once again ";
			repeat = true;
		}
		break;
		}
	} while (repeat);
}

int main()
{
	
	while (true)
	{
		int choice;
		cout << "Welcome in Student Database \n";
		cout << "(1) Reading data\n";
		cout << "(2) Writing data\n";
		cout << "(3) Deleting selected\n";
		cout << "If you want to exit enter 997: ";
		cin >> choice;
		if (choice == 997)
		{
			break;
		}
		switch (choice)
		{
		case 1:
		{
			system("cls");
			Reading_data_menu();
		}
		break;
		case 2:
		{
			system("cls");
			vector<Student*> objects = Writing_data_menu();
			if (!objects.empty())
			{
				for (size_t i = 0; i < objects.size(); i++)
				{
					objects[i]->~Student();
				}
			}
		}
		break;
		case 3:
		{
			system("cls");
			Delete_menu();
		}
		break;
		default:
		{
			cout << "Choose once again!!! ";
		}
		break;
		}
	}
	
	return 0;
}

