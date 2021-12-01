#include"Student.h"

const std::string& Student::get_speciality()const
{
	return speciality;
}
const std::string& Student::get_group()const
{
	return group;
}
double Student::get_rating()const
{
	return rating;
}
double Student::det_attendance()const
{
	return attendance;
}
void Student::set_speciality(const std::string& spetiality)
{
	this->speciality = speciality;
}
void Student::set_group(const std::string& group)
{
	this->group = group;
}
void Student::set_rating(double rating)
{
	this->rating = rating;
}
void Student::set_attendance(double attendance)
{
	this->attendance = attendance;
}

//          Constractor
Student::Student(HUMAN_TAKE_PARAMETERS, STUDENT_TAKE_PARAMETERS) :Human(HUMAN_GIVE_PARAMETERTS)
{
	this->speciality = speciality;
	this->group = group;
	this->rating = rating;
	this->attendance = attendance;
	cout << "SConstructor:\t" << this << endl;
}
Student::~Student()
{
	cout << "SDestructor:\t" << this << endl;
}

//                         Methods:
void Student::print()const
{
	Human::print();
	cout << speciality + " " + group << " " << rating << " " << attendance << endl;
}