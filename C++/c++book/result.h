// result.h
// Class Result to represent a measurement and the time of measurement.
// ---------------------------------------------------
#ifndef _RESULT_
#define _RESULT_
#include "DayTime.h"

class Result{
    private:
        double val;
        const DayTime time;
        static double min, max;
        static bool first;
        static void setMinMax(double w);

    public:
        Result();
        Result(double w, const DayTime& z = currentTime());
        Result(double w, int hr, int min, int sec);

        double getVal() const {return val;}
        void setVal(double w) {val = w;}
        
        const DayTime& getTime() const {return time;}
        void setTime(const DayTime& z) {time = z;}
        bool setTime(int hr, int min, int sec) {return time.setTime(hr, min, sec);}
        void print() const;

        static double getMin() {return min;}
        static double getMax() {return max;}
};

Result::Result() : val(0.0){} // Lista de inicialização
Result::Result(double w, const DayTime& z) : val(w), time(z){}
Result::Result(double w, int hr, int min, int sec) : val(w), time(hr, min, sec){}


#endif    // _RESULT_