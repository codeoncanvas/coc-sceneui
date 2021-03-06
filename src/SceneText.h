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
#include "cinder/Text.h"

namespace coc {

class SceneText;
typedef std::shared_ptr<SceneText> SceneTextRef;

class SceneText : public coc::scene::Object {
public:

    SceneText(std::string objID="");
    ~SceneText();
    
    static SceneTextRef create(const coc::scene::ObjectRef & object);
    static SceneTextRef create(const glm::ivec2 & size);
    static SceneTextRef create(int width, int height);

    virtual void setup() override;
    
    void setTextOffset(const glm::ivec2 & value) { textOffset = value; }
    const glm::ivec2 & getTextOffset() { return textOffset; }
    
    virtual void update() override;
    
    virtual void drawSelf() override;

    //!must be called after changing text
	void generateTexture();

	//!adjusts object size to max width of text with correct alignment
	void adjustWidthAndAlignment( int newWidth, ci::TextBox::Alignment alignment );

	ci::TextBox * getTextBox() { return &textBox; }
	ci::gl::TextureRef getTexture() { return tex; }

    ci::TextBox textBox;
	ci::gl::TextureRef tex;
	bool bDebug;
    
protected:
    
    glm::ivec2 textOffset;
};

};
