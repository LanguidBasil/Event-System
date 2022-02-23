#include <iostream>
#include <vector>

#include "EventSystem.h"

class CallableClass
{
public:
	void operator ()()
	{
		std::cout << "I'm imposter func" << std::endl;
	}
};

void PrintImAFunc()
{
	std::cout << "No! I'm a very cool func!" << std::endl;
}

void PrintBye()
{
	std::cout << "Bye!" << std::endl;
}

void PrintHelloWorld()
{
	std::cout << "Hello World!" << std::endl;
}

int main()
{
	std::cout << "We're going to fire some events!" << std::endl;

	EventSystem::Event e;
	CallableClass callableClass;

	e += PrintHelloWorld;
	e += PrintBye;
	e += PrintImAFunc;
	e += callableClass;

	e.Fire();

	e -= PrintHelloWorld;

	std::cout << std::endl;
	e.Fire();

	std::cin.get();
}