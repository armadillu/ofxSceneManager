#pragma once

#include "ofMain.h"
#include "ofxAnimatableFloat.h"

#include "ofxSceneManager.h"
#include "MyScene1.h"
#include "MyScene2.h"
#include "MyScene3.h"


class testApp : public ofBaseApp{

	enum Scenes{ SCENE_1 = 1, SCENE_2, SCENE_3 };
	
	public:
		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
	
		void windowResized(int w, int h);
	
		ofxSceneManager *		sceneManager;
};
