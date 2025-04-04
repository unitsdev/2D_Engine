#include "Scene.hpp"
#include "viewport.hpp"
#include "FileDialog.hpp"
#include <iostream>
using namespace std;
SDL_Texture* Scene::Texture = nullptr;
bool Scene::Active = false;
string str = "";
SDL_Event* Scene::ev;
void Scene::SetTarget(){
  SDL_SetRenderTarget(App::GetRenderer(),Scene::Texture);
}
void Scene::DefaultTarget(){
  SDL_SetRenderTarget(App::GetRenderer(),nullptr);
}
void Scene::Init(){
    Scene::Texture = SDL_CreateTexture(App::GetRenderer(),SDL_PIXELFORMAT_RGBA8888,SDL_TEXTUREACCESS_TARGET,200,200);
}
void Scene::Update(int new_w,int new_h){
  SDL_DestroyTexture(Scene::Texture);
  Scene::Texture = nullptr;
  Scene::Texture = SDL_CreateTexture(App::GetRenderer(),SDL_PIXELFORMAT_RGBA8888,SDL_TEXTUREACCESS_TARGET,new_w,new_h);
  //SDL_UpdateTexture(Scene::Texture, nullptr, new_w,new_h);
}
void Scene::Event(){
  if(App::event.type == SDL_QUIT){
    App::Close();
  }
  if(App::event.type ==SDL_KEYUP){
    if(App::event.key.keysym.sym == SDLK_SPACE){
      FileDialog::th = thread(FileDialog::opendirectory,&str);
      FileDialog::th.detach();
    }
  }
}
void Scene::Render(){

  //SDL_RenderSetViewport(App::GetRenderer(),&Viewport::Rect);
  Scene::SetTarget();
  //SDL_SetRenderTarget(renderer, texture);
  SDL_SetRenderDrawColor(App::GetRenderer(),0,255,255,255);
  SDL_RenderFillRect(App::GetRenderer(),nullptr);
  SDL_SetRenderDrawColor(App::GetRenderer(),0,0,0,255);
  SDL_Rect rect = {0,0,100,100};
  SDL_RenderFillRect(App::GetRenderer(),&rect);
  //SDL_RenderSetViewport(App::GetRenderer(),nullptr);
  Scene::DefaultTarget();
}

