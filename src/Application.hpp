#ifndef APPLICATION_HPP
#define APPLICATION_HPP 
#include <SDL2/SDL.h>
#include "TITLES.hpp"
class App{
  private:
    static constexpr int INITIALWIDTH = 900;
    static constexpr int INITIALHEIGHT = 900;
    static SDL_Window* window;
    static SDL_Renderer* renderer;
    static bool running;
  public:
    static float ScaleX;
    static float ScaleY;
    static int WIDTH;
    static int HEIGHT;
    static SDL_Event event;
    static void Init();
    static void Destroy();
    static void Render();
    static void Event();
    static bool Closed();
    static void Close();
    static SDL_Renderer* GetRenderer();
    static SDL_Window* GetWindow();
};
#endif //APPLICATION_HPP
