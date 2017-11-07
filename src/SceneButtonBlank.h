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
#include "ciButton.h"

namespace coc {

class SceneButtonBlank;
typedef std::shared_ptr<SceneButtonBlank> SceneButtonBlankRef;

class SceneButtonBlank : public coc::scene::Object, public coc::ciButton {
public:

	SceneButtonBlank(std::string objID="");
	~SceneButtonBlank();

	static SceneButtonBlankRef create( std::string objID="" );
	static SceneButtonBlankRef create(const coc::scene::ObjectRef & object, bool replace = true);

	void setBounds( coc::Rect rect );

	virtual void update() override;

	virtual void drawSelf() override;

	virtual void pointMoved(int pointX, int pointY, int pointID=0) override;
	virtual void pointPressed(int pointX, int pointY, int pointID=0) override;
	virtual void pointDragged(int pointX, int pointY, int pointID=0) override;
	virtual void pointReleased(int pointX, int pointY, int pointID=0) override;

	bool bDebug = false;

};

};