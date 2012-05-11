//
//  MyScene1.h
//  emptyExample
//
//  Created by Oriol Ferrer Mesià on 11/05/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef emptyExample_MyScene1_h
#define emptyExample_MyScene1_h

#include "ofMain.h"
#include "ofxScene.h"
#include "ofxAnimatableFloat.h"

class MyScene1 : public ofxScene{

	virtual void setup(){  //load your scene 1 assets here...
		printf("MyScene1 setup\n");
		radius.reset(0);
		radius.setDuration(0.75);
		radius.setCurve(TANH);
	};
	
	virtual void update(float dt){ //update scene 1 here		
		radius.update(dt);
	};
	
	void draw(){ //draw scene 1 here

		float rSize = 10;
		ofSetRectMode(OF_RECTMODE_CENTER);
		for (int i = 0; i < 100; i++) {
			ofSetColor( ofRandom(255), ofRandom(255), ofRandom(255) );
			float randRad = ofRandom( radius.val() );
			float randAng = ofRandom(2.0 * M_PI);
			float xx = ofGetAppPtr()->mouseX + randRad * cosf( randAng );
			float yy = ofGetAppPtr()->mouseY + randRad * sinf( randAng );
			ofRect( xx, yy, rSize, rSize );
		}
		ofSetRectMode(OF_RECTMODE_CORNER);
	};
	
	//screen notifications
	void screenWillAppear( ofxScene * fromScreen ){  // reset our scene when we appear
		radius.reset(0); 
		radius.animateTo(150);
	};
	
	void screenWillDisappear( ofxScene * toScreen ){ 
		radius.animateTo(0);
	}
	
	ofxAnimatableFloat radius;
};

#endif
