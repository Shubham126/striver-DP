#include<bits/stdc++.h>
using namespace std;

int fibbonaci(int a){

    if(a == 1 or a == 0){
        return a;
    }
    
    return fibbonaci(a-1) + fibbonaci(a-2);
}

int main(){

    int a;
    cin>> a;

    cout<<fibbonaci(a);

    return 0;
}