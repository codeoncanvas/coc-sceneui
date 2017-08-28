//
//	    ┌─┐╔═╗┌┬┐┌─┐
//      │  ║ ║ ││├┤
//      └─┘╚═╝─┴┘└─┘
//	 ┌─┐┌─┐╔╗╔┬  ┬┌─┐┌─┐
//	 │  ├─┤║║║└┐┌┘├─┤└─┐
//	 └─┘┴ ┴╝╚╝ └┘ ┴ ┴└─┘
//	http://CodeOnCanvas.cc
//
// Copyright (c) 2017, Code on Canvas Pty Ltd

#pragma once

#include "SceneButton.h"

namespace coc {
    
//--------------------------------------------------------------
class SceneKeyboardKey;
typedef std::shared_ptr<SceneKeyboardKey> SceneKeyboardKeyRef;

class SceneKeyboardKey {
public:
    
    enum Type {
        KeyNone=0,
        KeyAbcLower,
        KeyAbcUpper,
        KeyNum,
        KeyExtra,
        KeyCaps,
        KeyBackspace,
        KeyNumToggle,
        KeyAbcToggle,
        
        // NOT SURE WE NEED THE REST.
        Q,W,E,R,T,Y,U,I,O,P,
        A,S,D,F,G,H,J,K,L,
        Z,X,C,V,B,N,M,
        NUM1,NUM2,NUM3,NUM4,NUM5,NUM6,NUM7,NUM8,NUM9,NUM0,
        FORWARDSLASH,HASH,DOLLAR,UNDERSCORE,AND,MINUS,PLUS,OPENBRACKET,CLOSEBRACKET,
        COMMA,DOUBLEQUOTE,SINGLEQUOTE,COLON,SEMICOLON,EXCLAMATION,QUESTION,
        AT,SPACE,DOT,COM
    };
    
    static SceneKeyboardKeyRef create(Type type, std::string objID, std::string character="") {
        SceneKeyboardKeyRef key(new SceneKeyboardKey());
        key->type = type;
        key->objID = objID;
        key->character = character;
        return key;
    }
    
    SceneKeyboardKey() {
        type = KeyNone;
        objID = "";
        character = "";
    }
    
    Type type;
    std::string objID;
    std::string character;
    SceneButtonRef btn;

};
    
//--------------------------------------------------------------
class SceneKeyboard;
typedef std::shared_ptr<SceneKeyboard> SceneKeyboardRef;
    
class SceneKeyboard : public coc::scene::Object {
    
public:
    
    static SceneKeyboardRef create(const coc::scene::ObjectRef & object);
    
    SceneKeyboard(std::string objID="");
    ~SceneKeyboard();
    
    void exit();
    
    void setup() override;
    
    void update() override;
    
    void drawSelf() override;
    
    std::vector<SceneKeyboardKeyRef> keysAll;
    std::vector<SceneKeyboardKeyRef> keysAbcLower;
    std::vector<SceneKeyboardKeyRef> keysAbcUpper;
    std::vector<SceneKeyboardKeyRef> keysNum;
    SceneKeyboardKeyRef keyCapsActive;
    SceneKeyboardKeyRef keyCapsInactive;
    SceneKeyboardKeyRef keyAbcToggle;
    SceneKeyboardKeyRef keyNumToggle;
    
    std::string text;
    bool bUpperCase;
    bool bUpperCaseChanged;
    bool bNumeric;
    bool bNumericChanged;
    bool bTextChanged;

};

    
};
