#include <Display.h>
#include <XPT2046_Touchscreen.h>

namespace display
{
    class Display_XPT2046_Touchscreen : public LoopHandler
    {
    public:
        Display_XPT2046_Touchscreen(Interface *interface, XPT2046_Touchscreen &ts) : _interface(interface), _ts(&ts) {}

        void calibration(TS_Point origin, TS_Point horizontal, TS_Point vertical);

        void loopHandler() override;

    private:
        Interface *_interface;
        XPT2046_Touchscreen *_ts;

        float _a11, _a12, _a13, _a21, _a22, _a23;
        bool _down = false;
    };
}