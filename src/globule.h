#pragma once

#include "ofMain.h"

class globule : public ofBaseApp{
 public:
  void setup();
  void update();
  void draw();
		
  void keyPressed(int key);
  void keyReleased(int key);
  void mouseMoved(int x, int y);
  void mouseDragged(int x, int y, int button);
  void mousePressed(int x, int y, int button);
  void mouseReleased(int x, int y, int button);
  void windowResized(int w, int h);
  void dragEvent(ofDragInfo dragInfo);
  void gotMessage(ofMessage msg);

 protected:
  float width, height;
  ofImage img;
  ofPixels pixels;
  static const int maxIterations = 2;
  static const float cmix = 0.5;
  float r, r2;
  float mx, my;
  ofColor background;
  ofColor foreground;

  ofColor feedbackColor(float px, float py, ofColor background);

};
