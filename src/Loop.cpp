#include "Loop.hpp"
#include "Application.hpp"
#include "AppIMGui.hpp"
#include "Event.hpp"
#include "rendercomb.hpp"
void MLoop::Loop(){
  while(!App::Closed()){
      Event::HandleEvent();
      MRender::Render();
  }
}
