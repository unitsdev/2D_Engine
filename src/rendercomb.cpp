#include "Application.hpp"
#include "AppIMGui.hpp"
#include "rendercomb.hpp"
#include "Scene.hpp"
void MRender::Render(){
    
    AImGui::Render();
    App::Render();
    Scene::Render();

    ImGui_ImplSDLRenderer2_RenderDrawData(ImGui::GetDrawData(),App::GetRenderer());
    SDL_RenderPresent(App::GetRenderer());
}
