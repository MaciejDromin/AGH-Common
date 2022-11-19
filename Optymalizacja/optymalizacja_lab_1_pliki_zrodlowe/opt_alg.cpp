#include"opt_alg.h"
matrix f(double x, matrix(*ff)(matrix, matrix, matrix), matrix ud1 = NULL, matrix ud2 = NULL) {
    solution X(x);
    matrix fg = X.fit_fun(ff, ud1, ud2);
    return fg;
}

double* expansion(matrix(*ff)(matrix, matrix, matrix), double x0, double d, double alpha, int Nmax, matrix ud1, matrix ud2)
{
    try
    {
        double* p = new double[2]{ 0, 0 };
        //Tu wpisz kod funkcji
        double i = 0;
        double x1 = x0 + d;
        if (f(x1, ff) == f(x0, ff)) {
            p[0] = x0;
            p[1] = x1;
            return p;
        }
        if (f(x1, ff) > f(x0, ff)) {
            d = -d;
            x1 = x0 + d;
            if (f(x1, ff) >= f(x0, ff)) {
                p[0] = x1;
                p[1] = x0 - d;
                return p;
            }
        }

        double xim1 = x0;
        double xi = x0;
        double xip1 = x0;

        do {
            if (i > Nmax) {
                throw ("Too many iterations");
            }
            i = i + 1;
            xim1 = xi; //poprzedni to bedzie obecny
            xi = xip1; // obecny to bedzie poprzedni powiekszony
            xip1 = x0 + pow(alpha, i) * d; //zmiane robimy jedynie w kroku naprzod
        } while (f(xi, ff) >= f(xip1, ff));

        if (d > 0) {
            p[0] = xim1;
            p[1] = xip1;
            return p;
        }

        p[0] = xip1;
        p[1] = xim1;
        return p;
    }
    catch (string ex_info)
    {
        throw ("double* expansion(...):\n" + ex_info);
    }
}

//double* expansion(matrix(*ff)(matrix, matrix, matrix), double x0, double d, double alpha, int Nmax, matrix ud1, matrix ud2)
//{
//	try
//	{
//		double* p = new double[2]{ 0,0 };
//		//Tu wpisz kod funkcji
//
//        double i=0;
//        double x1 = x0+d;
//
//        solution X0(x0),X1(x1*(x0+d));
//        matrix fx0 = X0.fit_fun(ff,ud1,ud2);
//        matrix fx1 = X1.fit_fun(ff,ud1,ud2);
//        fx0 = X0.y();
//        fx1 = X1.y();
//
//        if(fx1 == fx0){
//            p[0]=x0;
//            p[1]=x1;
//            return p;
//        }
//        if(fx1 > fx0){
//            d = -d;
//            x1 = x0+d;
//            if(fx1 >= fx0){
//                p[0] = x1;
//                p[1] = x0-d;
//                return p;
//            }
//        }
//
//        matrix fxp1;
//        matrix fxi;
//        double xp1 = x0;
//        double xm1 = x0;
//        double xi = x0;
//        do{
//            if(i > Nmax){
//                throw("Error if(i>nMax)!");
//            }
//            i = i+1;
//            xm1 = xi; //mniejsza to poprzednia
//            xi = xp1; //obecna to poprzednia większa
//            xp1 = x0 + pow(alpha, i) * d; //zwiększamy +1
//
//            solution Xi(xi);
//            fxi = Xi.fit_fun(ff,ud1,ud2);
//            solution Xp1(xp1);
//            fxp1 = Xp1.fit_fun(ff,ud1,ud2);
//            fxi = Xi.y();
//            fxp1 = Xp1.y();
//
//        }while(fxi >= fxp1);
//
//        if(d>0){
//            p[0] = xm1;
//            p[1] = xp1;
//            return p;
//        }
//        p[0] = xp1;
//        p[1] = xm1;
//		return p;
//	}
//	catch (string ex_info)
//	{
//		throw ("double* expansion(...):\n" + ex_info);
//	}
//}
double gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}


double phi(double n)
{
    return (pow((1.0 + sqrt(5.0)) / 2.0, n) / sqrt(5.0) ) - (pow((1.0 - sqrt(5.0)) / 2.0, n) / sqrt(5.0));
}

solution fib(matrix(*ff)(matrix, matrix, matrix), double a, double b, double epsilon, matrix ud1, matrix ud2)
{
	try
	{
		solution Xopt;
		//Tu wpisz kod funkcji


        //szukanie k
        double k = 0;
      //  φk > (b - a) / ε
       int x=0;

        while(2<5){
            if(phi(x)>(b-a)/epsilon){
                k = x*1.0;
                break;
            }
            x++;
        }
//if(phi(3)<=(b-a)/epsilon){
//    cout<<"True"<<endl;
//}else{
//    cout<<"False"<<endl;
//}
        //cout<<phi(7)<<endl;
        double a0 = a;
        double b0 = b;
        double c0 = b0 - phi(k-1) / phi(k)*(b0-a0);
        double d0 = a0+b0-c0;
        double ci=c0;
        double di=d0;
        double ai=a0;
        double bi=b0;
        double aip1=a0;
        double bip1=b0;
        double cip1=c0;
        double dip1=d0;
        for(int i=0; i<k-3;i++){
            if(f(ci,ff) < f(di,ff)){
                aip1 = ai;
                bip1 = di;
            }else{
                bip1 = bi;
                aip1 = ci;
            }
            cip1 = bip1 - phi(k-i-2) / phi(k-i-1)*(bip1 - aip1);
            dip1 = aip1 + bip1 - cip1;
        }
        Xopt = cip1;
		return Xopt;
	}
	catch (string ex_info)
	{
		throw ("solution fib(...):\n" + ex_info);
	}

}

