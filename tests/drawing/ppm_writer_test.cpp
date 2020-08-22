#include "gtest/gtest.h"

#include <filesystem>
#include <fstream>
#include <memory>

#include "data_structures/color.h"
#include "drawing/ppm_writer.h"
#include "drawing/canvas.h"

TEST(PPM_WRITER_TEST, test_initialization)
{
    std::unique_ptr<raytracer::canvas> canvas = std::make_unique<raytracer::canvas>(10, 10);
    std::string output_file("outfile.ppm");
    raytracer::ppm_writer writer(output_file, std::move(canvas));

    std::fstream out(output_file);
    EXPECT_TRUE(out);

    std::filesystem::path path(output_file);
    std::filesystem::remove(path);
}

TEST(PPM_WRITER_TEST, test_header_output)
{
    std::unique_ptr<raytracer::canvas> canvas = std::make_unique<raytracer::canvas>(10, 10);
    std::string output_file("outfile.ppm");
    raytracer::ppm_writer writer(output_file, std::move(canvas));

    writer.generate_image();
    std::fstream generated_file(output_file);
    std::string line;

    for (size_t i = 0; i < 3; i++)
    {
        getline(generated_file, line);
        if (i == 0) { EXPECT_EQ(line, "P3"); }
        if (i == 1) { EXPECT_EQ(line, "10 10"); }
        if (i == 2) { EXPECT_EQ(line, "255"); }
    }

    std::filesystem::path path(output_file);
    std::filesystem::remove(path);
}

TEST(PPM_WRITER_TEST, test_body_output)
{
    std::unique_ptr<raytracer::canvas> canvas = std::make_unique<raytracer::canvas>(10, 10);
    raytracer::color red(1, 0, 0);
    raytracer::color green(0, 1, 0);
    raytracer::color blue(0, 0, 1);
    canvas->write_pixel(0,0, red);
    canvas->write_pixel(4,5, green);
    canvas->write_pixel(9,9, blue);

    std::string output_file("outfile.ppm");
    raytracer::ppm_writer writer(output_file, std::move(canvas));

    writer.generate_image();
    std::fstream generated_file(output_file);
    std::string line;

    for (size_t i = 0; i < 23; i++)
    {
        getline(generated_file, line);
        if (i < 3) { continue; }
        if (i == 3) { EXPECT_EQ(line, "255 0 0 0 0 0 0 0 0 0 0 0 0 0 0"); }
        if (i < 13) { continue ;}
        if (i == 13) { EXPECT_EQ(line, "0 0 0 0 0 0 0 0 0 0 0 0 0 255 0"); }
        if (i < 23) { continue ;}
        if (i == 23) { EXPECT_EQ(line, "0 0 0 0 0 0 0 0 0 0 0 0 0 0 255"); }
    }

    std::filesystem::path path(output_file);
    std::filesystem::remove(path);
}

