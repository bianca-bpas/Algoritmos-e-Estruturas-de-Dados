#include "Article2.h"
#include <iostream>
using namespace std;

// Initialize static member
int Article::count = 0;

// Constructor
Article::Article(long number, const string& name, double price) 
    : articleNumber(number), articleName(name), salesPrice(price >= 0 ? price : 0.0) {
    count++;
    cout << "An object of type Article is created.\nThis is the " << count << " Article.\n";
}

// Copy Constructor
Article::Article(const Article& other) 
    : articleNumber(other.articleNumber), articleName(other.articleName), salesPrice(other.salesPrice) {
    count++;
    cout << "A copy of Article is created. Total articles: " << count << endl;
}

// Destructor
Article::~Article() {
    cout << "The object of type Article is destroyed.\nThere are still " << --count << " articles.\n";
}

// Print details of Article
void Article::print() const {
    cout << "Article Number: " << articleNumber << "\n"
         << "Article Name: " << articleName << "\n"
         << "Sales Price: $" << salesPrice << endl;
}

// Static method to get current count
int Article::getCount() {
    return count;
}

// Setter and Getter Implementations
void Article::setArticleNumber(long number) { articleNumber = number; }
void Article::setArticleName(const string& name) { articleName = name; }
void Article::setSalesPrice(double price) { salesPrice = (price >= 0 ? price : 0.0); }

long Article::getArticleNumber() const { return articleNumber; }
string Article::getArticleName() const { return articleName; }
double Article::getSalesPrice() const { return salesPrice; }
