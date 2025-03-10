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
        Article(long a_number = 0L, const string& a_name = "", double s_price = 0.0) {
            article_number = a_number; 
            article_name = a_name; 
            if (s_price >= 0){
                sales_price = s_price;
            } else {sales_price = 0.0;}}
        ~Article();
        void print();
        void setNumber(long a_number) {this->article_number = a_number;}
        void setName(string& a_name) {this->article_name = a_name;}
        void setPrice(double s_price) {if (s_price >= 0){this->sales_price = s_price;} else {this->sales_price = 0.0;}}
        long getNumber() {return this->article_number;}
        const string& getName(){return this->article_name;}
        double getPrice() {return this->sales_price;}

};

#endif