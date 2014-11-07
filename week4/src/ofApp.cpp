#include "ofApp.h"
vector<string>  answer;
vector<string>  answer2;
vector<string>  checker;
string hint, hint2, hint3, hint4, hint5;
bool ClickedOn, ClickedOn2, ClickedOn3, ClickedOn4, ClickedOn5;
bool CheckOn, CheckOn2, CheckOn3, CheckOn4, CheckOn5;
bool HintOn, HintOn2, HintOn3, HintOn4, HintOn5;
bool showAnswers;
int textfieldX, textfieldY, textfieldWidth, textfieldHeight;
int buttonX, buttonY, buttonWidth, buttonHeight;
//--------------------------------------------------------------
void ofApp::setup(){
	ClickedOn, ClickedOn2, ClickedOn3, ClickedOn4, ClickedOn5 = false; //this will make sure you can't start typing yet
	CheckOn, CheckOn2, CheckOn3, CheckOn4, CheckOn5 = false; //this will make sure you can't start typing yet
	showAnswers = true; //show typed answers

	answer.push_back(""); //answer1
	answer.push_back(""); //answer2
	answer.push_back(""); //answer3
	answer.push_back(""); //answer4
	answer.push_back(""); //answer5

	answer2.push_back("..."); //answer2-1
	answer2.push_back("..."); //answer2-2
	answer2.push_back("..."); //answer2-3
	answer2.push_back("..."); //answer2-4
	answer2.push_back("..."); //answer2-5

	checker.push_back(""); //checker1
	checker.push_back(""); //checker2
	checker.push_back(""); //checker3
	checker.push_back(""); //checker4
	checker.push_back(""); //checker5


	//this is for changing the size of a textfield
	textfieldX = 80;
	textfieldY = 240;
	textfieldWidth = 320;
	textfieldHeight = 30;

	buttonX = 80;
	buttonY = 500;
	buttonWidth = 150;
	buttonHeight = 30;

}

