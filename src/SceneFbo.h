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
#include "cocFboWrapper.h"
#include "ciImage.h"

namespace coc {

class SceneFbo;
typedef std::shared_ptr<SceneFbo> SceneFboRef;

class SceneFbo : public coc::scene::Object {
public:

    SceneFbo(std::string objID="");
    ~SceneFbo();
    
    static SceneFboRef create(const coc::scene::ObjectRef & object);
    static SceneFboRef create(const glm::ivec2 & size);
    static SceneFboRef create(int width, int height);

    virtual void setup() override;
    
    void addChild(const coc::scene::ObjectRef & child) override;

    virtual void update() override;
    
    virtual void drawSelf() override;
    
	virtual void pointMoved(int pointX, int pointY, int pointID=0) override;
    virtual void pointPressed(int pointX, int pointY, int pointID=0) override;
	virtual void pointDragged(int pointX, int pointY, int pointID=0) override;
	virtual void pointReleased(int pointX, int pointY, int pointID=0) override;
    
    coc::scene::ObjectRef container;
    coc::FboWrapper fbo;
    coc::ciImageRef fboImage;
    bool bUpdateFbo;
    bool bAlpha;
    bool bMipmap;
    ci::ColorA clearColor;

};

};
