#ifndef ARTICLE2_H
#define ARTICLE2_H

#include <string>
using namespace std;

class Article {
private:
    long articleNumber;
    string articleName;
    double salesPrice;
    static int count; // Static member to track object count

public:
    // Constructors and Destructor
    Article(long number, const string& name, double price);
    Article(const Article& other); // Copy constructor
    ~Article();

    // Accessor Methods
    void print() const;
    static int getCount(); // Static method to get object count

    // Setters and Getters
    void setArticleNumber(long number);
    void setArticleName(const string& name);
    void setSalesPrice(double price);

    long getArticleNumber() const;
    string getArticleName() const;
    double getSalesPrice() const;
};

#endif
