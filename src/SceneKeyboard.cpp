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

#include "SceneKeyboard.h"
#include "cocSceneTexture.h"
#include "cocAssetsCI.h"
#include "cocAssetsOF.h"

namespace coc {
    
using namespace std;
using namespace ci;
using namespace ci::app;
using namespace coc::scene;
    
//--------------------------------------------------------------
SceneKeyboardRef SceneKeyboard::create(const coc::scene::ObjectRef & object) {
    SceneKeyboardRef keyboard(new SceneKeyboard());
    keyboard->copyFrom(object);
    if(keyboard->getParent()) {
        keyboard->getParent()->replaceChild(object, keyboard); // replace object.
    }
    return keyboard;
}
    
//--------------------------------------------------------------
SceneKeyboard::SceneKeyboard(std::string objID) :
coc::scene::Object(objID),
text(""),
bUpperCase(false),
bUpperCaseChanged(false),
bNumeric(false),
bNumericChanged(false),
bTextChanged(false) {
    //
}
    
SceneKeyboard::~SceneKeyboard() {
    exit();
}

void SceneKeyboard::exit() {
    //
}
    
//--------------------------------------------------------------
void SceneKeyboard::setup() {
    coc::scene::Object::setup();
    
    //first row
    
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyAbcLower, "keyboard/q", "q") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyAbcLower, "keyboard/w", "w") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyAbcLower, "keyboard/e", "e") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyAbcLower, "keyboard/r", "r") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyAbcLower, "keyboard/t", "t") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyAbcLower, "keyboard/y", "y") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyAbcLower, "keyboard/u", "u") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyAbcLower, "keyboard/i", "i") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyAbcLower, "keyboard/o", "o") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyAbcLower, "keyboard/p", "p") );
    
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyAbcUpper, "keyboard/QQ", "Q") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyAbcUpper, "keyboard/WW", "W") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyAbcUpper, "keyboard/EE", "E") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyAbcUpper, "keyboard/RR", "R") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyAbcUpper, "keyboard/TT", "T") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyAbcUpper, "keyboard/YY", "Y") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyAbcUpper, "keyboard/UU", "U") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyAbcUpper, "keyboard/II", "I") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyAbcUpper, "keyboard/OO", "O") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyAbcUpper, "keyboard/PP", "P") );
    
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyNum, "keyboard/1", "1") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyNum, "keyboard/2", "2") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyNum, "keyboard/3", "3") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyNum, "keyboard/4", "4") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyNum, "keyboard/5", "5") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyNum, "keyboard/6", "6") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyNum, "keyboard/7", "7") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyNum, "keyboard/8", "8") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyNum, "keyboard/9", "9") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyNum, "keyboard/0", "0") );
    
    //second row
    
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyAbcLower, "keyboard/a", "a") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyAbcLower, "keyboard/s", "s") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyAbcLower, "keyboard/d", "d") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyAbcLower, "keyboard/f", "f") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyAbcLower, "keyboard/g", "g") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyAbcLower, "keyboard/h", "h") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyAbcLower, "keyboard/j", "j") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyAbcLower, "keyboard/k", "k") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyAbcLower, "keyboard/l", "l") );
    
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyAbcUpper, "keyboard/AA", "A") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyAbcUpper, "keyboard/SS", "S") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyAbcUpper, "keyboard/DD", "D") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyAbcUpper, "keyboard/FF", "F") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyAbcUpper, "keyboard/GG", "G") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyAbcUpper, "keyboard/HH", "H") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyAbcUpper, "keyboard/JJ", "J") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyAbcUpper, "keyboard/KK", "K") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyAbcUpper, "keyboard/LL", "L") );
    
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyNum, "keyboard/slash", "/") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyNum, "keyboard/pound", "#") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyNum, "keyboard/dollar", "$") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyNum, "keyboard/underscore", "_") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyNum, "keyboard/ampersand", "&") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyNum, "keyboard/hyphen", "-") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyNum, "keyboard/plus", "+") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyNum, "keyboard/left-paranthesis", "(") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyNum, "keyboard/right-paranthesis", ")") );
    
    //third row
    
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyAbcLower, "keyboard/z", "z") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyAbcLower, "keyboard/x", "x") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyAbcLower, "keyboard/c", "c") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyAbcLower, "keyboard/v", "v") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyAbcLower, "keyboard/b", "b") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyAbcLower, "keyboard/n", "n") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyAbcLower, "keyboard/m", "m") );
    
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyAbcUpper, "keyboard/ZZ", "Z") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyAbcUpper, "keyboard/XX", "X") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyAbcUpper, "keyboard/CC", "C") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyAbcUpper, "keyboard/VV", "V") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyAbcUpper, "keyboard/BB", "B") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyAbcUpper, "keyboard/NN", "N") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyAbcUpper, "keyboard/MM", "M") );
    
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyNum, "keyboard/comma", ",") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyNum, "keyboard/doublequotes", "\"") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyNum, "keyboard/singlequote", "'") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyNum, "keyboard/colon", ":") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyNum, "keyboard/semicolon", ";") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyNum, "keyboard/exclamation", "!") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyNum, "keyboard/question", "?") );
    
    //Other keys
    
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyExtra, "keyboard/at", "@") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyExtra, "keyboard/space", " ") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyExtra, "keyboard/dot", ".") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyExtra, "keyboard/com", ".com") );
    
    keysAll.push_back( keyCapsInactive = SceneKeyboardKey::create(SceneKeyboardKey::KeyCaps, "keyboard/caps") );
    keysAll.push_back( keyCapsActive = SceneKeyboardKey::create(SceneKeyboardKey::KeyCaps, "keyboard/caps-active") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyBackspace, "keyboard/backspace") );
    keysAll.push_back( keyNumToggle = SceneKeyboardKey::create(SceneKeyboardKey::KeyNumToggle, "keyboard/num") );
    keysAll.push_back( keyAbcToggle = SceneKeyboardKey::create(SceneKeyboardKey::KeyAbcToggle, "keyboard/abc") );
    
    
    for(auto key : keysAll) {
        
        key->btn = SceneKeyButton::create( findObjectByID(key->objID) );
        key->btn->setup();
        string keyDownObjID = key->objID + "-down";
        coc::scene::TextureRef keyDownObj = std::static_pointer_cast<coc::scene::Texture>( findObjectByID(keyDownObjID) );
        coc::scene::ObjectRef keyDownObj0 = findObjectByID(keyDownObjID);
#if defined( COC_CI )
        coc::Assets * assets = coc::scene::getAssets();
        //todo: replace images with white bg/fg images
        key->btn->texDownBg = ((coc::AssetsCI *)assets)->getTextureRef(keyDownObj->assetID);
        key->btn->texDownFg = ((coc::AssetsCI *)assets)->getTextureRef(keyDownObj->assetID);
        key->btn->texUpBg = ((coc::AssetsCI *)assets)->getTextureRef(key->objID);
        key->btn->texUpFg = ((coc::AssetsCI *)assets)->getTextureRef(key->objID);
#endif
         keyDownObj0->getParent()->removeChild(keyDownObj0);
        
        if(key->type == SceneKeyboardKey::KeyAbcLower) {
            
            keysAbcLower.push_back(key);
            
        } else if(key->type == SceneKeyboardKey::KeyAbcUpper) {
            
            keysAbcUpper.push_back(key);
            
        } else if(key->type == SceneKeyboardKey::KeyNum) {
            
            keysNum.push_back(key);
        }
        
        key->btn->bDebug = false;
        
//        addChild(key->btn);
    }
    
    bUpperCaseChanged = true;
    bNumericChanged = true;

}

