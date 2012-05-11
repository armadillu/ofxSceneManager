//
//  MyScene3.h
//  emptyExample
//
//  Created by Oriol Ferrer Mesià on 11/05/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef emptyExample_MyScene3_h
#define emptyExample_MyScene3_h

#include "ofMain.h"
#include "ofxScene.h"

class MyScene3 : public ofxScene{

	
	void setup(){  //load your scene 3 assets here...
		printf("MyScene3 setup\n");
	};
	
	
	void update(float){ //update scene 3 here
	};
	
	
	void draw(){ //draw scene 3 here
		ofSetColor(128);
		ofNoFill();
		ofBeginShape();
		for (int i = 0; i < 12; i++){
			ofCurveVertex( ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight()) );
		}
		ofEndShape();
		ofFill();
	};
};

#endif
