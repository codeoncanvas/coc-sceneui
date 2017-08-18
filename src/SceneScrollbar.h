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
#include "ciScrollbar.h"

namespace coc {

class SceneScrollbar;
typedef std::shared_ptr<SceneScrollbar> SceneScrollbarRef;

class SceneScrollbar : public coc::scene::Object, public coc::ciScrollbar {
public:

    SceneScrollbar(std::string objID="");
    ~SceneScrollbar();
    
    static SceneScrollbarRef create(const coc::scene::ObjectRef & object);
    static SceneScrollbarRef create(const glm::ivec2 & size);
    static SceneScrollbarRef create(int width, int height);

    virtual void setup() override;

    virtual void update() override;
    
    virtual void drawSelf() override;
    
    virtual void pointMoved(int pointX, int pointY, int pointID=0) override;
    virtual void pointPressed(int pointX, int pointY, int pointID=0) override;
    virtual void pointDragged(int pointX, int pointY, int pointID=0) override;
    virtual void pointReleased(int pointX, int pointY, int pointID=0) override;
    glm::vec2 pointTransform(glm::vec2 pos, glm::mat4 mat);
    
    bool bDebug;

    ci::Color bgCol;
    ci::Color fgCol;
    bool hasRoundedCorners = true;

};

};
