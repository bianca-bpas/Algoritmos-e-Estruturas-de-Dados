// DayTime.h
// The class DayTime containing operators < and ++ .
// ---------------------------------------------------
#ifndef _DAYTIME_
#define _DAYTIME_

class DayTime{
    private:
        short hour, minute, second;
        bool overflow;

    public:
        DayTime(int h = 0, int m = 0, int s = 0);
        bool setTime(int hour, int minute, int second = 0);
        int getHour() const {return hour;}
        int getMinute() const {return minute;}
        int getSecond() const {return second;}
        int asSeconds() const{
            return (60*60*hour + 60*minute + second);}

        bool operator<(const DayTime& t) const {return asSeconds() < t.asSeconds();}
    
        DayTime& operator++(){
            ++second;
            return *this;
        }
        
    void print() const;

};
#endif // _DAYTIME_