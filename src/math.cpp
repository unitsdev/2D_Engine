#include "math.hpp"
float math::min(float a,float b){
  if(a < b){
    return a;
  }
  else{
    return b;
  }
}
float math::max(float a,float b){
  if(a > b){
    return a;
  }else{
    return b;
  }
}
