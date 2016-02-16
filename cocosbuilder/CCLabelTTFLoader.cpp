#include "CCLabelTTFLoader.h"

using namespace cocos2d;

#define PROPERTY_COLOR "color"
#define PROPERTY_OPACITY "opacity"
#define PROPERTY_BLENDFUNC "blendFunc"
#define PROPERTY_FONTNAME "fontName"
#define PROPERTY_FONTSIZE "fontSize"
#define PROPERTY_HORIZONTALALIGNMENT "horizontalAlignment"
#define PROPERTY_VERTICALALIGNMENT "verticalAlignment"
#define PROPERTY_STRING "string"
#define PROPERTY_DIMENSIONS "dimensions"

namespace cocosbuilder {

void LabelTTFLoader::onHandlePropTypeColor3(Node * pNode, Node * pParent, const char * pPropertyName, Color3B pColor3B, CCBReader * ccbReader) {
    if(strcmp(pPropertyName, PROPERTY_COLOR) == 0) {
        ((Label *)pNode)->setColor(pColor3B);
    } else {
        NodeLoader::onHandlePropTypeColor3(pNode, pParent, pPropertyName, pColor3B, ccbReader);
    }
}

void LabelTTFLoader::onHandlePropTypeByte(Node * pNode, Node * pParent, const char * pPropertyName, unsigned char pByte, CCBReader * ccbReader) {
    if(strcmp(pPropertyName, PROPERTY_OPACITY) == 0) {
        ((Label *)pNode)->setOpacity(pByte);
    } else {
        NodeLoader::onHandlePropTypeByte(pNode, pParent, pPropertyName, pByte, ccbReader);
    }
}

void LabelTTFLoader::onHandlePropTypeBlendFunc(Node * pNode, Node * pParent, const char * pPropertyName, BlendFunc pBlendFunc, CCBReader * ccbReader) {
    if(strcmp(pPropertyName, PROPERTY_BLENDFUNC) == 0) {
        ((Label *)pNode)->setBlendFunc(pBlendFunc);
    } else {
        NodeLoader::onHandlePropTypeBlendFunc(pNode, pParent, pPropertyName, pBlendFunc, ccbReader);
    }
}

    void LabelTTFLoader::onHandlePropTypeFontTTF(Node * pNode, Node * pParent, const char * pPropertyName, const char * pFontTTF, CCBReader * ccbReader) {
        if(strcmp(pPropertyName, PROPERTY_FONTNAME) == 0) {
            _fontName = pFontTTF;
        } else {
            NodeLoader::onHandlePropTypeFontTTF(pNode, pParent, pPropertyName, pFontTTF, ccbReader);
        }
    }
    
    void LabelTTFLoader::onHandlePropTypeText(Node * pNode, Node * pParent, const char * pPropertyName, const char * pText, CCBReader * ccbReader) {
        std::string text(pText);
        std::replace(text.begin(), text.end(), '\r', '\n');
        
        if(strcmp(pPropertyName, PROPERTY_STRING) == 0) {
            ((Label *)pNode)->setString(text.c_str());
        } else {
            NodeLoader::onHandlePropTypeText(pNode, pParent, pPropertyName, text.c_str(), ccbReader);
        }
    }
    
    void LabelTTFLoader::onHandlePropTypeFloatScale(Node * pNode, Node * pParent, const char * pPropertyName, float pFloatScale, CCBReader * ccbReader) {
        if(strcmp(pPropertyName, PROPERTY_FONTSIZE) == 0) {
            _fontSize = pFloatScale;
        } else {
            NodeLoader::onHandlePropTypeFloatScale(pNode, pParent, pPropertyName, pFloatScale, ccbReader);
        }
    }

void LabelTTFLoader::onHandlePropTypeIntegerLabeled(Node * pNode, Node * pParent, const char * pPropertyName, int pIntegerLabeled, CCBReader * ccbReader) {
    if(strcmp(pPropertyName, PROPERTY_HORIZONTALALIGNMENT) == 0) {
        ((Label *)pNode)->setHorizontalAlignment(TextHAlignment(pIntegerLabeled));
    } else if(strcmp(pPropertyName, PROPERTY_VERTICALALIGNMENT) == 0) {
        ((Label *)pNode)->setVerticalAlignment(TextVAlignment(pIntegerLabeled));
    } else {
        NodeLoader::onHandlePropTypeFloatScale(pNode, pParent, pPropertyName, pIntegerLabeled, ccbReader);
    }
}

void LabelTTFLoader::onHandlePropTypeSize(Node * pNode, Node * pParent, const char * pPropertyName, Size size, CCBReader * ccbReader) {
    if(strcmp(pPropertyName, PROPERTY_DIMENSIONS) == 0) {
        ((Label *)pNode)->setDimensions(size.width,size.height);
    } else {
        NodeLoader::onHandlePropTypeSize(pNode, pParent, pPropertyName, size, ccbReader);
    }
}
    
    void LabelTTFLoader::parseProperties(cocos2d::Node * pNode, cocos2d::Node * pParent, CCBReader * ccbReader) {
        NodeLoader::parseProperties(pNode, pParent, ccbReader);
        
        Label *label = ((Label *)pNode);
        
        // Set label font
        if (_fontName.find(".ttf") != std::string::npos) {
            TTFConfig ttfConfig(_fontName.c_str(), _fontSize, GlyphCollection::DYNAMIC);
            label->setTTFConfig(ttfConfig);
        }
        else {
            label->setSystemFontName(_fontName);
            label->setSystemFontSize(_fontSize);
        }
    }

}
