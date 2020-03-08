#include <iostream>
#include <set>
#include <vector>
#include <chrono>
#include <random>
#include <iterator>
#include <array>


class Timer
{
	using clock_t = std::chrono::steady_clock;
	using timepoint_t = clock_t::time_point;

private:
	timepoint_t begin;

public:
	Timer() : begin(clock_t::now())
	{}

	~Timer() noexcept
	{}

	void stop()
	{
		auto end = clock_t::now();
		std::cout << "lead time: " << std::chrono::duration_cast <std::chrono::milliseconds>(end - begin).count() << std::endl;
	}
};




int main()
{
	std::mt19937 gen;
	gen.seed(time(0));

	std::set<int> mySet;

	Timer myTimer_1;
	for (int i = 0; i < 200000; i++)
	{
		mySet.insert(gen());
	}
	myTimer_1.stop();


	Timer myTimer_2;
	std::vector<int> myVector;
	for (int i = 0; i < 200000; i++)
	{
		myVector.push_back(gen());
	}
	std::sort(myVector.begin(), myVector.end());
	myTimer_2.stop();


	Timer myTimer_3;
	std::array<int, 200000> myArray;
	for (int i = 0; i < 200000; i++)
	{
		myArray[i] = gen();
	}
	std::sort(myArray.begin(), myArray.end());
	myTimer_3.stop();


	/*std::cout << "mySet" << std::endl;
	for (auto& item : mySet)
	{
		std::cout << item << std::endl;
	}

	std::cout << "Vector" << std::endl;
	for (int i = 0; i < 10; i++)
	{
		std::cout << myVector[i] << std::endl;
	}*/

	return 0;
}