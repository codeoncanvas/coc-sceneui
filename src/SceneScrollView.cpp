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

#include "SceneScrollView.h"
#include "cocGLUtils.h"
#include "Globals.h"

namespace coc {

using namespace ci;
using namespace coc::scene;
using namespace std;

SceneScrollView::SceneScrollView(std::string objID) :
coc::scene::Object(objID),
fboClearColor(1,1,1,1) {
    //
}

SceneScrollView::~SceneScrollView() {
    //
}

//--------------------------------------------------------------
SceneScrollViewRef SceneScrollView::create(const coc::scene::ObjectRef & object) {
    SceneScrollViewRef scrollview(new SceneScrollView(""));
    scrollview->copyFrom(object); // copy scene properties before replacing.
    scrollview->objectType = ObjectTypeCustom;
    scrollview->getParent()->replaceChild(object, scrollview); // replace.
    return scrollview;
}

SceneScrollViewRef SceneScrollView::create(const glm::ivec2 & size) {
    return create(size.x, size.y);
}

SceneScrollViewRef SceneScrollView::create(int width, int height) {
    SceneScrollViewRef scrollview(new SceneScrollView());
    scrollview->objectType = ObjectTypeCustom;
    scrollview->width = width;
    scrollview->height = height;
    return scrollview;
}

//--------------------------------------------------------------
void SceneScrollView::setup() {

    container = coc::scene::Object::create("container");

    glm::ivec2 displaySize = glm::ivec2(width, height);
    
    setWindowRect(Rectf(ivec2(0, 0), displaySize));
    setContentRect(Rectf(ivec2(0, 0), displaySize));
    setDoubleTapEnabled(false);
	setBounceEasing(glm::vec2(1.0, 0.2));
	setDragVelocityDecay(glm::vec2(0.9, 0.9));
    setDragBoundsLimit(glm::vec2(0.0, 0.1));

    fbo0.setup(displaySize, true, true);
    if(maskTexture) {
        fbo1.setup(displaySize, true, true);
        fboImage = coc::ciImage::create(fbo1.getTextureRef());
    } else {
        fboImage = coc::ciImage::create(fbo0.getTextureRef());
    }
}

//--------------------------------------------------------------
void SceneScrollView::addChild(const coc::scene::ObjectRef & child) {
    if(container == nullptr) {
        return;
    }
    container->addChild(child);
}

//--------------------------------------------------------------
void SceneScrollView::update() {
    coc::scene::Object::update();
    
    bool bShowing = true;
    bShowing = bShowing && (colorWithAlphaAbsolute.a > 0.0);
    bShowing = bShowing && (visible == true);
    
    //----------------------------------------------------------
    for(int i=0; i<buttons.size(); i++) {
        coc::ButtonRef & button = buttons[i]->button;
        button->setTransform(modelMatrixAbsolute);
        if(bShowing == false) {
            button->reset();
        }
    }
    
    coc::ScrollView::update( SystemTimeDelta() );
    
    if(bShowing == false) {
        return;
    }

    //----------------------------------------------------------
     coc::enableAlphaBlendingPremult();
    
    fbo0.bind();
    ci::gl::clear(fboClearColor);
    
    glm::vec2 scrollPos = getScrollPos();
    container->x = scrollPos.x;
    container->y = scrollPos.y;
    container->update();
    container->draw();
    
    fbo0.unbind();
    
    //----------------------------------------------------------
    if(maskTexture) {
    
        fbo1.bind();
        ci::gl::clear(fboClearColor);
        
        gl::ScopedGlslProg bindShader(maskShader);
        gl::ScopedTextureBind bindImage(fbo0.getTextureRef(), 0);
        gl::ScopedTextureBind bindMask(maskTexture, 1);
        gl::drawSolidRect(Rectf(glm::vec2(0,0), glm::vec2(width, height)));
        
        fbo1.unbind();
    }
    
    gl::enableAlphaBlending();
    
    fboImage->update();
}

void SceneScrollView::drawSelf() {
    fboImage->draw();
}

//--------------------------------------------------------------
void SceneScrollView::pointMoved(int pointX, int pointY, int pointID) {
    if (!bDisablePoints) coc::ScrollView::pointMoved(pointX, pointY, pointID);
    
    glm::vec2 pos = screenToLocal(glm::vec2(pointX, pointY));
    if(inside(pos) == false) {
        return;
    }
    container->pointMoved(pos.x, pos.y);
}

void SceneScrollView::pointPressed(int pointX, int pointY, int pointID) {
    if (!bDisablePoints) coc::ScrollView::pointPressed(pointX, pointY, pointID);

    glm::vec2 pos = screenToLocal(glm::vec2(pointX, pointY));
    if(inside(pos) == false) {
        return;
    }
    container->pointPressed(pos.x, pos.y);
}

void SceneScrollView::pointDragged(int pointX, int pointY, int pointID) {
    if (!bDisablePoints) coc::ScrollView::pointDragged(pointX, pointY, pointID);
    
    glm::vec2 pos = screenToLocal(glm::vec2(pointX, pointY));
    if(inside(pos) == false) {
        return;
    }
    container->pointDragged(pos.x, pos.y);
}

void SceneScrollView::pointReleased(int pointX, int pointY, int pointID) {
    if (!bDisablePoints) coc::ScrollView::pointReleased(pointX, pointY, pointID);
    
    glm::vec2 pos = screenToLocal(glm::vec2(pointX, pointY));
    if(inside(pos) == false) {
        return;
    }
    container->pointReleased(pos.x, pos.y);
}

bool SceneScrollView::inside(glm::vec2 pos) {
    bool bInside = true;
    bInside = bInside && (pos.x >= 0);
    bInside = bInside && (pos.x <= width);
    bInside = bInside && (pos.y >= 0);
    bInside = bInside && (pos.y <= height);
    return bInside;
}

//--------------------------------------------------------------

ci::vec2 SceneScrollView::screenToLocalContainer( ci::vec2 p )
{
    vec2 scrollP = screenToLocal( p );
    vec2 containerP = container->screenToLocal( scrollP );
    containerP.x += getScrollPos().x;
    return containerP;
}

};
