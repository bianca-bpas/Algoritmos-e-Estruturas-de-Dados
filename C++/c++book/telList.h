// telList.h
// Class TelList to represent a list
// containing names and telephone numbers.
// ----------------------------------------------------
#ifndef _TelList_
#define _TelList_
#include <string>
using namespace std;
#define PSEUDO -1
#define MAX 100

struct Element {string name, telNr;};

class TelList{
    private:
        Element v[MAX];
        int count;
    
    public:
        TelList(){count = 0;}
        int getCount() const {return count;}
        Element *retrieve(int i){return (i >= 0 && i < count)? &v[i]:NULL;}
        bool append(const Element &el){return append(el.name, el.telNr);}
        bool append(const string& name, const string& telNr);
        bool erase(const string& name);
        int search(const string& name);
        void print();
        int print(const string& name);
        int getNewEntries();
};

#endif