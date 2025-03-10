// Result.h
// The class Result to represent a measurement
// and the time the measurement was taken.
// ---------------------------------------------------
#ifndef _RESULT_
#define _RESULT_
#include "DayTime.h" // Class DayTime
class Result
{
private:
double val;
DayTime time;
public:
// Constructor and access methods
friend class ControlPoint; // All methods of
};

#endif