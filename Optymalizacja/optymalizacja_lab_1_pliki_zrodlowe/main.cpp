/*********************************************
Kod stanowi uzupe�nienie materia��w do �wicze�
w ramach przedmiotu metody optymalizacji.
Kod udost�pniony na licencji CC BY-SA 3.0
Autor: dr in�. �ukasz Sztangret
Katedra Informatyki Stosowanej i Modelowania
Akademia G�rniczo-Hutnicza
*********************************************/

#include"opt_alg.h"

void lab1();
void lab2();
void lab3();
void lab4();
void lab5();
using namespace std;
int main()
{
	try
	{
        lab1();
	}
	catch (string EX_INFO)
	{
		cerr << "ERROR:\n";
		cerr << EX_INFO << endl << endl;
	}
	system("pause");
	return 0;
}

void lab1()
{
    cout<<"Metoda ekspansji"<<endl;
    double x0 = 100;
    double d = 1, alpha = 1.1;
    int Nmax = 1000;
    double* p = expansion(ff,x0,d,alpha,Nmax,NULL,NULL);
    cout<<"wynik: ["<<p[0]<<" ; "<<p[1]<<"]"<<endl;

//     x0 = 100;
//     d = 1, alpha = 1.1;
//     Nmax = 1000;
//    p = expansion(ff,x0,d,alpha,Nmax,NULL,NULL);
//    cout<<"wynik: ["<<p[0]<<" ; "<<p[1]<<"]"<<endl;

     x0 = 100;
     d = 1, alpha = 1.5;
     Nmax = 1000;
    p = expansion(ff,x0,d,alpha,Nmax,NULL,NULL);
    cout<<"wynik: ["<<p[0]<<" ; "<<p[1]<<"]"<<endl;

     x0 = -100;
     d = 1, alpha = 1.5;
     Nmax = 1000;
    p = expansion(ff,x0,d,alpha,Nmax,NULL,NULL);
    cout<<"wynik: ["<<p[0]<<" ; "<<p[1]<<"]"<<endl;

     x0 = -100;
     d = 1, alpha = 2.5;
     Nmax = 1000;
    p = expansion(ff,x0,d,alpha,Nmax,NULL,NULL);
    cout<<"wynik: ["<<p[0]<<" ; "<<p[1]<<"]"<<endl;

     x0 = -10;
     d = 1, alpha = 2.5;
     Nmax = 1000;
    p = expansion(ff,x0,d,alpha,Nmax,NULL,NULL);
    cout<<"wynik: ["<<p[0]<<" ; "<<p[1]<<"]"<<endl;

     x0 = 10;
     d = 1, alpha = 2.5;
     Nmax = 1000;
    p = expansion(ff,x0,d,alpha,Nmax,NULL,NULL);
    cout<<"wynik: ["<<p[0]<<" ; "<<p[1]<<"]"<<endl;

    double a = p[0];
    double b = p[1];
    cout<<"Metoda Fibonacziego"<<endl;
    
}

void lab2()
{

}

void lab3()
{

}

void lab4()
{

}

void lab5()
{

}

