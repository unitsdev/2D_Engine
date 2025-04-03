#include "Application.hpp"
#include "AppIMGui.hpp"
#include "Loop.hpp"
#include "math.hpp"
#include <iostream>
using namespace std;
int main(){
  App::Init();
  AImGui::Init();
  MLoop::Loop();
  AImGui::Destroy();
  App::Destroy();
  return 0;
}
