﻿#include<iostream>
#include<Windows.h>
#include<cmath>
using namespace std;

namespace Geometry
{
	enum Color
	{
		console_default = 0x07,
		console_blue = 0x99,
		console_green = 0xAA,
		console_purpul = 0x55,
		conslole_yellow = 0xEE,
		conslode_white = 0xFF
	};
	//enum (Enumeration или перечисление) - это набор именованных констант типа 'int'

	class Shape
	{
	protected:
		Color color;
	public:
		Shape(Color color) :color(color) {}
		virtual ~Shape() {}

		virtual double get_area()const = 0;      //Площадь фигуры
		virtual double get_perimeter()const = 0; // Периметер фигуры
		virtual void draw()const = 0;            //Любую фигуру можно нарисовать
	};

	class Square :public Shape
	{
		double side;
	public:
		double get_side()const
		{
			return side;
		}
		void set_side(double side)
		{
			if (side <= 0) side = 1;
			this->side = side;
		}
		Square(double side, Color color) :Shape(color)
		{
			set_side(side);
		}
		~Square() {};

		double get_area()const
		{
			return side * side;
		}
		double get_perimeter()const
		{
			return side * 4;
		}

		void draw()const
		{
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, color);
			for (int i = 0; i < side; i++)
			{
				for (int i = 0; i < side; i++)
				{
					cout << "* ";
				}
				cout << endl;
			}
			SetConsoleTextAttribute(hConsole, Color::console_default);
		}

		void info()
		{
			cout << typeid(*this).name() << endl;
			cout << "Длина стороны:\t" << side << endl;
			cout << "Площадь:\t" << get_area() << endl;
			cout << "Периметр:\t" << get_perimeter() << endl;
			draw();
		}
	};

	class Rectangle :public Shape
	{
		double side_A;
		double side_B;
	public:
		double get_side_A()const
		{
			return side_A;
		}
		double get_side_B()const
		{
			return side_B;
		}
		void set_side_A(double side_A)
		{
			if (side_A <= 0)side_A = 1;
			this->side_A = side_A;
		}
		void set_side_B(double side_B)
		{
			if (side_B <= 0)side_B = 1;
			this->side_B = side_B;
		}
		Rectangle(double side_A, double side_B, Color color) :Shape(color)
		{
			set_side_A(side_A);
			set_side_B(side_B);
		}
		~Rectangle() {};

		double get_area()const
		{
			return side_A * side_B;
		}
		double get_perimeter()const
		{
			return (side_A + side_B) * 2;
		}
		void draw()const
		{
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			for (int i = 0; i < side_A; i++)
			{
				SetConsoleTextAttribute(hConsole, color);
				for (int j = 0; j < side_B; j++)
				{
					cout << "* ";
				}
				SetConsoleTextAttribute(hConsole, Color::console_default);
				cout << endl;
			}
		}
		void info()
		{
			cout << typeid(*this).name() << endl;
			cout << "Длина стороны A:\t" << side_A << endl;
			cout << "Длина стороны B:\t" << side_B << endl;
			cout << "Площадь:\t" << get_area() << endl;
			cout << "Периметр:\t" << get_perimeter() << endl;
			draw();
		}
	};

	class Circle : public Shape
	{
		double radius;
		//double diamiter = radius+radius;
	public:
		double get_radius()const
		{
			return radius;
		}
		/*double get_diamiter()const
		{
			return diamiter;
		}*/

		void set_radius(double radius)
		{
			if (radius <= 0)radius = 1;
			this->radius = radius;
		}
		Circle(double radius, Color color) :Shape(color)
		{
			set_radius(radius);
		}
		~Circle() {};

		double get_area()const
		{
			return pow(radius, 2);
		}
		double get_perimeter()const
		{
			return 2 * radius;
		}
		void draw() const
		{
			cout << "Представть что здесь круг (_ _ *)..Zzz" << endl;
		}
		void info()
		{
			cout << typeid(*this).name() << endl;
			cout << "Длина радиуса:\t" << radius << endl;
			cout << "Длина диаметра:\t" << 2 * radius << endl;
			//cout << "Длина диаметра:\t" << diamiter << endl;
			cout << "Площадь:\t" << get_area() << "п" << endl;
			cout << "Периметр:\t" << get_perimeter() << "п" << endl;
			draw();
		}

	};

}

void main()
{
	setlocale(LC_ALL, "Rus");

	//Shape shape(Color::console_blue);
	Geometry::Square square(8, Geometry::Color::console_purpul); square.info();

	Geometry::Rectangle rect(5, 12, Geometry::Color::conslole_yellow); rect.info();

	Geometry::Circle kr(5, Geometry::Color::console_blue); kr.info();

	/*const double PI = acos(-1.0);
	cout << PI << endl;*/

}