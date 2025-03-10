// stdMeth.cpp
// Using standard methods.
// ---------------------------------------------------
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class CD{
    private:
        string interpret, title;
        long seconds;
    
    public:
        CD (const string& i ="", const string& t="", long s = 0L){interpret = i; title = t; seconds = s;}

        const string & getInterpret() const {return interpret;}
        const string & getTitle() const {return title;}
        long getSeconds() const {return seconds;}
};
void printLine(CD cd);

int main(){
    CD cd1("Mister X", "Let's dance", 30*60 + 41), cd2("New Guitars", "Flamenco Collection", 2772), cd3 = cd1, cd4;
    cd4 = cd2;
    string line(70, '-');
    line += '\n';

    cout << line << left
         << setw(20) << "Interpreter" << setw(30) << "Title"
         << "Length (Min::Sec)\n" << line << endl;
    printLine(cd3);
    printLine(cd4);
    
    return 0;
}

void printLine(CD cd){
    cout << left << setw(20) << cd.getInterpret()
                 << setw(30) << cd.getTitle()
         << right << setw(5) << cd.getSeconds() / 60
         << ':'   << setw(2) << cd.getSeconds() % 60 << endl;
}