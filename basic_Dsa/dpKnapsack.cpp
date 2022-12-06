#include <bits/stdc++.h>
using namespace std;
int max(int a, int b){
    if(a > b){
        return a;
    }
    return b;
}
int main() {
    // Write C++ code here
    vector<pair<int,int> >array;
    array.push_back(make_pair(0,0));
    int num, capacity;
    cout<<"Enter number of elements :: "<<endl;
    cin>>num;
    cout<<"Enter Maximum Capacity :: "<<endl;
    cin>>capacity;
    
    int table[50][50];
    // vector<int,int> table;
    for(int i = 1; i <= num; i++ ){
        cout<<"Enter weight of "<<i<<"th element :: "<<endl;
        int temp1,temp2;
        cin>>temp1;
        cout<<"Enter profit of "<<i<<"th element :: "<<endl;
        cin>>temp2;
        array.push_back(make_pair(temp1, temp2));
    }
    sort(array.begin(), array.end());
    // for(int i = 1; i<= num ; i++){
    //     cout<<array[i].first<<", "<<array[i].second<<endl;
    // }
    
    for(int i = 0; i<=num; i++){
        // table.push_back();
        for(int w = 0; w<=capacity; w++){
            if(i == 0 || w == 0){
                table[i][w] = 0;
            }
            else if(array[i].first < w){
                table[i][w] = max(array[i].second + table[i-1][w - array[i].first], table[i-1][w]);
            }
            else{
                table[i][w] = table[i-1][w];
            }
        }
    }
     int i = num, j = capacity;
    while(i >= 1 && j >= 0){
   
    if(table[i][j] == table[i-1][j]){
        cout<<"Element "<<i<<" not taken"<<endl;
    }
    else{
        cout<<"Element "<<i<<"  taken"<<endl;
        j -= array[i].first;
    }
    i--;
    }
    cout<<"J :: "<<j<<endl;
}