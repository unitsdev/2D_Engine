#include "AppIMGui.hpp"
#include "Scene.hpp"
#include "game.hpp"
#include <iostream>
using namespace std;
void AImGui::Init(){
  IMGUI_CHECKVERSION();
  ImGui::CreateContext();
  ImGuiIO& io = ImGui::GetIO(); (void)io;
  ImGui::GetIO().ConfigFlags = ImGuiConfigFlags_DockingEnable;
  ImGui::GetIO().ConfigDockingAlwaysTabBar;
  ImGui::StyleColorsDark();
  ImGui_ImplSDL2_InitForSDLRenderer(App::GetWindow(), App::GetRenderer());
  ImGui_ImplSDLRenderer2_Init(App::GetRenderer());
}
void AImGui::Destroy(){
  ImGui_ImplSDLRenderer2_Shutdown();
  ImGui_ImplSDL2_Shutdown();
  ImGui::DestroyContext();
}
void AImGui::Render(){
  ImGui_ImplSDLRenderer2_NewFrame();
  ImGui_ImplSDL2_NewFrame();
  ImGui::NewFrame();
 ImGuiID dockspace = ImGui::DockSpaceOverViewport(0, ImGui::GetMainViewport(),ImGuiDockNodeFlags_PassthruCentralNode);

  //ImGui::SetNextWindowDockID(dockspace);
  //ImGui::SetNextWindowPos(ImVec2(App::WIDTH-260,0));
  if (ImGui::BeginMainMenuBar()) {
    if (ImGui::BeginMenu("File")) {
      if(ImGui::MenuItem(TITLES::MENUBAR::CREATEPROJECT)){

      }
      if(ImGui::MenuItem(TITLES::MENUBAR::OPENPROJECT)){
        GAME::Project::Open();
      }
      if(ImGui::MenuItem(TITLES::MENUBAR::SAVEPROJECT)){

      }
      if(ImGui::MenuItem(TITLES::MENUBAR::CLOSE)){
        App::Close();
      }
      
      ImGui::EndMenu();
    }
    string text = GAME::Project::GameRunning ? "Stop" : "Play";
    int windowWidth = ImGui::GetWindowSize().x/2;
    int textWidth = ImGui::CalcTextSize(text.c_str()).x;
    ImGui::SetCursorPosX(windowWidth-textWidth);
    if(ImGui::Button(text.c_str())){
        GAME::Project::GameRunning = !GAME::Project::GameRunning;
        if(GAME::Project::GameRunning==true){
            GAME::Scene::Open();
        }
        else if(GAME::Project::GameRunning == false){
          GAME::Scene::Close();
        }

    }
    ImGui::EndMainMenuBar();
  }
  ImGui::Begin(TITLES::SCENEMANAGER);
  ImGui::End();
  ImGui::Begin(TITLES::EXPLORER);
  ImGui::End();
  ImGui::Begin(TITLES::SCENE,nullptr,8 | 16);
  static int oldw,oldh;
  int w = ImGui::GetWindowSize().x;
  int h = ImGui::GetWindowSize().y-10;
  if(oldw != w || oldh != h){
    Scene::Update(w,h);
    oldw = w;
    oldh = h;
  }
  if(ImGui::IsWindowFocused()){
    Scene::Active = true;
  }else{
    Scene::Active=false;
  }
  ImGui::SetCursorPos(ImVec2{0,10});
  ImGui::Image((ImTextureID)Scene::Texture, { float(w), float(h) });
  ImGui::End();
  ImGui::Render();
}
