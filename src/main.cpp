#include <list>
#include <mutex>
#include <algorithm>

#include <iostream>

using namespace std;


class SomeData
{
	int a;
	string b;
public:
	void do_something() {};
};

class DataWrapper
{
private:
	SomeData data;
	std::mutex mtx;
public:
	template<typename Function>
	void process_data(Function func)
	{
		std::lock_guard<mutex> l(mtx);
		func(data);
	}
};

SomeData* unprotected;

void* mal_function(SomeData& protected_data)
{
	unprotected = &protected_data;
}

DataWrapper x;

void foo()
{
	x.process_data(mal_function);
	unprotected->do_something();
}

int main()
{
	foo();
	return 0;
}