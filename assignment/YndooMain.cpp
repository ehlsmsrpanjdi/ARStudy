//#include "PreCompile.h"
//#include <iostream>
//#include <list>
//#include "YndooList.h"
//
//int main() {
//	_CrtSetDbgFlag(_CRTDBG_LEAK_CHECK_DF | _CRTDBG_ALLOC_MEM_DF);
//	{
//		std::list<int> StlList;
//		StlList.push_front(1);
//		StlList.push_front(2);
//		StlList.push_back(-1);
//		StlList.push_front(0);
//
//		StlList.insert(++StlList.begin(), 300);
//		StlList.insert(StlList.end(), 300);
//		StlList.remove(300);
//		//StlList.erase(++StlList.begin());
//
//		{
//			std::cout << "front() : " << StlList.front() << std::endl;
//		}
//
//		std::cout << "=== Std::List ===" << std::endl;
//		for (std::list<int>::iterator iter = StlList.begin(); iter != StlList.end(); ++iter)
//		{
//			std::cout << *iter << std::endl;
//		}
//
//		std::cout << "=== Std::List (reverse) ===" << std::endl;
//		for (std::list<int>::reverse_iterator iter = StlList.rbegin(); iter != StlList.rend(); ++iter)
//		{
//			std::cout << *iter << std::endl;
//		}
//
//		std::cout << "size() : " << StlList.size() << std::endl;
//	}
//
//	std::cout << "===================================" << std::endl;
//
//	{
//		YndooList<int> MyList;
//		MyList.push_front(1);
//		MyList.push_front(2);
//		MyList.push_back(-1);
//		MyList.push_front(0);
//
//		//MyList.pop_back();
//
//		MyList.insert(++MyList.begin(), 300);
//		MyList.insert(MyList.end(), 300);
//		MyList.remove(300);
//
//		std::cout << "=== YndooList Int ===" << std::endl;
//		YndooList<int>::iterator iter = MyList.begin();
//		//Node* node = iter;
//
//		for (YndooList<int>::iterator iter = MyList.begin(); iter != MyList.end(); ++iter)
//		{
//			std::cout << *iter << std::endl;
//		}
//
//		std::cout << "Size : " << MyList.size() << std::endl;
//		std::cout << "front() : " << MyList.front() << std::endl;
//
//		std::cout << "=== YndooList Int (reverse) ===" << std::endl;
//		for (YndooList<int>::reverse_iterator iter = MyList.rbegin(); iter != MyList.rend(); ++iter)
//		{
//			std::cout << *iter << std::endl;
//		}
//
//
//		std::cout << "=== YndooList Int (Cleared) ===" << std::endl;
//		MyList.clear();
//		for (YndooList<int>::iterator iter = MyList.begin(); iter != MyList.end(); ++iter)
//		{
//			std::cout << *iter << std::endl;
//		}
//	}
//
//	{
//		YndooList<std::string> MyList;
//		MyList.push_front("C");
//		MyList.push_front("B");
//		MyList.push_back("D");
//		MyList.push_front("A");
//
//		MyList.pop_front();
//		MyList.pop_back();
//
//		std::cout << "=== YndooList string ===" << std::endl;
//		for (YndooList<std::string>::iterator iter = MyList.begin(); iter != MyList.end(); ++iter)
//		{
//			std::cout << *iter << std::endl;
//		}
//	}
//}