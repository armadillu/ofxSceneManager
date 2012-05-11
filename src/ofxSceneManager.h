/*
 *  ofxSceneManager.h
 *
 *  Created by Oriol Ferrer Mesià on 02/11/09.
 *  Copyright 2009 uri.cat. All rights reserved.
 *
 */

#ifndef ofxSceneManager_h
#define ofxSceneManager_h

#define MAX_HISTORY	10

#include "ofxScreenCurtain.h"
#include "ofxScene.h"

class ofxScene;

class ofxSceneManager{

	public:

		ofxSceneManager();
		~ofxSceneManager();
	
		void update(float dt);
		void draw();
	
		void addScreen( ofxScene* newScreen, string screenID );
		
		bool goToScreen( string screenID, bool regardless = false, bool doTransition = true );

		//Events
		void windowResized(int w, int h);
		void keyPressed(int key);
		void mouseMoved(int x, int y);
		
		//debug
		void setDrawDebug(bool debug){ drawDebugInfo = debug; }
		bool getDrawDebug(){ return drawDebugInfo; }
	
		//settings
		void setCurtainDropTime(float t);
		void setCurtainStayTime(float t);
		void setCurtainRiseTime(float t);
		void setOverlapUpdate(bool o); // if true, we will update both screens while transitioning, otherwise just one at a time

	private:

		int getNumScreens();
		ofxScene * getCurrentScreen();
		string getCurrentScreenID();
		ofxScene * getScreen(string screenID);

		void updateHistory( ofxScene* );
		void drawDebug();
	
		map <string, ofxScene *>		screens; //fast access to screen by sID
			
		ofxScene*						currentScreen;
		ofxScene*						futureScreen;
	
		bool						overlapUpdate; // if true, we will update both screens when transitioning 
		bool 						drawDebugInfo;

		vector <ofxScene*>			history;

		ofxScreenCurtain			curtain;
		float						curtainDropTime;
		float						curtainStayTime;
		float						curtainRiseTime;
};

#endif
