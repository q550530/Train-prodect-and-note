#include <iostream>

using namespace std;
struct Comp
{
    int real=0;
    int image=0;
    int squimage=0;

};

Comp adder(Comp aa,Comp ab) {
    Comp temp;
    temp.real = aa.real + ab.real;
    temp.image = aa.image + ab.image;
    return temp;

}

Comp min(Comp aa, Comp ab) {
    Comp temp;
    temp.real = aa.real - ab.real;
    temp.image = aa.image - ab.image;
    return temp;

}

Comp multiply(Comp ma,Comp mb) {
    Comp temp;
    
    
    temp.real = ma.real * mb.real;
    temp.image = ma.image * mb.real + mb.real*ma.image;
    temp.squimage = ma.image * mb.image;
    return temp;

}

void vShow(Comp va,Comp vb, Comp ans,int type) {
     cout << endl;
     cout << "(" << va.real << "+" << va.image << "i)" << "\0";
     switch (type)
     {
     case 0:
         cout << "+" << '\0';
         cout << "(" << vb.real << "+" << vb.image << "i)=(" << ans.real << "+" << ans.image << "i)"<< endl;
         break;
     case 1:
         cout << "-" << '\0';
         if (ans.image>0)
                 cout << "(" << vb.real << "+" << vb.image << "i)=(" << ans.real << "+" << ans.image << "i)" << endl;
         else
         {
             cout << "(" << vb.real << "+" << vb.image << "i)=(" << ans.real << ans.image << "i)" << endl;
         }
         break;
     case 2:
         cout << "*" << '\0';
         cout << "(" << vb.real << "+" << vb.image << "i)=(" << ans.real << "+" << ans.image << "i+" << ans.squimage << "i^2)" << "\0" << endl;
         break;
         
     }
     

}


int main()
{
    Comp a,b,cAns,dAns,eAns;
    a.real = 2;
    a.image = 3;
    b.real = 4;
    b.image = 5;
    cAns = adder(a,b);
    vShow(a,b,cAns,0);
    dAns = min(a,b);
    vShow(a, b, dAns, 1);
    eAns = multiply(a, b);
    vShow(a, b, eAns, 2);

    system("pause");
    return 0;
}
