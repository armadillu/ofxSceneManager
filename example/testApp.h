#pragma once

#include "ofMain.h"
#include "ofxAnimatableFloat.h"

#include "ofxSceneManager.h"
#include "MyScene1.h"
#include "MyScene2.h"
#include "MyScene3.h"

#define SCENE_1	"Scene1"
#define SCENE_2	"Scene2"
#define SCENE_3	"Scene3"


class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
	
		void windowResized(int w, int h);
	
		ofxSceneManager *		screenManager;
};
