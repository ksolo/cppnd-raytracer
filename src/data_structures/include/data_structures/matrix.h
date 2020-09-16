#ifndef MATRIX_H
#define MATRIX_H

#include <vector>

namespace raytracer
{
class matrix
{
    const std::vector<std::vector<double>>& _data;
public:
    matrix(const std::vector<std::vector<double>>& data);
    double at(int row, int col) const;
};
}

#endif
