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
#include "cocScrollView.h"
#include "cocFboWrapper.h"
#include "ciImage.h"

namespace coc {

class SceneScrollView;
typedef std::shared_ptr<SceneScrollView> SceneScrollViewRef;

class SceneScrollView : public coc::scene::Object, public coc::ScrollView {
public:

    SceneScrollView(std::string objID="");
    ~SceneScrollView();

    static SceneScrollViewRef create(const coc::scene::ObjectRef & object);
    static SceneScrollViewRef create(const glm::ivec2 & size);
    static SceneScrollViewRef create(int width, int height);

    void setMaskTexture(const ci::gl::TextureRef & value) { maskTexture = value; }
    void setMaskShader(const ci::gl::GlslProgRef & value) { maskShader = value; }
    void setClearColor(const ci::ColorA & value) { fboClearColor = value; }
    
    virtual void setup() override;
    
    void addChild(const coc::scene::ObjectRef & child) override;
    
    virtual void update() override;
    
    virtual void drawSelf() override;
    
	virtual void pointMoved(int pointX, int pointY, int pointID=0) override;
    virtual void pointPressed(int pointX, int pointY, int pointID=0) override;
	virtual void pointDragged(int pointX, int pointY, int pointID=0) override;
	virtual void pointReleased(int pointX, int pointY, int pointID=0) override;
    bool inside(glm::vec2 pos);
    
    coc::scene::ObjectRef container;
    coc::FboWrapper fbo0;
    coc::FboWrapper fbo1;
    coc::ciImageRef fboImage;
    ci::ColorA fboClearColor;
    
    ci::gl::GlslProgRef maskShader;
    ci::gl::TextureRef maskTexture;

    bool bDisablePoints = false; //useful if only wanting programmatic control instead touch/cursor

	ci::vec2 screenToLocalContainer( ci::vec2 p );

};

};
