#ifndef DEF_REFERENTIAL
#define DEF_REFERENTIAL

#include <iostream>
#include <string>
#include <vector>
 
class Referential
{
    public:
	
	//vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv ~CONSTRUCTORS~ vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv//
	Referential();
	//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ ~CONSTRUCTORS~ ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^//
	
	
    private:
	
	std::string m_name;
	int m_time;
	int m_firstaxis[3];
	int m_secondaxis[3];
	int m_thirdaxis[3];
	int m_position[3];
	int m_speed[3];
	int m_acceleration[3];
};
 
#endif