//--------------------------------------------------------------
void ofApp::update(){
	if(answer[0] == answer2[0]){
		checker[0] = "correct";
	}
	if(answer[1] == answer2[1]){
		checker[1] = "correct";
	}
	if(answer[2] == answer2[2]){
		checker[2] = "correct";
	}
	if(answer[3] == answer2[3]){
		checker[3] = "correct";
	}
	if(answer[4] == answer2[4]){
		checker[4] = "correct";
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	//making all the answer1 textfields
	ofSetColor(60,60,60);
	ofRect(textfieldX, textfieldY, textfieldWidth, textfieldHeight);
	ofRect(textfieldX, textfieldY+50, textfieldWidth, textfieldHeight);
	ofRect(textfieldX, textfieldY+100, textfieldWidth, textfieldHeight);
	ofRect(textfieldX, textfieldY+150, textfieldWidth, textfieldHeight);
	ofRect(textfieldX, textfieldY+200, textfieldWidth, textfieldHeight);

	//making all the answer1 texts
	if(showAnswers){ //making sure if texts are visible or not
		ofSetColor(255,255,255);
		ofDrawBitmapString(answer[0], 100, 260);
		ofDrawBitmapString(answer[1], 100, 310);
		ofDrawBitmapString(answer[2], 100, 360);
		ofDrawBitmapString(answer[3], 100, 410);
		ofDrawBitmapString(answer[4], 100, 460);
	}
	if(!showAnswers){ //making sure if texts are visible or not
		ofSetColor(255,255,255);
		ofDrawBitmapString(answer2[0], 100, 260);
		ofDrawBitmapString(answer2[1], 100, 310);
		ofDrawBitmapString(answer2[2], 100, 360);
		ofDrawBitmapString(answer2[3], 100, 410);
		ofDrawBitmapString(answer2[4], 100, 460);
	}

	//ask the visible question
	ofSetColor(0,0,0);
	ofDrawBitmapString("What are your 5 most favourite things?", 80, 220);

	//ask the visible hint question
	ofSetColor(0,0,0);
	ofDrawBitmapString("What is the hint?", 420, 220);


	//making all the hint textfields
	ofSetColor(100,100,100);
	ofRect(textfieldX+340, textfieldY, textfieldWidth+100, textfieldHeight);
	ofRect(textfieldX+340, textfieldY+50, textfieldWidth+100, textfieldHeight);
	ofRect(textfieldX+340, textfieldY+100, textfieldWidth+100, textfieldHeight);
	ofRect(textfieldX+340, textfieldY+150, textfieldWidth+100, textfieldHeight);
	ofRect(textfieldX+340, textfieldY+200, textfieldWidth+100, textfieldHeight);

	//making all the hint texts
	ofSetColor(255,255,255);
	ofDrawBitmapString(hint, 440, 260);
	ofDrawBitmapString(hint2, 440, 310);
	ofDrawBitmapString(hint3, 440, 360);
	ofDrawBitmapString(hint4, 440, 410);
	ofDrawBitmapString(hint5, 440, 460);

	//making the buttons 
	ofSetColor(180, 180, 180);
	ofRect(buttonX, buttonY, buttonWidth, buttonHeight);
	ofSetColor(0,0,0);
	ofDrawBitmapString("Player 1", 120, 520);
	//making the text of the buttons
	ofSetColor(150, 150, 150);
	ofRect(buttonX+170, buttonY, buttonWidth, buttonHeight);
	ofSetColor(0,0,0);
	ofDrawBitmapString("Player 2", 290, 520);

	//making all the "correct" text
	ofSetColor(0,100,0);
	ofDrawBitmapString(checker[0], 860, 260);
	ofDrawBitmapString(checker[1], 860, 310);
	ofDrawBitmapString(checker[2], 860, 360);
	ofDrawBitmapString(checker[3], 860, 410);
	ofDrawBitmapString(checker[4], 860, 460);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	////////////////////////This is checking all the clicks for answer1 textfields/////////////////////////
	if(ClickedOn){ //check when clicked on textfield 1
		if(key==8 && answer[0].size()>0) { // BACKSPACE
			answer[0] = answer[0].substr(0, answer[0].size()-1); // delete one character
		} 
		else {
			answer[0].append (1, (char)key ); //input the key you typed
		}
	}
	if(ClickedOn2){ //check when clicked on textfield 2
		if(key==8 && answer[1].size()>0) { // BACKSPACE
			answer[1] = answer[1].substr(0, answer[1].size()-1); // delete one character
		} 
		else {
			answer[1].append (1, (char)key ); //input the key you typed
		}
	}
	if(ClickedOn3){ //check when clicked on textfield 3
		if(key==8 && answer[2].size()>0) { // BACKSPACE
			answer[2] = answer[2].substr(0, answer[2].size()-1); // delete one character
		} 
		else {
			answer[2].append (1, (char)key ); //write the text
		}
	}
	if(ClickedOn4){ //check when clicked on textfield 4
		if(key==8 && answer[3].size()>0) { // BACKSPACE
			answer[3] = answer[3].substr(0, answer[3].size()-1); // delete one character
		} 
		else {
			answer[3].append (1, (char)key ); //input the key you typed
		}
	}
	if(ClickedOn5){ //check when clicked on textfield 5
		if(key==8 && answer[4].size()>0) { // BACKSPACE
			answer[4] = answer[4].substr(0, answer[4].size()-1); // delete one character
		} 
		else {
			answer[4].append (1, (char)key ); //input the key you typed
		}
	}
	if(key==13){ //ENTER
		ClickedOn, ClickedOn2, ClickedOn3, ClickedOn4, ClickedOn5 = false; //This will make the typing of all answers stop 
	}

	////////////////////////This is checking all the clicks for answer2 textfields/////////////////////////
	if(CheckOn){ //check when clicked on textfield 1
		if(key==8 && answer2[0].size()>0) { // BACKSPACE
			answer2[0] = answer2[0].substr(0, answer2[0].size()-1); // delete one character
		} 
		else {
			answer2[0].append (1, (char)key ); //input the key you typed
		}
	}
	if(CheckOn2){ //check when clicked on textfield 2
		if(key==8 && answer2[1].size()>0) { // BACKSPACE
			answer2[1] = answer2[1].substr(0, answer2[1].size()-1); // delete one character
		} 
		else {
			answer2[1].append (1, (char)key ); //input the key you typed
		}
	}
	if(CheckOn3){ //check when clicked on textfield 3
		if(key==8 && answer2[2].size()>0) { // BACKSPACE
			answer2[2] = answer2[2].substr(0, answer2[2].size()-1); // delete one character
		} 
		else {
			answer2[2].append (1, (char)key ); //write the text
		}
	}
	if(CheckOn4){ //check when clicked on textfield 4
		if(key==8 && answer2[3].size()>0) { // BACKSPACE
			answer2[3] = answer2[3].substr(0, answer2[3].size()-1); // delete one character
		} 
		else {
			answer2[3].append (1, (char)key ); //input the key you typed
		}
	}
	if(CheckOn5){ //check when clicked on textfield 5
		if(key==8 && answer2[4].size()>0) { // BACKSPACE
			answer2[4] = answer2[4].substr(0, answer2[4].size()-1); // delete one character
		} 
		else {
			answer2[4].append (1, (char)key ); //input the key you typed
		}
	}
	if(key==13){ //ENTER
		CheckOn, CheckOn2, CheckOn3, CheckOn4, CheckOn5 = false; //This will make the typing of all answers2 stop 
	}

	////////////////////////This is checking all the clicks for hint textfields/////////////////////////
	if(HintOn){ //check when clicked on textfield 1
		if(key==8 && hint.size()>0) { // BACKSPACE
			hint = hint.substr(0, hint.size()-1); // delete one character
		} 
		else {
			hint.append (1, (char)key ); //input the key you typed
		}
	}
	if(HintOn2){ //check when clicked on textfield 2
		if(key==8 && hint2.size()>0) { // BACKSPACE
			hint2 = hint2.substr(0, hint2.size()-1); // delete one character
		} 
		else {
			hint2.append (1, (char)key ); //input the key you typed
		}
	}
	if(HintOn3){ //check when clicked on textfield 3
		if(key==8 && hint3.size()>0) { // BACKSPACE
			hint3 = hint3.substr(0, hint3.size()-1); // delete one character
		} 
		else {
			hint3.append (1, (char)key ); //input the key you typed
		}
	}
	if(HintOn4){ //check when clicked on textfield 4
		if(key==8 && hint4.size()>0) { // BACKSPACE
			hint4 = hint4.substr(0, hint4.size()-1); // delete one character
		} 
		else {
			hint4.append (1, (char)key ); //input the key you typed
		}
	}
	if(HintOn5){ //check when clicked on textfield 5
		if(key==8 && hint5.size()>0) { // BACKSPACE
			hint5 = hint5.substr(0, hint5.size()-1); // delete one character
		} 
		else {
			hint5.append (1, (char)key ); //input the key you typed
		}
	}
	if(key==13){ //ENTER
		HintOn, HintOn2, HintOn3, HintOn4, HintOn5 = false; //This will make the typing of all hints stop 
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	
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
	///////////////This is for making answer textfields clickable///////////////////
	if(showAnswers){ //this is to allow or disable the ablity to click on the answers
		//answer textfield 1
		if(mouseX >= textfieldX && mouseX <= textfieldX+textfieldWidth && mouseY >= textfieldY && mouseY <= textfieldY+textfieldHeight){
			ClickedOn = true;
		}
		else{
			ClickedOn = false;
		}
		//answer textfield 2
		if(mouseX >= textfieldX && mouseX <= textfieldX+textfieldWidth && mouseY >= textfieldY+50 && mouseY <= textfieldY+textfieldHeight+50){ 
			ClickedOn2 = true;
		}
		else{
			ClickedOn2 = false;
		}
		//answer textfield 3
		if(mouseX >= textfieldX && mouseX <= textfieldX+textfieldWidth && mouseY >= textfieldY+100 && mouseY <= textfieldY+textfieldHeight+100){
			ClickedOn3 = true;
		}
		else{
			ClickedOn3 = false;
		}
		//answer textfield 4
		if(mouseX >= textfieldX && mouseX <= textfieldX+textfieldWidth && mouseY >= textfieldY+150 && mouseY <= textfieldY+textfieldHeight+150){ 
			ClickedOn4 = true;
		}
		else{
			ClickedOn4 = false;
		}
		//answer textfield 5
		if(mouseX >= textfieldX && mouseX <= textfieldX+textfieldWidth && mouseY >= textfieldY+200 && mouseY <= textfieldY+textfieldHeight+200){
			ClickedOn5 = true;
		}
		else{
			ClickedOn5 = false;
		}
	}

	if(!showAnswers){ //this is to allow or disable the ablity to click on the answers
		//answer textfield 1
		if(mouseX >= textfieldX && mouseX <= textfieldX+textfieldWidth && mouseY >= textfieldY && mouseY <= textfieldY+textfieldHeight){
			CheckOn = true;
			cout << "Work!" << endl;
		}
		else{
			CheckOn = false;
		}
		//answer textfield 2
		if(mouseX >= textfieldX && mouseX <= textfieldX+textfieldWidth && mouseY >= textfieldY+50 && mouseY <= textfieldY+textfieldHeight+50){ 
			CheckOn2 = true;
		}
		else{
			CheckOn2 = false;
		}
		//answer textfield 3
		if(mouseX >= textfieldX && mouseX <= textfieldX+textfieldWidth && mouseY >= textfieldY+100 && mouseY <= textfieldY+textfieldHeight+100){
			CheckOn3 = true;
		}
		else{
			CheckOn3 = false;
		}
		//answer textfield 4
		if(mouseX >= textfieldX && mouseX <= textfieldX+textfieldWidth && mouseY >= textfieldY+150 && mouseY <= textfieldY+textfieldHeight+150){ 
			CheckOn4 = true;
		}
		else{
			CheckOn4 = false;
		}
		//answer textfield 5
		if(mouseX >= textfieldX && mouseX <= textfieldX+textfieldWidth && mouseY >= textfieldY+200 && mouseY <= textfieldY+textfieldHeight+200){
			CheckOn5 = true;
		}
		else{
			CheckOn5 = false;
		}
	}

	///////////////This is for making hint textfields clickable///////////////////

	//hint textfield 1
	if(mouseX >= textfieldX+340 && mouseX <= textfieldX+textfieldWidth+340 && mouseY >= textfieldY && mouseY <= textfieldY+textfieldHeight){
		HintOn = true;
	}
	else{
		HintOn = false;
	}
	//hint textfield 2
	if(mouseX >= textfieldX+340 && mouseX <= textfieldX+textfieldWidth+340 && mouseY >= textfieldY+50 && mouseY <= textfieldY+textfieldHeight+50){
		HintOn2 = true;
	}
	else{
		HintOn2 = false;
	}
	//hint textfield 3
	if(mouseX >= textfieldX+340 && mouseX <= textfieldX+textfieldWidth+340 && mouseY >= textfieldY+100 && mouseY <= textfieldY+textfieldHeight+100){
		HintOn3 = true;
	}
	else{
		HintOn3 = false;
	}
	//hint textfield 4
	if(mouseX >= textfieldX+340 && mouseX <= textfieldX+textfieldWidth+340 && mouseY >= textfieldY+150 && mouseY <= textfieldY+textfieldHeight+150){
		HintOn4 = true;
	}
	else{
		HintOn4 = false;
	}
	//hint textfield 5
	if(mouseX >= textfieldX+340 && mouseX <= textfieldX+textfieldWidth+340 && mouseY >= textfieldY+200 && mouseY <= textfieldY+textfieldHeight+200){
		HintOn5 = true;
	}
	else{
		HintOn5 = false;
	}

	///////This is for making the answer visible or not///////
	if(mouseX >= buttonX && mouseX <= buttonX+150 && mouseY >= buttonY && mouseY <= buttonY+30){
		showAnswers = false;
	}
	if(mouseX >= buttonX+170 && mouseX <= buttonX+320 && mouseY >= buttonY && mouseY <= buttonY+30){
		showAnswers = true;
	}
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
