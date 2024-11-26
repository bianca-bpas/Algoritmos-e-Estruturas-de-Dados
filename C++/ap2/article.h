#ifndef _ARTICLE_
#define _ARTICLE_
#include <iostream>
using namespace std;

class Article{
    private:
        long article_number;
        string article_name;
        double sales_price;

    public:
        Article(long a_number = 0L, const string& a_name = "", double s_price = 0.0) {article_number = a_number; article_name = a_name; sales_price = s_price};
        ~Article();
        void print();
        void setNumber(long a_number) {this->article_number = a_number;}
        void setName(string& a_name) {this->article_name = a_name;}
        void setPrice(double s_price) {this->sales_price = s_price;}
        long getNumber() {};
        
};

#endif