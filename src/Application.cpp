#include "Application.hpp"
#include "Scene.hpp"
bool App::running = true;
int App::WIDTH = App::INITIALWIDTH;
int App::HEIGHT = App::INITIALHEIGHT;
float App::ScaleX = 1.0f;
float App::ScaleY = 1.0f;
void App::Init(){
  if(SDL_Init(SDL_INIT_EVERYTHING) < 0){
    return;
  }
  SDL_SetHint(SDL_HINT_RENDER_DRIVER, "software");
  App::window = SDL_CreateWindow(TITLES::APPNAME, SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,INITIALWIDTH,INITIALHEIGHT,SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI);
  App::renderer = SDL_CreateRenderer(window,-1,0);
  App::ScaleX = App::WIDTH/App::INITIALWIDTH;
  App::ScaleY = App::HEIGHT/App::INITIALHEIGHT;
  Scene::Init();
}
void App::Render(){
  SDL_SetRenderDrawColor(renderer, 255,255,255,255);
  SDL_RenderClear(renderer);
}
void App::Destroy(){
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
  SDL_Quit();
}
void App::Close(){
  App::running = false;
}
void App::Event(){
  switch(App::event.type){
    case(SDL_QUIT):
      App::Close();
      break;
    case(SDL_KEYUP):
      if(App::event.key.keysym.sym == SDLK_ESCAPE){
        App::Close();
      }
      break;
    case(SDL_WINDOWEVENT):
      if(App::event.window.event == SDL_WINDOWEVENT_SIZE_CHANGED){
        App::WIDTH = App::event.window.data1;
        App::HEIGHT = App::event.window.data2;
        App::ScaleX = App::WIDTH/App::INITIALWIDTH;
        App::ScaleY = App::HEIGHT/App::INITIALHEIGHT;
      }
      break;
    default:
      break;
  }
}
SDL_Window* App::window = nullptr;
SDL_Renderer* App::renderer = nullptr;
SDL_Event App::event;
SDL_Renderer* App::GetRenderer(){
  return App::renderer;
}

SDL_Window* App::GetWindow(){
  return App::window;
}
bool App::Closed(){
  return !App::running;
}
