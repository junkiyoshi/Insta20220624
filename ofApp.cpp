#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openFrameworks");

	ofBackground(0);
	ofSetLineWidth(2);
	ofSetCircleResolution(60);
	ofNoFill();
	//ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_ADD);
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWindowSize() * 0.5);

	auto frame_param = ofGetFrameNum() % 180;
	auto noise_param = frame_param < 60 ? ofMap(frame_param, 0, 60, 0, 1) : frame_param < 90 ? 1 : frame_param < 150 ? ofMap(frame_param, 90, 150, 1, 0) : 0;

	for (int i = 0; i < 4; i++) {

		auto x = ofMap(ofNoise(ofRandom(1000), ofGetFrameNum() * 0.01), 0, 1, -360, 360) * noise_param;
		auto y = ofMap(ofNoise(ofRandom(1000), ofGetFrameNum() * 0.01), 0, 1, -360, 360) * noise_param;
		
		ofDrawCircle(x, y, 65);

		auto deg = ofMap(i, 0, 4, 0, 180);
		ofDrawLine(glm::vec2(x + 50 * cos(deg * DEG_TO_RAD), y + 50 * sin(deg * DEG_TO_RAD)), glm::vec2(x + 80 * cos(deg * DEG_TO_RAD), y + 80 * sin(deg * DEG_TO_RAD)));
		ofDrawLine(glm::vec2(x + 50 * cos((deg + 180) * DEG_TO_RAD), y + 50 * sin((deg + 180) * DEG_TO_RAD)), glm::vec2(x + 80 * cos((deg + 180) * DEG_TO_RAD), y + 80 * sin((deg + 180) * DEG_TO_RAD)));
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}