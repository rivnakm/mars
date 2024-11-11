#include <iostream>

#include <cxxopts.hpp>

int main(int argc, char **argv)
{
    cxxopts::Options options("mars", "Mars language compiler");

    // clang-format off
    options.add_options()
        ("h,help", "Print usage")
    ;
    // clang-format on

    auto result = options.parse(argc, argv);

    if (argc == 1 || result.count("help"))
    {
        std::cout << options.help() << std::endl;
        exit(0);
    }

    return 0;
}
