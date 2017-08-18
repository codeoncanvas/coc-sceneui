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

#include "SceneFbo.h"
#include "cocGLUtils.h"

namespace coc {

using namespace std;
using namespace ci;
using namespace coc::scene;

SceneFbo::SceneFbo(std::string objID) :
coc::scene::Object(objID),
bUpdateFbo(true),
bAlpha(true),
bMipmap(false),
clearColor(1,1,1,0) {

    //
}

SceneFbo::~SceneFbo() {
    //
}

SceneFboRef SceneFbo::create(const coc::scene::ObjectRef & object) {
    SceneFboRef fbo(new SceneFbo());
    fbo->copyFrom(object);
    fbo->objectType = ObjectTypeCustom;
    fbo->getParent()->replaceChild(object, fbo); // replace object.
    return fbo;
}

SceneFboRef SceneFbo::create(const glm::ivec2 & size) {
    return create(size.x, size.y);
}

SceneFboRef SceneFbo::create(int width, int height) {
    SceneFboRef fbo(new SceneFbo());
    fbo->objectType = ObjectTypeCustom;
    fbo->width = width;
    fbo->height = height;
    return fbo;
}

void SceneFbo::setup() {
    
    container = coc::scene::Object::create();
    
    glm::vec2 fboSize(width, height);
    
    gl::Texture::Format fboTextureFormat = gl::Fbo::Format::getDefaultColorTextureFormat( bAlpha );
    if(bMipmap) {
        fboTextureFormat.enableMipmapping();
    }
    
    gl::Fbo::Format fboFormat;
    fboFormat.setColorTextureFormat(fboTextureFormat);
    
    fbo.setup(fboSize, fboFormat);
    
    fboImage = coc::ciImage::create(fbo.getTextureRef());
    fboImage->setSize(fboSize);
}

void SceneFbo::addChild(const coc::scene::ObjectRef & child) {
    if(container) {
        container->addChild(child);
    }
}

void SceneFbo::update() {

    coc::scene::Object::update();
    
    bool bShowing = true;
    bShowing = bShowing && (colorWithAlphaAbsolute.a > 0.0);
    bShowing = bShowing && (visible == true);
    if(bShowing == false) {
        return;
    }
    
    if(bUpdateFbo) {
    
        coc::enableAlphaBlendingPremult();
    
        fbo.bind();
        gl::clear(clearColor);
        
        container->update();
        container->draw();
        
        fbo.unbind();
        
        gl::enableAlphaBlending();
    }
    
    fboImage->update();
}

void SceneFbo::drawSelf() {
    fboImage->draw();
}

//--------------------------------------------------------------
void SceneFbo::pointMoved(int pointX, int pointY, int pointID) {
    glm::vec2 pos = screenToLocal(glm::vec2(pointX, pointY));
    container->pointMoved(pos.x, pos.y);
}

void SceneFbo::pointPressed(int pointX, int pointY, int pointID) {
    glm::vec2 pos = screenToLocal(glm::vec2(pointX, pointY));
    container->pointPressed(pos.x, pos.y);
}

void SceneFbo::pointDragged(int pointX, int pointY, int pointID) {
    glm::vec2 pos = screenToLocal(glm::vec2(pointX, pointY));
    container->pointDragged(pos.x, pos.y);
}

void SceneFbo::pointReleased(int pointX, int pointY, int pointID) {
    glm::vec2 pos = screenToLocal(glm::vec2(pointX, pointY));
    container->pointReleased(pos.x, pos.y);
}

};
