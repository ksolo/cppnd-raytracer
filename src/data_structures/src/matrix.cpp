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

    matrix matrix::operator*(const matrix &rhs)
    {
        std::vector<std::vector<double>> result;
        for (size_t ri=0; ri < _data.size(); ri++)
        {
            result.push_back({});
            for (size_t ci=0; ci < _data[ri].size(); ci++)
            {
                const auto& row = _data[ri];
                const auto& col = column(ci);

                double sum = 0;
                for (size_t i=0; i < row.size(); i++)
                {
                    sum += row.at(i) * col.at(i);
                }
                result.at(ri).push_back(sum);
            }
        }
        return matrix(result);
    }

    // private

    bool matrix::epsilon_compare(double a, double b)
    {
        return std::abs(a - b) <= epsilon;
    }

    std::vector<double> matrix::column(int index)
    {
        std::vector<double> result;
        for (const auto& row : _data)
        {
            result.push_back(row[index]);
        }
        return result;
    }
}
