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
#include "cocTextBoxExtended.h"

namespace coc {

class SceneTextExtended;
typedef std::shared_ptr<SceneTextExtended> SceneTextExtendedRef;

class SceneTextExtended : public coc::scene::Object {
public:

	SceneTextExtended(std::string objID="");
	~SceneTextExtended();

	static SceneTextExtendedRef create(const coc::scene::ObjectRef & object);
	static SceneTextExtendedRef create(const glm::ivec2 & size);
	static SceneTextExtendedRef create(int width, int height);

	virtual void setup() override;

	void setTextOffset(const glm::ivec2 & value) { textOffset = value; }
	const glm::ivec2 & getTextOffset() { return textOffset; }

	virtual void update() override;

	virtual void drawSelf() override;

	coc::TextBoxExtended textBox;

protected:

	glm::ivec2 textOffset;
};

};
