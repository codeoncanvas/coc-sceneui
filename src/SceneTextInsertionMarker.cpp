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
//#include "cocSceneTexture.h"

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
    
SceneTextInsertionMarker::~SceneTextInsertionMarker() {
    //
}
    
void SceneTextInsertionMarker::exit() {
    
    exit();
    
}
    
SceneTextInsertionMarkerRef SceneTextInsertionMarker::create(std::string _assetPath) {
    SceneTextInsertionMarkerRef marker(new SceneTextInsertionMarker());
    marker->objectType = ObjectTypeCustom;
    marker->assetPath = _assetPath;
    return marker;
}
    
void SceneTextInsertionMarker::setup() {
    
    coc::scene::Object::setup();
    
    markerPos = vec2(0,0);
    
    insertionMarker = gl::Texture::create( loadImage( getAssetPath( assetPath ) ) );

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
