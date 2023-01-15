/*********************************************
Kod stanowi uzupe�nienie materia��w do �wicze�
w ramach przedmiotu metody optymalizacji.
Kod udost�pniony na licencji CC BY-SA 3.0
Autor: dr in�. �ukasz Sztangret
Katedra Informatyki Stosowanej i Modelowania
Akademia G�rniczo-Hutnicza
*********************************************/

#include"opt_alg.h"
#include"user_funs.h"

void lab1();

void lab2();

void lab3();

void lab4();

void lab5();

using namespace std;

int main() {
    try {
        // lab1();
        lab2();
    }
    catch (string EX_INFO) {
        cerr << "ERROR:\n";
        cerr << EX_INFO << endl << endl;
    }
    system("pause");
    return 0;
}

void lab1() {
    cout << "Metoda ekspansji" << endl;
    double x0;
    double d, alpha;
    int Nmax;
    double *p;

    x0 = 100;
    d = 1, alpha = 1.1;
    Nmax = 1000;
    p = expansion(ff, x0, d, alpha, Nmax, NULL, NULL);
    cout << "wynik: [" << p[0] << " ; " << p[1] << "]" << endl;

    x0 = 100;
    d = 1, alpha = 1.5;
    Nmax = 1000;
    p = expansion(ff, x0, d, alpha, Nmax, NULL, NULL);
    cout << "wynik: [" << p[0] << " ; " << p[1] << "]" << endl;

    x0 = -100;
    d = 1, alpha = 1.5;
    Nmax = 1000;
    p = expansion(ff, x0, d, alpha, Nmax, NULL, NULL);
    cout << "wynik: [" << p[0] << " ; " << p[1] << "]" << endl;

    solution::clear_calls();

    x0 = -100;
    d = 1, alpha = 2.5;
    Nmax = 1000;
    p = expansion(ff, x0, d, alpha, Nmax, NULL, NULL);
    cout << "wynik: [" << p[0] << " ; " << p[1] << "]" << endl;

    solution::clear_calls();

    x0 = -10;
    d = 1, alpha = 2.5;
    Nmax = 1000;
    p = expansion(ff, x0, d, alpha, Nmax, NULL, NULL);
    cout << "wynik: [" << p[0] << " ; " << p[1] << "]" << endl;

    solution::clear_calls();

    x0 = 10;
    d = 1, alpha = 2.5;
    Nmax = 1000;
    p = expansion(ff, x0, d, alpha, Nmax, NULL, NULL);
    cout << "wynik: [" << p[0] << " ; " << p[1] << "]" << endl;

    solution::clear_calls();

    cout << "Metoda Fibonacziego" << endl;
    double epsilon = 1e-10;
    double gamma = 1e-200;
    Nmax = 1000;

    cout << fib(fR, 1e-4, 1e-2, epsilon) << endl;

    solution::clear_calls();

    epsilon = 1e-7;
    cout << fib(fR, 1e-4, 1e-2, epsilon) << endl;

    solution::clear_calls();

}

void lab2() {
    solution::clear_calls();

    double s = 0.5, alphaHJ = 0.5, epsilon = 1e-3;
    int Nmax = 1000;
    solution opt;
    matrix x0;

//    x0 = 2.0 * rand_mat(2, 1) - 1.0;
//    cout << "x0: " << x0 << endl << endl;
//    opt = HJ(ff2, x0, s, alphaHJ, epsilon, Nmax);
//    cout << opt << endl << endl;
//    solution::clear_calls();

    //Ramie robota
    s = 2;
    x0 = 10.0 * rand_mat(2, 1);
    cout << x0 << endl << endl;
    opt = HJ(fT2, x0, s, alphaHJ, epsilon, Nmax);
    cout << opt << endl << endl;
    solution::clear_calls();

}

void lab3() {

}

void lab4() {
    // Wywowac i sprawdzic SD, CG, Newton
}

void lab5() {

}

