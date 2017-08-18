//
//      ┌─┐╔═╗┌┬┐┌─┐
//      │  ║ ║ ││├┤
//      └─┘╚═╝─┴┘└─┘
//   ┌─┐┌─┐╔╗╔┬  ┬┌─┐┌─┐
//   │  ├─┤║║║└┐┌┘├─┤└─┐
//   └─┘┴ ┴╝╚╝ └┘ ┴ ┴└─┘
//  http://CodeOnCanvas.cc
//
// Copyright (c) 2016, Code on Canvas Pty Ltd

#include "SceneScrollViewWithScrollbar.h"

namespace coc {

using namespace ci;
using namespace std;
using namespace coc::scene;

//--------------------------------------------------------------
SceneScrollViewWithScrollbar::SceneScrollViewWithScrollbar(std::string objID) :
        SceneScrollView() {
    //
}

SceneScrollViewWithScrollbar::~SceneScrollViewWithScrollbar() {
    //
}

//--------------------------------------------------------------
SceneScrollViewWithScrollbarRef SceneScrollViewWithScrollbar::create(const coc::scene::ObjectRef & object) {
    SceneScrollViewWithScrollbarRef scrollview(new SceneScrollViewWithScrollbar(""));
    scrollview->copyFrom(object); // copy scene properties before replacing.
    scrollview->objectType = ObjectTypeCustom;
    scrollview->getParent()->replaceChild(object, scrollview); // replace.
    return scrollview;
}

SceneScrollViewWithScrollbarRef SceneScrollViewWithScrollbar::create(const glm::ivec2 & size) {
    return create(size.x, size.y);
}

SceneScrollViewWithScrollbarRef SceneScrollViewWithScrollbar::create(int width, int height) {
    SceneScrollViewWithScrollbarRef scrollview(new SceneScrollViewWithScrollbar());
    scrollview->objectType = ObjectTypeCustom;
    scrollview->width = width;
    scrollview->height = height;
    return scrollview;
}

//--------------------------------------------------------------
void SceneScrollViewWithScrollbar::update() {

    if(scrollbar) {
        coc::Scrollbar::Type scrollbarType = scrollbar->getType();

        float contentRatio = 1;
        if(scrollbarType == coc::Scrollbar::Vertical) {
            contentRatio = windowSize.y / (float)contentSize.y;
        } else if(scrollbarType == coc::Scrollbar::Horizontal) {
            contentRatio = windowSize.x / (float)contentSize.x;
        }

        scrollbar->setContentRatio(contentRatio);

        bool bScroll = (contentRatio < 1);
        scrollbar->setEnabled(bScroll);
        setEnabled(bScroll);

        if(scrollbar->hasPositionChanged()) {

            float scrollPos = scrollbar->getPosition();

            if(scrollbarType == coc::Scrollbar::Vertical) {
                setScrollPositionNormalized(glm::vec2(0, scrollPos));
            } else if(scrollbarType == coc::Scrollbar::Horizontal) {
                setScrollPositionNormalized(glm::vec2(scrollPos, 0));
            }

        } else {

            float scrollPos = 0;
            if(scrollbarType == coc::Scrollbar::Vertical) {
                scrollPos = getScrollPositionNormalized().y;
            } else if(scrollbarType == coc::Scrollbar::Horizontal) {
                scrollPos = getScrollPositionNormalized().x;
            }

            scrollbar->setPosition(scrollPos);
        }
    }

    SceneScrollView::update();
}

};
