#include "globule.h"
#include "ofAppGlutWindow.h"

//--------------------------------------------------------------
int main(){
  ofAppGlutWindow window; // create a window
  // set width, height, mode (OF_WINDOW or OF_FULLSCREEN)
  ofSetupOpenGL(&window, 400, 400, OF_WINDOW);
  ofRunApp(new globule()); // start the app
}
