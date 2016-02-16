#include "CCControlButtonLoader.h"
#include "cocos2d.h"

using namespace cocos2d;
using namespace cocos2d::extension;

namespace cocosbuilder {;

#define PROPERTY_ZOOMONTOUCHDOWN "zoomOnTouchDown"
#define PROPERTY_TITLE_NORMAL "title|1"
#define PROPERTY_TITLETTF_NORMAL "titleTTF|1"
#define PROPERTY_TITLETTFSIZE_NORMAL "titleTTFSize|1"
#define PROPERTY_LABELANCHORPOINT "labelAnchorPoint"
    
// TODO: Should be "preferredSize". This is a typo in cocos2d-iphone, cocos2d-x and CocosBuilder!    
#define PROPERTY_PREFEREDSIZE "preferedSize"
    
#define PROPERTY_TITLECOLOR_NORMAL "titleColor|1"
#define PROPERTY_TITLECOLOR_HIGHLIGHTED "titleColor|2"
#define PROPERTY_TITLECOLOR_DISABLED "titleColor|4"
#define PROPERTY_TITLECOLOR_SELECTED "titleColor|8"
    
#define PROPERTY_BACKGROUNDSPRITEFRAME_NORMAL "backgroundSpriteFrame|1"
#define PROPERTY_BACKGROUNDSPRITEFRAME_HIGHLIGHTED "backgroundSpriteFrame|2"
#define PROPERTY_BACKGROUNDSPRITEFRAME_DISABLED "backgroundSpriteFrame|4"
#define PROPERTY_BACKGROUNDSPRITEFRAME_SELECTED "backgroundSpriteFrame|8"
    
    
    void ControlButtonLoader::onHandlePropTypeCheck(Node * pNode, Node * pParent, const char * pPropertyName, bool pCheck, CCBReader * ccbReader) {
        if(strcmp(pPropertyName, PROPERTY_ZOOMONTOUCHDOWN) == 0) {
            ((ControlButton *)pNode)->setZoomOnTouchDown(pCheck);
        } else {
            ControlLoader::onHandlePropTypeCheck(pNode, pParent, pPropertyName, pCheck, ccbReader);
        }
    }
    
    void ControlButtonLoader::onHandlePropTypeString(Node * pNode, Node * pParent, const char * pPropertyName, const char * pString, CCBReader * ccbReader) {
        if(strcmp(pPropertyName, PROPERTY_TITLE_NORMAL) == 0) {
            ((ControlButton *)pNode)->setTitleForState(pString, Control::State::NORMAL);
            ControlLoader::onHandlePropTypeString(pNode, pParent, pPropertyName, pString, ccbReader);
        }
    }
    
    void ControlButtonLoader::onHandlePropTypeFontTTF(Node * pNode, Node * pParent, const char * pPropertyName, const char * pFontTTF, CCBReader * ccbReader) {
        if (strcmp(pPropertyName, PROPERTY_TITLETTF_NORMAL) == 0) {
            _fontName = pFontTTF;
        }
        else {
            ControlLoader::onHandlePropTypeFontTTF(pNode, pParent, pPropertyName, pFontTTF, ccbReader);
        }
    }
    
    void ControlButtonLoader::onHandlePropTypeFloatScale(Node * pNode, Node * pParent, const char * pPropertyName, float pFloatScale, CCBReader * ccbReader) {
        if (strcmp(pPropertyName, PROPERTY_TITLETTFSIZE_NORMAL) == 0) {
            _fontSize = pFloatScale;
        }
        else {
            ControlLoader::onHandlePropTypeFloatScale(pNode, pParent, pPropertyName, pFloatScale, ccbReader);
        }
    }
    
    void ControlButtonLoader::onHandlePropTypePoint(Node * pNode, Node * pParent, const char * pPropertyName, Vec2 pPoint, CCBReader * ccbReader) {
        if(strcmp(pPropertyName, PROPERTY_LABELANCHORPOINT) == 0) {
            ((ControlButton *)pNode)->setLabelAnchorPoint(pPoint);
        } else {
            ControlLoader::onHandlePropTypePoint(pNode, pParent, pPropertyName, pPoint, ccbReader);
        }
    }
    
