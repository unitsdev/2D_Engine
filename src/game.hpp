#ifndef GAME_HPP
#define GAME_HPP
#include <string>
namespace GAME{
  class Project{
      private:
        static void OpenPRIVATE();
      public:
        static bool GameRunning;
        static std::string ProjectDirectory;
        static bool Init();
        static void Open();
        static void Destroy();
  };
};
#endif //GAME_HPP
