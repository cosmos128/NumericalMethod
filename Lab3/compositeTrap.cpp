#include <iostream>
#include <cmath>
#define e 2.718

using namespace std;

float f(int x){
    return pow(e, -x);
}

float comTrapezoidal(int l, int u, int n){
    float I, h, x = l;

    h = (u - l)/n;
    I = f(x);
    for(int i = 1; i <= n-1; i++){
        x += h;
        I += (2 * f(x));
    }
    
    I += f(u);
    // cout << i <<"\t" << h;
    return (h * I)/2.0;
}

int main(){
    int l,u, n;
    cout <<"Enter lower bound: "; 
    cin >> l;
    cout << "Enter upper bound: ";
    cin >> u;
    cout << "Enter no of divisions: ";
    cin >> n;

    cout << "\nI: "<< comTrapezoidal(l, u, n);
    return 0;
}