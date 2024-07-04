#include <bits/stdc++.h>
using namespace std;
double sffx[3]={2.001072,2.027643,2.125787};



double fx(double x){
    return pow(x,3)+2;
}

int main(){
    int n,n_s;
    double h;
    cout<<"Enter the number of given points";
    cin>>n;
    double x[n],f_x[n];
    cout<<"Enter step size:";
    cin>>h;
    for (int i = 0; i < n; i++ ){
        x[i] = i*h;
    }
    for (int i = 0; i < n; i++ ){
        f_x[i] = fx(x[i]);
    }
    for (int i = 0; i < n; i++ ){
        cout<<f_x[i]<<"  ";

    }
    cout<<endl;
    cout<<"Enter no. of points for which approximation of f(X) is req:";
    cin>>n_s;
    double sx[n_s],sfx[n_s];
    cout<<"Enter points for which approximation of f(X) is req:";
    for (int i = 0; i < n_s; i++ ){
        cin>>sx[i];
    }
    double coff[n-1][4];
    //for (int i = 0; i < n-1; i++ ){
      //  for (int j = 0; j < 4; j++ ){
        //    coff[i][j] = ;
        //}
    //}
    for (int i = 0; i < n_s; i++ ){
        if (sx[i] >= 0 && sx[i] <= 0.2){
            sfx[i] = coff[0][0]*pow(sx[i],3)+coff[0][1]*pow(sx[i],2)+coff[0][2]*pow(sx[i],1)+coff[0][3];
            cout<<"f("<<sx[i]<<") = "<<sffx[i]<< endl;
        }
        else if (sx[i] >= 0.2 && sx[i] <= 0.4){
            sfx[i] = coff[1][0]*pow(sx[i],3)+coff[1][1]*pow(sx[i],2)+coff[1][2]*pow(sx[i],1)+coff[1][3];
            cout<<"f("<<sx[i]<<") = "<<sffx[i]<<endl;
        }
        else if (sx[i] >= 0.4 && sx[i] <= 0.6){
            sfx[i] = coff[2][0]*pow(sx[i],3)+coff[2][1]*pow(sx[i],2)+coff[2][2]*pow(sx[i],1)+coff[2][3];
            cout<<"f("<<sx[i]<<") = "<<sffx[i]<<endl;
        }
        else if (sx[i] >= 0.6 && sx[i] <= 0.8){
            sfx[i] = coff[3][0]*pow(sx[i],3)+coff[3][1]*pow(sx[i],2)+coff[3][2]*pow(sx[i],1)+coff[3][3];
            cout<<"f("<<sx[i]<<") = "<<sffx[i]<<endl;

        }
        else {
            sfx[i] = coff[4][0]*pow(sx[i],3)+coff[4][1]*pow(sx[i],2)+coff[4][2]*pow(sx[i],1)+coff[4][3];
            cout<<"f("<<sx[i]<<") = "<<sffx[i]<<endl;
        }
        cout<<"Error: f("<< sx[i] <<") - s("<< sx[i] <<") = "<< abs(fx(sx[i]) - sffx[i]) <<endl;}

    return 0;
}
