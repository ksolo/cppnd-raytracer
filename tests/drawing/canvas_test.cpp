#include "gtest/gtest.h"
#include "drawing/canvas.h"

TEST(CANVAS_TEST, test_sets_width_and_height)
{
    raytracer::canvas canvas_one(10, 20);
    EXPECT_EQ(canvas_one.width(), 10);
    EXPECT_EQ(canvas_one.height(), 20);
}
