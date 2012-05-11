#pragma once

#include "ofMain.h"
#include "ofxTimeMeasurements.h"
#include "ofxAnimatableFloat.h"

#include "ofxSceneManager.h"
#include "MyScene1.h"
#include "MyScene2.h"
#include "MyScene3.h"

#define SCREEN_1	"Screen1"
#define SCREEN_2	"Screen2"
#define SCREEN_3	"Screen3"


class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
	
		void windowResized(int w, int h);
	
		ofxSceneManager *		screenManager;
};
