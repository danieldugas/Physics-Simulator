#include "MaterialPoint.h"
#include "Referential.h"
#include <vector>


using namespace std;

const char* /* Can't make array of string, for some reason char* works */GREEKNAMES[24] = { "alpha", "beta", "gamma", "delta", "epsilon", "zeta", "eta", "theta", "iota", "kappa", "lambda", "mu", "nu", "xi", "omicron", "pi", "rho", "sigma", "tau", "upsilon", "phi", "chi", "psi", "omega" };
//const char GREEKCAPITALLETTERS[24] = { 'Α', 'Β', 'Γ', 'Δ', 'Ε', 'Ζ', 'Η', 'Θ', 'Ι', 'Κ', 'Λ', 'Μ', 'Ν', 'Ξ', 'Ο', 'Π', 'Ρ', 'Σ', 'Τ', 'Υ', 'Φ', 'Χ', 'Ψ', 'Ω' }
//const char GREEKLOWERCASELETTERS[24] = { 'α', 'β', 'γ', 'δ', 'ε', 'ζ', 'η', 'θ', 'ι', 'κ', 'λ', 'μ', 'ν', 'ξ', 'ο', 'π', 'ρ', 'σ', 'τ', 'υ', 'φ', 'χ', 'ψ', 'ω' }



//vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv ~CONSTRUCTORS~ vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv//
MaterialPoint::MaterialPoint() : m_mass_kg(0), m_charge_C(0)
{
	cerr << "Unassigned point created!" << endl; // REMOVE AFTER TESTING 
}

MaterialPoint::MaterialPoint(vector< MaterialPoint > &MaterialPoints) : m_mass_kg(0), m_charge_C(0)
{
	m_name = GREEKNAMES[MaterialPoints.size()%24];
	MaterialPoints.push_back(*this);
}

MaterialPoint::MaterialPoint( vector< MaterialPoint > &MaterialPoints, double mass, double charge) : m_mass_kg(mass), m_charge_C(charge)
{
	m_name = GREEKNAMES[MaterialPoints.size()%24];
	MaterialPoints.push_back(*this);
}
//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ ~CONSTRUCTORS~ ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^//

void MaterialPoint::displayname()
{
		cout << m_name;
}
