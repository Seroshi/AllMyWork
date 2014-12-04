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

		//Font, images and sound
		ofTrueTypeFont font;
		ofImage options;
		ofImage square; ofImage square2; 
		ofImage triangle; ofImage triangle2;
		ofImage circle; ofImage circle2;
		ofImage cross; ofImage cross2;
		ofSoundPlayer mistake;
		ofSoundPlayer newlvl;
		ofSoundPlayer explosion;

		//counters
		int counterCircle, counterTriangle, counterCross, counterRectangle;

		//booleans for the bombs
		bool cirkelVisible, triangleVisible, CrossVisible, RectangleVisible;
		bool cirkelVisible2, triangleVisible2, CrossVisible2, RectangleVisible2;
		bool hasLostGame;

		//x & y coordinates
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

		//Gameplay elements
		int lives;
		int score;
		int mistakes;
		int LVLdifference;
		float speed;

		//pulsate for circle
		float pulsateCircle;
		float pulsateLimitCircle;
		int beatCircle;
		//pulsate for triangle
		float pulsateTriangle;
		float pulsateLimitTriangle;
		int beatTriangle;
		//pulsate for rectangle
		float pulsateRectangle;
		float pulsateLimitRectangle;
		int beatRectangle;
		//pulsate for cross
		float pulsateCross;
		float pulsateLimitCross;
		int beatCross;
		//Max pulsateLimit for every bomb
		int pulsateLimitMax;
};
