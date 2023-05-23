#include <bits/stdc++.h>
#include<cmath>
using namespace std;
int main()
{
    long double L,I,Ac,Aw,Ap;
    cout<<"Enter the inductance value in henry:";
    cin>>L;
    cout<<"Enter the maximum value of current:";
    cin>>I;

    //energy calc
    long double E,K1;//energy
    E=(L*I*I)/2;
    long double J;

    cout<<"Input K1 value(factor of wire as given in sheet):";
    cin>>K1;


    //wire area
    long double a;
    cout<<"input area of wire(a) in meter:";
    cin>>a;
    //current density calc.(considering skin effect in constant K1)
    J=(I*K1)/a;



    //area product estimation:
    cout<<"Input area of cross section of core:";
    cin>>Ac;
     cout<<"Input window area:";
    cin>>Aw;
    cout<<"Area product= "<<Ac*Aw<<endl;
     Ap=Ac*Aw;



    //Max. magnetic flux estimation:
    long double K,B;//K-window utilization factor J-current density B-magneyic flux intensity
    cout<<"Enter the window utilization factor:";
    //K=0.6,generally
    cin>>K;
    B=2*E/(K*J*Ap);

    //Permeance value calculation;
    long double lembda,munot,mur,Lm,Lg;
    cout<<"Enter the absolute permeability:";
    cin>>munot;
    cout<<"relative permeability:";
    cin>>mur;
    cout<<"Enter the area of the flux flowing path:";
    cin>>Lm;
    cout<<"Enter the mean path length and airgap length:";
    cin>>Lg;

    lembda=(munot*mur*Ac)/(Lm+mur*Lg);



    //calculation of number of turns
    int N=sqrt(L/lembda);

    if((N*a)<(K*Aw))
    {
        cout<<"Number of turns "<<N<<endl;
        cout<<"Area of wire "<<a<<endl;
        cout<<"Permeance "<<lembda<<endl;
        cout<<"Energy stored "<<E<<endl;
        cout<<"Estimated area product "<<Ap<<endl;
        cout<<"Max. flux density"<<B<<endl;
    }
    else
    cout<<"Designing parameters are not favourable for design."<<endl;

    return 0;
}
