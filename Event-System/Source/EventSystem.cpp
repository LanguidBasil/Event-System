#include "EventSystem.h"

#include <vector>

namespace EventSystem
{
	Event::Event()
		: Subscribed(std::vector<std::function<void()>>()) {}

	Event::~Event() {}

	void Event::Fire()
	{
		for (auto& func : Subscribed)
			func();
	}

	void Event::Add(std::function<void()> func)
	{
		Subscribed.push_back(func);
	}

	void Event::Remove(std::function<void()> func)
	{
		for (auto it = Subscribed.begin(); it != Subscribed.end(); it++)
		{
			const auto& current = it->target<void()>();
			const auto& target = func.target<void()>();

			if (current == target)
			{
				Subscribed.erase(it);
				return;
			}
		}
	}

	void Event::RemoveAll()
	{
		Subscribed.clear();
	}

	void Event::operator += (std::function<void()> func)
	{
		Add(func);
	}

	void Event::operator -= (std::function<void()> func)
	{
		Remove(func);
	}
}