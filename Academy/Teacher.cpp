#include"Teacher.h"

const std::string& Teacher::get_speciality()const
{
	return spetiality;
}
unsigned int Teacher::get_experience()const
{
	return experience;
}
void Teacher::set_speciality(const std::string& spetiality)
{
	this->spetiality = spetiality;
}
void Teacher::set_experience(unsigned int experience)
{
	this->experience = experience;
}

//          Constructors:
Teacher::Teacher(HUMAN_TAKE_PARAMETERS, TEACHER_TAKE_PARAMETERS) :Human(HUMAN_GIVE_PARAMETERTS)
{
	set_speciality(spetiality);
	set_experience(experience);
	cout << "TConstrructor:\t" << this << endl;
}
Teacher::~Teacher()
{
	cout << "TDectructor:\t" << this << endl;
}

//                          Methods:
void Teacher::print()const
{
	Human::print();
	cout << spetiality << " " << experience << endl;
}