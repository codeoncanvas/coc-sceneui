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
    
    static SceneTextInsertionMarkerRef create(std::string assetPath);
    
    void exit();
    
    void setup() override;
    
    void update() override;
    
    void drawSelf() override;
    
    void setOn() { bEnabled = true; };
    
    void setOff() { bEnabled = false; };
    
    glm::vec2 markerPos;
    
    ci::gl::TextureRef insertionMarker;
    std::string assetPath;
    bool bEnabled;
    bool bVisible;
    
};
    
};
