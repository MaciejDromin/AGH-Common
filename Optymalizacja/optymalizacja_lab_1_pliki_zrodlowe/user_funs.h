#pragma once

#include"ode_solver.h"
matrix ff(matrix x, matrix ud1, matrix ud2);
matrix df(double t, matrix y, matrix ud1, matrix ud2);
matrix fR(matrix x, matrix ud1, matrix ud2);
matrix ff2(matrix x, matrix ud1, matrix ud2);
matrix df2(double t, matrix y, matrix ud1, matrix ud2);
matrix fT2(matrix x, matrix ud1, matrix ud2);
matrix fT3A(matrix x, matrix ud1, matrix ud2);
matrix fT3B(matrix x, matrix ud1, matrix ud2);
matrix df3(double t, matrix x, matrix ud1, matrix ud2);
matrix fr3(matrix x, matrix ud1, matrix ud2);