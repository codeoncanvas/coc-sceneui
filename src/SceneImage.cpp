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

#include "SceneImage.h"

namespace coc {

using namespace ci;
using namespace coc::scene;

SceneImage::SceneImage(const ci::gl::TextureRef & texture) :
coc::scene::Object(),
coc::ciImage(texture) {
    //
}

SceneImage::~SceneImage() {
    //
}

SceneImageRef SceneImage::create(const coc::scene::ObjectRef & object, const ci::gl::TextureRef & texture) {
    SceneImageRef sceneImage(new SceneImage(texture));
    sceneImage->copyFrom(object); // copy scene properties from object before replacing it.
    sceneImage->objectType = ObjectTypeCustom;
    sceneImage->getParent()->replaceChild(object, sceneImage); // replace object.
    sceneImage->setSize(glm::vec2(sceneImage->width, sceneImage->height));
    return sceneImage;
}

SceneImageRef SceneImage::create(const glm::ivec2 & size, const ci::gl::TextureRef & texture) {
    SceneImageRef sceneImage(new SceneImage(texture));
    sceneImage->objectType = ObjectTypeCustom;
    sceneImage->width = size.x;
    sceneImage->height = size.y;
    sceneImage->setSize(glm::vec2(sceneImage->width, sceneImage->height));
    return sceneImage;
}


SceneImageRef SceneImage::create(const ci::gl::TextureRef & texture) {
    SceneImageRef sceneImage(new SceneImage(texture));
    sceneImage->objectType = ObjectTypeCustom;
    sceneImage->width = texture->getWidth();
    sceneImage->height = texture->getHeight();
    sceneImage->setSize(glm::vec2(sceneImage->width, sceneImage->height));
    return sceneImage;
}

void SceneImage::setup() {
    //
}

void SceneImage::update() {
    coc::scene::Object::update();
    coc::ciImage::update();
}

void SceneImage::drawSelf() {
    coc::ciImage::draw();
}

};
