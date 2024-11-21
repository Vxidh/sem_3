#include<iostream>
using namespace std;

int gcd(int n, int m){
    if(n==0) return m;
    if(m==0) return n;
    return(m, n%m);
}