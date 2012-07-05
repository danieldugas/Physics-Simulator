#ifndef DEF_FUNCTION
#define DEF_FUNCTION

#include <iostream>
#include <vector>

class Function
{
    public:
	
	//vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv ~CONSTRUCTORS~ vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv//
	Function();
	Function(const double constant);
	Function(const double *variablelocation);
	Function(const std::vector< Function >& argument, const std::vector< char >& operators);
	//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ ~CONSTRUCTORS~ ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^//

	double value() const;
	double DEBUG_value() const; // REMOVE AFTER TESTING
	
	void add_argument(const double new_argument);
	void add_argument(const double *new_argument);
	void add_argument(const Function new_argument);
	void edit_argument(unsigned int position, const Function new_argument);
	void add_operator(const char new_operator);
	void edit_operator(unsigned int position, const char new_operator);
	
	Function& operator+=(const Function& to_add);
	
	~Function();
	
    private:
	
	bool m_isconstant; //if the function is constant
	bool m_isavariable; //if the function is a variable, such as time
	double m_constantvalue;
	const double *m_variablelocation;
	std::vector< Function > m_arguments;
	std::vector< char > m_operators;
};


 
#endif
