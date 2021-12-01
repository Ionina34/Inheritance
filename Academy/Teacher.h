#pragma once
#include"Define.h"
#include"Human.h"

class Teacher :public Human
{
	std::string spetiality;
	unsigned int experience;
public:
	const std::string& get_speciality()const;
	unsigned int get_experience()const;
	void set_speciality(const std::string& spetiality);
	void set_experience(unsigned int experience);

	//          Constructors:
	Teacher(HUMAN_TAKE_PARAMETERS, TEACHER_TAKE_PARAMETERS);
	~Teacher();

	//                          Methods:
	void print()const;
};
