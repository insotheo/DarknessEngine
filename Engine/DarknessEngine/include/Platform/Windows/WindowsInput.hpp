#ifndef DE_WINDOWS_INPUT_HPP
#define DE_WINDOWS_INPUT_HPP

#include "Core/Input.h"

namespace DarknessEngine{
    class WindowsInput : public Input{
    protected:
        virtual bool isKeyPressedIMPL(int keycode) override;
        virtual bool isMouseButtonPressedIMPL(int button) override;
        virtual float getMouseXPosIMPL() override;
        virtual float getMouseYPosIMPL() override;
    };
}

#endif