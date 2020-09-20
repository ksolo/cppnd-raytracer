#include <cmath>

#include <iostream>

#include "data_structures/matrix.h"

namespace raytracer
{
    matrix::matrix(const std::vector<std::vector<double>> &data) : _data(data) {};

    double matrix::at(int row, int col) const
    {
        return _data[row][col];
    }

    bool matrix::operator==(const matrix& rhs)
    {
        for (size_t i=0; i < _data.size(); i++)
        {
            for (size_t j=0; j < _data[i].size(); j++)
            {
                if (!epsilon_compare(at(i, j), rhs.at(i, j))) return false;
            }
        }
        return true;
    }

    // private

    bool matrix::epsilon_compare(double a, double b)
    {
        return std::abs(a - b) <= epsilon;
    }
}
