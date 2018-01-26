#include <iostream>
#include <algorithm>
#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
  this->Kp = Kp;
  this->Ki = Ki;
  this->Kd = Kd;
}

void PID::UpdateError(double cte) {
  p_error = Kp*cte;
  sum_cte += cte;
  i_error = Ki*sum_cte;
  d_error = Kd*(cte - previous_cte);
  previous_cte = cte;
}

double PID::TotalError() {

}

double PID::GetSteering() {
  double a = -p_error - i_error - d_error;
  // clip a between [-1, 1]
  return max(min(a, 1.0), -1.0);
}
