#pragma once

#include <vector>
#include <functional>

namespace EventSystem
{
	class Event
	{
	public:
		explicit Event();
		explicit Event(const Event&) = delete;
		~Event();

		void Fire();
		void Add(std::function<void()>);
		void Remove(std::function<void()>);
		void RemoveAll();
		void operator += (std::function<void()>);
		void operator -= (std::function<void()>);

	private:
		std::vector<std::function<void()>> Subscribed;
	};
}