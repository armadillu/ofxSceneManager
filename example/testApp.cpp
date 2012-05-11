#include "testApp.h"


void testApp::setup(){

	ofSetFrameRate(60);
	ofEnableAlphaBlending();
	ofSetVerticalSync(true);
	ofBackground(32, 32, 32);
	ofEnableSmoothing();
		
	///////////////////////////////////////
	
	screenManager = new ofxSceneManager();
	screenManager->addScreen( new MyScene1(), SCENE_1);
	screenManager->addScreen( new MyScene2(), SCENE_2);
	screenManager->addScreen( new MyScene3(), SCENE_3);
	
	screenManager->setDrawDebug(true);
	screenManager->setCurtainDropTime(1.0);
	screenManager->setCurtainStayTime(0.0);
	screenManager->setCurtainRiseTime(1.0);
	screenManager->setOverlapUpdate(true);
}

void testApp::update(){
	
	float dt = 0.016666666;
	screenManager->update( dt );
		
}


void testApp::draw(){

	screenManager->draw();
	
	ofSetColor(255,0,0);
	ofDrawBitmapString( "press 1, 2, or 3 to change scene", ofGetWidth() - 290, ofGetHeight() - 10);	
}


void testApp::keyPressed(int key){

	if (key == '1') screenManager->goToScreen(SCENE_1, true); /* true >> regardless of curtain state (so u can change state while curtain is moving)*/
	if (key == '2') screenManager->goToScreen(SCENE_2);
	if (key == '3') screenManager->goToScreen(SCENE_3);
}


void testApp::windowResized(int w, int h){
	screenManager->windowResized(w,h); // in case your screens need to know, will forward to all of them
}
