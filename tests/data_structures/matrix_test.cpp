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
    EXPECT_EQ(m.at(0, 3), 4) << "expect value at 0,3 to be 4";
    EXPECT_EQ(m.at(1, 0), 5.5) << "expect value at 1,0 to be 5.5";
    EXPECT_EQ(m.at(1, 2), 7.5) << "expect value at 1,2 to be 7.5";
    EXPECT_EQ(m.at(2, 2), 11) << "expect value at 2,2 to be 11";
    EXPECT_EQ(m.at(3, 0), 13.5) << "expect value at 3,0 to be 13.5";
    EXPECT_EQ(m.at(3, 2), 15.5) << "expect value at 3,2 to be 15.5";
}
