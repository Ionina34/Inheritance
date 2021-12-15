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
	//������� ������ �������, ������� ����������� � ���� �����:
	/*Hello();
	World();*/

	//�������� ������� � ��������� �������:
	std::thread hello_thread ( Hello);
	std::thread world_thread ( World);
	cin.get(); //������� ������� Enter
	finish = true;
	hello_thread.join();
	world_thread.join();
}