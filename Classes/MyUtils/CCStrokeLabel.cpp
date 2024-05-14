#include "CCStrokeLabel.h"

using namespace cocos2d;


 CCStrokeLabel* CCStrokeLabel::create(cocos2d::CCLabelTTF* labelTTF,cocos2d::ccColor3B fullColor,cocos2d::ccColor3B StrokeColor,float strokeSize)
 {
	 CCStrokeLabel* tmp = new CCStrokeLabel;
	 tmp->autorelease();
	 tmp->m_label = labelTTF;
	 tmp->m_fullColor = fullColor;
	 tmp->m_StrokeColor = StrokeColor;
	 tmp->m_strokeSize = strokeSize;
	 tmp->init();
	 return tmp;
 }


bool  CCStrokeLabel::init()
{
	bool bRet = false;
	do{
		
		float strokeSize = getStrokeSize();
		// float fontSize = m_fontSize - 2 * strokeSize;
		// 	m_label = CCLabelTTF::labelWithString(
		// 		m_str.c_str(), m_font.c_str(), m_fontSize);
		CCSize textureSize = m_label->getContentSize();
		textureSize.width += 2 * strokeSize;
		textureSize.height += 2 * strokeSize;
		//call to clear error
		glGetError();
		CCRenderTexture *rt = CCRenderTexture::create(
			textureSize.width, textureSize.height);
		if(!rt)
		{
			//ERROR_MSG("create render texture failed !!!!");
			addChild(m_label);
			return false;
		}


		m_label->setColor(m_fullColor);


		ccBlendFunc originalBlend = m_label->getBlendFunc();
		ccBlendFunc func = { GL_SRC_ALPHA, GL_ONE};
		m_label->setBlendFunc(func);


		m_label->setAnchorPoint(ccp(0.5, 0.5));


		rt->begin();
		for(int i = 0; i < 360; i += 15)
		{
			float r = CC_DEGREES_TO_RADIANS(i);
			m_label->setPosition(ccp(
				textureSize.width * 0.5f + sin(r) * strokeSize,
				textureSize.height * 0.5f + cos(r) * strokeSize));
			m_label->visit();
		}
		m_label->setColor(m_StrokeColor);
		m_label->setBlendFunc(originalBlend);
		m_label->setPosition(ccp(textureSize.width * 0.5f, textureSize.height * 0.5f));
		m_label->visit();
		rt->end();


		CCTexture2D *texture = rt->getSprite()->getTexture();
		texture->setAliasTexParameters();
		m_sprite = CCSprite::createWithTexture(rt->getSprite()->getTexture());
		setContentSize(m_sprite->getContentSize());
		m_sprite->setAnchorPoint(ccp(0.5f, 0.5f));
		m_sprite->setPosition(ccp(0, 0));
		((CCSprite *)m_sprite)->setFlipY(true);
		addChild(m_sprite);
	}while(0);

	return bRet;
	
}
float CCStrokeLabel::getStrokeSize()
{
	return m_strokeSize;
}
void CCStrokeLabel::setStrokeSize(float strokeSize)
{
	m_strokeSize = strokeSize;
}
