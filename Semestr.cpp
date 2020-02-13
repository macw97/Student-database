#include "Semestr.h"
Semestr::Semestr(int nr_semestr, Subjects Subject_list) :nr_semestr(nr_semestr), Subject_list(Subject_list)
{
	cout << "Object creater\n";
	suma_ect();
	average_count();
}
Semestr::Semestr()
{
	size_t Subject_storage;
	cout << "Insert semester number: ";
	cin >> this->nr_semestr;
	cout << "\nNumber of subjects in semester: ";
	cin >> Subject_storage;
	for (int i = 0; i < Subject_storage; i++)
	{
		Subject* ob = new Subject();
		Subject_list.push_back(ob);
	}
	suma_ect();
	average_count();
}
size_t Semestr::get_subject_count()
{
	return Subject_list.size();
}
Subjects Semestr::get_list_of_subjects()
{
	return Subject_list;
}
int Semestr::get_sem() const
{
	return nr_semestr;
}
int Semestr::get_ect_total() const
{
	return ECTs_total;
}
int Semestr::get_ect_coll() const
{
	return ECTs_collected;
}
double Semestr::get_average() const
{
	return sem_average;
}
void Semestr::set_ect_total(int total)
{
	ECTs_total = total;
}
void Semestr::set_ect_coll(int coll)
{
	ECTs_collected = coll;
}
void Semestr::set_sem_average(double average)
{
	sem_average = average;
}
void Semestr::suma_ect()
{
	int suma_coll = 0, suma_total = 0;
	for (int i = 0; i < Subject_list.size(); i++)
	{
		suma_total += Subject_list[i]->get_ECT();
		if (Subject_list[i]->get_final_score()>=3)
		{
			suma_coll += Subject_list[i]->get_ECT();
		}
	}
	if ((suma_total - suma_coll) > 15)
		next_sem = false;

	set_ect_total(suma_total);
	set_ect_coll(suma_coll);
}
void Semestr::average_count()
{
	double average = 0;
	int count = 0;
	for (int i = 0; i < Subject_list.size(); i++)
	{
		average+=Subject_list[i]->get_final_score() * Subject_list[i]->get_ECT();
		count += Subject_list[i]->get_ECT();
	}
	set_sem_average(average / count);
}
void Semestr::print()
{
	cout << "Semester: " << nr_semestr << endl;
	cout << "Ects total: " << ECTs_total << endl;
	cout << "Ects collected: " << ECTs_collected << endl;
	cout << "Semester average: " << sem_average << endl;
	cout << "============================\n";
	for (int i = 0; i < Subject_list.size(); i++)
	{
		Subject_list[i]->Subject::print();
		cout << "============================\n";
	}
}