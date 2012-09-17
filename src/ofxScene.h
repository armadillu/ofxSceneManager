/*
 *  ofxScene.h
 *  Cocoa Test
 *
 *  Created by Oriol Ferrer Mesià on 28/10/09.
 *  Copyright 2009 uri.cat. All rights reserved.
 *
 */

/**
 
 Mainly an abstract class, to define a protocol for custom "ofxScene" subclasses
 
 **/

#ifndef ofxScene_h
#define ofxScene_h

//#include "ofxSceneManager.h"
#include "ofMain.h"

class ofxSceneManager;

class ofxScene{

	public:

		ofxScene(){ printf("ofxScene Constructor \n"); };	
		virtual ~ofxScene() { printf("ofxScene Destructor :: %d\n", sceneID); }

		virtual void setup(){ printf("ofxScene setup :: %d\n", sceneID); };
		
		virtual void update(float){} ;
		virtual void draw(){};

		virtual void showUI(){}
		virtual void hideUI(){}

		virtual void pauseScene(){}
		virtual void resumeScene(){}

		//notifications
		virtual void sceneWillAppear( ofxScene * fromScreen ) { printf("ofxScene::sceneWillAppear() :: %d\n", sceneID); };
		virtual void sceneDidAppear() { printf("ofxScene::sceneDidAppear() :: %d\n", sceneID); };
		virtual void sceneWillDisappear( ofxScene * toScreen) { printf("ofxScene::sceneWillDisappear() :: %d\n", sceneID); };
		virtual void sceneDidDisappear( ofxScene * fromScreen ) { printf("ofxScene::sceneDidDisappear() :: %d\n", sceneID); };
	
		//events - desktop
		virtual void keyPressed(int key) {} ;
		virtual void keyReleased(int key) {};
		virtual void mouseMoved(int x, int y ) {};
		virtual void mouseDragged(int x, int y, int button) {};
		virtual void mousePressed(int x, int y, int button) {};
		virtual void mouseReleased(int x, int y, int button) {};
		virtual void windowResized(int w, int h){};

		//touch events - iphone
		#ifdef TARGET_OF_IPHONE
		virtual void touchDown(ofTouchEventArgs &touch){};
		virtual void touchMoved(ofTouchEventArgs &touch){};
		virtual void touchUp(ofTouchEventArgs &touch){};
		virtual void touchDoubleTap(ofTouchEventArgs &touch){};
		virtual void touchCancelled(ofTouchEventArgs &touch){};
		#endif
	
		//visual debug
		virtual void drawDebug(){ ofDrawBitmapString( "I am Scene: " + ofToString(sceneID), ofGetWidth() - 200, 20); }
	
		int getSceneID(){ return sceneID;}
		ofxSceneManager * getManager(){ return manager;}
	private:

		friend class ofxSceneManager;
		void setSceneID( int s ){ sceneID = s; }
		void setManager( ofxSceneManager *sm ){ manager = sm; }
	
		int sceneID;
		ofxSceneManager * manager;
};

#endif

