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

SceneTextInsertionMarkerRef SceneTextInsertionMarker::create(const coc::scene::ObjectRef & object, bool replace )
{
    if(object == nullptr) {
        return nullptr;
    }
    SceneTextInsertionMarkerRef insert = SceneTextInsertionMarker::create( object->width, object->height );
    insert->x = object->x;
    insert->y = object->y;
//    insert->markerPos.x = object->x;
//    insert->markerPos.y = object->y;
    if (replace && object->getParent()) {
        object->getParent()->replaceChild(object, insert);
    }
    return insert;
}

SceneTextInsertionMarkerRef SceneTextInsertionMarker::create(const glm::ivec2 & size) {
    return create(size.x, size.y);
}
    
SceneTextInsertionMarkerRef SceneTextInsertionMarker::create(int width, int height) {
    SceneTextInsertionMarkerRef marker(new SceneTextInsertionMarker());
    marker->objectType = ObjectTypeCustom;
    marker->width = width;
    marker->height = height;
    return marker;
}

    
void SceneTextInsertionMarker::setup() {
    
    coc::scene::Object::setup();
    
}
    
void SceneTextInsertionMarker::update() {

    if (text && text->tex) {
        markerPos.x = text->tex->getWidth();
    }
    
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
            gl::color(markerColor);
            Rectf cursor = Rectf(markerPos.x, markerPos.y, markerPos.x+this->width, markerPos.y+this->height );
            gl::drawSolidRect(cursor);
        }
    }

}


};
