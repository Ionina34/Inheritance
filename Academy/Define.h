#pragma once

#include<iostream>
#include<string>
#include<ctime>
using std::cin;
using std::cout;
using std::endl;

#define HUMAN_TAKE_PARAMETERS const std::string& last_name, const std::string& first_name, unsigned int age
#define HUMAN_GIVE_PARAMETERTS last_name, first_name, age

#define STUDENT_TAKE_PARAMETERS const std::string& speciality, const std::string& group, double rating, double attendance
#define STUDENT_GIVE_PARAMETERS speciality, group, rating, attendance

#define TEACHER_TAKE_PARAMETERS const std::string& spetiality, unsigned int experience
#define	TEACHER_GIVE_PARAMETERS spetiality, experience
