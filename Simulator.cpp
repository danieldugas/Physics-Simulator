/* ---- after testing is done, delete 'REMOVE AFTER TESTING' comments ---- */

#include <iostream>
#include <fstream>
#include "MaterialPoint.h"
#include "Function.h"
#include "Referential.h"
#include "Field.h"

using namespace std;



int main()
{
	//vector< MaterialPoint > points;
	//MaterialPoint point(points);
	//Referential laboratory;
	
	double time, deltatime(0.001), drag(-0.1), mass(1), k(100) ,P1_charge = 0.16, P2_charge = -0.16, B_tesla = 10, P1_x(0), P1_y(0), P1_vx(10), P1_vy(0), P1_ax, P1_ay, P2_x(0), P2_y(-10), P2_vx(10), P2_vy(0), P2_ax, P2_ay;

	double *P1_velocity_x = &P1_vx;
	double *P1_velocity_y = &P1_vy;
	double *P1_position_x = &P1_x;
	double *P1_position_y = &P1_y;
	
	double *P2_velocity_x = &P2_vx;
	double *P2_velocity_y = &P2_vy;
	double *P2_position_x = &P2_x;
	double *P2_position_y = &P2_y;

	Function dxP1toP2;
	dxP1toP2.add_argument(P2_position_x);
	dxP1toP2.add_operator('-');
	dxP1toP2.add_argument(P1_position_x);
	
	Function dyP1toP2;
	dyP1toP2.add_argument(P2_position_y);
	dyP1toP2.add_operator('-');
	dyP1toP2.add_argument(P1_position_y);
	
	Function dP1toP2_squared;
	dP1toP2_squared.add_argument(dxP1toP2);
	dP1toP2_squared.add_operator('^');
	dP1toP2_squared.add_argument(2);
	dP1toP2_squared.add_operator('+');
	dP1toP2_squared.add_argument(dyP1toP2);
	dP1toP2_squared.add_operator('^');
	dP1toP2_squared.add_argument(2);
	
	Function P1_forces_x;
	P1_forces_x.add_argument(P1_velocity_x);
	P1_forces_x.add_operator('*');
	P1_forces_x.add_argument(drag);
	P1_forces_x.add_operator('+');
	P1_forces_x.add_argument(P1_charge);
	P1_forces_x.add_operator('*');
	P1_forces_x.add_argument(B_tesla);
	P1_forces_x.add_operator('*');
	P1_forces_x.add_argument(P1_velocity_y);
	
	P1_forces_x.add_operator('-');
	P1_forces_x.add_argument(k);
	P1_forces_x.add_operator('*');
	P1_forces_x.add_argument(P1_charge);
	P1_forces_x.add_operator('*');
	P1_forces_x.add_argument(P2_charge);
	P1_forces_x.add_operator('*');
	P1_forces_x.add_argument(dxP1toP2);
	P1_forces_x.add_operator('*');
	P1_forces_x.add_argument(dP1toP2_squared);
	P1_forces_x.add_operator('^');
	P1_forces_x.add_argument(-3/2);

	Function P1_forces_y;
	P1_forces_y.add_argument(P1_velocity_y);
	P1_forces_y.add_operator('*');
	P1_forces_y.add_argument(drag);
	P1_forces_y.add_operator('-');
	P1_forces_y.add_argument(P1_charge);
	P1_forces_y.add_operator('*');
	P1_forces_y.add_argument(B_tesla);
	P1_forces_y.add_operator('*');
	P1_forces_y.add_argument(P1_velocity_x);
	
	P1_forces_y.add_operator('-');
	P1_forces_y.add_argument(k);
	P1_forces_y.add_operator('*');
	P1_forces_y.add_argument(P1_charge);
	P1_forces_y.add_operator('*');
	P1_forces_y.add_argument(P2_charge);
	P1_forces_y.add_operator('*');
	P1_forces_y.add_argument(dyP1toP2);
	P1_forces_y.add_operator('*');
	P1_forces_y.add_argument(dP1toP2_squared);
	P1_forces_y.add_operator('^');
	P1_forces_y.add_argument(-3/2);
	
	Function P2_forces_x;
	P2_forces_x.add_argument(P2_velocity_x);
	P2_forces_x.add_operator('*');
	P2_forces_x.add_argument(drag);
	P2_forces_x.add_operator('+');
	P2_forces_x.add_argument(P2_charge);
	P2_forces_x.add_operator('*');
	P2_forces_x.add_argument(B_tesla);
	P2_forces_x.add_operator('*');
	P2_forces_x.add_argument(P2_velocity_y);
	
	P2_forces_x.add_operator('-');
	P2_forces_x.add_argument(k);
	P2_forces_x.add_operator('*');
	P2_forces_x.add_argument(P1_charge);
	P2_forces_x.add_operator('*');
	P2_forces_x.add_argument(P2_charge);
	P2_forces_x.add_operator('*');
	P2_forces_x.add_argument(dxP1toP2);
	P2_forces_x.add_operator('*');
	P2_forces_x.add_argument(dP1toP2_squared);
	P2_forces_x.add_operator('^');
	P2_forces_x.add_argument(-3/2);

	Function P2_forces_y;
	P2_forces_y.add_argument(P2_velocity_y);
	P2_forces_y.add_operator('*');
	P2_forces_y.add_argument(drag);
	P2_forces_y.add_operator('-');
	P2_forces_y.add_argument(P2_charge);
	P2_forces_y.add_operator('*');
	P2_forces_y.add_argument(B_tesla);
	P2_forces_y.add_operator('*');
	P2_forces_y.add_argument(P2_velocity_x);
	
	P2_forces_y.add_operator('+');
	P2_forces_y.add_argument(k);
	P2_forces_y.add_operator('*');
	P2_forces_y.add_argument(P1_charge);
	P2_forces_y.add_operator('*');
	P2_forces_y.add_argument(P2_charge);
	P2_forces_y.add_operator('*');
	P2_forces_y.add_argument(dyP1toP2);
	P2_forces_y.add_operator('*');
	P2_forces_y.add_argument(dP1toP2_squared);
	P2_forces_y.add_operator('^');
	P2_forces_y.add_argument(-3/2);
		
	
	Function P1_acceleration_x;
	P1_acceleration_x.add_argument(P1_forces_x);
	P1_acceleration_x.add_argument(mass);
	P1_acceleration_x.add_operator('/');
	
	Function P1_acceleration_y;
	P1_acceleration_y.add_argument(P1_forces_y);
	P1_acceleration_y.add_argument(mass);
	P1_acceleration_y.add_operator('/');
	
	Function P2_acceleration_x;
	P2_acceleration_x.add_argument(P2_forces_x);
	P2_acceleration_x.add_argument(mass);
	P2_acceleration_x.add_operator('/');
	
	Function P2_acceleration_y;
	P2_acceleration_y.add_argument(P2_forces_y);
	P2_acceleration_y.add_argument(mass);
	P2_acceleration_y.add_operator('/');
	
	const char* output_filename("./position.txt");
	ofstream output_file(output_filename, ios::out | ios::trunc);
	if(output_file) // if opened successfully
	{
		time = 0;
		for (int i(0); time <= 100 && dP1toP2_squared.value() != 0; i++)
		{
			if ( (i % 10000 )== 0 ) 
			{
				cout << "P1( " << P1_x << " ; " << P1_y << " )" << endl << "VP1( " << P1_vx << " ; " << P1_vy << " )" << endl;
				cout << "P2( " << P2_x << " ; " << P2_y << " )" << endl << "VP2( " << P2_vx << " ; " << P2_vy << " )" << endl;
				dP1toP2_squared.DEBUG_value();
			}
			if ( (i % 10) == 0 ) output_file << time << ";" << P1_x << ";" << P1_y << ";" << P2_x << ";" << P2_y << endl;
			
			P1_ax = P1_acceleration_x.value();
			P1_ay = P1_acceleration_y.value();
			P2_ax = P2_acceleration_x.value();
			P2_ay = P2_acceleration_y.value();
			
			P1_x += ( deltatime*P1_vx );
			P1_y += ( deltatime*P1_vy );
			P1_vx += ( deltatime*P1_ax );
			P1_vy += ( deltatime*P1_ay );
			P2_x += ( deltatime*P2_vx );
			P2_y += ( deltatime*P2_vy );
			P2_vx += ( deltatime*P2_ax );
			P2_vy += ( deltatime*P2_ay );
			
			
			time = time + deltatime;
		}
	}
}
