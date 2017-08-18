//
//	    ┌─┐╔═╗┌┬┐┌─┐
//      │  ║ ║ ││├┤
//      └─┘╚═╝─┴┘└─┘
//	 ┌─┐┌─┐╔╗╔┬  ┬┌─┐┌─┐
//	 │  ├─┤║║║└┐┌┘├─┤└─┐
//	 └─┘┴ ┴╝╚╝ └┘ ┴ ┴└─┘
//	http://CodeOnCanvas.cc
//
// Copyright (c) 2016, Code on Canvas Pty Ltd

#pragma once

#include "cocSceneObject.h"
#include "ciButton.h"

namespace coc {

class SceneButton;
typedef std::shared_ptr<SceneButton> SceneButtonRef;

class SceneButton : public coc::scene::Object, public coc::ciButton {
public:

    SceneButton(std::string objID="");
    ~SceneButton();
    
    static SceneButtonRef create(const coc::scene::ObjectRef & object);
    static SceneButtonRef create(const glm::ivec2 & size);
    static SceneButtonRef create(int width, int height);

    virtual void setup() override;

    virtual void update() override;
    
    virtual void drawSelf() override;
    
	virtual void pointMoved(int pointX, int pointY, int pointID=0) override;
    virtual void pointPressed(int pointX, int pointY, int pointID=0) override;
	virtual void pointDragged(int pointX, int pointY, int pointID=0) override;
	virtual void pointReleased(int pointX, int pointY, int pointID=0) override;
    
    ci::gl::TextureRef texUp;
    ci::gl::TextureRef texOver;
    ci::gl::TextureRef texDown;
    
    glm::vec2 screenPointDown;
    float releaseDistLimit;
    
    bool bDebug;

};

};