void SceneKeyboard::setCol( ColorA colUpBg, ColorA colUpFg, ColorA colDownBg, ColorA colDownFg )
{
    for (auto k : keysAll) {
        k->btn->colUpBg = colUpBg;
        k->btn->colUpFg = colUpFg;
        k->btn->colDownBg = colDownBg;
        k->btn->colDownFg = colDownFg;
    }
}

//--------------------------------------------------------------
void SceneKeyboard::update() {
    
    bTextChanged = false;
    
    SceneKeyboardKeyRef keyPressed = nullptr;
    for(auto key : keysAll) {
        if(key->btn->pressedInside()) {
            keyPressed = key;
            break;
        }
    }
    
    if(keyPressed) {
        
        bool bAdd = false;
        bAdd = bAdd || (keyPressed->type == SceneKeyboardKey::KeyAbcLower);
        bAdd = bAdd || (keyPressed->type == SceneKeyboardKey::KeyAbcUpper);
        bAdd = bAdd || (keyPressed->type == SceneKeyboardKey::KeyNum);
        bAdd = bAdd || (keyPressed->type == SceneKeyboardKey::KeyExtra);
        if(bAdd) {
            addChar( keyPressed->character );
            bTextChanged = true;
        }
        
        bool bDelete = false;
        bDelete = bDelete || (keyPressed->type == SceneKeyboardKey::KeyBackspace);
        bDelete = bDelete && (text.length() > 0);
        if(bDelete) {
            text = text.substr(0, text.length()-1);
            bTextChanged = true;
        }
        
        bool bCaps = false;
        bCaps = bCaps || (keyPressed->type == SceneKeyboardKey::KeyCaps);
        if(bCaps) {
            bUpperCase = !bUpperCase;
            bUpperCaseChanged = true;
        }
        
        bool bNum = false;
        bNum = bNum || (keyPressed->type == SceneKeyboardKey::KeyNumToggle);
        bNum = bNum || (keyPressed->type == SceneKeyboardKey::KeyAbcToggle);
        if(bNum) {
            bNumeric = !bNumeric;
            bNumericChanged = true;
        }
    }
    
    bool bLayoutChanged = false;
    bLayoutChanged = bLayoutChanged || bUpperCaseChanged;
    bLayoutChanged = bLayoutChanged || bNumericChanged;
    if(bLayoutChanged) {
        
        bUpperCaseChanged = false;
        bNumericChanged = false;
        
        for(auto key : keysAbcLower) {
            key->btn->visible = !bUpperCase && !bNumeric;
        }
        for(auto key : keysAbcUpper) {
            key->btn->visible = bUpperCase && !bNumeric;
        }
        for(auto key : keysNum) {
            key->btn->visible = bNumeric;
        }
        
        keyNumToggle->btn->visible = !bNumeric;
        keyAbcToggle->btn->visible = bNumeric;
        if (bNumeric) {
            keyCapsActive->btn->visible = !bNumeric;
            keyCapsInactive->btn->visible = !bNumeric;
        }
        else {
            keyCapsActive->btn->visible = bUpperCase;
            keyCapsInactive->btn->visible = !bUpperCase;
        }
    }
    
    if(bTextChanged) {
        cout << text << endl;
    }
    
    coc::scene::Object::update();
}
    
//--------------------------------------------------------------
void SceneKeyboard::drawSelf() {
    //
    coc::scene::Object::drawSelf();
}


//--------------------------------------------------------------

void SceneKeyboard::setKeyEventsEnabled( bool b )
{
    if (keyEventsEnabled == b) return;
    keyEventsEnabled = b;
    if (keyEventsEnabled) {
        cbKeyDown = getWindow()->getSignalKeyDown().connect(  std::bind( &SceneKeyboard::keyDown, this, std::placeholders::_1) );
    }
    else {
        cbKeyDown.disconnect();
    }

}

void SceneKeyboard::keyDown( ci::app::KeyEvent event )
{

    auto keyCode = event.getCode();
    if (keyCode == KeyEvent::KEY_DELETE || keyCode == KeyEvent::KEY_BACKSPACE ) {
        text = text.substr(0, text.length()-1);
    }
    else {
        //todo: better support for special chars
        std::string tmp = "";
        tmp += event.getChar();
        addChar( tmp );
    }

}


};
