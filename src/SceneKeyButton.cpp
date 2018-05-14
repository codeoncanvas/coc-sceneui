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

#include "SceneKeyButton.h"

namespace coc {

using namespace std;
using namespace ci;
using namespace coc::scene;

SceneKeyButton::SceneKeyButton(std::string objID) :
coc::scene::Object(objID),
coc::ciButton(),
releaseDistLimit(20),
bDebug(false),
colUpBg( Color::white() ),
colUpFg( Color::black() ),
colDownBg( Color::white() ),
colDownFg( Color::black() )
{

    //
}

SceneKeyButton::~SceneKeyButton() {
    //
}

SceneKeyButtonRef SceneKeyButton::create(const coc::scene::ObjectRef & object) {
    if(object == nullptr) {
        return nullptr;
    }
    SceneKeyButtonRef button(new SceneKeyButton());
    button->copyFrom(object);
    button->objectType = ObjectTypeCustom;
    button->getParent()->replaceChild(object, button); // replace object.
    return button;
}

SceneKeyButtonRef SceneKeyButton::create(const glm::ivec2 & size) {
    return create(size.x, size.y);
}

SceneKeyButtonRef SceneKeyButton::create(int width, int height) {
    SceneKeyButtonRef button(new SceneKeyButton());
    button->objectType = ObjectTypeCustom;
    button->width = width;
    button->height = height;
    return button;
}

void SceneKeyButton::setup() {
    coc::ciButton::setRect(Rectf(0, 0, width, height));
}

void SceneKeyButton::update() {
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

void SceneKeyButton::drawSelf() {

    if(bDebug) {
        drawDebug();
    }
    
//    gl::color(ColorA(colorWithAlphaAbsolute)); / todo: apply opacity to colours

    if (down()) {

        if (!texDownBg) return;
        gl::ScopedColor bg( colDownBg);
        ci::gl::draw(texDownBg, ci::Rectf(0, 0, texDownBg->getWidth(), texDownBg->getHeight()));
        if (!texDownFg) return;
        gl::ScopedColor fg( colDownFg);
        ci::gl::draw(texDownFg, ci::Rectf(0, 0, texDownFg->getWidth(), texDownFg->getHeight()));

    }
    else {

        if (!texUpBg) return;
        gl::ScopedColor bg( colUpBg);
        ci::gl::draw(texUpBg, ci::Rectf(0, 0, texUpBg->getWidth(), texUpBg->getHeight()));
        if (!texUpFg) return;
        gl::ScopedColor fg( colUpFg);
        ci::gl::draw(texUpFg, ci::Rectf(0, 0, texUpFg->getWidth(), texUpFg->getHeight()));

    }
}

void SceneKeyButton::pointMoved(int pointX, int pointY, int pointID) {
    coc::ciButton::pointMoved(pointX, pointY);
}

void SceneKeyButton::pointPressed(int pointX, int pointY, int pointID) {
    coc::ciButton::pointPressed(pointX, pointY);
}

void SceneKeyButton::pointDragged(int pointX, int pointY, int pointID) {
    coc::ciButton::pointDragged(pointX, pointY);
}

void SceneKeyButton::pointReleased(int pointX, int pointY, int pointID) {
    coc::ciButton::pointReleased(pointX, pointY);
}

};
