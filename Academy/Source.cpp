#include"Define.h"
#include"Human.h"
#include"Student.h"
#include"Teacher.h"
#include"Graduate.h"

void main()
{
	setlocale(LC_ALL, "Rus");
	Human hm("Тупенко", "Василий", 18);
	hm.print();
	Student st("Pinkman", "Jessie", 28, "Chemistry", "ww_01", 90, 85);
	st.print();
	Teacher t("White", "Walter", 50, "Chemistry", 20);
	t.print();
	Graduate gr("Shrader", "Hunk", 40, "Criminalistic", "OBN", 90, 90, "How to catch Heisehberg");
	gr.print();
}