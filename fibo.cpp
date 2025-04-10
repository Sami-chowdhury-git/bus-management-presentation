#include<bits/stdc++.h>
using namespace std;
int fib(int x){
if(x==0 || x==1){
    return x;
}
else{
    return fib(x-1)+fib(x-2);
}
}
int main(){
int x;
cin>>x;
if(x<0){
    return 0;
}
else{
    int num= fib(x);
    cout<<num<< " ";
}
return 0;
}
