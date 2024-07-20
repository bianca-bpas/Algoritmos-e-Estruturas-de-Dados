#include <iostream>
#include <vector>
#include <list>
using namespace std;

struct DS{
    vector<int> R;
    vector<list<int>> sets;
    int count;
}

DS* create_QuickFind(int n){
    DS* ds = new DS;
    ds->R.resize(n);
    ds->sets.resize(n);
    ds->count = n;
    for (int i = 0; i < n; i++){
        ds->R[i] = i;
        ds->sets[i].push_back(i);
    }
    return ds;
}
int find(DS* ds, int curr){
    return ds->R[curr];
}

void union(DS* ds, int a, int b){
    int root1 = find(ds, a);
    int root2 = find(ds, b);

    if (root1 != root2){
        int l1 = ds->sets[root1];
        int l2 = ds->sets[root2];
        if (l1->size < l2->size){
            swap(l1, l2);
        }

        int temp = l2.front();
        while (temp != NULL){
            ds->R[temp] = l1.front();
            temp = 
        }
    }
}
