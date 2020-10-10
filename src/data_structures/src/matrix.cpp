#include <cmath>

#include <iostream>

#include "data_structures/matrix.h"

namespace raytracer
{
    matrix::matrix(const std::vector<std::vector<double>> data) : _data(data) {};

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
        std::vector<std::vector<double>> data;
        for (size_t ri=0; ri < _data.size(); ri++)
        {
            std::vector<double> row;
            for (size_t ci=0; ci < _data[ri].size(); ci++)
            {
                auto col = rhs.column(ci);
                row.push_back(product(_data[ri], col));
            }
        }
        return matrix(data);
    }

    std::string matrix::to_str()
    {
        std::string result = "";
        for (auto row : _data)
        {
            for (auto colval : row)
            {
                result.append(std::to_string(colval));
            }
            result.append("\n");
        }
        return result;
    }

    // private
    double matrix::product(std::vector<double> &row, std::vector<double> &col)
    {
        double sum{0};
        for(size_t i=0; i < row.size(); i++)
            sum += row[i] * col[i];
        return sum;
    }

    bool matrix::epsilon_compare(double a, double b)
    {
        return std::abs(a - b) <= epsilon;
    }

    std::vector<double> matrix::column(int index) const
    {
        std::vector<double> result;
        for (auto& row : _data)
        {
            result.push_back(row[index]);
        }
        return result;
    }
}
