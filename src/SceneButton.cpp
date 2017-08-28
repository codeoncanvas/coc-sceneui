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

#include "SceneButton.h"
#include "cocSceneTexture.h"
#include "cocAssetsCI.h"

namespace coc {

using namespace std;
using namespace ci;
using namespace coc::scene;

SceneButton::SceneButton(std::string objID) :
coc::scene::Object(objID),
coc::ciButton(),
releaseDistLimit(20),
bDebug(false) {

    //
}

SceneButton::~SceneButton() {
    //
}

SceneButtonRef SceneButton::create(const coc::scene::ObjectRef & object) {
    if(object == nullptr) {
        return nullptr;
    }
    
    std::string assetID = ((const coc::scene::Texture *)object.get())->assetID;
    
    coc::Assets * assets = coc::scene::getAssets();
    
    SceneButtonRef button(new SceneButton());
    button->copyFrom(object);
    button->objectType = ObjectTypeCustom;
    button->getParent()->replaceChild(object, button); // replace object.
    
    button->texUp = ((coc::AssetsCI *)assets)->getTextureRef(assetID);
    return button;
}

SceneButtonRef SceneButton::create(const glm::ivec2 & size) {
    return create(size.x, size.y);
}

SceneButtonRef SceneButton::create(int width, int height) {
    SceneButtonRef button(new SceneButton());
    button->objectType = ObjectTypeCustom;
    button->width = width;
    button->height = height;
    return button;
}

void SceneButton::setup() {
    coc::ciButton::setRect(Rectf(0, 0, width, height));
}

void SceneButton::update() {
    coc::scene::Object::update();
    
    bool bShowing = true;
    bShowing = bShowing && (colorWithAlphaAbsolute.a > 0.0);
    bShowing = bShowing && (visible == true);
    if(bShowing == false) {
        reset(); // prevents input when the object is not visible.
    }
    
    coc::ciButton::setTransform(modelMatrixAbsolute);
    coc::ciButton::update();
    
    if(pressedInside()) {
        screenPointDown = localToScreen( getPointPosLast() );
    }
    if(down()) {
        glm::vec2 screenPoint = localToScreen( getPointPosLast() );
        float dist = glm::length(screenPoint - screenPointDown);
        if(dist >= releaseDistLimit) {
            reset();
        }
    }
}

void SceneButton::drawSelf() {

    if(bDebug) {
        drawDebug();
    }
    
    gl::color(ColorA(colorWithAlphaAbsolute));

    gl::TextureRef tex = texUp;
    if(down()) {
        if(texDown) {
            tex = texDown;
        }
    } else if(over()) {
        if(texOver) {
            tex = texOver;
        }
    }
    if(tex) {
        ci::gl::draw(tex, ci::Rectf(0, 0, tex->getWidth(), tex->getHeight()));
    }
}

void SceneButton::pointMoved(int pointX, int pointY, int pointID) {
    coc::ciButton::pointMoved(pointX, pointY);
}

void SceneButton::pointPressed(int pointX, int pointY, int pointID) {
    coc::ciButton::pointPressed(pointX, pointY);
}

void SceneButton::pointDragged(int pointX, int pointY, int pointID) {
    coc::ciButton::pointDragged(pointX, pointY);
}

void SceneButton::pointReleased(int pointX, int pointY, int pointID) {
    coc::ciButton::pointReleased(pointX, pointY);
}

};
