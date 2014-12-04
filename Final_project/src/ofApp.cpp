#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
	//All the things for the game
	lives = 10;
	score = 0;
	mistakes = 0;
	LVLdifference = 0;

	//Pulsate for circle
	pulsateCircle = 0;
	pulsateLimitCircle = 100;
	beatCircle = 0;
	//pulsate for triangle
	pulsateTriangle = 0;
	pulsateLimitTriangle = 100;
	beatTriangle = 0;
	//pulsate for rectangle
	pulsateRectangle = 0;
	pulsateLimitRectangle = 100;
	beatRectangle = 0;
	//pulsate for cross
	pulsateCross = 0;
	pulsateLimitCross = 100;
	beatCross = 0;
	//Max pulsateLimit for all bombs
	pulsateLimitMax = 150;

	counterCircle = 0;
	counterTriangle = 0;
	counterCross = 0;
	counterRectangle = 0;
	centerX = 450;
	centerY = 250;
	speed = 0.5;
	enemyRadius = 60;

	hasLostGame = false;
	cirkelVisible, cirkelVisible2 = false;
	triangleVisible, triangleVisible2 = false;
	CrossVisible, CrossVisible2 = false;
	RectangleVisible, RectangleVisible2 = false;

	triangleX = ofRandom(ofGetWidth());
	triangleY = ofRandom(ofGetHeight());
	circleX = ofRandom(ofGetWidth());
	circleY = ofRandom(ofGetHeight());
	lineX = ofRandom(ofGetWidth());
	lineY = ofRandom(ofGetHeight());
	rectangleX = ofRandom(ofGetWidth());
	rectangleY = ofRandom(ofGetHeight());

	font.loadFont("NexaLight.otf", 12);
	options.loadImage("options2.png");
	square.loadImage("square.png"); square2.loadImage("square2.png"); 
	cross.loadImage("cross.png"); cross2.loadImage("cross2.png");
	circle.loadImage("circle.png"); circle2.loadImage("circle2.png");
	triangle.loadImage("triangle.png"); triangle2.loadImage("triangle2.png");  
	mistake.loadSound("mistake.mp3");
	newlvl.loadSound("newlvl.mp3");
	explosion.loadSound("explosion.wav");

	ofEnableSmoothing();
}

