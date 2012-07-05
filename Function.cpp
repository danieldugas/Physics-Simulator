#include "Function.h"
#include <cmath>
#include <vector>

using namespace std;

const double INF = pow(2, 50);


//vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv ~CONSTRUCTORS~ vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv//
Function::Function() : m_isconstant(false), m_isavariable(false)
{	
}
Function::Function(const double constant) : m_isconstant(true), m_isavariable(false), m_constantvalue(constant)
{
	
}
Function::Function(const double* variablelocation) : m_isconstant(false), m_isavariable(true), m_variablelocation(variablelocation)
{
	
}
Function::Function(const vector< Function >& arguments, const vector< char >& operators) : m_isconstant(false), m_isavariable(false)
{
	if ( arguments.size() - operators.size() == 1 )
	{
		m_arguments=arguments;
		m_operators=operators;
	}
	else {cerr << "invalid function arguments and operators"; }
}
//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ ~CONSTRUCTORS~ ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^//



double Function::value() const
{
	if (m_isconstant) { return m_constantvalue; }
	if (m_isavariable) { return *m_variablelocation; }
	if (!m_isconstant && !m_isavariable)
	{ 
		if ( m_arguments.size() - m_operators.size() != 1 ) { cerr << "Error: mismatched arguments/operators" << endl; return 0;}
		vector< double > tempvalues;
		for(unsigned int a = 0; a < m_arguments.size(); a++) { tempvalues.push_back( m_arguments[a].value() ); }
		vector< char > tempoperators;
		for(unsigned int b = 0; b < m_operators.size(); b++) { tempoperators.push_back( m_operators[b] ); }
		double tempresult(0);
		
	
		for(unsigned int i=0; i < m_operators.size(); i++) // by reversing i, the rightmost power is applied first instead
		{
			if (m_operators[i] == '^')
			{
				if ( m_arguments[i].value() == 0 && m_arguments[i+1].value() < 0 ) { tempvalues[i] = INF; cerr << "0 pow -1" << endl; }
				else { tempvalues[i] = pow( m_arguments[i].value(), m_arguments[i+1].value() ); }
				tempvalues[i+1] = 1;
				tempoperators[i] = '*';	
			}
		}
		for(unsigned int j=0; j < m_operators.size(); j++) // by reversing j, the rightmost division is applied first instead
		{
			if (m_operators[j] == '/')
			{
				if ( tempvalues[j+1] == 0) { tempvalues[j] = INF; cerr << "div 0" << endl; }
				else { tempvalues[j] = ( tempvalues[j]/tempvalues[j+1] ); }
				tempvalues[j+1] = 1;
				tempoperators[j] = '*';	
			}
		}
		
		double product(1);
		for(unsigned int k=0; k < m_operators.size(); k++)
		{
			if (m_operators[k] == '+' || m_operators[k] == '-')
			{
				for(unsigned int l=0; l <= k; l++) { product = product * tempvalues[l]; tempvalues[l] = 1; }
				tempresult = tempresult + product;
				
				
				if (m_operators[k] == '+') { product = 1; }
				if (m_operators[k] == '-') { product = -1; }
			}
			
		}
		for(unsigned int l=0; l < tempvalues.size(); l++) { product = product * tempvalues[l]; tempvalues[l] = 1; }
		tempresult = tempresult + product;
		
		
		return tempresult;
	}
	
	return 0;
	
}

