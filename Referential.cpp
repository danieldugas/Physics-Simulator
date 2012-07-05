#include "Referential.h"

using namespace std;

//vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv ~CONSTRUCTORS~ vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv//
Referential::Referential()
{
	m_name = "laboratory";
	m_time = 0;
	m_firstaxis[0] = 1;
	m_firstaxis[1] = 0;
	m_firstaxis[2] = 0;
	m_secondaxis[0] = 0;
	m_secondaxis[1] = 1;
	m_secondaxis[2] = 0;
	m_thirdaxis[0] = 0;
	m_thirdaxis[1] = 0;
	m_thirdaxis[2] = 1;
	m_position[0] = 0;
	m_position[1] = 0;
	m_position[2] = 0;
	m_speed[0] = 0;
	m_speed[1] = 0;
	m_speed[2] = 0;
	m_acceleration[0] = 0;
	m_acceleration[1] = 0;
	m_acceleration[2] = 0;
}
//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ ~CONSTRUCTORS~ ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^//
