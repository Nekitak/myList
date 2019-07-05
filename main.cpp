
#include "list.h"
 

using namespace Reality;
 
 

int main()
{

	list<int> list1;
	list1.push_back(4);

	list1.push_back(424);
	list1.push_back(455);
	 
 

	std::cout << list1.GetSize();
	std::cout << "\n";
 
	for (size_t i = 0; i < list1.GetSize(); i++)
	{
		std::cout << list1[i] << " ";
	}
	   
	list<char> list2;

	list2.push_back('h');

	list2.push_back('w');

	list2.printOn();

	system("pause");
	return 0;
}