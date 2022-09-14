#include <iostream>
#include <iomanip>
//#include <stdlib.h>
//#include <conio.h>
#include <math.h>

using namespace std;

float x_low,x_up,x_mid_new,x_mid_old;


float f(float x){
    return x*x-3;
}

void make_limit(){
    if(f(x_mid_new)>0){
        x_up=x_mid_new;
    }
    else{
        x_low=x_mid_new;
    }
}
float find_error(){
    float error=fabs(x_mid_new-x_mid_old)/x_mid_new;
    return error;
}
void bisection(){
    float error=1;
    while(error>=0.005){
        x_mid_old=x_mid_new;
        x_mid_new=((x_low+x_up)/2.0);

        error=find_error();
        cout<<setw(15)<<x_low<<setw(15)<<f(x_low)<<setw(15)<<x_up<<setw(15)<<f(x_up)<<setw(15)<<x_mid_new<<
        setw(15)<<f(x_mid_new)<<setw(15)<<error<<"\n" ;
        make_limit();

    }
    return;
}

int main(){
  /// cin>>a>>b>>c>>d;

    do{
        cout<<"enter initial guess:";
        cin>>x_low>>x_up;
    }
    while(f(x_low)*f(x_up)>0);
    cout << setw(15) <<"xl"<< setw(15)<<"f(xl)"<<setw(15)<<"xu"<<setw(15)<<"f(xu)"<<setw(15)<<"xm"<<setw(15)<<"f(xm)"<<setw(15)<<"error" <<"\n";

    bisection();
    cout << setw(15) << "Root is: "<< x_mid_new <<"\n";
    return 0;
}