double Function::DEBUG_value() const //REMOVE AFTER TESTING
{
	cerr << endl << endl << "----------------------- ESTIMATING VALUE -----------------------" << endl;
	if (m_isconstant) { cerr << "Constant Value == " << m_constantvalue; cerr << endl << "---------------------- ESTIMATION COMPLETE ----------------------" << endl << endl; return m_constantvalue; }
	if (m_isavariable) { cerr << "Variable Value == " << *m_variablelocation; cerr << endl << "---------------------- ESTIMATION COMPLETE ----------------------" << endl << endl; return *m_variablelocation; }
	if (!m_isconstant && !m_isavariable)
	{ 
		if ( m_arguments.size() - m_operators.size() != 1 ) { cerr << "Error: mismatched arguments/operators" << endl; cerr << endl << "---------------------- ESTIMATION COMPLETE ----------------------" << endl << endl; return 0;}
		vector< double > tempvalues;
		for(unsigned int a = 0; a < m_arguments.size(); a++) { tempvalues.push_back( m_arguments[a].value() ); }
		vector< char > tempoperators;
		for(unsigned int b = 0; b < m_operators.size(); b++) { tempoperators.push_back( m_operators[b] ); }
		double tempresult(0);
		

		// vvvv DEBUG vvvv
		cerr << " -- For Function ";
		for(unsigned int i=0; i < m_operators.size(); i++) 
		{
			cerr << m_arguments[i].value() << m_operators[i];
		}
		cerr << m_arguments[m_operators.size()].value() << " -- " << endl << endl; 
		// ^^^^ DEBUG ^^^^
		

	
		for(unsigned int i=0; i < m_operators.size(); i++) // by reversing i, the rightmost power is applied first instead
		{
			if (m_operators[i] == '^')
			{
				if ( m_arguments[i].value() == 0 && m_arguments[i+1].value() < 0 ) { tempvalues[i] = INF; cerr << "WARNING: 0 pow -1" << endl; }
				else { tempvalues[i] = pow( m_arguments[i].value(), m_arguments[i+1].value() ); }
				tempvalues[i+1] = 1;
				tempoperators[i] = '*';	
			}
		}
		for(unsigned int j=0; j < m_operators.size(); j++) // by reversing j, the rightmost division is applied first instead
		{
			if (m_operators[j] == '/')
			{
				if ( tempvalues[j+1] == 0) { tempvalues[j] = INF; cerr << "WARNING: div 0" << endl; }
				else { tempvalues[j] = ( tempvalues[j]/tempvalues[j+1] ); }
				tempvalues[j+1] = 1;
				tempoperators[j] = '*';	
			}
		}
		
		double product(1);
		for(unsigned int k=0; k < m_operators.size(); k++)
		{
			if (m_operators[k] == '+' || m_operators[k] == '-')
			{
				for(unsigned int l=0; l <= k; l++) { product = product * tempvalues[l]; tempvalues[l] = 1; }
				tempresult = tempresult + product;
				
				
				if (m_operators[k] == '+') { product = 1; }
				if (m_operators[k] == '-') { product = -1; }
			}
			
		}
		for(unsigned int l=0; l < tempvalues.size(); l++) { product = product * tempvalues[l]; tempvalues[l] = 1; }
		tempresult = tempresult + product;
		cerr << "Value == " << tempresult;
		cerr << endl << "---------------------- ESTIMATION COMPLETE ----------------------" << endl << endl;
		return tempresult;
	}
	cerr << "Value == " << "zero";
	cerr << endl << "---------------------- ESTIMATION COMPLETE ----------------------" << endl << endl;
	return 0;
	
}


void Function::add_argument(const double new_argument)
{
	if (!m_isconstant && !m_isavariable)
	{
		Function temp(new_argument);
		m_arguments.push_back(temp);
	}
	else cerr << "function cannot accept arguments";
}
void Function::add_argument(const double *new_argument)
{
	if (!m_isconstant && !m_isavariable)
	{
		Function temp(new_argument);
		m_arguments.push_back(temp);
	}
	else cerr << "function cannot accept arguments";
}
void Function::add_argument(const Function new_argument)
{
	if (!m_isconstant && !m_isavariable)
	{
		m_arguments.push_back(new_argument);
	}
	else cerr << "function cannot accept arguments";
}


void Function::edit_argument(unsigned int position, const Function new_argument)
{
	if (!m_isconstant && !m_isavariable)
	{
		if ( position < m_arguments.size() ) m_arguments[position] = new_argument;
		else // position >= the vector size
		{
			Function one(1);
			while ( m_arguments.size() <= position)
			{
				if (m_arguments.size() == position) m_arguments.push_back(new_argument);
				else m_arguments.push_back(one);
				m_operators.push_back('*'); // for position == 5, 4+6+7 becomes 4+6+7*1*1*3
			}
		}
	}
	else cerr << "function cannot accept arguments";
}

