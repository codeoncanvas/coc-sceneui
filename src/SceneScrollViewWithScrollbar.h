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

#pragma once

#include "SceneScrollView.h"
#include "PopupSelectScrollbar.h"

namespace coc {

class SceneScrollViewWithScrollbar;
typedef std::shared_ptr<SceneScrollViewWithScrollbar> SceneScrollViewWithScrollbarRef;

class SceneScrollViewWithScrollbar : public SceneScrollView {
public:

    SceneScrollViewWithScrollbar(std::string objID="");
    ~SceneScrollViewWithScrollbar();

    static SceneScrollViewWithScrollbarRef create(const coc::scene::ObjectRef & object);
    static SceneScrollViewWithScrollbarRef create(const glm::ivec2 & size);
    static SceneScrollViewWithScrollbarRef create(int width, int height);

    void setScrollbar(const PopupSelectScrollbarRef & value) { scrollbar = value; }

    void update() override;

    PopupSelectScrollbarRef scrollbar;
};

};
