#include "game.hpp"
#include "FileDialog.hpp"
#include <thread>
#include <iostream>
using namespace std;
thread OpenThread;
namespace GAME{
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
  void Project::Destroy(){

  }

};
