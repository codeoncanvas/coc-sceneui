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
SceneKeyboardRef SceneKeyboard::create(const coc::scene::ObjectRef & object, bool replace ) {
    SceneKeyboardRef keyboard(new SceneKeyboard());
    keyboard->copyFrom(object);
    if(replace && keyboard->getParent()) {
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
    
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyAbcLower, prefix + "/q", "q") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyAbcLower, prefix + "/w", "w") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyAbcLower, prefix + "/e", "e") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyAbcLower, prefix + "/r", "r") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyAbcLower, prefix + "/t", "t") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyAbcLower, prefix + "/y", "y") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyAbcLower, prefix + "/u", "u") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyAbcLower, prefix + "/i", "i") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyAbcLower, prefix + "/o", "o") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyAbcLower, prefix + "/p", "p") );
    
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyAbcUpper, prefix + "/QQ", "Q") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyAbcUpper, prefix + "/WW", "W") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyAbcUpper, prefix + "/EE", "E") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyAbcUpper, prefix + "/RR", "R") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyAbcUpper, prefix + "/TT", "T") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyAbcUpper, prefix + "/YY", "Y") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyAbcUpper, prefix + "/UU", "U") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyAbcUpper, prefix + "/II", "I") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyAbcUpper, prefix + "/OO", "O") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyAbcUpper, prefix + "/PP", "P") );
    
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyNum, prefix + "/1", "1") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyNum, prefix + "/2", "2") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyNum, prefix + "/3", "3") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyNum, prefix + "/4", "4") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyNum, prefix + "/5", "5") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyNum, prefix + "/6", "6") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyNum, prefix + "/7", "7") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyNum, prefix + "/8", "8") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyNum, prefix + "/9", "9") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyNum, prefix + "/0", "0") );
    
    //second row
    
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyAbcLower, prefix + "/a", "a") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyAbcLower, prefix + "/s", "s") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyAbcLower, prefix + "/d", "d") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyAbcLower, prefix + "/f", "f") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyAbcLower, prefix + "/g", "g") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyAbcLower, prefix + "/h", "h") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyAbcLower, prefix + "/j", "j") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyAbcLower, prefix + "/k", "k") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyAbcLower, prefix + "/l", "l") );
    
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyAbcUpper, prefix + "/AA", "A") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyAbcUpper, prefix + "/SS", "S") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyAbcUpper, prefix + "/DD", "D") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyAbcUpper, prefix + "/FF", "F") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyAbcUpper, prefix + "/GG", "G") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyAbcUpper, prefix + "/HH", "H") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyAbcUpper, prefix + "/JJ", "J") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyAbcUpper, prefix + "/KK", "K") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyAbcUpper, prefix + "/LL", "L") );
    
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyNum, prefix + "/slash", "/") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyNum, prefix + "/pound", "#") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyNum, prefix + "/dollar", "$") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyNum, prefix + "/underscore", "_") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyNum, prefix + "/ampersand", "&") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyNum, prefix + "/hyphen", "-") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyNum, prefix + "/plus", "+") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyNum, prefix + "/left-parenthesis", "(") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyNum, prefix + "/right-parenthesis", ")") );
    
    //third row
    
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyAbcLower, prefix + "/z", "z") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyAbcLower, prefix + "/x", "x") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyAbcLower, prefix + "/c", "c") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyAbcLower, prefix + "/v", "v") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyAbcLower, prefix + "/b", "b") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyAbcLower, prefix + "/n", "n") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyAbcLower, prefix + "/m", "m") );
    
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyAbcUpper, prefix + "/ZZ", "Z") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyAbcUpper, prefix + "/XX", "X") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyAbcUpper, prefix + "/CC", "C") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyAbcUpper, prefix + "/VV", "V") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyAbcUpper, prefix + "/BB", "B") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyAbcUpper, prefix + "/NN", "N") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyAbcUpper, prefix + "/MM", "M") );
    
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyNum, prefix + "/comma", ",") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyNum, prefix + "/doublequotes", "\"") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyNum, prefix + "/singlequote", "'") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyNum, prefix + "/colon", ":") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyNum, prefix + "/semicolon", ";") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyNum, prefix + "/exclamation", "!") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyNum, prefix + "/question", "?") );
    
    //Other keys
    
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyExtra, prefix + "/at", "@") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyExtra, prefix + "/space", " ") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyExtra, prefix + "/dot", ".") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyExtra, prefix + "/com", ".com") );
    
    keysAll.push_back( keyCapsInactive = SceneKeyboardKey::create(SceneKeyboardKey::KeyCaps, prefix + "/caps") );
    keysAll.push_back( keyCapsActive = SceneKeyboardKey::create(SceneKeyboardKey::KeyCaps, prefix + "/caps-active") );
    keysAll.push_back( SceneKeyboardKey::create(SceneKeyboardKey::KeyBackspace, prefix + "/backspace") );
    keysAll.push_back( keyNumToggle = SceneKeyboardKey::create(SceneKeyboardKey::KeyNumToggle, prefix + "/num") );
    keysAll.push_back( keyAbcToggle = SceneKeyboardKey::create(SceneKeyboardKey::KeyAbcToggle, prefix + "/abc") );
    
    
    for(auto key : keysAll) {
        
        key->btn = SceneKeyButton::create( findObjectByID(key->objID + "-bg-up") );
        key->btn->setup();
#if defined( COC_CI )
        coc::Assets * assets = coc::scene::getAssets();
        //todo: replace images with white bg/fg images
        key->btn->texDownBg = ((coc::AssetsCI *)assets)->getTextureRef(key->objID + "-bg-down");
        key->btn->texDownFg = ((coc::AssetsCI *)assets)->getTextureRef(key->objID + "-fg-down");
        key->btn->texUpBg = ((coc::AssetsCI *)assets)->getTextureRef(key->objID + "-bg-up");
        key->btn->texUpFg = ((coc::AssetsCI *)assets)->getTextureRef(key->objID + "-fg-up");
#endif
        auto downBG = findObjectByID(key->objID + "-bg-down");
        downBG->getParent()->removeChild(downBG);
        auto downFG = findObjectByID(key->objID + "-fg-down");
        downFG->getParent()->removeChild(downFG);
        auto upFG = findObjectByID(key->objID + "-fg-up");
        upFG->getParent()->removeChild(upFG);
        
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

    if (event.isMetaDown() || event.isControlDown() || event.isAccelDown() || event.isAltDown())
        return;

    auto keyCode = event.getCode();

    switch( keyCode ) {
        case KeyEvent::KEY_DELETE:
        case KeyEvent::KEY_BACKSPACE:
            text = text.substr(0, text.length()-1);
            break;
        default:
        {
            char ch = event.getChar();
            if ( ch == ' ' || isalnum( ch ) ) {
                addChar( ch );
            }

        }
            break;

    }

}


};
