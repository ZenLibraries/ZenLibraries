
#include "zen/po.hpp"

using namespace zen::po;

int main(int argc, const char* argv[]) {

  auto p = Program("myprog")
    .set_description("A sample program that can manage a code project")
    .set_author("Sam Vervaeck")
    .add_flag(Flag { "-C", "--work-dir" }
        .set_description("Act as if run from this directory")
        .set_metavar("DIR"))
    .add_subcommand(Subcommand { "build" }
      .set_description("Build a project or some files")
      .add_flag(Flag { "files" }
        .set_nary(true)
        .set_metavar("PATH")
        .set_description("Source files to build"))
      .add_flag(Flag { "--clean" }
        .set_is_bool(true)
        .set_description("Wether to clean intermediate artifacts before building")));

  p.parse(argc, argv);

  return 0;
}
