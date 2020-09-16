#include "data_structures/matrix.h"

namespace raytracer
{
    matrix::matrix(const std::vector<std::vector<double>> &data) : _data(data) {};
    double matrix::at(int row, int col) const
    {
        return _data[row][col];
    }
}
