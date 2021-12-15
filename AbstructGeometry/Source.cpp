#define _USE_MATH_DEFINES
#include<iostream>
#include<Windows.h>
#include<conio.h>
#include<cmath>
using namespace std;

namespace Geometry
{
//#define DRAW*
	enum Color
	{
		red = 0x000000FF,
		green = 0x0000FF00,
		blue = 0x00FF0000,
		yellow = 0x0000FFFF,
		white = 0xFFFFFF,

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
#ifdef DRAW*
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
#endif // DRAW*
			HWND hwnd =  GetConsoleWindow();
			HDC hdc = GetDC(hwnd);
			HPEN hPen = CreatePen(PS_SOLID, 5, color);
			HBRUSH hBrush = CreateSolidBrush(color);

			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);
		
			int start_x = 400;
			int start_y = 200;
			const POINT verticies[] =
			{
				{start_x,start_y},
				{start_x,start_y+side},
				{start_x+side,start_y+side},
				{start_x+side,start_y}
			};

			Polygon(hdc, verticies, sizeof(verticies) / sizeof(POINT));

			DeleteObject(hPen);
			DeleteObject(hBrush);
			ReleaseDC(hwnd,hdc );
		}

		void info()
		{
			cout << typeid(*this).name() << endl;
			cout << "Длина стороны:\t" << side << endl;
			cout << "Площадь:\t" << get_area() << endl;
			cout << "Периметр:\t" << get_perimeter() << endl;
			char key;
			do
			{
				draw();
				if (key = _kbhit())key = _getch();
			} while (key != 27);
			system("CLS");
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
#ifdef DRAW*
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
#endif // DRAW*

			HWND hwnd = GetConsoleWindow();
				HDC hdc = GetDC(hwnd);
				HPEN hPen = CreatePen(PS_SOLID, 5, color);
				HBRUSH hBrush = CreateSolidBrush(color);

				SelectObject(hdc, hPen);
				SelectObject(hdc, hBrush);

				int start_x = 400;
				int start_y = 200;
				const POINT verticies[] =
				{
					{start_x,start_y},
					{start_x,start_y+side_A},
					{start_x+side_B,start_y+side_A},
					{start_x+side_B,start_y}
				};
				Polygon(hdc, verticies, sizeof(verticies) / sizeof(POINT));

				DeleteObject(hPen);
				DeleteObject(hBrush);
				ReleaseDC(hwnd, hdc);
		}
		void info()
		{
			cout << typeid(*this).name() << endl;
			cout << "Длина стороны A:\t" << side_A << endl;
			cout << "Длина стороны B:\t" << side_B << endl;
			cout << "Площадь:\t" << get_area() << endl;
			cout << "Периметр:\t" << get_perimeter() << endl;
			char key;
			do
			{
				draw();
				if (key = _kbhit())key = _getch();
			} while (key != 27);
			system("CLS");
		}
	};

	class Circle : public Shape
	{
		double radius;
	public:
		Circle(double radius, Color color = Color::white) :Shape(color)
		{
			set_radius(radius);
		}
		~Circle() {};
		void set_radius(double radius)
		{
			if (radius <= 0)radius = 1;
			this->radius = radius;
		}
		double get_radius()const
		{
			return radius;
		}

		double get_area()const
		{
			return pow(radius, 2) * M_PI;
		}
		double get_perimeter()const
		{
			return 2 * radius * M_PI;
		}
		void draw() const
		{
			//cout << "Представть что здесь круг (_ _ *)..Zzz" << endl;

			//GDI -Graphics Interface (WinAPI)
			HWND hwnd = GetConsoleWindow();//Получаем окно консоли
			//HWND hwnd = FindWindow(NULL, /*L"Inheritance - Microsoft Visual Studio"*/ L"Desktop");
			HDC hdc = GetDC(hwnd); //Создаем контекст. На это контексте мы будем рисовать

			HPEN hPen = CreatePen(PS_SOLID, 5, color);//Создаем карандаш
			//PS_SOLID - сплошная линия
			//5 - толщина линии в пикселях
			//RGB(...) - цвет
			HBRUSH hbrush = CreateSolidBrush(color);

			SelectObject(hdc, hPen);//Выбираем чем и на чем будем рисовать
			SelectObject(hdc, hbrush);


			int start_x = 300;
			int start_y = 270;
			int end_x = 400;
			int end_y = 370;
			//Ellipse(hdc, start_x, start_y, end_x, end_y);
			Ellipse(hdc, start_x, start_y, start_x + 2 * radius, start_y + 2 * radius);

			DeleteObject(hPen);
			DeleteObject(hbrush);
			ReleaseDC(hwnd, hdc);
		}
		void info()
		{
			cout << typeid(*this).name() << endl;
			cout << "Радиус круга:\t" << get_radius() << endl;
			cout << "Площадь круга:\t" << get_area() << endl;
			cout << "Периметр круга:\t" << get_perimeter() << endl;
			char key;
			do
			{
				draw();
				//if (_kbhit())break;//_kbhit() ожидает нажатия клавиш 
				//и возвращает нулевое значение при ее нажатии
				if (key = _kbhit())key = _getch();
			} while (key != 27);
			system("CLS");
		}

	};

	class Triangle :public Shape
	{
	public:
		Triangle(Color color = Color::white) :Shape(color) {};
		~Triangle() {};
		virtual double get_height()const = 0;
	};

	class EquilateralTriangle :public Triangle
	{
		double side;
	public:
		EquilateralTriangle(double side, Color color = Color::white) :Triangle(color)
		{
			set_side(side);
		}
		~EquilateralTriangle() {};
		void set_side(double side)
		{
			if (side <= 0)side = 1;
			this->side = side;
		}
		double get_side()const
		{
			return side;
		}
		double get_height()const
		{
			return sqrt(side * side - pow(side / 2, 2));
		}
		double get_area()const
		{
			return (side * get_height()) / 2;
		}
		double get_perimeter()const
		{
			return 3 * side;
		}
		void draw()const
		{
			HWND hwnd = GetConsoleWindow();
			HDC hdc = GetDC(hwnd);
			HPEN hPen = CreatePen(PS_SOLID, 5, color);
			HBRUSH hBrush = CreateSolidBrush(color);
			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);

			int start_x = 400;
			int start_y = 200;
			const POINT verticies[] =
			{
				{start_x, start_y + side},
				{start_x + side , start_y + side},
				{start_x+side / 2,start_y + side - get_height()}
			};

			Polygon(hdc, verticies, sizeof(verticies) / sizeof(POINT));

			DeleteObject(hBrush);
			DeleteObject(hPen);
			ReleaseDC(hwnd, hdc);
		}
		void info() const
		{
			cout << typeid(*this).name() << endl;
			cout << "Длина стороны:\t" << get_side() << endl;
			cout << "Высота треуголька:\t" << get_height() << endl;
			cout << "Площадь треугольника:\t" << get_area() << endl;
			cout << "Периметр треугольника:\t" << get_perimeter() << endl;
			char key;
			do
			{
				draw();
				if (key = _kbhit())key = _getch();
			} while (key != 27);
			system("CLS");
		}
	};

	class IsoscelesTriangle : public Triangle
	{
		double side_S;
		double side_G;
	public:
		IsoscelesTriangle(double side_S, double side_G, Color color = Color::white) :Triangle(color)
		{
			set_side_G(side_G);
			set_side_S(side_S);
		}
		~IsoscelesTriangle() {}
		void set_side_S(double side_S)
		{
			if (side_S <= 0)side_S = 1;
			this->side_S = side_S;
		}
		void set_side_G(double side_G)
		{
			if (side_G <= 0)side_G = 1;
			this->side_G = side_G;
		}
		double get_side_S()const
		{
			return side_S;
		}
		double get_side_G()const
		{
			return side_G;
		}
		double get_height()const
		{
			return sqrt(side_S * side_S - pow(side_G / 2, 2));
		}
		double get_area()const
		{
			return (side_G * get_height()) / 2;
		}
		double get_perimeter()const
		{
			return side_S * 2 + side_G;
		}
		void draw()const
		{
			HWND hwnd = GetConsoleWindow();
			HDC hdc = GetDC(hwnd);
			HPEN hPen = CreatePen(PS_SOLID, 5, color);
			HBRUSH hBrush = CreateSolidBrush(color);
			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);

			int start_x = 400;
			int start_y = 200;
			const POINT verticies[] =
			{
				{start_x,start_y+side_S},
				{start_x+side_G,start_y+side_S},
				{start_x+side_G/2,start_y+side_S-get_height()}
			};

			Polygon(hdc, verticies, sizeof(verticies) / sizeof(POINT));

			DeleteObject(hBrush);
			DeleteObject(hPen);
			ReleaseDC(hwnd,hdc);
		}
		void info() const
		{
			cout << typeid(*this).name() << endl;
			cout << "Длина сторон:\t" << get_side_S() << endl;
			cout << "Длина основания:\t" << get_side_G() << endl;
			cout << "Высота треуголька:\t" << get_height() << endl;
			cout << "Площадь треугольника:\t" << get_area() << endl;
			cout << "Периметр треугольника:\t" << get_perimeter() << endl;
			char key;
			do
			{
				draw();
				if (key = _kbhit())key = _getch();
			} while (key != 27);
			//system("CLS");
		}
	};
}


void main()
{
	setlocale(LC_ALL, "Rus");


	//Shape shape(Color::console_blue);
	Geometry::Square square(200, Geometry::Color::yellow); square.info();

	Geometry::Rectangle rect(200, 300, Geometry::Color::conslole_yellow); rect.info();

	Geometry::Circle kr(200, Geometry::Color::yellow); kr.info();

	/*const double PI = acos(-1.0);
	cout << PI << endl;*/

	Geometry::EquilateralTriangle tr(200, Geometry::Color::green); tr.info();

	Geometry::IsoscelesTriangle tre(200,250, Geometry::Color::red); tre.info();

	}