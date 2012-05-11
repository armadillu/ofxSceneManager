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

class MyScene1 : public ofxScene{

	virtual void setup(){  //load your scene 1 assets here...
		printf("MyScene1 setup\n");
		radius = 0;
		visible = false;
	};
	
	virtual void update(float){ //update scene 1 here		
		if (visible){ 
			radius ++;	// grow when appearing
		}else { 
			radius -= 2; // shrink when leaving
		}
		radius = ofClamp(radius, 0, 150);
	};
	
	void draw(){ //draw scene 1 here

		float rSize = 10;
		ofSetRectMode(OF_RECTMODE_CENTER);
		for (int i = 0; i < 100; i++) {
			ofSetColor( ofRandom(255), ofRandom(255), ofRandom(255) );
			float randRad = ofRandom(radius);
			float randAng = ofRandom(2.0 * M_PI);
			float xx = ofGetAppPtr()->mouseX + randRad * cosf( randAng );
			float yy = ofGetAppPtr()->mouseY + randRad * sinf( randAng );
			ofRect( xx, yy, rSize, rSize );
		}
		ofSetRectMode(OF_RECTMODE_CORNER);
	};
	
	//screen notifications
	void screenWillAppear( ofxScene * fromScreen ){ 
		radius = 0; // reset our scene when we appear
		visible = true;
	};
	
	void screenWillDisappear( ofxScene * toScreen ){ 
		visible = false;
	}
	
	float radius;
	bool visible;
};

#endif
