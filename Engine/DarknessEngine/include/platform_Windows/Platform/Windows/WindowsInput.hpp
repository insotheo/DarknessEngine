#ifndef DE_WINDOWS_INPUT_HPP
#define DE_WINDOWS_INPUT_HPP

#include "Core/Input.h"

namespace DarknessEngine{
    class WindowsInput : public Input{
    protected:
        bool isKeyPressed_impl(int keycode) override;
        bool isMouseButtonPressed_impl(int btn) override;
        float getMouseXPos_impl() override;
        float getMouseYPos_impl() override;
    };
}

#endif