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
#include "ciImage.h"

namespace coc {

class SceneImage;
typedef std::shared_ptr<SceneImage> SceneImageRef;

class SceneImage : public coc::scene::Object, public coc::ciImage {
public:

    SceneImage(const ci::gl::TextureRef & texture);
    ~SceneImage();

    static SceneImageRef create(const coc::scene::ObjectRef & object, const ci::gl::TextureRef & texture);
    static SceneImageRef create(const glm::ivec2 & size, const ci::gl::TextureRef & texture);
    static SceneImageRef create(const ci::gl::TextureRef & texture);
    
    virtual void setup() override;
    
    virtual void update() override;
    
    virtual void drawSelf() override;
    
protected:
    
    //
};

};
