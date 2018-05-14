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

class SceneKeyButton;
typedef std::shared_ptr<SceneKeyButton> SceneKeyButtonRef;

class SceneKeyButton : public coc::scene::Object, public coc::ciButton {
public:

    SceneKeyButton(std::string objID="");
    ~SceneKeyButton();
    
    static SceneKeyButtonRef create(const coc::scene::ObjectRef & object);
    static SceneKeyButtonRef create(const glm::ivec2 & size);
    static SceneKeyButtonRef create(int width, int height);

    virtual void setup() override;

    virtual void update() override;
    
    virtual void drawSelf() override;
    
	virtual void pointMoved(int pointX, int pointY, int pointID=0) override;
    virtual void pointPressed(int pointX, int pointY, int pointID=0) override;
	virtual void pointDragged(int pointX, int pointY, int pointID=0) override;
	virtual void pointReleased(int pointX, int pointY, int pointID=0) override;
    
    ci::gl::TextureRef texUpBg, texUpFg;
    ci::gl::TextureRef texDownBg, texDownFg;

    ci::ColorA colUpBg, colUpFg;
	ci::ColorA colDownBg, colDownFg;
    
    glm::vec2 screenPointDown;
    float releaseDistLimit;
    
    bool bDebug;

};

};
