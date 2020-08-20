#include "gtest/gtest.h"

#include <filesystem>
#include <fstream>
#include <memory>

#include "drawing/ppm_writer.h"
#include "drawing/canvas.h"

TEST(PPM_WRITER_TEST, test_initialization)
{
    std::unique_ptr<raytracer::canvas> canvas = std::make_unique<raytracer::canvas>(10, 20);
    std::string output_file("outfile.ppm");
    raytracer::ppm_writer writer(output_file, std::move(canvas));

    std::fstream out(output_file);
    EXPECT_TRUE(out);

    std::filesystem::path path(output_file);
    std::filesystem::remove(path);
}

TEST(PPM_WRITER_TEST, test_header_output)
{
    std::unique_ptr<raytracer::canvas> canvas = std::make_unique<raytracer::canvas>(10, 20);
    std::string output_file("outfile.ppm");
    raytracer::ppm_writer writer(output_file, std::move(canvas));

    writer.generate_image();
    std::fstream generated_file(output_file);
    std::string line;

    for (size_t i = 0; i < 3; i++)
    {
        getline(generated_file, line);
        if (i == 0) { EXPECT_EQ(line, "P3"); }
        if (i == 1) { EXPECT_EQ(line, "10 20"); }
        if (i == 2) { EXPECT_EQ(line, "255"); }
    }

    std::filesystem::path path(output_file);
    std::filesystem::remove(path);
}

