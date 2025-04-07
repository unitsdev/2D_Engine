#include "game.hpp"
#include "FileDialog.hpp"
#include <thread>
#include <iostream>
#include <dlfcn.h>
using namespace std;
thread OpenThread;
namespace GAME{
  //project class
  bool Project::GameRunning = false;
  std::string Project::ProjectDirectory = "\0";
  bool Project::Init(){
     return false; 
  }
  void Project::OpenPRIVATE(){
      FileDialog::opendirectory(&ProjectDirectory);
      if(ProjectDirectory.empty()){
        cerr << "Project directory empty please try again\nor select another directory" << endl;
        return;
      }
  }
  void Project::Open(){
      OpenThread = thread(OpenPRIVATE);
      OpenThread.detach();
  }
  //scene class 
  void* Scene::handle = nullptr;
  Scene::Func Scene::Render = nullptr;
  void Scene::Compilation(){
    string command = "make -C " +Project::ProjectDirectory;
    int result = system(command.c_str());
    if(result != 0){
      cerr << "error compilate try again or rewrite code" << endl;
      return;
    }
  }
  void Scene::Open(){
    if(Project::ProjectDirectory.empty()){
      return;
    }
    Scene::Compilation();
    string file = Project::ProjectDirectory + "/lib/build/test.so";
    handle = dlopen(file.c_str(), RTLD_LAZY);
    if(handle == nullptr){
      Project::GameRunning = false;
      return;
    }
    Scene::Render = (Func)dlsym(handle,"Render");
  }
  void Scene::Close(){
    if(handle == nullptr){return;}
    dlclose(handle);
    Scene::Render = nullptr;
    handle = nullptr;
  }
};
