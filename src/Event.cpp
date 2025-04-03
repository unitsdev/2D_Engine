#include "Application.hpp"
#include "AppIMGui.hpp"
#include "Event.hpp"
#include "Scene.hpp"
void Event::HandleEvent(){
  while(SDL_PollEvent(&App::event)){
    ImGui_ImplSDL2_ProcessEvent(&App::event);
    Scene::Active ? Scene::Event() : App::Event();
  }
}
