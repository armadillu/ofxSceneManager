//
//  MyScene2.h
//  emptyExample
//
//  Created by Oriol Ferrer Mesià on 11/05/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef emptyExample_MyScene2_h
#define emptyExample_MyScene2_h

#include "ofMain.h"
#include "ofxScene.h"

class MyScene2 : public ofxScene{

	
	void setup(){ 
		printf("MyScene2 setup\n");
		camera.initGrabber(640, 480);	//start cam when we get notified that we will be shown soon
	};
	
	
	void update(float){ //update scene 2 here
		camera.update();
	};
	
	
	void draw(){ //draw scene 2 here
		ofSetColor(255);
		camera.draw( 0, 0, ofGetWidth(), ofGetHeight() );
	};
		
	ofVideoGrabber camera;

};

#endif
