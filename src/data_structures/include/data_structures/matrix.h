#ifndef MATRIX_H
#define MATRIX_H

#include <string>
#include <vector>

namespace raytracer
{
class matrix
{
private:
    static constexpr double epsilon = 0.0001;
    const std::vector<std::vector<double>>& _data;
    bool epsilon_compare(double a, double b);
    std::vector<double> column(int index);
public:
    // constructor
    matrix(const std::vector<std::vector<double>>& data);

    // operator overloads

    bool operator==(const matrix& rhs);
    matrix operator*(const matrix& rhs);


    // value of the item at provided row, col
    double at(int row, int col) const;

    // easy display
    std::string to_str();
};
}

#endif
