/*
*  Created by Tobias Zimmer, August 2016.
*  www.tobiaszimmer.net
*
*  Font originally developed by Dr. Allen V. Hershey in 1967.
*  Font vectors made available by Paul Bourke.
*  paulbourke.net/dataformats/hershey/
*
*/

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(255);

	//set color of the font (default is black)
	hersheyFont.setColor(ofColor(0));
}

//--------------------------------------------------------------
void ofApp::update(){
	
}

//--------------------------------------------------------------
void ofApp::draw(){
	//gui information
	ofSetColor(0);
	ofDrawBitmapString("press 's' to save as svg", 20, 30);
	ofDrawBitmapString("press 'p' to save as pdf", 20, 50);
	ofDrawBitmapString("available characters:", 20, 140);

	drawFont();
}

//--------------------------------------------------------------
void ofApp::drawFont() {
	//characters are available from ASCII-Code 32 to 126
	//if a character you want to draw is not available, the output is '?'

	//draw all available characters 
	int asciiCode = 32;
	for (int y = 0; y < 10; y++)
	{
		for (int x = 0; x < 10; x++)
		{
			string character = ofToString((char)asciiCode);
			hersheyFont.draw(character, 20 + x * 40, 210 + y * 40, 1);
			asciiCode++;
		}
	}

	//simple
	//inputs: string, xPos,	yPos, scale
	hersheyFont.draw("size 0.5", 600, 210, .5);
	hersheyFont.draw("size 1", 720, 210, 1);
	hersheyFont.draw("size 1.5", 870, 210, 1.5);

	//centered
	//inputs: string, xPos, yPos, scale, centered
	hersheyFont.draw("CENTERED", 800, 290, .75, true);
	hersheyFont.draw("CENTERED CENTERED", 800, 290 + 40, .75, true);

	//rotated
	//inputs: string, xPos, yPos, scale, centered, angle
	hersheyFont.draw("ROTATE", 610, 450, .75, false, mouseX);

	//rotate centered
	hersheyFont.draw("ROTATE CENTERED", 940, 450, .75, true, mouseX);

	//getPath
	//if you need more flexibility, you can get the font vectors as ofPath
	ofPath p = hersheyFont.getPath("GETPATH", .75);
	p.draw(765, 570);
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	switch (key) {
	case 'p':
		ofBeginSaveScreenAsPDF("file.pdf");
			drawFont();
		ofEndSaveScreenAsPDF();
		break;
	case 's':
		ofBeginSaveScreenAsSVG("file.svg");
			drawFont();
		ofEndSaveScreenAsSVG();
		break;
	}
}