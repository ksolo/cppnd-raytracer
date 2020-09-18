#include "gtest/gtest.h"

#include "data_structures/matrix.h"

TEST(MATRIX_TEST, initializing_4x4_matrix)
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

TEST(MATRIX_TEST, initializing_2x2_matrix)
{
    std::vector<std::vector<double>> data {
        { -3, 5 },
        { 1, -2 }
    };

    raytracer::matrix m(data);
    EXPECT_EQ(m.at(0, 0), -3) << "expect value at 0,0 to be -3";
    EXPECT_EQ(m.at(0, 1), 5) << "expect value at 0,1 to be 5";
    EXPECT_EQ(m.at(1, 0), 1) << "expect value at 1,0 to be 1";
    EXPECT_EQ(m.at(1, 1), -2) << "expect value at 0,1 to be -2";
}

TEST(MATRIX_TEST, initializing_3x3_matrix)
{
    std::vector<std::vector<double>> data {
        { -3, 5, 0 },
        { 1, -2, -7 },
        { 0, 1, 1 }
    };

    raytracer::matrix m(data);
    EXPECT_EQ(m.at(0, 0), -3) << "expect value at 0,0 to be -3";
    EXPECT_EQ(m.at(1, 1), -2) << "expect value at 1,1 to be -2";
    EXPECT_EQ(m.at(2, 2), 1) << "expect value at 2,2 to be 1";
}
