#include <bits/stdc++.h>
#include <vector>

using namespace std;

int search_tallest(vector<vector<int>> skyline, int n, int m){
    for(int i = 0; i < n; i++){
        for(int a = 0; a < m; a++){
             if(skyline[i][a] == 0)  
                return a;  
        }
    }
    throw invalid_argument("There are no buildings in the matrix.");
}

int main(){
    //O(m+n)
    //variables para input
    int n = 5; //this is length of data
    int m = 6;
    vector<vector<int>> skyline = {{1,1,1,1,1,1},
                                   {1,1,1,1,1,1},
                                   {1,1,1,1,1,1},
                                   {1,1,1,1,1,1},
                                   {1,1,1,1,1,1}};
            
    int tallest_building_pos = search_tallest(skyline, n, m);
    cout << "The tallest building is in location: " << tallest_building_pos;
    return 0;
    }
