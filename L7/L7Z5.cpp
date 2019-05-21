#include <iostream>
#include <vector>

using namespace std;

class Union_Find {
    public:
        Union_Find(int n): _parent(n),_rank(n, 0){
            for(int i=0; i<n; ++i)
                _parent[i] = i;
        }
    
        int find(int i){
            //kompresja ścieżek
            if(_parent[i] == i) // szukanie korzenia
                return i;
            _parent[i] = find(_parent[i]);
            return _parent[i];
        }
    
        void Union(int i, int j){
            if(_parent[i] == _parent[j])
                return;
            int fa = find(i);
            int fb = find(j);
            //przypisanie po randze
            if(fa!=fb){
                if(_rank[fa] < _rank[fb])
                    _parent[fa] = fb; // złączenie wysp
                else {
                    _parent[fb] = fa;
                    if(_rank[fa] == _rank[fb])
                        _rank[fa]++; // lub zwiększenie rangi
                }
            }
        }
    private:
        vector<int> _parent;
        vector<int> _rank;
};

int main(){
    bool ta[5][5] =
    {
        {1,1,0,0,0},
        {1,1,0,0,0},
        {1,1,0,0,0},
        {1,1,0,0,0},
        {1,1,0,0,1}
    };
    bool tb[5][5] =
    {
        {1,1,0,0,0},
        {1,1,0,0,0},
        {1,1,1,1,0},
        {1,1,0,1,0},
        {1,1,0,1,1}
    };
    return 0;
}
