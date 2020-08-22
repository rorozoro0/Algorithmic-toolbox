#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int compute_min_refills(int m, vector<int> & stops,int n) {
    int mstop=0,lref=0;
    for(int i=0;i<n-1;mstop++)
    {
        lref=i;
        while(stops[i+1]-stops[lref]<=m && i<n-1)
            i++;
        if(lref==i){
            return -1;
        }
    }

    return mstop-1;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);

    for (size_t i = 0; i < n; ++i)
        cin >> stops[i];
    stops.push_back(0);
    stops.push_back(d);
    sort(stops.begin(),stops.end());
    cout << compute_min_refills(m, stops,n+2) << "\n";

    return 0;
}
