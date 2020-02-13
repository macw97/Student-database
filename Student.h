#pragma once
#include <string>
#include "Semestr.h"

typedef vector<Semestr*> Semestr_storage;

class Student
{
private:
	string name, surname, faculty ,major;
	int ID;
	double final_average;
	size_t sem_num;
	bool fin_stud;

	Semestr_storage Semestr_list;
	vector<double> all_average;

public:
	Student(string name, string surname, string faculty, string major, int ID);
	Student();
	~Student()
	{
		cout << "Student Destructor activated\n";
		for (size_t i = 0; i < Semestr_list.size(); i++)
		{
			
			delete Semestr_list[i];
			
		}
	}
	string get_name() const;
	string get_surname() const;
	string get_faculty() const;
	string get_major() const;
	int get_ID() const;
	double get_final_average() const;
	bool get_fin_stud() const;
	size_t get_semester_list_size();
	Semestr_storage get_list();

	void set_name(string name);
	void set_surname(string surname);
	void set_ID(int ID);
	void set_faculty(string faculty);
	void set_major(string major);
	void set_final_average(double final_average);
    void set_fin_stud(bool fin_stud);

	vector<double> year_average();
	void count_final();
	void print();

};

