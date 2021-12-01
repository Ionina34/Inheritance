#pragma once
#include"Human.h"
#include"Define.h"

class Student :public Human
{
	std::string speciality;
	std::string group;
	double rating;     // Успеваемость
	double attendance; //Посещаемость
public:
	const std::string& get_speciality()const;
	const std::string& get_group()const;
	double get_rating()const;
	double det_attendance()const;
	void set_speciality(const std::string& spetiality);
	void set_group(const std::string& group);
	void set_rating(double rating);
	void set_attendance(double attendance);

	//          Constractor
	Student(HUMAN_TAKE_PARAMETERS, STUDENT_TAKE_PARAMETERS);
	~Student();

	//                         Methods:
	void print()const;
};