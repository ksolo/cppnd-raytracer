#ifndef MATRIX_H
#define MATRIX_H

#include <vector>

namespace raytracer
{
class matrix
{
    static constexpr double epsilon = 0.0001;
    const std::vector<std::vector<double>>& _data;
    bool epsilon_compare(double a, double b);
public:
    // constructor
    matrix(const std::vector<std::vector<double>>& data);

    // operator overloads

    bool operator==(const matrix& rhs);


    // value of the item at provided row, col
    double at(int row, int col) const;
};
}

#endif
