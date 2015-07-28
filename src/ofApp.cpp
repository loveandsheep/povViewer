#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	dotstar.setup(NUMLED);
	receiver.setup(12400);
	ofSetVerticalSync(false);
	ofSetFrameRate(60);
}

//--------------------------------------------------------------
void ofApp::update(){
	
	ofBuffer buf;
	int sigLength = -1;
	
	while (receiver.hasWaitingMessages())
	{
		
		ofxOscMessage m;
		receiver.getNextMessage(&m);
		
		if (!receiver.hasWaitingMessages()){
			if (m.getAddress() == "/led/set")
			{
				buf = m.getArgAsBlob(0);
				sigLength = m.getArgAsInt32(1);
			}
		}
		
		
	}
	
	if (sigLength > 0)
	{
		int cnt = 0;
		char byte = 0x00;
		for (int i = 0;i < buf.size();i++)
		{
			if (i % 2 == 0) byte = buf.getBinaryBuffer()[i];
			if (i % 2 == 1)
			{
				int byteNum = (int)(unsigned char)(buf.getBinaryBuffer()[i]);
				memset(&bytes[cnt], (int)(unsigned char)byte, byteNum);
				
				cnt += byteNum;
			}
		}
		
		int numPix = NUMLED;
		for (int i = 0;i < numPix;i++){
			dotstar.setColor(i,
							 bytes[i],
							 bytes[i + numPix],
							 bytes[i + numPix * 2]);
		}
	}
	
	dotstar.show();
}

//--------------------------------------------------------------
void ofApp::draw(){
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
