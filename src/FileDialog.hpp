#ifndef FILEDIALOG_HPP
#define FILEDIALOG_HPP
#include <string>
#include <thread>
class FileDialog{
  public:
    static std::thread th;
    static void opendirectory(std::string* FilePath);
};
#endif //FILEDIALOG_HPP
