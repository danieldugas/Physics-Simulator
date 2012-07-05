#ifndef DEF_FIELD
#define DEF_FIELD

#include <iostream>
#include <string>
 
class Field
{
    public:
	
	//vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv ~CONSTRUCTORS~ vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv//
	Field();
	//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ ~CONSTRUCTORS~ ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^//
	Field(int theta);
    private:
	
	std::string m_name;
	
};
 
#endif
