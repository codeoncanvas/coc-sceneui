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
textOffset(0,0),
bDebug(false){
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
    if (bDebug) {
        gl::ScopedColor red(1,0,0);
        gl::drawStrokedRect(tex->getBounds());
    }
}

void SceneText::generateTexture()
{
    tex = gl::Texture::create( textBox.render() );
}

void SceneText::adjustWidthAndAlignment( int newWidth, TextBox::Alignment alignment )
{
    switch (alignment) {
        case TextBox::Alignment::LEFT:
            width = newWidth;
            break;
        case TextBox::Alignment::CENTER:
            x = x - .5 * (newWidth - width);
            width = newWidth;
            break;
        case TextBox::Alignment::RIGHT:
            x = x + width - newWidth;
            width = newWidth;
            break;
    }
    textBox.setAlignment(  TextBox::Alignment::CENTER );
    textBox.setSize( ivec2(width,textBox.getSize().y) );
}

};
