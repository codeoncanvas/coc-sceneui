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

#pragma once

#include "cocSceneObject.h"

namespace coc {

//--------------------------------------------------------------
class SceneTextInsertionMarker;
typedef std::shared_ptr<SceneTextInsertionMarker> SceneTextInsertionMarkerRef;
    
class SceneTextInsertionMarker :  public coc::scene::Object {

public:
    
    SceneTextInsertionMarker(std::string objID="");
    ~SceneTextInsertionMarker();
    
    static SceneTextInsertionMarkerRef create(const glm::ivec2 & size);
    static SceneTextInsertionMarkerRef create(int width, int height);
    
    void setMarkerColor(const ci::ColorA & value) { markerColor = value; }
    
    void exit();
    
    void setup() override;
    
    void update() override;
    
    void drawSelf() override;
    
    void setOn() { bEnabled = true; };
    
    void setOff() { bEnabled = false; };
    
    glm::vec2 markerPos;
    ci::ColorA markerColor;
    
    ci::gl::TextureRef insertionMarker;
    bool bEnabled;
    bool bVisible;
    
};
    
};
