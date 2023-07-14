#include <cstdlib>
#include <iostream>
#include <string>
#define MAX_COMMAND_LENGTH 4096

int main(int argc, char *argv[]) {

  if (argc < 2) {
    std::cout << "Usage: uba <path>" << std::endl;
    return 1;
  }
  std::string filename = "temp.md";
  std::string command = "${VISUAL:-${EDITOR:-vi}} " + filename;
  if (std::system(command.c_str()) == -1) {
    std::cerr << "Error: Could not open text editor\n";
    return 1;
  }
  return 0;
}
