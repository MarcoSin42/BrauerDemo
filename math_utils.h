#include <armadillo>
#include <QPolygon>
#include <complex>

using namespace std;
using namespace arma;

#ifndef MATH_UTILS_H
#define MATH_UTILS_H


cx_vec get_roots(vector<double>);

QPolygon *get_brauer(complex<double>, complex<double>);
cx_vec off_diag_sum(cx_mat);
#endif // MATH_UTILS_H
