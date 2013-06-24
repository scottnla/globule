#include "globule.h"

//--------------------------------------------------------------
void globule::setup(){
  ofBackground(0,0,0);
  ofEnableSmoothing();
  ofSetFrameRate(30);
  width = ofGetWidth();
  height = ofGetHeight();
  img.allocate(width,height,OF_IMAGE_COLOR);
  pixels = img.getPixelsRef();
  r = 4;
  background.set(255, 255, 255);
  foreground.set(255, 0, 255);
}

//--------------------------------------------------------------
void globule::update(){
  r2 = r*(6 + 3*sin(ofGetFrameNum()*0.05));
  for(int i = 0; i < width; i++) {
    for(int j = 0; j < height; j++) {
      float real = ofMap(i, 0, width, -r, r);
      float imaginary = ofMap(j, 0, height, -r, r);
      float rere = real*real;
      float imim = imaginary*imaginary;

      int n = 0;
      for(; n < maxIterations; n++) {
	real = real*(rere - 3*imim) + mx;
	imaginary = imaginary*(3*rere - imim) + my;
	rere = real*real;
	imim = imaginary*imaginary;
	if(rere + imim > r*r) {
	  break;
	}
      }

      float x = ofMap(real, -r2, r2, 0, width);
      float y = ofMap(imaginary, -r2, r2, 0, height);
      
      ofColor cnew;
      cnew.setHsb(2*255/3, 255, 255/maxIterations * n);
      ofColor cfeedback = feedbackColor(x, y, background);
      pixels.setColor(i, j, foreground.lerp(cnew.lerp(cfeedback,cmix),0.1));
    }
  }
  img.setFromPixels(pixels);
}

//--------------------------------------------------------------
void globule::draw(){
  img.draw(0,0);
}

//--------------------------------------------------------------
void globule::keyPressed(int key){

}

//--------------------------------------------------------------
void globule::keyReleased(int key){

}

//--------------------------------------------------------------
void globule::mouseMoved(int x, int y){
  mx = ofMap(x, 0, width, -r, r);
  my = ofMap(y, 0, height, -r, r);
}

//--------------------------------------------------------------
void globule::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void globule::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void globule::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void globule::windowResized(int w, int h){

}

//--------------------------------------------------------------
void globule::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void globule::dragEvent(ofDragInfo dragInfo){ 

}

//--------------------------------------------------------------
ofColor globule::feedbackColor(float px, float py, ofColor background) {
  int x = int(px);
  int y = int(py);
  if (x < 0 || y < 0 || x >= width - 1 || y >= width - 1) {
    return background;
  }
  float dx = px - x;
  float dy = px - y;
  ofColor color1, color2;
  color1 = pixels.getColor(x,y);
  color2 = pixels.getColor(x,y+1);

  color1.lerp(pixels.getColor(x+1,y),dx);
  color2.lerp(pixels.getColor(x+1,y+1),dx);
  color1.lerp(color2,dy);
  return color1;
}
