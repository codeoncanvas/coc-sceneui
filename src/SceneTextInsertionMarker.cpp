//
//	    ┌─┐╔═╗┌┬┐┌─┐
//      │  ║ ║ ││├┤
//      └─┘╚═╝─┴┘└─┘
//	 ┌─┐┌─┐╔╗╔┬  ┬┌─┐┌─┐
//	 │  ├─┤║║║└┐┌┘├─┤└─┐
//	 └─┘┴ ┴╝╚╝ └┘ ┴ ┴└─┘
//	http://CodeOnCanvas.cc
//
// Copyright (c) 2017, Code on Canvas Pty Ltd

#include "SceneTextInsertionMarker.h"

namespace coc {

using namespace std;
using namespace ci;
using namespace ci::app;
using namespace coc::scene;

SceneTextInsertionMarker::SceneTextInsertionMarker (std::string objID) :
coc::scene::Object(objID),
bEnabled(true),
bVisible(true) {
    
}
    
void SceneTextInsertionMarker::exit() {
    
    exit();
    
}
    
void SceneTextInsertionMarker::setup() {
    
    coc::scene::Object::setup();
    
    markerPos = vec2(0,0);
    
    insertionMarker = gl::Texture::create( loadImage( getAssetPath("svg/text/insertionMarker.png").string() ) );

}
    
void SceneTextInsertionMarker::update() {
    
    int elapsedTime = getElapsedSeconds();
    if (elapsedTime % 2 == 0) {
        bVisible = true;
    }
    else {
        bVisible = false;
    }
    
    coc::scene::Object::update();
}
    
void SceneTextInsertionMarker::drawSelf() {
    
    if (bEnabled) {
        if (bVisible) {
            gl::draw(insertionMarker, markerPos);
        }
    }

}


};
