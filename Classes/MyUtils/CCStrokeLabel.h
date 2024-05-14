#ifndef __CCSTROKELABEL_H__
#define __CCSTROKELABEL_H__
#include "cocos2d.h"
#include "label_nodes/CCLabelTTF.h"


class CCStrokeLabel : public cocos2d::CCNode {
    
public:
    
	 virtual bool init();
	static CCStrokeLabel* create(cocos2d::CCLabelTTF* labelTTF,cocos2d::ccColor3B fullColor,cocos2d::ccColor3B StrokeColor,float strokeSize);
	float getStrokeSize();
	void setStrokeSize(float strokeSize);
    
private:

	cocos2d::CCSprite* m_sprite;
	cocos2d::CCLabelTTF* m_label;
	cocos2d::ccColor3B m_fullColor;
	cocos2d::ccColor3B m_StrokeColor;
	float m_strokeSize;
};

#endif
