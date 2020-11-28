#pragma once
#include <mutex>

template <typename T>
class singleton
{
private :
	inline static T* p;
	inline static std::mutex m;
public:
	singleton() {};
	~singleton() {};
	static T* GetInstance()
	{
		std::lock_guard lock(m);
		if (!p)
			p = new T;
		return p;
	}
	static void ReleaseIntacne()
	{
		std::lock_guard lock(m);
		if (p)
			delete p;
		p = nullptr;
	}
};
