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

double phi(double n)
{
    return (pow((1.0 + sqrt(5.0)) / 2.0, n) / sqrt(5.0) ) - (pow((1.0 - sqrt(5.0)) / 2.0, n) / sqrt(5.0));
}

solution fib(matrix(*ff)(matrix, matrix, matrix), double a, double b, double epsilon, matrix ud1, matrix ud2)
{
    // CORRECT VALUE FOR O1
    // x = 0.00208886
    // y = 1.15537e-07

	try
	{
		solution Xopt;
        /* double k = 0;

        // THIS APPROACH IS GIVING WEIRD VALUES
        int x=0;
        while(true){
            if(phi(x)>(b-a)/epsilon){
                k = x*1.0;
                break;
            }
            x++;
        } */

        int k = static_cast<int>(ceil(log2(sqrt(5) * (b-a)/epsilon)/log2((1 + sqrt(5))/ 2)));

        int *F = new int[k] {1, 1};
        for (int i = 2; i < k; ++i)
            F[i] = F[i-2] + F[i-1];

        solution A(a), B(b), C, D;
        C.x = B.x - 1.0 * F[k-2] / F[k-1] * (B.x - A.x);
        D.x = A.x + B.x - C.x;

        C.fit_fun(ff, ud1, ud2);
        D.fit_fun(ff, ud1, ud2);

        for (int i = 0;i<=k-3;i++) {
            if (C.y < D.y) {
                B = D;
            } else {
                A = C;
            }
            C.x = B.x - 1.0 * F[k-i-2]/F[k-i-1] * (B.x - A.x);
            D.x = A.x + B.x - C.x;
            C.fit_fun(ff, ud1, ud2);
            D.fit_fun(ff, ud1, ud2);

            ud1.add_row((B.x - A.x)());
        }

        Xopt = C;
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

/*
 * double a0 = a;
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
 * */
