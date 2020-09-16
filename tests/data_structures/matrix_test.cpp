#include "gtest/gtest.h"

#include "data_structures/matrix.h"

TEST(MATRIX_TEST, initializing_matrix_with_data)
{
    std::vector<std::vector<double>> data {
        {1, 2, 3, 4},
        {5.5, 6.5, 7.5, 8.5},
        {9, 10, 11, 12},
        {13.5, 14.5, 15.5, 16.5}
    };

    raytracer::matrix m(data);
    EXPECT_EQ(m.at(0, 0), 1) << "expect value at 0,0 to be 1";
}
