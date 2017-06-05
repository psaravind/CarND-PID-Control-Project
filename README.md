# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

---

## Dependencies

* cmake >= 3.5
 * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools]((https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* [uWebSockets](https://github.com/uWebSockets/uWebSockets) == 0.13, but the master branch will probably work just fine
  * Follow the instructions in the [uWebSockets README](https://github.com/uWebSockets/uWebSockets/blob/master/README.md) to get setup for your platform. You can download the zip of the appropriate version from the [releases page](https://github.com/uWebSockets/uWebSockets/releases). Here's a link to the [v0.13 zip](https://github.com/uWebSockets/uWebSockets/archive/v0.13.0.zip).
  * If you run OSX and have homebrew installed you can just run the ./install-mac.sh script to install this
* Simulator. You can download these from the [project intro page](https://github.com/udacity/CarND-PID-Control-Project/releases) in the classroom.

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pid`. 

## Describe the effect each of the P, I, D components had in your implementation

Proportional(P), Integral(I) and Differential(D) components greatly aided in stabilizing the steering angle and speed of the car.  PID controller was able to compensate for biases in the simuated car.  PID values were tuned after running several iterations of Twiddle algorithm, this hyper parameter tuning was optimized for car speed of 50.  

CTE error provided by the simulator is in the range [-5, 5], and the steering angle range [-1, 1], so the proportional value of .1 maps the CTE to steering angle.  Differential parameter of 2.9943 provides the difference between CTE's and the sum of all the CTE given by Integral(I) with value .0004.

## Describe how the final hyperparameters were chosen.

Car was not stable when the speed of the car was increased beyond 50, so to maintain stability of the car when the steering angle was high, the car would slow down to minimum value of 30, and the car would go closer to 50 for low steering angle.

Final P = .1, I = .0004, D = 2.9943 coefficients was selected using Twiddle aglorithm presented in the lecture.