#include "Result.h"
#include <iostream>
using namespace std;
class ControlPoint
{
private:
string name; // Name of control point
Result measure[100]; // Table with results
// . . .
public:
// Constructor and the other methods
// . . .
// Compute static values of measurement results
// (average, deviation from mean, ...).
bool statistic(); // Can access the private
// members of measure[i].
};