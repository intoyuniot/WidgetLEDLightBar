#include "WidgetLEDLightBar.h"


WidgetLEDLightBar::WidgetLEDLightBar(uint8_t ucItem)
{
    _Item=ucItem;
    memset(pCmdModeTopic,0,sizeof(pCmdModeTopic));
    memset(pDataStatusTopic,0,sizeof(pDataStatusTopic));
    sprintf(pCmdModeTopic,"channel/LEDLightBar_%d/cmd/mode",_Item);
    sprintf(pDataStatusTopic,"channel/LEDLightBar_%d/data/status",_Item);
}

WidgetLEDLightBar::~WidgetLEDLightBar()
{

}

void WidgetLEDLightBar::begin(void (*UserCallBack)(void))
{
    _EventCb=UserCallBack;
    IntoRobot.subscribe(pCmdModeTopic, NULL, this);
}

int WidgetLEDLightBar::getMode(void)
{
    return _mode;
}

int WidgetLEDLightBar::getLength(void)
{
    return _length;
}

int WidgetLEDLightBar::getBrightness(void)
{
    return _brightness;
}

uint32_t WidgetLEDLightBar::getRGB(void)
{
    return _rgb;
}

void WidgetLEDLightBar::widgetBaseCallBack(uint8_t *payload, uint32_t len)
{
    if(!jsonGetValue(payload, "mode", _mode)) return;
    if(!jsonGetValue(payload, "brightness",_brightness)) return;
    if(!jsonGetValue(payload, "length", _length)) return;
    if(!jsonGetValue(payload, "rgb", _rgb)) return;

    _EventCb();
    IntoRobot.publish(pDataStatusTopic,1);
}

