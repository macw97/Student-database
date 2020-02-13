#include "Student.h"

Student::Student(string name, string surname, string faculty, string major,  int ID) :name{ name }, surname{ surname }, faculty{ faculty }, major{major}, ID{ ID }
{
	all_average = year_average();
}
Student::Student()
{
	size_t Sems;
	cout << "Name : ";
	cin >> this->name;
	cout << "Surname : ";
	cin >> this->surname;
	cout << "Faculty : ";
	cin >> this->faculty;
	cout << "Major: ";
	cin >> this->major;
	cout << "ID : ";
	cin >> this->ID;
	cout << "Number of semesters : ";
	cin >> Sems;
	for (int i = 0; i < Sems; i++)
	{
		Semestr* object = new Semestr();
		Semestr_list.push_back(object);
	}
	all_average = year_average();
	count_final();
}

string Student::get_name() const
{
	return name;
}

string Student::get_surname() const
{
	return surname;
}

string Student::get_faculty() const
{
	return faculty;
}

string Student::get_major() const
{
	return major;
}

int Student::get_ID() const
{
	return ID;
}

double Student::get_final_average() const
{
	return final_average;
}

bool Student::get_fin_stud() const
{
	return fin_stud;
}
size_t Student::get_semester_list_size()
{
	return Semestr_list.size();
}
Semestr_storage Student::get_list()
{
	return Semestr_list;
}


void Student::set_name(string name)
{
	this->name = name;
}

void Student::set_surname(string surname)
{
	this->surname = surname;
}

void Student::set_ID(int ID)
{
	this->ID = ID;
}

void Student::set_faculty(string faculty)
{
	this->faculty = faculty;
}

void Student::set_major(string major)
{
	this->major = major;
}

void Student::set_final_average(double final_average)
{
	this->final_average = final_average;
}



void Student::set_fin_stud(bool fin_stud)
{
	this->fin_stud = fin_stud;
}



vector<double> Student::year_average()
{
	vector<double> average;
	size_t sems = Semestr_list.size();
	double sum = 0;
	int counter = 0;
	if (sems == 1)
	{
		sum = Semestr_list[0]->get_average();
		average.push_back(sum);
	}
	if ((sems >= 2) && (sems % 2 == 1))
	{
		for (int i = 0; i < sems - i; i++)
		{
			if (i % 2 == 0)
			{
				sum = Semestr_list[i]->get_average() * Semestr_list[i]->get_ect_total() + Semestr_list[i + 1]->get_average() * Semestr_list[i + 1]->get_ect_total();
				counter = Semestr_list[i]->get_ect_total() + Semestr_list[i + 1]->get_ect_total();
				average.push_back(sum / counter);
			}
		}
	}
	if ((sems >= 2) && (sems % 2 == 0))
	{
		for (int i = 0; i < sems; i++)
		{
			if (i % 2 == 0)
			{
				sum = Semestr_list[i]->get_average() * Semestr_list[i]->get_ect_total() + Semestr_list[i + 1]->get_average() * Semestr_list[i + 1]->get_ect_total();
				counter = Semestr_list[i]->get_ect_total() + Semestr_list[i + 1]->get_ect_total();
				average.push_back(sum / counter);
			}
		}
	}
	return average;

	}
	

void Student::count_final()
{
	double sum = 0;
	for (int i=0;i<Semestr_list.size();i++)
	{
		sum += Semestr_list[i]->get_average() * Semestr_list[i]->get_ect_total();
	}
	set_final_average(sum / Semestr_list.size());
}
void Student::print()
{
	cout << "Student : " << name << " " << surname << endl;
	cout << "ID : " << ID << endl;
	cout << "Average: " << final_average << endl;
	for (auto i : all_average) cout << "\t" << i << endl;
	for (auto i : Semestr_list) i->Semestr::print();
}
