#ifndef SUBJECT_H
#define SUBJECT_H

#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
#include <cstdlib>
#include <sstream>

#define UNASSIGNED 0

using namespace std;

class Subject
{
private:
	string short_name, full_name;
	int ECT;
	double practice_score, lab_score, final_score, exam_score;
public:
	Subject(string short_name, string full_name, int ECT, double practice_score, double lab_score, double exam_score);
	Subject();
	~Subject()
	{
		cout << "Subject object terminated\n";
	}
	string get_short_name() const;
	string get_full_name() const;
    int get_ECT() const;
	double get_practice_score() const;
	double get_lab_score() const;
	double get_exam_score() const;
	double get_final_score() const;

	void set_short_name(string short_name1);
	void set_full_name(string full_name1);
	void set_ECT(int ECT1);
	void set_practice_score(double practice_score1);
	void set_lab_score(double lab_score1);
	void set_exam_score(double exam_score1);
	void set_final_score(double final_score1);
                        /*Methods*/
	void count_final();
	void print();
};

#endif SUBJECT_H