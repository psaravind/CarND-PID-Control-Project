#include "PID.h"
#include <iostream>
#include <uWS/uWS.h>
#include <math.h>

using namespace std;
constexpr double pi() { return M_PI; }

/*
* TODO: Complete the PID class.
*/

PID::PID(double Kp, double Ki, double Kd) {
	p_error = 0;
	i_error = 0;
	d_error = 0;

	p[0] = Kp;
	p[1] = Ki;
	p[2] = Kd;

	dp[0] = 0.01;
	dp[1] = .0000001;
	dp[2] = .01;
	
	best_err = 1e9;
	first = true;
}

PID::~PID() {}

void PID::UpdateError(double cte) {
	d_error = cte - p_error;
	p_error = cte;
	i_error += cte;
	
	total_error += pow(cte, 2);
	steps++;
}

double PID::getValue() {
	double steer = -p[0] * p_error - p[2] * d_error - p[1] * i_error;
	
	steer = steer < -1 ? -1 : steer;
	steer = steer >  1 ?  1 : steer;

	return steer;
}

double PID::TotalError() {
	return total_error / steps;
}

void PID::twiddle() {
	double err = TotalError();
	total_error = 0;
	steps = 0;

	if (best_err > 1e8) {
		best_err = err;
		std::cout << "Kp: " << p[0] << 
			" Kd: " << p[2] << 
			" Ki: " << p[1] << 
			" Error: " << best_err << std::endl;
		p[index] += dp[index];
		return;
	}
	i_error = 0;
	d_error = 0;
	p_error = 0;

	if (err < best_err) {
		best_err = err;
		dp[index] *= 1.1;

		index++;
		index = index % 3;
		first = true;
		std::cout << "Kp: " << p[0] << 
			" Kd: " << p[2] << 
			" Ki: " << p[1] << 
			" Error: " << best_err << std::endl;
	} else {
		if (first == true) 
			first = false;
		else {
			p[index] += dp[index];
			dp[index] *= 0.9;
			index++;
			index = index % 3;
			first = true;
		}
	}
	if (first)
		p[index] += dp[index];
	else
		p[index] -= 2 * dp[index];
}