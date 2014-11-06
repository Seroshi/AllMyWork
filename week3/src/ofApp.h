#pragma once

#include "ofMain.h"

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

		///fucntions for arduino
        void setupArduino();
        void updateArduino();
    
        //variables for Arduino
    
        //allows for serial output -- we'll do this next week. :)
        ofSerial serial;
        //an arduino object
        ofArduino myArduino;
        //this variable will only be false when the code first runs arduino
        bool bSetupArduino;

		//for the game
		ofImage face;
		ofSoundPlayer mistake;
		ofSoundPlayer newlvl;

		int counterCircle, counterTriangle, counterCross, counterRectangle;

		bool cirkelVisible, triangleVisible, CrossVisible, RectangleVisible;
		bool hasLostGame;

		float enemyX;
		float enemyY;

		float playerRadius;
		float enemyRadius;
		float enemyRadiusR;

		float circleX, circleY;
		float triangleX, triangleY;
		float lineX, lineY;
		float rectangleX, rectangleY;

		int centerX;
		int centerY;
		int lives;
		int score;
		float speed;
		
};
