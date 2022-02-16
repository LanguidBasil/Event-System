#include "EventSystem.h"

#include <vector>

namespace Events
{
	Event::Event()
		: Subscribed(std::vector<std::function<void()>>()) {}

	Event::~Event() {}

	void Event::Fire()
	{
		for (auto& func : Subscribed)
			func();
	}

	void Event::operator += (std::function<void()> func)
	{
		Subscribed.push_back(func);
	}

	void Event::operator -= (std::function<void()> func)
	{
		//for (auto& f : Subscribed)
		//{
		//	if (f == func)
		//		Subscribed.erase(f);
		//}
	}
}