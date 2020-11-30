#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> v;


int solution(int m, int n, vector<vector<int>> puddles) {
    v.resize(n,vector<int> (m,0));
    for(int i=0;i<puddles.size();i++)v[puddles[i][1]-1][puddles[i][0]-1]=-1;
    for(int i=0;i<n;i++) {
        if(v[i][0]!=-1) v[i][0]=1;
        else break;
    }    
    for(int i=0;i<m;i++){
        if(v[0][i]!=-1) v[0][i]=1;
        else break;
    }
    for(int x=0; x<m; x++){
        for(int y=0;y<n;y++){
            if(v[y][x]) continue;
            if(v[y-1][x]!=-1) v[y][x]+=v[y-1][x];
            if(v[y][x-1]!=-1) v[y][x]+=v[y][x-1];
            v[y][x]%=1000000007;
        }
    }
    return v[n-1][m-1];
}

int main(){
    vector<vector <int>> puddles(1, vector<int> (2,0)); //물웅덩이
    puddles[0][0]=2;
    puddles[0][1]=2;
    v.resize(4,vector<int> (3,0));
    cout<<solution(4,3,puddles);
}