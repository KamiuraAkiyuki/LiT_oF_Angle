#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);
    ofSetCircleResolution(64);
    radiusValue = hypotf(mousePosition.y, mousePosition.x);
    angleValue = (atan2(mousePosition.y, -mousePosition.x)+pi)*360/(2*pi);
}

//--------------------------------------------------------------
void ofApp::update(){
    
    //color.setHsb((atan2(mousePosition.y, -mousePosition.x)+pi)/(2*pi)*255.0, 255, 255);
    color.setHsb(ofGetElapsedTimeMillis()/10%256, 255, 255);
    
    angleValue = (atan2(mousePosition.y, -mousePosition.x)+pi)/(2*pi)*360;
    if (!isSpacePressed){
        radiusValue = hypotf(mousePosition.x, mousePosition.y);
    }
    else {
        radiusValue = hypotf(mousePosition.x, mousePosition.y) + ofRandom(-5, 5);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    // 座標の中心をスクリーンの真ん中にする
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    
    // 線の太さを2pxに設定
    ofSetLineWidth(2);
    
    // 方眼の背景
    ofSetColor(200);
    for (int i = -14; i < 15; i++){
        ofLine(ofGetWidth()*i/30, -ofGetHeight()/2, ofGetWidth()*i/30, ofGetHeight()/2);
    }
    for (int i = -9; i < 10; i++){
        ofLine(-ofGetWidth()/2, ofGetHeight()*i/20, ofGetWidth()/2, ofGetHeight()*i/20);
    }

    
    // マウスの位置に十字のラインを描画
    ofSetColor(100);
    ofLine(-ofGetWidth()/2, mousePosition.y, ofGetWidth()/2, mousePosition.y);
    ofLine(mousePosition.x, -ofGetHeight()/2, mousePosition.x, ofGetHeight()/2);
    
    // 色を指定
    ofPushStyle();
    ofSetLineWidth(3);
    ofSetColor(color, 180);
    ofLine(radiusValue*cosf(atan2(mousePosition.y, mousePosition.x))/4, radiusValue*sinf(atan2(mousePosition.y, mousePosition.x))/4, radiusValue*cosf(atan2(mousePosition.y, mousePosition.x)), radiusValue*sinf(atan2(mousePosition.y, mousePosition.x)));
    ofNoFill();
    ofCircle(0, 0, radiusValue);
    ofFill();
    ofCircle(0, 0, radiusValue/4);
    ofPopStyle();
    
    // spacekeyが押されたモード
    if (isSpacePressed){
        // 半径と角度の値を文字で表示
        ofSetColor(100);
        string radiusString = "radius: " + ofToString(radiusValue);
        ofDrawBitmapString(radiusString, mousePosition.x + 5, mousePosition.y + 15);
        string angleString = "angle: " + ofToString(angleValue);
        ofDrawBitmapString(angleString, mousePosition.x + 5, mousePosition.y + 35);
        
        // 扇型の描画
        ofBeginShape();
        ofSetColor(150, 150, 150, 200);
        ofVertex(0, 0);
        ofVertex(radiusValue, 0);
        for (int i = 1; i < (int)angleValue*4; i++){
            ofVertex(radiusValue*cosf(i/180.0*pi/4), -radiusValue*sinf(i/180.0*pi/4));
        }
        ofEndShape();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    switch (key){
        case ' ':
            isSpacePressed = !isSpacePressed;
            break;
        default:
            break;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int mousex, int mousey){
    mousePosition.x = mousex - ofGetWidth()/2;
    mousePosition.y = mousey - ofGetHeight()/2;
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
