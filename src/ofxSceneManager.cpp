/*
 *  ofxSceneManager.cpp
 *  Cocoa Test
 *
 *  Created by Oriol Ferrer Mesià on 02/11/09.
 *  Copyright 2009 uri.cat. All rights reserved.
 *
 */

#include "ofxSceneManager.h"
#include "ofxScene.h"

ofxSceneManager::ofxSceneManager(){

	currentScreen = futureScreen = NULL;
	curtainDropTime = 0.5;
	curtainStayTime = 0.0;
	curtainRiseTime = 0.5;
	drawDebugInfo = false;
	overlapUpdate = false;
}


ofxSceneManager::~ofxSceneManager(){}


void ofxSceneManager::addScreen( ofxScene* newScreen, string screenID ){

	int c = screens.count( screenID );
	
	if ( c > 0 ){
		printf("ofxSceneManager::addScreen(%s) >> we already have a screen with that ID", screenID.c_str() );
	}else{
		newScreen->setup();
		newScreen->setScreenID( screenID );
		newScreen->setManager( this );
		screens[screenID] = newScreen;
		printf("ofxSceneManager::addScreen(%s) >> added screen\n", screenID.c_str() );		
		if (screens.size() == 1){	//first screen, we activate it
			currentScreen = getScreen( screenID );
			goToScreen( screenID, true/*regardless*/, false/*transition*/ ); 
		}
	}
}


void ofxSceneManager::update( float dt ){

	if ( !curtain.isReady() ){ //curtain is busy, so we are pre or post transition

		curtain.update(dt);
		if ( curtain.hasReachedBottom() ){			
			currentScreen->sceneDidDisappear(futureScreen);
			futureScreen->sceneWillAppear(currentScreen);
			updateHistory( futureScreen );
			currentScreen = futureScreen;
			futureScreen = NULL;
		}
		
		if ( curtain.hasReachedTop() ){
			currentScreen->sceneDidAppear();
		}
	}else{
		futureScreen = NULL;			
	}

	
	if (currentScreen != NULL){
						
		vector <ofxScene*> screensToUpdate;
		screensToUpdate.push_back(currentScreen);
		if (overlapUpdate){
			if (futureScreen != NULL){
				screensToUpdate.push_back(futureScreen);
			}
		}
		
		for (int i = 0; i < screensToUpdate.size(); i++){
			ofxScene * s = screensToUpdate[i];
			s->update(dt);
		}
	}
}


void ofxSceneManager::draw(){

	if (currentScreen != NULL){
		
		vector <ofxScene*> screensToDraw;
		screensToDraw.push_back(currentScreen);
		
		for (int i = 0; i < screensToDraw.size(); i++){
			ofxScene * s = screensToDraw[i];
			s->draw();
			if (drawDebugInfo){
				ofSetColor(255, 0, 0);
				s->drawDebug();
			}
		}
		
		if ( !curtain.isReady() ){
			curtain.draw();
		}
		//curtain.drawDebug();
	}
	
	if (drawDebugInfo){
		ofSetColor(255, 0, 0);
		drawDebug();
	}
}

void ofxSceneManager::drawDebug(){

	int y = 20;
	int x = 20;
	int lineHeight = 15;
	if (currentScreen){
		ofDrawBitmapString( "current ofxScene: " + currentScreen->getScreenID() , x, y);
		y += lineHeight;
	}
	if (futureScreen){
		ofDrawBitmapString( "Future ofxScene: " + futureScreen->getScreenID() , x, y);
		y += lineHeight;
	}
}


bool ofxSceneManager::goToScreen( string ID, bool regardless, bool doTransition){
	
	if ( curtain.isReady() || regardless){

		ofxScene * next = getScreen( ID );
		
		if (doTransition){
			
			if (next != NULL){
				futureScreen = next;
				curtain.dropAndRaiseCurtain(curtainDropTime, curtainStayTime, curtainRiseTime, regardless);
				currentScreen->sceneWillDisappear(futureScreen);				
				return true;
			}else{
				printf("ofxSceneManager::gotoScreen(%s) >> screen not found!\n", ID.c_str());
			}			
		}else{	
			
			if (next != NULL){
				//notify
				currentScreen->sceneWillDisappear(next);
				next->sceneWillAppear(currentScreen);
				currentScreen->sceneDidDisappear(futureScreen);
				next->sceneDidAppear();
				//hot-swap current screens
				currentScreen = next;
				futureScreen = NULL;
				return true;
			}
		}

	}else{
		if (futureScreen != NULL)
			printf("ofxSceneManager::gotoScreen(%s) >> CANT DO! we are in the middle of a transition to %s!\n", ID.c_str(), futureScreen->getScreenID().c_str() );
		else
			printf("ofxSceneManager::gotoScreen(%s) >> CANT DO! we are in the middle of a transition to another screen!\n", ID.c_str() );
	}
	return false;
}


void ofxSceneManager::updateHistory( ofxScene * s ){
	
	history.push_back(s);
	if (history.size() > MAX_HISTORY){
		history.erase(history.begin());
	}	
}


int ofxSceneManager::getNumScreens(){ 
	return screens.size(); 
}


ofxScene * ofxSceneManager::getCurrentScreen(){ 
	return currentScreen;
}


string ofxSceneManager::getCurrentScreenID(){ 
	if (currentScreen != NULL )
		return currentScreen->getScreenID();
	else
		return "NULL";
}


ofxScene * ofxSceneManager::getScreen(string screenID){
	if ( screens.count( screenID ) > 0 ){
		return screens[screenID];
	}else{
		return NULL;
	}
};

void ofxSceneManager::setCurtainDropTime(float t){
	curtainDropTime = t;
}

void ofxSceneManager::setCurtainStayTime(float t){
	curtainStayTime = t;
}

void ofxSceneManager::setCurtainRiseTime(float t){
	curtainDropTime = t;
}

void ofxSceneManager::setOverlapUpdate(bool t){
	overlapUpdate = t;
}


/// ALL EVENTS HERE /////////////////////////////////////////////////////////// TODO

void ofxSceneManager::keyPressed(int key){
	if (currentScreen != NULL) currentScreen->keyPressed( key );
}

void ofxSceneManager::mouseMoved(int x, int y){	
	if (currentScreen != NULL) currentScreen->mouseMoved( x, y );
}

void ofxSceneManager::windowResized (int w, int h){
	
	for( map<string,ofxScene*>::iterator ii = screens.begin(); ii != screens.end(); ++ii ){
		//string key = (*ii).first;
		ofxScene* t = (*ii).second;
		t->windowResized(w, h);
	}
}
