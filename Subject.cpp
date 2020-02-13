#include "Subject.h"



Subject::Subject(string short_name, string full_name, int ECT, double practice_score, double lab_score, double exam_score):short_name{ short_name }, full_name{ full_name }, ECT{ ECT }, practice_score{ practice_score }, lab_score{ lab_score }, exam_score{exam_score}
{
	count_final();
}
Subject::Subject()
{
	string input;
	vector<string> temp;
	cout << "Insert Subject Student info (ex. short name-full-ects) : ";
	cin.ignore();
	getline(cin, input);
	stringstream ss(input);
	string indv;
	while (getline(ss,indv,'-'))
	{
		temp.push_back(indv);
	}
	for (auto v : temp) cout << v << endl;
	this->short_name = temp[0];
	this->full_name = temp[1];
	this->ECT = stoi(temp[2]);
	input = "";
	cout << "Insert Student grades (ex. practice - lab - exam) : ";
	getline(cin, input);
	vector<double> grades;
	stringstream ss1(input);
	while (getline(ss1, indv, '-'))
	{
		double holder = atof(indv.c_str());
		grades.push_back(holder);
	}
	for (auto v : grades) cout << v << endl;
	this->practice_score = grades[0];
	this->lab_score = grades[1];
	this->exam_score = grades[2];
	count_final();
}

string Subject::get_short_name() const
{
	return short_name;
}

string Subject::get_full_name() const
{
	return full_name;
}

int Subject::get_ECT() const
{
	return ECT;
}

double Subject::get_practice_score() const
{
	return practice_score;
}

double Subject::get_lab_score() const
{
	return lab_score;
}

double Subject::get_exam_score() const
{
	return exam_score;
}

double Subject::get_final_score() const
{
	return final_score;
}

void Subject::set_short_name(string short_name1)
{
	short_name = short_name1;
}

void Subject::set_full_name(string full_name1)
{
	full_name = full_name1;
}

void Subject::set_ECT(int ECT1)
{
	ECT = ECT1;
}

void Subject::set_practice_score(double practice_score1)
{
	practice_score = practice_score1;
}

void Subject::set_lab_score(double lab_score1)
{
	lab_score = lab_score1;
}

void Subject::set_exam_score(double exam_score1)
{
	exam_score = exam_score1;
}

void Subject::set_final_score(double final_score1)
{
	final_score = final_score1;
}

void Subject::count_final()
{
		double sum = 0;                            
		int check = 0;
		vector<double> finaly;
		finaly.resize(3);
		finaly[0] = get_practice_score();
		finaly[1] = get_lab_score();
		finaly[2] = get_exam_score();
		for (int i = 0; i < finaly.size(); i++)
		{
			sum += finaly[i];
			if (finaly[i] == UNASSIGNED)
			{
				check++;
			}
		}
		double xd;                                              // przybli¿anie do po³ówek i ca³oœæi 
		xd = sum / (3 - check);
		int xd1 = int(xd);
		double xd2 = xd - xd1;
		if (xd2 < 0.25)
			set_final_score(xd1);
		if (xd2 >= 0.25 && xd2 <= 0.75)
			set_final_score(xd1 + 0.5);
		if (xd2 > 0.75)
			set_final_score(xd1 + 1);
		

}

void Subject::print()
{
	cout << "Short name of subject: " << short_name << endl;
	cout << "Full name of subject: " << full_name << endl;
	cout << "Number of ECT's: " << ECT << endl;
	cout << "Exercise grade: " << practice_score << endl;
	cout << "Laboratory grade: " << lab_score << endl;
	cout << "Exam grade: " << exam_score << endl;
	cout << "Final grade: " << final_score << endl;
}



