#include "math_utils.h"
#include <iostream>

/**
 * @brief get_roots: Given a set of coefficient representing the coefficient of a polynomial going
 * smallest degree to greatest degree, solve for the roots of the equation
 * @param coeffs Coefficient of the polynomial to solve
 * Should have following form:
 *      c_0 + c_1 x + c_2 x^2 ... + c_(n-1) x^(n-1)
 *      coeffs = [c_0, c_1, ... , c_(n-1)]
 * @return roots of the polynomial in a complex-valued vector
 */
cx_vec get_roots(vector<double> coeffs)
{
    cx_vec results;
    int n = coeffs.size() - 1;


    // Construct the companion matrix
    cx_mat comp_mat = cx_mat(n,n, fill::zeros);
    for (int i = 1; i < n; ++i) {
        comp_mat(i, i - 1) = 1;

        // Fill the right-side with the coefficients
        comp_mat(i - 1, n - 1) = -coeffs[i - 1] / coeffs[coeffs.size() - 1]; // Normalize coefficients
    }

    //comp_mat.print();

    // Compute the roots via eigenvalue solver
    eig_gen(results, comp_mat);

    return results;
}

/**
int main()
{
    vector<double> a = {1, 0, 1};
    cx_vec roots;

    cout << "a:";
    for (const auto i: a) {
        cout << i << ", ";
    }
    cout << endl;

    cout << "solving..." << endl;

    roots = get_roots(a);



    for (const complex<double> i: roots)
    {
        cout << real(i) << " + " << imag(i) << 'i' << endl;
    }

    cout << endl;
}
**/
