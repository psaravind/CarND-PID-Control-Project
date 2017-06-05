#ifndef PID_H
#define PID_H

class PID {
protected:
  /*
  * Errors
  */
  double p_error = 0;
  double i_error = 0;
  double d_error = 0;
  double total_error = 0;

  int steps = 0;

  /*
  * Coefficients
  */
  
  double p[3];
  double dp[3];
  double best_err;

  int index = 0;
  bool first;

public:
  
  /*
  * Constructor
  */
  PID(double Kp, double Ki, double Kd);

  /*
  * Destructor.
  */
  virtual ~PID();

  double getValue();

  int getSteps() {return steps;}

  void UpdateError(double cte);

  /*
  * Calculate the total PID error.
  */
  double TotalError();

  void twiddle();
};

#endif /* PID_H */
