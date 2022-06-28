#include "MutantStack.hpp"

int main()
{
	MutantStack<int> mstack;

	mstack.push(5);
	std::cout << "push " << mstack.top() << std::endl;
	mstack.push(17);
	std::cout << "push " << mstack.top() << std::endl;

	std::cout << "Top Element of the stack: " << mstack.top() << std::endl;

	std::cout << "Stack size: " << mstack.size() << std::endl << std::endl;
	mstack.pop();
	std::cout << "pop from top of stack" << std::endl;

	std::cout << "Stack size: " << mstack.size() << std::endl << std::endl;

	mstack.push(3);
	std::cout << "push " << mstack.top() << std::endl;
	mstack.push(5);
	std::cout << "push " << mstack.top() << std::endl;
	mstack.push(737);
	std::cout << "push " << mstack.top() << std::endl;
	//[...]
	mstack.push(0);
	std::cout << "push " << mstack.top() << std::endl << std::endl;

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << "Stack Element: " << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	return 0;
}