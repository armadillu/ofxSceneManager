#include "testApp.h"


void testApp::setup(){

	ofSetFrameRate(60);
	ofEnableAlphaBlending();
	ofSetVerticalSync(true);
	ofBackground(32, 32, 32);
	ofEnableSmoothing();
		
	///////////////////////////////////////
	
	sceneManager = new ofxSceneManager();
	sceneManager->addScene( new MyScene1(), SCENE_1);
	sceneManager->addScene( new MyScene2(), SCENE_2);
	sceneManager->addScene( new MyScene3(), SCENE_3);
	
	sceneManager->setDrawDebug(true);
	sceneManager->setCurtainDropTime(1.0);
	sceneManager->setCurtainStayTime(0.0);
	sceneManager->setCurtainRiseTime(1.0);
	sceneManager->setOverlapUpdate(true);
}

void testApp::update(){
	
	float dt = 0.016666666;
	sceneManager->update( dt );
		
}


void testApp::draw(){

	sceneManager->draw();
	
	ofSetColor(255,0,0);
	ofDrawBitmapString( "press 1, 2, or 3 to change scene", ofGetWidth() - 290, ofGetHeight() - 10);	
}


void testApp::keyPressed(int key){
	
	if (key == '1') sceneManager->goToScene(SCENE_1, true); /* true >> regardless of curtain state (so u can change state while curtain is moving)*/
	if (key == '2') sceneManager->goToScene(SCENE_2);
	if (key == '3') sceneManager->goToScene(SCENE_3);
}


void testApp::windowResized(int w, int h){
	sceneManager->windowResized(w,h); // in case your screens need to know, will forward to all of them
}
