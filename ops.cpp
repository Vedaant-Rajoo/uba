#include <chrono>
#include <sstream>
#include "ops.h"

int new_c() {
  auto now = std::chrono::system_clock::now();
  auto duration = now.time_since_epoch();
  auto seconds = std::chrono::duration_cast<std::chrono::seconds>(duration);

  std::stringstream ss;
  ss << "file_" << seconds.count() << ".md";

  std::string filename = ss.str();

  std::string editor = "${VISUAL:-${EDITOR:-vi}} " + filename;

  if (system(editor.c_str()) != 0) {
    std::cout << "Error: could not open editor" << std::endl;
    return 1;
  }
  return 0;
}

int register_c(std::string username, std::string password) {
  CURL *curl = curl_easy_init();

  std::string data = "username=" + username + "&password=" + password;
  // Set the URL
  curl_easy_setopt(curl, CURLOPT_URL, "http://localhost:3000/login");

  // Specify the POST data
  curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data.c_str());

  // Perform the request, res will get the return code
  CURLcode res = curl_easy_perform(curl);

  // Check for errors
  if (res != CURLE_OK) {
    std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res)
              << std::endl;
              return 1;
  }
  return 0;
}