solution lag(matrix(*ff)(matrix, matrix, matrix), double a, double b, double epsilon, double gamma, int Nmax, matrix ud1, matrix ud2)
{
	try
	{
		solution Xopt;
		//Tu wpisz kod funkcji

		return Xopt;
	}
	catch (string ex_info)
	{
		throw ("solution lag(...):\n" + ex_info);
	}
}

solution HJ(matrix(*ff)(matrix, matrix, matrix), matrix x0, double s, double alpha, double epsilon, int Nmax, matrix ud1, matrix ud2)
{
	try
	{
		solution Xopt;
		//Tu wpisz kod funkcji

		return Xopt;
	}
	catch (string ex_info)
	{
		throw ("solution HJ(...):\n" + ex_info);
	}
}

solution HJ_trial(matrix(*ff)(matrix, matrix, matrix), solution XB, double s, matrix ud1, matrix ud2)
{
	try
	{
		//Tu wpisz kod funkcji

		return XB;
	}
	catch (string ex_info)
	{
		throw ("solution HJ_trial(...):\n" + ex_info);
	}
}

solution Rosen(matrix(*ff)(matrix, matrix, matrix), matrix x0, matrix s0, double alpha, double beta, double epsilon, int Nmax, matrix ud1, matrix ud2)
{
	try
	{
		solution Xopt;
		//Tu wpisz kod funkcji

		return Xopt;
	}
	catch (string ex_info)
	{
		throw ("solution Rosen(...):\n" + ex_info);
	}
}

solution pen(matrix(*ff)(matrix, matrix, matrix), matrix x0, double c, double dc, double epsilon, int Nmax, matrix ud1, matrix ud2)
{
	try {
		solution Xopt;
		//Tu wpisz kod funkcji

		return Xopt;
	}
	catch (string ex_info)
	{
		throw ("solution pen(...):\n" + ex_info);
	}
}

solution sym_NM(matrix(*ff)(matrix, matrix, matrix), matrix x0, double s, double alpha, double beta, double gamma, double delta, double epsilon, int Nmax, matrix ud1, matrix ud2)
{
	try
	{
		solution Xopt;
		//Tu wpisz kod funkcji

		return Xopt;
	}
	catch (string ex_info)
	{
		throw ("solution sym_NM(...):\n" + ex_info);
	}
}

solution SD(matrix(*ff)(matrix, matrix, matrix), matrix(*gf)(matrix, matrix, matrix), matrix x0, double h0, double epsilon, int Nmax, matrix ud1, matrix ud2)
{
	try
	{
		solution Xopt;
		//Tu wpisz kod funkcji

		return Xopt;
	}
	catch (string ex_info)
	{
		throw ("solution SD(...):\n" + ex_info);
	}
}

solution CG(matrix(*ff)(matrix, matrix, matrix), matrix(*gf)(matrix, matrix, matrix), matrix x0, double h0, double epsilon, int Nmax, matrix ud1, matrix ud2)
{
	try
	{
		solution Xopt;
		//Tu wpisz kod funkcji

		return Xopt;
	}
	catch (string ex_info)
	{
		throw ("solution CG(...):\n" + ex_info);
	}
}

solution Newton(matrix(*ff)(matrix, matrix, matrix), matrix(*gf)(matrix, matrix, matrix),
	matrix(*Hf)(matrix, matrix, matrix), matrix x0, double h0, double epsilon, int Nmax, matrix ud1, matrix ud2)
{
	try
	{
		solution Xopt;
		//Tu wpisz kod funkcji

		return Xopt;
	}
	catch (string ex_info)
	{
		throw ("solution Newton(...):\n" + ex_info);
	}
}

solution golden(matrix(*ff)(matrix, matrix, matrix), double a, double b, double epsilon, int Nmax, matrix ud1, matrix ud2)
{
	try
	{
		solution Xopt;
		//Tu wpisz kod funkcji

		return Xopt;
	}
	catch (string ex_info)
	{
		throw ("solution golden(...):\n" + ex_info);
	}
}

solution EA(matrix(*ff)(matrix, matrix, matrix), int N, matrix limits, int mi, int lambda, matrix sigma0, double epsilon, int Nmax, matrix ud1, matrix ud2)
{
	try
	{
		solution Xopt;
		//Tu wpisz kod funkcji

		return Xopt;
	}
	catch (string ex_info)
	{
		throw ("solution EA(...):\n" + ex_info);
	}
}
