#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, maior; cin >> n;
    vector<int> songs;
    // chave     idx   value
    map<int, pair<int, int>> sequence;

    for (int i = 0; i < n; i++){
        cin >> k;
        songs.push_back(k);
    }

    sequence[songs[0]].first = 0;
    sequence[songs[0]].second++;                                                                                                                                                                                                                                                               
    for (int song = 1; song < n; song++){
        auto it = sequence.find(songs[song]);
        if(it != sequence.end()){
            sequence[songs[song]].first = song;
            sequence[songs[song]].second += sequence[songs[song-1]].second;
        } else {
            auto next = ++it;
            next->second = 1;
            song = it->first;
            sequence.erase(songs[song]);

        }
    }

    pair<int, int> maxValue = {0, 0};
    
    for (map<int, int>::iterator atual = sequence.begin(); atual != sequence.end(); atual++){
        if (atual->second > maxValue.second){
            maxValue = {atual->first, atual->second};
        }
    }

    cout << maxValue.second << endl;

    return 0;
}