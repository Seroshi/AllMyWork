#include "ofApp.h"
ofImage face;

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

//--------------------------------------------------------------
void ofApp::setup(){
	lives = 10;
	score = 0;
	counterCircle = 0;
	counterTriangle = 0;
	centerX = 450;
	centerY = 250;
	speed = 0.5;
	enemyRadius = 60;

	hasLostGame = false;
	cirkelVisible = false;
	triangleVisible = false;
	CrossVisible = false;
	RectangleVisible = false;

	triangleX = ofRandom(ofGetWidth());
	triangleY = ofRandom(ofGetHeight());
	circleX = ofRandom(ofGetWidth());
	circleY = ofRandom(ofGetHeight());
	lineX = ofRandom(ofGetWidth());
	lineY = ofRandom(ofGetHeight());
	rectangleX = ofRandom(ofGetWidth());
	rectangleY = ofRandom(ofGetHeight());

	face.loadImage("face.png");

	ofEnableSmoothing();
	/*
	speed = 5;
	playerRadius = 60;
	enemyRadius = 20;
	//show enemy at the top position
	enemyY = 0-enemyRadius;
	enemyX = ofRandom(ofGetWidth());
	hasLostGame = false;
	score = 0;
	ofSetVerticalSync(true);
	*/
}
void ofApp::updateArduino(){
	//a call to update the arduino data ins and out
	myArduino.update();
}
//This will setup all of my Arduino pins
void ofApp::setupArduino(){
	myArduino.sendDigitalPinMode(9,ARD_OUTPUT);
}

//--------------------------------------------------------------
void ofApp::update(){
	/*
	//if Arduino is ready
	if(myArduino.isArduinoReady()){
		//1st setup the arduino if haven't already
		if(bSetupArduino == false){
			//cout << "Arduino running" << endl;
			//This function assign the pins
			setupArduino();
			//we're starting running arduino so no need to call setup again!
			bSetupArduino = true;//only do this once
		}
		//2nd do the update of the Arduino
		updateArduino();
	}
	*/
	//When ur not dead do this
	if(hasLostGame == false){
		//Turn the 9th pin on the arduino on. For this code LED is ON.
		myArduino.sendDigital(9, ARD_HIGH);

		//Show circle after a specific time
		if(counterCircle > 9990){
			cirkelVisible = true;
			circleY += speed;
			counterCircle++;
			//resetting counter if circle appeared
			if(counterCircle>12000){
				counterCircle = 0;
				lives--;
			}
		}
		//Hide Cirkel within a certain time
		else{
			cirkelVisible = false;
			//let counter pick a random number
			counterCircle = ofRandom(1,10000);
			//reset location of the circle
			circleX = ofRandom(ofGetWidth());
			circleY = -50;
		}
		//Show triangle after a specific time
		if(counterTriangle > 9990){
			triangleVisible = true;
			triangleY += speed;
			counterTriangle++;
			//resetting counter if triangle appeared
			if(counterTriangle>12000){
				counterTriangle = 0;
				lives--;
			}
		}
		//Hide triangle within a certain time
		else{
			triangleVisible = false;
			//let counter pick a random number
			counterTriangle = ofRandom(1,10000);
			//reset location of the triangle
			triangleX = ofRandom(ofGetWidth());
			triangleY = -50;
		}
		//Show cross after a specific time
		if(counterCross > 9990){
			CrossVisible = true;
			lineY += speed;
			counterCross++;
			//resetting counter if cross appeared
			if(counterCross>12000){
				counterCross = 0;
				lives--;
			}
		}
		//Hide cross within a certain time
		else{
			CrossVisible = false;
			//let counter pick a random number
			counterCross = ofRandom(1,10000);
			//reset location of the cross
			lineX = ofRandom(ofGetWidth());
			lineY = -50;
		}
		//Show rectangle after a specific time
		if(counterRectangle > 9990){
			RectangleVisible = true;
			rectangleY += speed;
			counterRectangle++;
			//resetting counter if rectangle appeared
			if(counterRectangle>12000){
				counterRectangle = 0;
				lives--;
			}
		}
		//Hide rectangle within a certain time
		else{
			RectangleVisible = false;
			//let counter pick a random number
			counterRectangle = ofRandom(1,10000);
			//reset location of the rectangle
			rectangleX = ofRandom(ofGetWidth());
			rectangleY = -50;
		}
	}
	if(lives == 0){
		hasLostGame = true;
		cirkelVisible = false;
		triangleVisible = false;
		CrossVisible = false;
		RectangleVisible = false;
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofEnableSmoothing();
	ofSetColor(0,0,0);
	ofDrawBitmapString("Lives: " + ofToString(lives), 20,30);
	ofDrawBitmapString("Score: " + ofToString(score), 20,70);
	ofSetColor(255,0,0);

	//Show & draw a circle
	if(cirkelVisible){
		ofCircle(circleX, circleY, enemyRadius);
	}
	//Show & draw a triangle
	if(triangleVisible){
		ofTriangle(triangleX,triangleY, triangleX+(enemyRadius*1.2),triangleY-(enemyRadius*1.9), triangleX+(enemyRadius*2.4),triangleY);
	}
	//Show & draw a cross
	if(CrossVisible){
		ofSetLineWidth(10);
		ofLine(lineX-100,lineY-50, lineX,lineY-150);
		ofLine(lineX-100,lineY-150, lineX,lineY-50);
	}
	//Show & draw a rectangle
	if(RectangleVisible){
		//ofRect(rectangleX,rectangleY, 100, 100);
		face.draw(100,100);
	}
	if(hasLostGame){
		ofDrawBitmapString("\n Game Over! Press SPACEBAR to restart", 320,300);
		myArduino.sendDigital(9, ARD_LOW);
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	if(key == 358){
		//Check if a circle is visible when "RIGHT" button is pressed
		if(hasLostGame == false && cirkelVisible){
			counterCircle = 0;
			score++;
		}
		//If not, you lose 1 life
		else{
			if(hasLostGame == false){
				lives--;
			}
		}
	}
	if(key == 356){
		//Check if a rectangle is visible when "LEFT" button is pressed
		if(hasLostGame == false && RectangleVisible){
			counterRectangle = 0;
			score++;
		}
		//If not, you lose 1 life
		else{
			if(hasLostGame == false){
				lives--;
			}
		}
	}
	if(key == 357){
		//Check if a rectangle is visible when "UP" button is pressed
		if(hasLostGame == false && triangleVisible){
			counterTriangle = 0;
			score++;
		}
		//If not, you lose 1 life
		else{
			if(hasLostGame == false){
				lives--;
			}
		}
	}
	if (key == 359){
		//Check if a cross is visible when "DOWN" button is pressed
		if(hasLostGame == false && CrossVisible){
			counterCross = 0;
			score++;
		}
		//If not, you lose 1 life
		else{
			if(hasLostGame == false){
				lives--;
			}
		}
	}
	//Restaring the game
	if(key == 32){
		if(hasLostGame){
			hasLostGame = false;
			cout << "RESET";
			score = 0;
			lives = 10;
			cout << counterCircle;
			counterCircle = 0;
			counterCross = 0;
			counterRectangle = 0;
			counterTriangle = 0;
		}
	}
	//cout << key;
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
