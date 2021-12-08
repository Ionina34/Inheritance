#include<iostream>
using namespace std;

class Weapon
{
	int damage; //Наносимый урон
	int size;
public:
	Weapon(int damage, int size) :damage(damage), size(size)
	{
	}
	virtual ~Weapon()
	{
	}
	virtual void apply() = 0; //Чисто виртуальный метод (Чисто виртуальная функция)
	//Как раз этот чисто виртуальный метод как раз делает класс абстрактным

	virtual void info()
	{
		cout << "Damage:\t" << damage << endl;
		cout << "Size:\t" << size << endl;
	}
};

class ColdArms :public Weapon
{
public:
	ColdArms(int damage, int size) :Weapon(damage, size) {}
	~ColdArms() {}
	//Этот класс НЕ определяет чисто виртуальный метод apply, 
	//а просто наследует его чистую виртуальность, и следовательно 
	//этот класс так же является абстрактным.
};

class Knife :public ColdArms
{
public:
	Knife(int damage, int size) :ColdArms(damage, size) {}
	~Knife() {}
	//Этот класс уже является конкретным, 
	//поскольку он реализует чисто виртуальную функцую apply
	void apply()
	{
		cout << "Чистить картошку, резать яблоки" << endl;
	}
	void info()
	{
		Weapon::info();
		apply();
	}
};

class Machete :public ColdArms
{
public:
	Machete(int damage, int size) :ColdArms(damage, size) {}
	~Machete() {}
	void apply()
	{
		cout << "Олично рубит тросник, так же очень удобен для стрижки деревьев" << endl;
	}
	void info()
	{
		Weapon::info();
		apply();
	}
};

void main()
{
	setlocale(LC_ALL, "Rus");
	//Weapon w(20, 5); w.info();  //Создать экземпляр этого класса нельзя, 
	                              //поскольку тоже является абстрактным

	//ColdArms ca(20, 5);   //Создать экземпляр этого класса нельзя, 
	                        //поскольку тоже является абстрактным

	Knife kn(20, 5); kn.info();
	Machete m(50, 25); m.info();
}