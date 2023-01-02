#include"user_funs.h"
#include"ode_solver.h"
#include <math.h>

matrix ff(matrix x, matrix ud1, matrix ud2){
    matrix y;
    y = -cos(0.1 * x()) * exp(-pow(0.1 * x() - 2 * M_PI,2)) + 0.002 * pow(0.1 * x(),2);
    return y;
}

matrix df(double t, matrix y, matrix ud1, matrix ud2){
    double a = 0.98, b = 0.63, g = 9.81, PA = 0.75, TA = 90.0, PB = 1.0, DB = 0.00365665, Fin = 0.01, Tin = 10.0;

    matrix dY(3, 1);
    double FAout = a * b * m2d(ud2) * sqrt(2 * g * y(0) / PA);
    double FBout = a * b * DB * sqrt(2 * g * y(1) / PB);
    dY(0) = -FAout;
    dY(1) = FAout + Fin - FBout;
    dY(2) = ( Fin / y(1) ) * (Tin - y(2)) + ( FAout / y(1) ) * (TA - y(2));

    return dY;
}

matrix fR(matrix x, matrix ud1, matrix ud2){
    double y;
    matrix Y0 = matrix(3, new double[3]{ 5,1,10 });
    matrix* Y = solve_ode(df, 0, 1, 1000, Y0, ud1, x);
    int n = get_len(Y[0]);
    double max = Y[1](0, 2);
    for (int i = 0; i < n; i++)
        if (max < Y[1](i, 2)) max = Y[1](i, 2);
    y = abs(max - 50);
    return y;
}

matrix ff2(matrix x, matrix ud1, matrix ud2){
    matrix y;
    y = pow(x(0), 2) + pow(x(1), 2) - cos(2.5 * 3.14 * x(1)) - cos(2.5 * 3.14 * x(1)) + 2;
    return y;
}

matrix df2(double t, matrix y, matrix ud1, matrix ud2) {
    double mr = 1, mc = 9, l = 0.5, b = 0.5;
    double I = mr * l * l / 3.0 + mc * l * l;
    matrix dY(2,1);
    dY(0) = y(1);
    dY(1) = (ud2(0) * (ud1(0) - y(0)) + ud2(1)*(ud1(1) - y(1)) - b * y(1) ) / I;
    return dY;
}

matrix fT2(matrix x, matrix ud1, matrix ud2) {
    matrix y;
    matrix y0(2,1), y_ref(2, new double[2]{3.14,0});
    matrix* Y = solve_ode(df2, 0, 0.1, 100, y0, y_ref, x);
    y = 0;
    int n = get_len(Y[0]);
    for (int i = 0;i<n;i++) {
        y = y + 10 * pow(y_ref(0)-Y[1](i,0), 2)
            + pow(y_ref(1) - Y[1](i,1), 2)
            + pow(x(0) * (y_ref(0) - Y[1](i,0)) + x(1) * (y_ref(1) - Y[1](i,1)), 2);
    }
    y = y * 0.1;
    return y;
}