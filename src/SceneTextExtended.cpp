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

#include "SceneTextExtended.h"

namespace coc {

using namespace coc::scene;

SceneTextExtended::SceneTextExtended(std::string objID) :
		coc::scene::Object(objID),
		textOffset(0,0) {
	//
}

SceneTextExtended::~SceneTextExtended() {
	//
}

SceneTextExtendedRef SceneTextExtended::create(const coc::scene::ObjectRef & object) {
	if(object == nullptr) {
		return nullptr;
	}
	SceneTextExtendedRef text(new SceneTextExtended(""));
	text->copyFrom(object); // copy scene properties from object before replacing it.
	text->objectType = ObjectTypeCustom;
	text->getParent()->replaceChild(object, text); // replace object.
	return text;
}

SceneTextExtendedRef SceneTextExtended::create(const glm::ivec2 & size) {
	return create(size.x, size.y);
}

SceneTextExtendedRef SceneTextExtended::create(int width, int height) {
	SceneTextExtendedRef text(new SceneTextExtended());
	text->objectType = ObjectTypeCustom;
	text->width = width;
	text->height = height;
	return text;
}

void SceneTextExtended::setup() {
	//
}

void SceneTextExtended::update() {
	coc::scene::Object::update();

	//
}

void SceneTextExtended::drawSelf() {

	ci::gl::ScopedModelMatrix pushModelMatrix;
	textBox.drawWithLeading(textOffset);
}

};