void Function::add_operator(const char new_operator)
{
	if (!m_isconstant && !m_isavariable)
	{
		m_operators.push_back(new_operator);
	}
	else cerr << "function cannot accept operators";
}
void Function::edit_operator(unsigned int position, const char new_operator)
{
	if (!m_isconstant && !m_isavariable)
	{	
		if ( position < m_operators.size() ) m_operators[position] = new_operator;
		else // position >= the vector size
		{
			Function one(1);
			while ( m_operators.size() <= position)
			{
				if (m_operators.size() == position) m_operators.push_back(new_operator);
				else m_operators.push_back('*');
				m_arguments.push_back(one); // for position == 4, 4+6+7 becomes 4+6+7*1*1/3
			}
		}
	}
	else cerr << "function cannot accept operators";
}

Function& Function::operator+=(const Function& to_add)
{
	if (m_isconstant)
	{
		m_isconstant = 0;
		m_isavariable = 0;
		m_arguments.clear();
		m_operators.clear();
		if (to_add.m_isconstant) { m_isconstant = 1; m_constantvalue += to_add.m_constantvalue; }
		if (to_add.m_isavariable)
		{
			Function copy(m_constantvalue);
			m_arguments.push_back(copy);
			m_operators.push_back('+');
			m_arguments.push_back(to_add);
		}
		if (!to_add.m_isconstant && !to_add.m_isavariable)
		{
			Function copy(m_constantvalue);
			m_arguments.push_back(copy);
			m_operators.push_back('+');
			for(unsigned int a(0);a < to_add.m_arguments.size(); a++) m_arguments.push_back(to_add.m_arguments[a]);
			for(unsigned int b(0);b < to_add.m_operators.size(); b++) m_operators.push_back(to_add.m_operators[b]);
		}
	}
	if (m_isavariable)
	{
		m_isconstant = 0;
		m_isavariable = 0;
		m_arguments.clear();
		m_operators.clear();
		if (to_add.m_isconstant)
		{
			Function copy(m_variablelocation);
			Function copy2(to_add.m_constantvalue);
			m_arguments.push_back(copy);			
			m_arguments.push_back(copy2);
			m_operators.push_back('+');

		}
		if (to_add.m_isavariable)
		{
			Function copy(m_variablelocation);
			Function copy2(to_add.m_variablelocation);
			m_arguments.push_back(copy);
			m_operators.push_back('+');
			m_arguments.push_back(copy2);
		}
		if (!to_add.m_isconstant && !to_add.m_isavariable)
		{
			Function copy(m_variablelocation);
			m_arguments.push_back(copy);
			m_operators.push_back('+');
			for(unsigned int a(0);a < to_add.m_arguments.size(); a++) m_arguments.push_back(to_add.m_arguments[a]);
			for(unsigned int b(0);b < to_add.m_operators.size(); b++) m_operators.push_back(to_add.m_operators[b]);
		}
	}
	if (!m_isconstant && !m_isavariable)
	{
		m_isconstant = 0;
		m_isavariable = 0;
		if (to_add.m_isconstant)
		{
			Function copy(to_add.m_constantvalue);
			m_arguments.push_back(copy);			
			m_operators.push_back('+');

		}
		if (to_add.m_isavariable)
		{
			Function copy(to_add.m_variablelocation);
			m_arguments.push_back(copy);
			m_operators.push_back('+');
		}
		if (!to_add.m_isconstant && !to_add.m_isavariable)
		{
			m_operators.push_back('+');
			for(unsigned int a(0);a < to_add.m_arguments.size(); a++) m_arguments.push_back(to_add.m_arguments[a]);
			for(unsigned int b(0);b < to_add.m_operators.size(); b++) m_operators.push_back(to_add.m_operators[b]);
		}	
	}
	return *this;
}

Function::~Function()
{
	//if (m_isavariable) delete m_variablelocation;
}
