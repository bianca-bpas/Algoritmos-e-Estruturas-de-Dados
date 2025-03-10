// Euro.h
// The class Euro with operator functions
// declared as friend functions.
// ---------------------------------------------------
#ifndef _EURO_H_
#define _EURO_H_
// ....
class Euro
{
private:
long data; // Euros * 100 + Cents
public:
// Constructors and other methods as before.
// Operators -(unary), +=, -= as before.
// Division Euro / double :
Euro operator/( double x) // Division *this/x
{ // = *this * (1/x)
return (*this * (1.0/x));
}
// Global friend functions
friend Euro operator+( const Euro& e1, const Euro& e2);
friend Euro operator-( const Euro& e1, const Euro& e2);
friend Euro operator*( const Euro& e, double x)
{
Euro temp(( (double)e.data/100.0) * x) ;
return temp;
}
friend Euro operator*( double x, const Euro& e)
{
return e * x;
}
};
// Addition:
inline Euro operator+( const Euro& e1, const Euro& e2)
{
Euro temp; temp.data = e1.data + e2.data;
return temp;
}
// Subtraction:
inline Euro operator-( const Euro& e1, const Euro& e2)
{
Euro temp; temp.data = e1.data - e2.data;
return temp;
}
#endif // _EURO_H_