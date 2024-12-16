#include "Article2.h"
#include <iostream>
using namespace std;

void test(Article obj) {
    cout << "\nInside test() function:\n";
    obj.print();
    cout << "Exiting test()...\n";
}

int main() {
    // Creating Articles
    Article article1(101, "Laptop", 1200.99);
    Article article2(102, "Smartphone", 799.49);

    cout << "\nPrinting Article objects:\n";
    article1.print();
    article2.print();

    cout << "\nTesting copy constructor:\n";
    test(article1);

    cout << "\nCurrent Article count: " << Article::getCount() << endl;

    return 0;
}
