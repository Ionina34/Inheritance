#include<iostream>
#include<thread>
#include<Windows.h>
using namespace std;

bool finish = false;

void Hello()
{
	while (!finish)
	{
		cout << "+ " ;
		Sleep(150);
	}
}
void World()
{
	while (!finish)
	{
		cout << "- " ;
		Sleep(150);
	}
}


void main()
{
	//Простые вызовы функций, которые выполняются в один поток:
	/*Hello();
	World();*/

	//Запустим функции в отдельных потоках:
	std::thread hello_thread ( Hello);
	std::thread world_thread ( World);
	cin.get(); //Ожидает нажатия Enter
	finish = true;
	hello_thread.join();
	world_thread.join();
}