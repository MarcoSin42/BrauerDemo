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
cx_mat rand_cxmat(int);

double linmap(double,double,double,double,double);

#endif // MATH_UTILS_H
