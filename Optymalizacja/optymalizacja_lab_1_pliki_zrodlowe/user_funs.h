#pragma once

#include"ode_solver.h"
matrix ff(matrix x, matrix ud1, matrix ud2);
matrix df(double t, matrix y, matrix ud1, matrix ud2);
matrix fR(matrix x, matrix ud1, matrix ud2);