    void ControlButtonLoader::onHandlePropTypeSize(Node * pNode, Node * pParent, const char * pPropertyName, Size pSize, CCBReader * ccbReader) {
        if(strcmp(pPropertyName, PROPERTY_PREFEREDSIZE) == 0) {
            ((ControlButton *)pNode)->setPreferredSize(pSize);
        } else {
            ControlLoader::onHandlePropTypeSize(pNode, pParent, pPropertyName, pSize, ccbReader);
        }
    }
    
    void ControlButtonLoader::onHandlePropTypeSpriteFrame(Node * pNode, Node * pParent, const char * pPropertyName, SpriteFrame * pSpriteFrame, CCBReader * ccbReader) {
        if(strcmp(pPropertyName, PROPERTY_BACKGROUNDSPRITEFRAME_NORMAL) == 0) {
            if(pSpriteFrame != nullptr) {
                ((ControlButton *)pNode)->setBackgroundSpriteFrameForState(pSpriteFrame, Control::State::NORMAL);
            }
        } else if(strcmp(pPropertyName, PROPERTY_BACKGROUNDSPRITEFRAME_HIGHLIGHTED) == 0) {
            if(pSpriteFrame != nullptr) {
                ((ControlButton *)pNode)->setBackgroundSpriteFrameForState(pSpriteFrame, Control::State::HIGH_LIGHTED);
            }
        } else if(strcmp(pPropertyName, PROPERTY_BACKGROUNDSPRITEFRAME_DISABLED) == 0) {
            if(pSpriteFrame != nullptr) {
                ((ControlButton *)pNode)->setBackgroundSpriteFrameForState(pSpriteFrame, Control::State::DISABLED);
            }
        } else if(strcmp(pPropertyName, PROPERTY_BACKGROUNDSPRITEFRAME_SELECTED) == 0) {
            if(pSpriteFrame != nullptr) {
                ((ControlButton *)pNode)->setBackgroundSpriteFrameForState(pSpriteFrame, Control::State::SELECTED);
            }
        } else {
            ControlLoader::onHandlePropTypeSpriteFrame(pNode, pParent, pPropertyName, pSpriteFrame, ccbReader);
        }
    }
    
    void ControlButtonLoader::onHandlePropTypeColor3(Node * pNode, Node * pParent, const char * pPropertyName, Color3B pColor3B, CCBReader * ccbReader) {
        if(strcmp(pPropertyName, PROPERTY_TITLECOLOR_NORMAL) == 0) {
            ((ControlButton *)pNode)->setTitleColorForState(pColor3B, Control::State::NORMAL);
        } else if(strcmp(pPropertyName, PROPERTY_TITLECOLOR_HIGHLIGHTED) == 0) {
            ((ControlButton *)pNode)->setTitleColorForState(pColor3B, Control::State::HIGH_LIGHTED);
        } else if(strcmp(pPropertyName, PROPERTY_TITLECOLOR_DISABLED) == 0) {
            ((ControlButton *)pNode)->setTitleColorForState(pColor3B, Control::State::DISABLED);
        } else if(strcmp(pPropertyName, PROPERTY_TITLECOLOR_SELECTED) == 0) {
            ((ControlButton *)pNode)->setTitleColorForState(pColor3B, Control::State::SELECTED);
        } else {
            ControlLoader::onHandlePropTypeColor3(pNode, pParent, pPropertyName, pColor3B, ccbReader);
        }
    }
    
    
    
    void ControlButtonLoader::parseProperties(cocos2d::Node * pNode, cocos2d::Node * pParent, CCBReader * ccbReader) {
        NodeLoader::parseProperties(pNode, pParent, ccbReader);
        
        ControlButton *button = ((ControlButton *)pNode);
        
        // Set label font
        if (_fontName.find(".ttf") != std::string::npos) {
            Label *title = Label::createWithTTF("", _fontName, _fontSize);
            button->setTitleLabelForState(title, Control::State::NORMAL);
        }
        else {
            Label *title = Label::createWithSystemFont("", _fontName, _fontSize);
            button->setTitleLabelForState(title, Control::State::NORMAL);
        }
    }

};