#ifndef APPIMGUI_HPP
#define APPIMGUI_HPP
#include "Application.hpp"
#include <imgui.h>
#include <imgui_impl_sdl2.h>
#include <imgui_impl_sdlrenderer2.h>
class AImGui{
  public:
    static void Init();
    static void Destroy();
    static void Render();
};
#endif //APPIMGUI_HPP

