#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	dotstar.setup(87);
	receiver.setup(12400);
}

//--------------------------------------------------------------
void ofApp::update(){
	
	ofBuffer buf;
	int sigLength = -1;
	
	while (receiver.hasWaitingMessages())
	{
		
		ofxOscMessage m;
		receiver.getNextMessage(&m);
		
		if (m.getAddress() == "/led/set")
		{
			buf = m.getArgAsBlob(0);
			sigLength = m.getArgAsInt32(1);
		}
		
		
	}
	
	if (sigLength > 0)
	{
		vector<char> bytes;
		char byte = 0x00;
		for (int i = 0;i < buf.size();i++)
		{
			if (i % 2 == 0) byte = buf.getBinaryBuffer()[i];
			if (i % 2 == 1)
			{
				for (int j = 0;j < (int)(unsigned char)(buf.getBinaryBuffer()[i]);j++)
				{
					bytes.push_back(byte);
				}
			}
		}
		
		int numPix = bytes.size()/3;
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
