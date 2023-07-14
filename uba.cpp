#include "ops.h"
#include <cstdlib>
#include <curl/curl.h>
#include <iostream>
#include <string>
#define MAX_COMMAND_LENGTH 4096

int main(int argc, char *argv[]) {

  if (argc < 2) {
    std::cout << "Usage: uba <command> <opts>" << std::endl;
    return 1;
  }
  std::string command = std::string(argv[1]);

  if (command == "new") {
    new_c();
  }
  if (command == "register") {
    register_c(std::string(argv[2]), std::string(argv[3]));
  }

  return 0;
}