//--------------------------------------------------------------
void ofApp::update(){
	//When ur not dead do this
	if(hasLostGame == false){
		//Show circle after a specific time
		if(counterCircle > 9990){
			cirkelVisible = true;
			if(circleY < ofGetHeight()-150) circleY += speed;//Makes the circle bom fall down
			else{
				if(cirkelVisible || pulsateLimitCircle > 0){
					pulsateCircle++; 
					if(pulsateCircle > pulsateLimitCircle){ //This checks the current pulserate
						cirkelVisible2 = true; //shows the second circel bom picture
						cirkelVisible = false; //hides the first cirkel bom picture
						if(pulsateCircle>pulsateLimitCircle+50){ //This makes the circel bom 2 visible for very short time 
							beatCircle += 1; //Start the beat counter
							pulsateCircle = 0; //Reset the pulsate
						}
					}
					else {
						cirkelVisible2 = false; cirkelVisible = true; // This is needed for the flickering
					}
					if(beatCircle>3){ //Makes the bomb beat 3 times 
						beatCircle = 0; pulsateLimitCircle -= 30; //Reset the beat count. Also lower the pulsateLimit
					}
					if(pulsateLimitCircle<1){
						explosion.play(); // Play bomb explosion sound
						lives --; //Substract 1 live
						cirkelVisible = false; cirkelVisible2 = false; 
						counterCircle = 0; //Resets the circle bom counter
					}
					if(pulsateLimitCircle<0) pulsateLimitCircle = pulsateLimitMax; //Resets the pulsateLimit
				}
			}
			counterCircle++; //Start the circle bom counter
		}
		//Hide Cirkel bom within a certain time
		else{
			cirkelVisible = false; cirkelVisible2 = false;
			//let counter pick a random number
			counterCircle = ofRandom(1,10000);
			//reset location of the circle bom somewhere at the top
			circleX = ofRandom(ofGetWidth()-200);
			circleY = -150;
			pulsateLimitCircle = pulsateLimitMax; //Resets the pulsateLimit
		}
		//Show triangle bom after a specific time
		if(counterTriangle > 9990){
			triangleVisible = true;
			if(triangleY < ofGetHeight()-150) triangleY += speed; //Makes the triangle bom fall down
			else{
				if(triangleVisible || pulsateLimitTriangle > 0){
					pulsateTriangle++; 
					if(pulsateTriangle > pulsateLimitTriangle){ //This checks the current pulserate
						triangleVisible2 = true; //shows the second circel bom picture
						triangleVisible = false; //hides the first cirkel bom picture
						if(pulsateTriangle>pulsateLimitTriangle+50){ //This makes the circel bom 2 visible for very short time 
							beatTriangle += 1; //Start the beat counter
							pulsateTriangle = 0; //Reset the pulsate
						}
					}
					else {
						triangleVisible2 = false; triangleVisible = true; // This is needed for the flickering
					}
					if(beatTriangle>3){ //Makes the bomb beat 3 times 
						beatTriangle = 0; pulsateLimitTriangle -= 30; //Reset the beat count. Also lower the pulsateLimit
					}
					if(pulsateLimitTriangle<1){
						explosion.play(); // Play bomb explosion sound
						lives --; //Substract 1 live
						triangleVisible = false; triangleVisible2 = false; 
						counterTriangle = 0; //Resets the triangle bom counter
					}
					if(pulsateLimitTriangle<0) pulsateLimitTriangle = pulsateLimitMax; //Resets the pulsateLimit
				}
			}
			counterTriangle++;
		}
		//Hide triangle bom within a certain time
		else{
			triangleVisible = false; triangleVisible2 = false;
			//let counter pick a random number
			counterTriangle = ofRandom(1,10000);
			//reset location of the triangle bom somewhere at the top
			triangleX = ofRandom(ofGetWidth()-200);
			triangleY = -150;
			pulsateLimitTriangle = pulsateLimitMax; //Resets the pulsateLimit
		}
		//Show cross bom after a specific time
		if(counterCross > 9990){
			CrossVisible = true;
			if(lineY < ofGetHeight()-150) lineY += speed; //Makes the cross bom fall down
			else{
				if(CrossVisible || pulsateLimitCross > 0){
					pulsateCross++; 
					if(pulsateCross > pulsateLimitCross){ //This checks the current pulserate
						CrossVisible2 = true; //shows the second cross bom picture
						CrossVisible = false; //hides the first cross bom picture
						if(pulsateCross>pulsateLimitCross+50){ //This makes the circel bom 2 visible for very short time 
							beatCross += 1; //Start the beat counter
							pulsateCross = 0; //Reset the pulsate
						}
					}
					else {
						CrossVisible2 = false; CrossVisible = true; // This is needed for the flickering
					}
					if(beatCross>3){ //Makes the bomb beat 3 times 
						beatCross = 0; pulsateLimitCross -= 30; //Reset the beat count. Also lower the pulsateLimit
					}
					if(pulsateLimitCross<1){
						explosion.play(); // Play bomb explosion sound
						lives --; //Substract 1 live
						CrossVisible = false; CrossVisible2 = false; 
						counterCross = 0; //Resets the Cross bom counter
					}
					if(pulsateLimitCross<0) pulsateLimitCross = pulsateLimitMax; //Resets the pulsateLimit
				}
			}
			counterCross++;
			//resetting counter if cross bom goes of the screen.
		}
		//Hide cross bom within a certain time
		else{
			CrossVisible = false; CrossVisible2 = false;
			//let counter pick a random number
			counterCross = ofRandom(1,10000);
			//reset location of the cross somewhere at the top
			lineX = ofRandom(ofGetWidth()-200);
			lineY = -150;
			pulsateLimitCross = pulsateLimitMax; //Resets the pulsateLimit
		}
		//Show rectangle after a specific time
		if(counterRectangle > 9990){
			RectangleVisible = true;
			if(rectangleY < ofGetHeight()-150) rectangleY += speed; //Makes the rectangle bom fall down
			else{
				if(RectangleVisible || pulsateLimitRectangle > 0){
					pulsateRectangle++; 
					if(pulsateRectangle > pulsateLimitRectangle){ //This checks the current pulserate
						RectangleVisible2 = true; //shows the second cross bom picture
						RectangleVisible = false; //hides the first cross bom picture
						if(pulsateRectangle>pulsateLimitRectangle+50){ //This makes the circel bom 2 visible for very short time 
							beatRectangle += 1; //Start the beat counter
							pulsateRectangle = 0; //Reset the pulsate
						}
					}
					else {
						RectangleVisible2 = false; RectangleVisible = true; // This is needed for the flickering
					}
					if(beatRectangle>3){ //Makes the bomb beat 3 times 
						beatRectangle = 0; pulsateLimitRectangle -= 30; //Reset the beat count. Also lower the pulsateLimit
					}
					if(pulsateLimitRectangle<1){
						explosion.play(); // Play bomb explosion sound
						lives --; //Substract 1 live
						RectangleVisible = false; RectangleVisible2 = false; 
						counterRectangle = 0; //Resets the Cross bom counter
					}
					if(pulsateLimitRectangle<0) pulsateLimitRectangle = pulsateLimitMax; //Resets the pulsateLimit
				}
			}
			counterRectangle++;
			//resetting counter if rectangle bom goes of the screen.
		}
		//Hide rectangle bom within a certain time
		else{
			RectangleVisible = false; RectangleVisible2 = false;
			//let counter pick a random number
			counterRectangle = ofRandom(1,10000);
			//reset location of the rectangle bom somewhere at the top
			rectangleX = ofRandom(ofGetWidth()-200);
			rectangleY = -150;
			pulsateLimitRectangle = pulsateLimitMax; //Resets the pulsateLimit
		}
		if(score == 0){
			speed = 0.5;
		}
		if(LVLdifference > 9){
			LVLdifference = 0; //Reset LVLdifference counter
			speed += 0.2; // Speed up the falling bombs
			newlvl.play(); // Play the next difficulty song
			pulsateLimitMax -= 10; // Make all the bombs explode faster
		}
	}
	if(lives == 0 || mistakes == 10){
		hasLostGame = true;
		cirkelVisible = false;
		triangleVisible = false;
		CrossVisible = false;
		RectangleVisible = false;
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetColor(255,255,255);
	options.draw(890,20);
	ofEnableSmoothing();
	ofSetColor(0,0,0);
	font.drawString("Lives left  : " + ofToString(lives), 20,30);
	font.drawString("Mistakes   : " + ofToString(mistakes) + " / 10", 20,50);
	font.drawString("Score: " + ofToString(score), 20,90);
	ofSetColor(255,255,255);


	//Show & draw a circle
	if(cirkelVisible)circle.draw(circleX, circleY);
	if(cirkelVisible2)circle2.draw(circleX-5, circleY-5);

	//Show & draw a triangle
	if(triangleVisible)triangle.draw(triangleX, triangleY);
	if(triangleVisible2)triangle2.draw(triangleX-5, triangleY-5);

	//Show & draw a cross
	if(CrossVisible)cross.draw(lineX, lineY);
	if(CrossVisible2)cross2.draw(lineX-5, lineY-5);

	//Show & draw a rectangle
	if(RectangleVisible)square.draw(rectangleX, rectangleY);
	if(RectangleVisible2)square2.draw(rectangleX-5, rectangleY-5);

	if(hasLostGame){ //When you lose
		ofSetColor(255, 0, 0);
		font.drawString("\n Game Over! Press SPACEBAR to restart", 320,300);
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	if(key == 358){
		//Check if a circle is visible when "RIGHT" button is pressed
		if(hasLostGame == false && cirkelVisible||hasLostGame == false && cirkelVisible2){
			counterCircle = 0;
			score++;
			LVLdifference++;
		}
		//If not, you lose 1 life
		else{
			if(hasLostGame == false){
				mistake.play();
				mistakes++;
			}
		}
	}
	if(key == 356){
		//Check if a rectangle is visible when "LEFT" button is pressed
		if(hasLostGame == false && RectangleVisible||hasLostGame == false && RectangleVisible2){
			counterRectangle = 0;
			score++;
			LVLdifference++;
		}
		//If not, you lose 1 life
		else{
			if(hasLostGame == false){
				mistake.play();
				mistakes++;
			}
		}
	}
	if(key == 357){
		//Check if a rectangle is visible when "UP" button is pressed
		if(hasLostGame == false && triangleVisible||hasLostGame == false && triangleVisible2){
			counterTriangle = 0;
			score++;
			LVLdifference++;
		}
		//If not, you lose 1 life
		else{
			if(hasLostGame == false){
				mistake.play();
				mistakes++;
			}
		}
	}
	if (key == 359){
		//Check if a cross is visible when "DOWN" button is pressed
		if(hasLostGame == false && CrossVisible||hasLostGame == false && CrossVisible2){
			counterCross = 0;
			score++;
			LVLdifference++;
		}
		//If not, you lose 1 life
		else{
			if(hasLostGame == false){
				mistake.play();
				mistakes++;
			}
		}
	}
	//Restaring the game
	if(key == 32){
		if(hasLostGame){ //This resets the whole game
			hasLostGame = false;
			score = 0;
			lives = 10;
			mistakes = 0;
			counterCircle = 0;
			counterCross = 0;
			counterRectangle = 0;
			counterTriangle = 0;
			pulsateLimitMax = 150;
		}
	}
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
