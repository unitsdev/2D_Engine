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
  };
  class Scene{
      private:
        static void* handle;
        static void Compilation();
        typedef void (*Func)();
      public:
        static Func Render;
        static void Open();
        static void Close();
  };  
};
#endif //GAME_HPP
