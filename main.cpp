#include <iostream>

#include <spdlog/spdlog.h>

#include <Args.hpp>
#include <Definitions.hpp>
#include <PSQLWrapper.hpp>

#include <Init.hpp>

using namespace std;

int main(int argc, char* argv[]) {
    ah::Args args(argc, argv);
    args.process(ah::Args::ArgsStyle::LIKE_CMAKE);
    init::MeetXInit(args);
    std::vector<std::string> files = {"/path/to/file1.ext", "/path/to/file2.ext"};
    spdlog::log(spdlog::level::info, parsers::castMediaVector(files));
    return 0;
}
