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

#include "SceneText.h"

namespace coc {

using namespace ci;
using namespace coc::scene;

SceneText::SceneText(std::string objID) :
coc::scene::Object(objID),
textOffset(0,0) {
    //
}

SceneText::~SceneText() {
    //
}

SceneTextRef SceneText::create(const coc::scene::ObjectRef & object) {
    if(object == nullptr) {
        return nullptr;
    }
    SceneTextRef text(new SceneText(""));
    text->copyFrom(object); // copy scene properties from object before replacing it.
    text->objectType = ObjectTypeCustom;
    text->getParent()->replaceChild(object, text); // replace object.
    return text;
}

SceneTextRef SceneText::create(const glm::ivec2 & size) {
    return create(size.x, size.y);
}

SceneTextRef SceneText::create(int width, int height) {
    SceneTextRef text(new SceneText());
    text->objectType = ObjectTypeCustom;
    text->width = width;
    text->height = height;
    return text;
}

void SceneText::setup() {
    //
}

void SceneText::update() {
    coc::scene::Object::update();

    if (!tex && textBox.getText().length()) {
        generateTexture();
    }
}

void SceneText::drawSelf() {

    ci::gl::ScopedModelMatrix pushModelMatrix;
    if (tex) gl::draw( tex, textOffset );
}

void SceneText::generateTexture()
{
    tex = gl::Texture::create( textBox.render() );
}

};
