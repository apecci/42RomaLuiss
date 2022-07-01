#include "MutantStack.hpp"
#include <iomanip>
#include <list>

int main()
{
MutantStack<int>	mstack;
	std::list<int>		lst;

	std::cout << "-------------------------------------" << std::endl;
	std::cout << "   Mutant Stack   |     std::list    " << std::endl;
	std::cout << "-------------------------------------" << std::endl;

	mstack.push(5);
	lst.push_back(5);
	mstack.push(17);
	lst.push_back(17);

	std::cout << " Last added :     |" << std::endl;
	std::cout << std::setw(17) << mstack.top() << " |" << std::setw(17) << lst.back() << std::endl;

	mstack.pop();
	lst.pop_back();

	std::cout << " Size :           |" << std::endl;
	std::cout << std::setw(17) << mstack.size() << " |" << std::setw(17) << lst.size() << std::endl;

	mstack.push(3);
	lst.push_back(3);
	mstack.push(5);
	lst.push_back(5);
	mstack.push(737);
	lst.push_back(737);
	mstack.push(0);
	lst.push_back(0);

	std::cout << " Last added :     |" << std::endl;
	std::cout << std::setw(17) << mstack.top() << " |" << std::setw(17) << lst.back() << std::endl;

	MutantStack<int>::iterator	mit = mstack.begin();
	std::list<int>::iterator	lit = lst.begin();
	MutantStack<int>::iterator	mend = mstack.end();
	std::list<int>::iterator	lend = lst.end();

	++mit;
	++lit;
	--mit;
	--lit;

	std::cout << " Contents :       |" << std::endl;
	while (mit != mend || lit != lend)
	{
		std::cout << std::setw(17) << *mit << " |" << std::setw(17) << *lit << std::endl;
		mit++;
		lit++;
	}

	std::stack<int>	s(mstack);
	std::list<int>	l(lst);

	std::cout << " Last added :     |" << std::endl;
	std::cout << std::setw(17) << s.top() << " |" << std::setw(17) << l.back() << std::endl;

	MutantStack<int>	mstack2 = mstack;
	std::list<int>		lst2 = lst;

	mstack2.push(2);
	lst2.push_back(2);
	mstack2.push(8);
	lst2.push_back(8);
	mstack2.push(12);
	lst2.push_back(12);

	mit = mstack2.begin();
	lit = lst2.begin();
	mend = mstack2.end();
	lend = lst2.end();

	std::cout << " Contents :       |" << std::endl;
	while (mit != mend || lit != lend)
	{
		std::cout << std::setw(17) << *mit << " |" << std::setw(17) << *lit << std::endl;
		mit++;
		lit++;
	}

	return (0);
}