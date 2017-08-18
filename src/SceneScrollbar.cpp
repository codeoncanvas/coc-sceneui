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

#include "SceneScrollbar.h"

namespace coc {

using namespace std;
using namespace ci;
using namespace coc::scene;

SceneScrollbar::SceneScrollbar(std::string objID) :
coc::scene::Object(objID),
bDebug(false) {

    //
}

SceneScrollbar::~SceneScrollbar() {
    //
}

SceneScrollbarRef SceneScrollbar::create(const coc::scene::ObjectRef & object) {
    SceneScrollbarRef scrollbar(new SceneScrollbar());
    scrollbar->copyFrom(object);
    scrollbar->objectType = ObjectTypeCustom;
    scrollbar->getParent()->replaceChild(object, scrollbar); // replace object.
    return scrollbar;
}

SceneScrollbarRef SceneScrollbar::create(const glm::ivec2 & size) {
    return create(size.x, size.y);
}

SceneScrollbarRef SceneScrollbar::create(int width, int height) {
    SceneScrollbarRef scrollbar(new SceneScrollbar());
    scrollbar->objectType = ObjectTypeCustom;
    scrollbar->width = width;
    scrollbar->height = height;
    return scrollbar;
}

void SceneScrollbar::setup() {
    coc::ciScrollbar::setup();
    setRect(Rectf(0, 0, width, height));
    if(width > height) {
        setType(Type::Horizontal);
    }
    fgCol = Color::white();
    bgCol = Color::hex(0x303030);
}

void SceneScrollbar::update() {
    coc::scene::Object::update();
    coc::ciScrollbar::update();
}

void SceneScrollbar::drawSelf() {
    
    // coc::ciScrollbar::draw();
    
        glm::ivec2 displaySize;
    if(type == Type::Vertical) {

        displaySize.x = 12;
        displaySize.y = rect.getH();

    } else if(type == Type::Horizontal) {

        displaySize.x = rect.getW();
        displaySize.y = 12;
    }

    glm::ivec2 displayPos;
    if(type == Type::Vertical) {

        displayPos.x = (int)((rect.getW() - displaySize.x) * 0.5);
        displayPos.y = 0;

    } else if(type == Type::Horizontal) {

        displayPos.x = 0;
        displayPos.y = (int)((rect.getH() - displaySize.y) * 0.5);
    }

    coc::Rect displayRect(displayPos, displayPos + displaySize);

    glm::ivec2 thumbSize = displaySize;
    if(type == Type::Vertical) {
        thumbSize.y *= contentRatio;
    } else if(type == Type::Horizontal) {
        thumbSize.x *= contentRatio;
    }

    ci::gl::ScopedColor bg( ColorA(bgCol, colorWithAlphaAbsolute.a) );
    hasRoundedCorners ? ci::gl::drawSolidRoundedRect(displayRect, displayRect.getW()) : ci::gl::drawSolidRect(displayRect);

    coc::Rect thumbRect;
    if(type == Type::Vertical) {
        thumbRect.y1 = coc::map(position, 0.0, 1.0, displayRect.y1, displayRect.y2 - thumbSize.y, true);
        thumbRect.y2 = thumbRect.y1 + thumbSize.y;
        thumbRect.x1 = displayPos.x;
        thumbRect.x2 = displayPos.x + displaySize.x;
    } else if(type == Type::Horizontal) {
        thumbRect.x1 = coc::map(position, 0.0, 1.0, displayRect.x1, displayRect.x2 - thumbSize.x, true);
        thumbRect.x2 = thumbRect.x1 + thumbSize.x;
        thumbRect.y1 = displayPos.y;
        thumbRect.y2 = displayPos.y + displaySize.y;
    }
    ci::gl::ScopedColor fg( ColorA(fgCol, colorWithAlphaAbsolute.a) );
    hasRoundedCorners ? ci::gl::drawSolidRoundedRect(thumbRect, thumbRect.getW()) : ci::gl::drawSolidRect(thumbRect);


    if(bDebug) {
        drawDebug();
    }
}

void SceneScrollbar::pointMoved(int pointX, int pointY, int pointID) {
    glm::vec2 pos = pointTransform(glm::vec2(pointX, pointY), glm::inverse(modelMatrixAbsolute));
    coc::ciScrollbar::pointMoved(pos.x, pos.y);
}

void SceneScrollbar::pointPressed(int pointX, int pointY, int pointID) {
    glm::vec2 pos = pointTransform(glm::vec2(pointX, pointY), glm::inverse(modelMatrixAbsolute));
    coc::ciScrollbar::pointPressed(pos.x, pos.y);
}

void SceneScrollbar::pointDragged(int pointX, int pointY, int pointID) {
    glm::vec2 pos = pointTransform(glm::vec2(pointX, pointY), glm::inverse(modelMatrixAbsolute));
    coc::ciScrollbar::pointDragged(pos.x, pos.y);
}

void SceneScrollbar::pointReleased(int pointX, int pointY, int pointID) {
    glm::vec2 pos = pointTransform(glm::vec2(pointX, pointY), glm::inverse(modelMatrixAbsolute));
    coc::ciScrollbar::pointReleased(pos.x, pos.y);
}

glm::vec2 SceneScrollbar::pointTransform(glm::vec2 pos, glm::mat4 mat) {
    glm::vec4 pos4(pos.x, pos.y, 0, 1);
    pos4 = mat * pos4;
    glm::vec2 pos2(pos4.x, pos4.y);
    return pos2;
}

};
