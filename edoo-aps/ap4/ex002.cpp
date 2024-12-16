#include "Article.h"
#include <iostream>
using namespace std;

void test() {
    static Article staticArticle(3, "Static Article", 50.0);
    Article localArticle(4, "Local Article", 20.0);

    cout << "\nIn test() function:\n";
    staticArticle.print();
    localArticle.print();
}

int main() {
    Article globalArticle(1, "Global Article", 30.0);

    {
        Article mainLocalArticle(2, "Main Local Article", 25.0);
        cout << "\nIn main() local scope:\n";
        mainLocalArticle.print();
    }

    cout << "\nCalling test() twice:\n";
    test();
    test();

    cout << "Current Article count: " << Article::getCount() << endl;

    return 0;
}
