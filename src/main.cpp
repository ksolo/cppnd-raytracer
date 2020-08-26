#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "data_structures/color.h"
#include "data_structures/tuple.h"
#include "drawing/canvas.h"
#include "drawing/ppm_writer.h"

struct projectile
{
    raytracer::tuple position;
    raytracer::tuple velocity;
};

struct environment
{
    raytracer::tuple wind;
    raytracer::tuple gravity;
};

projectile tick(environment env, projectile p)
{
    return projectile { (p.position + p.velocity), (p.velocity + env.gravity + env.wind) };
}

int main()
{
    raytracer::tuple starting_position = raytracer::tuple::point(0,1,0);
    raytracer::tuple initial_velocity = raytracer::tuple::vector(1, 1.8, 0).normalize() * 11.25;
    projectile p { starting_position, initial_velocity };

    raytracer::tuple wind = raytracer::tuple::vector(-0.01, 0, 0);
    raytracer::tuple gravity = raytracer::tuple::vector(0, -1.0, 0);
    environment env { wind, gravity };

    const int width = 360;
    const int height = 180;
    std::unique_ptr<raytracer::canvas> can = std::make_unique<raytracer::canvas>(width, height);

    std::vector<projectile> path { p };
    while(p.position.y() > 0)
    {
        std::cout << "position x: " << p.position.x() << " position y: " << p.position.y() << std::endl;
        p = tick(env, p);
        path.push_back(p);
    }

    raytracer::color red(1, 0, 0);
    for (auto proj : path)
    {
        if (proj.position.y() < height && proj.position.y() > 0)
            can->write_pixel(proj.position.x(), height - proj.position.y(), red);
    }

    std::string outfile = "cannon.ppm";
    raytracer::ppm_writer writer(outfile, std::move(can));
    writer.generate_image();
    return 0;
}
