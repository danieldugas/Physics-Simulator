#ifndef DEF_MATERIALPOINT
#define DEF_MATERIALPOINT

#include <iostream>
#include <string>
#include <vector>


class MaterialPoint
{
    public:
	
	//vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv ~CONSTRUCTORS~ vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv//
	MaterialPoint();
	MaterialPoint(std::vector< MaterialPoint > &MaterialPoints);
	MaterialPoint(std::vector< MaterialPoint > &MaterialPoints, double mass, double charge);
	//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ ~CONSTRUCTORS~ ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^//
	
	void displayname();
 
    private:
	
	std::string m_name;
	double m_mass_kg;
	double m_charge_C;
};
 
#endif
