#ifndef SEMESTER_H
#define SEMESTER_H
#include "Subject.h"
typedef vector<Subject*> Subjects;
class Semestr
{
private:
	int nr_semestr;
	int ECTs_total;
	int ECTs_collected;
	double sem_average;
	Subjects Subject_list;
	bool next_sem = true;
public:
	Semestr(int nr_semestr, Subjects Subject_list);
	Semestr();
	~Semestr()
	{
		cout << "Semestr destructor activated \n";
		for (size_t i = 0; i < Subject_list.size(); i++)
		{
			delete Subject_list[i];
		}
	}
	size_t get_subject_count();
	Subjects get_list_of_subjects();
	int get_sem() const;
	int get_ect_total() const;
	int get_ect_coll() const;
	double get_average() const;
	void set_ect_total(int total);
	void set_ect_coll(int coll);
	void set_sem_average(double average);
	// Methods
    void suma_ect();
	void average_count();
	void print();
};
#endif SEMESTER_H
