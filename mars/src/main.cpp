#include <iostream>

#include <cxxopts.hpp>

int main(int argc, char **argv)
{
    cxxopts::Options options("mars", "Mars language compiler");

    // clang-format off
    options.add_options()
        ("o,output", "Output file", cxxopts::value<std::string>())
        ("v,version", "Print version")
        ("h,help", "Print usage")
        ("f,files", "Input files to compile", cxxopts::value<std::vector<std::string>>())
    ;
    // clang-format on

    options.positional_help("<FILES>");
    options.parse_positional({"files"});

    const auto result = options.parse(argc, argv);

    if (argc == 1 || result.count("help"))
    {
        options.show_positional_help();
        std::cout << options.help() << std::endl;
        return 0;
    }
    if (result.count("version"))
    {
        std::cout << "Mars version " << MARS_VERSION << std::endl;
        return 0;
    }

    if (result.count("files") == 0)
    {
        std::cerr << "No input files were specified" << std::endl;
        return 1;
    }

    for (const auto files = result["files"].as<std::vector<std::string>>(); auto &file : files)
    {
        std::cout << "Compiling: " << file << std::endl;
    }

    std::string filename = "a.out";
    if (result.count("output"))
    {
        filename = result["output"].as<std::string>();
    }
    std::cout << "Output file: " << filename << std::endl;

    return 0;
}
