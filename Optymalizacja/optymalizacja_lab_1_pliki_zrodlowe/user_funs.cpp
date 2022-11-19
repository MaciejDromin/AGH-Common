#include"user_funs.h"
#include <math.h>

matrix ff(matrix x, matrix ud1, matrix ud2){
    matrix y;
    y = -cos(0.1 * x()) * exp(-pow(0.1 * x() - 2 * M_PI,2)) + 0.002 * pow(0.1 * x(),2);
    return y;
}
matrix df(double t, double a, double b, double g, matrix ud1, matrix ud2,matrix Y){
    matrix dY(3,1);
    double PA;
    double PB;
    double DB;
    double fin;
    double Tin;
    double Ta;
    double faout = a*b*m2d(ud2)*sqrt(2*g*Y(0)/PA);
    double fbout = a*b*DB*sqrt(2*g*Y(1)/PB);

    dY(0) = -faout;
    dY(1) = faout+fin-fbout;
    dY(2) = fin/Y(1)*(Tin-Y(2))+((faout/Y(1))*(Ta-Y(2)));
    
    return dY;
}
matrix fR(matrix x, matrix ud1, matrix ud2){
    double y;
    matrix Y0 = matrix(3,new double[3]{5,1,10});
    matrix *Y = solve_ode(df,0,1,1000,Y0,ud1,x);
    int n = get_len(Y[0]);
    double max = Y[1](0,2);
    for(int i=0;i<n;i++){
        if(max<Y[1](i,2)){
            max=Y[1](i,2);
        }
    }
    y=abs(max-50);
    return y;
}