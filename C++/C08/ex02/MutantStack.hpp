#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>

template <class T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack() : std::stack<T>(){};
		MutantStack(const MutantStack& copy){ *this = copy; };
		virtual ~MutantStack(){};

		MutantStack&	operator = (const MutantStack& op)
		{
			if (this == &op)
				return (*this);
			this->c = op.c;
			return (*this);
		};

		typedef typename	std::stack<T>::container_type::iterator iterator;
		iterator	begin() { return (this->c.begin());};
		iterator	end() { return (this->c.end());};

		typedef typename	std::stack<T>::container_type::const_iterator const_iterator;
		const_iterator	begin() const { return (this->c.begin());};
		const_iterator	end() const { return (this->c.end());};

};

#endif