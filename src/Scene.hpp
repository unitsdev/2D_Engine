#ifndef SCENE_HPP
#define SCENE_HPP
#include "Application.hpp"
class Scene{
    public:
      static bool Active;
      static SDL_Event* ev;
      static SDL_Texture *Texture;
      static void Init();
      static void Update(int new_w, int new_h);
      static void SetTarget();
      static void DefaultTarget();
      static void Event();
      static void Render();
};
#endif //SCENE_HPP

