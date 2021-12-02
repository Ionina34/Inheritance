#include<iostream>
#include<string>
#include<ctime>
using std::cin;
using std::cout;
using std::endl;

#define HUMAN_TAKE_PARAMETERS const std::string& last_name, const std::string& first_name, unsigned int age
#define HUMAN_GIVE_PARAMETERTS last_name, first_name, age

class Human
{
	std::string last_name;
	std::string first_name;
	unsigned int age;
public:
	const std::string& get_last_name()const
	{
		return last_name;
	}
	const std::string& get_first_name()const
	{
		return first_name;
	}
	unsigned int get_age()const
	{
		return age;
	}
	void set_last_name(const std::string& last_name)
	{
		this->last_name = last_name;
	}
	void set_first_name(const std::string& first_name)
	{
		this->first_name = first_name;
	}
	void set_age(unsigned int  age)
	{
		this->age = age;
	}

	//                       Constructors:
	Human(const std::string& last_name, const std::string& first_name, unsigned int age)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);
		cout << "HConstructoe:\t" << this << endl;
	}
	virtual ~Human()
	{
		cout << "HDestructor:\t" << this << endl;
	}

	//                Methods
	virtual void print()const
	{
		cout << last_name << " " << first_name << " " << age << endl;
	}
};

#define STUDENT_TAKE_PARAMETERS const std::string& speciality, const std::string& group, double rating, double attendance
#define STUDENT_GIVE_PARAMETERS speciality, group, rating, attendance

class Student :public Human
{
	std::string speciality;
	std::string group;
	double rating;     // Успеваемость
	double attendance; //Посещаемость
public:
	const std::string& get_speciality()const
	{
		return speciality;
	}
	const std::string& get_group()const
	{
		return group;
	}
	double get_rating()const
	{
		return rating;
	}
	double det_attendance()const
	{
		return attendance;
	}
	void set_speciality(const std::string& spetiality)
	{
		this->speciality = speciality;
	}
	void set_group(const std::string& group)
	{
		this->group = group;
	}
	void set_rating(double rating)
	{
		this->rating = rating;
	}
	void set_attendance(double attendance)
	{
		this->attendance = attendance;
	}

	//          Constractor
	Student(HUMAN_TAKE_PARAMETERS, STUDENT_TAKE_PARAMETERS) :Human(HUMAN_GIVE_PARAMETERTS)
	{
		this->speciality = speciality;
		this->group = group;
		this->rating = rating;
		this->attendance = attendance;
		cout << "SConstructor:\t" << this << endl;
	}
	~Student()
	{
		cout << "SDestructor:\t" << this << endl;
	}

	//                         Methods:
	void print()const
	{
		Human::print();
		cout << speciality + " " + group << " " << rating << " " << attendance << endl;
	}
};

#define TEACHER_TAKE_PARAMETERS const std::string& spetiality, unsigned int experience
#define	TEACHER_GIVE_PARAMETERS spetiality, experience

class Teacher :public Human
{
	std::string spetiality;
	unsigned int experience;
public:
	const std::string& get_speciality()const
	{
		return spetiality;
	}
	unsigned int get_experience()const
	{
		return experience;
	}
	void set_speciality(const std::string& spetiality)
	{
		this->spetiality = spetiality;
	}
	void set_experience(unsigned int experience)
	{
		this->experience = experience;
	}

	//          Constructors:
	Teacher(HUMAN_TAKE_PARAMETERS, TEACHER_TAKE_PARAMETERS) :Human(HUMAN_GIVE_PARAMETERTS)
	{
		set_speciality(spetiality);
		set_experience(experience);
		cout << "TConstrructor:\t" << this << endl;
	}
	~Teacher()
	{
		cout << "TDectructor:\t" << this << endl;
	}

	//                          Methods:
	void print()const
	{
		Human::print();
		cout << spetiality << " " << experience << endl;
	}
};

class Graduate :public Student
{
	std::string subject;     //Тема дипломного проекта
public:
	const std::string& get_subject()const
	{
		return subject;
	}
	void set_subject(const std::string& subject)
	{
		this->subject = subject;
	}

	//                       Constructors:
	Graduate(HUMAN_TAKE_PARAMETERS, STUDENT_TAKE_PARAMETERS, const std::string& subject) :Student(HUMAN_GIVE_PARAMETERTS, STUDENT_GIVE_PARAMETERS)
	{
		set_subject(subject);
		cout << "GConstructor:\t" << this << endl;
	}
	~Graduate()
	{
		cout << "GDectructor:\t" << this << endl;
	}

	//                          Methods:
	void print()const
	{
		Student::print();
		cout << subject << endl;
	}
};

//#define INHERITANCE_CHECK

void main()
{
	setlocale(LC_ALL, "Rus");

#ifdef INHERITANCE_CHECK
	Human hm("Тупенко", "Василий", 18);
	hm.print();
	Student st("Pinkman", "Jessie", 28, "Chemistry", "ww_01", 90, 85);
	st.print();
	Teacher t("White", "Walter", 50, "Chemistry", 20);
	t.print();
	Graduate gr("Shrader", "Hunk", 40, "Criminalistic", "OBN", 90, 90, "How to catch Heisehberg");
	gr.print();
#endif // INHERITANCE_CHECK

	//Generalisation (обобщение)
	Human* group[] =
	{
		new Student("Piknman","Jessie",25,"Chemistry","WW_011",90,80),
		new Student("Vecetti", "Tomas",30,"City business","Vice",88,90),
		new Teacher("White","Walter",50,"Chemistry",20),
		new Student("Diaz","Ricardo",55,"Weapons distribution", "Vice",91,80),
		new Graduate("Shrader","Hank",40,"Criminalistics","OBN",86,90,"How to catch Heisenderg"),
		new Teacher("Enisten","Albert",142,"Astronomy",110)
	};

	cout << sizeof(group)/sizeof(group[0]) << endl;
	cout << sizeof(Human*) << endl;
	cout << "\n---------------------------------------\n";
	//Specialisation
	for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
	{
		group[i]->print();
		cout << "\n---------------------------------------\n";
	}

	for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
	{
		delete group[i];
	}

}