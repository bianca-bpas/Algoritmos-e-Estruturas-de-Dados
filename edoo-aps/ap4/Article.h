#ifndef ARTICLE_H
#define ARTICLE_H

#include <string>
using namespace std;

class Article {
private:
    long articleNumber;
    string articleName;
    double salesPrice;
    static int count;

public:
    Article(long number, const string& name, double price);
    Article(const Article& other); // Copy constructor
    ~Article();
    void print() const;
    static int getCount();

    void setArticleNumber(long number);
    void setArticleName(const string& name);
    void setSalesPrice(double price);

    long getArticleNumber() const;
    string getArticleName() const;
    double getSalesPrice() const;
};

#endif
