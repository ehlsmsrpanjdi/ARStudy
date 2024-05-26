#include "PreCompile.h"
#include "KSWList.h"

//int main()
//{
//	LeakCheck;
//
//	ksw::list<int> li;
//	ksw::list<int> li2(1, 1);
//	ksw::list<int>::iterator it;
//
//	std::cout << std::endl;
//	for (it = li2.begin(); it != li2.end(); ++it)
//	{
//		std::cout << (*it) << " ";
//	}
//
//	li.push_back(2);
//	li.push_back(3);
//	li.push_back(4);
//	li.push_back(5);
//	li.push_front(1);
//
//	it = li.begin();
//	++it;
//	++it;
//	++it;
//	++it;
//	it = li.erase(it);
//
//	std::cout << std::endl;
//	for (it = li.begin(); it != li.end(); ++it)
//	{
//		std::cout << (*it) << " ";
//	}
//
//	li.pop_front();
//	li.pop_back();
//
//	std::cout << std::endl;
//	for (it = li.begin(); it != li.end(); ++it)
//	{
//		std::cout << (*it) << " ";
//	}
//
//	li.clear();
//	std::cout << std::endl;
//	for (it = li.begin(); it != li.end(); ++it)
//	{
//		std::cout << (*it) << " ";
//	}
//
//}