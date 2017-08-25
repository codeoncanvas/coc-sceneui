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

#include "SceneButtonBlank.h"

namespace coc {

using namespace coc::scene;

SceneButtonBlank::SceneButtonBlank(std::string objID) :
		coc::scene::Object(objID),
		coc::ciButton() {

	//
}

SceneButtonBlank::~SceneButtonBlank() {
	//
}

SceneButtonBlankRef SceneButtonBlank::create( std::string objID ) {
	return SceneButtonBlankRef(new SceneButtonBlank(objID));
}

SceneButtonBlankRef SceneButtonBlank::create(const coc::scene::ObjectRef & object, bool replace ) {
	if(object == nullptr) {
		return SceneButtonBlankRef();
	}

	SceneButtonBlankRef button(new SceneButtonBlank());
	button->copyFrom(object);
	button->objectType = ObjectTypeCustom;
	button->setRect(ci::Rectf(0, 0, button->width, button->height));
	if (replace) {
		button->getParent()->replaceChild(object, button);
	}
	else {
		object->getParent()->addChild( button );
	}

	return button;
}

void SceneButtonBlank::setBounds( coc::Rect rect ) {

	coc::scene::Object::setBounds(rect);
	setRect(0,0,rect.getW(),rect.getH());
}

void SceneButtonBlank::update() {
	coc::scene::Object::update();

	for(int i=0; i<points.size(); i++) {
		coc::ButtonPoint & point = points[i];
		glm::vec4 pos(point.pos.x, point.pos.y, 0, 1);
		pos = glm::inverse(modelMatrixAbsolute) * pos;
		point.pos = glm::vec2(pos.x, pos.y);
	}

	coc::ciButton::update();
}

void SceneButtonBlank::drawSelf() {

	if(bDebug) {
		drawDebug();
	}

}

void SceneButtonBlank::pointMoved(int pointX, int pointY, int pointID) {
	coc::ciButton::pointMoved(pointX, pointY);
}

void SceneButtonBlank::pointPressed(int pointX, int pointY, int pointID) {
	coc::ciButton::pointPressed(pointX, pointY);
}

void SceneButtonBlank::pointDragged(int pointX, int pointY, int pointID) {
	coc::ciButton::pointDragged(pointX, pointY);
}

void SceneButtonBlank::pointReleased(int pointX, int pointY, int pointID) {
	coc::ciButton::pointReleased(pointX, pointY);
}

};
