#ifndef DATE_H
#define DATE_H

class Date {
private:
    int day, month, year;
public:
    void init(int month, int day, int year);
    void init();
    void print() const;
};

#endif
