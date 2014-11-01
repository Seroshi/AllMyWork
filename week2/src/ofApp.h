#pragma once

#include "ofMain.h"
#include <iostream>
using namespace std;

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		void setupArduino();
		void updateArduino();
		bool bSetupArduino;

		//Variables for Arduino
		//Allow for serial output
		ofSerial serial;
		ofArduino myArduino;
		
};
