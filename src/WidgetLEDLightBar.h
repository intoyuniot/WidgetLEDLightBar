#ifndef WIDGET_LED_LIGHT_BAR_H_
#define WIDGET_LED_LIGHT_BAR_H_

#include "application.h"

class WidgetLEDLightBar: public WidgetBaseClass
{
    public:
        WidgetLEDLightBar(uint8_t ucItem = 0);
        ~WidgetLEDLightBar();
        void begin(void (*UserCallBack)(void) = NULL);
        int getMode(void);
        int getLength(void);
        int getBrightness(void);
        uint32_t getRGB(void);

    private:
        char pCmdModeTopic[64];
        char pDataStatusTopic[64];
        int _mode;
        int _brightness;
        int _length;
        uint32_t _rgb;
        uint8_t _Item = 0;

        void (*_EventCb)(void);
        void widgetBaseCallBack(uint8_t *payload, uint32_t len);
};

#endif
