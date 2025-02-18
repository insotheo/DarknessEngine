#ifndef DE_INPUT_H
#define DE_INPUT_H

namespace DarknessEngine{
    class Input{
    public:
        inline static bool isKeyPressed(int keycode) { return s_Instance->isKeyPressedIMPL(keycode); }
        inline static bool isMouseButtonPressed(int button) { return s_Instance->isMouseButtonPressedIMPL(button); }
        inline static float getMouseXPos() { return s_Instance->getMouseXPosIMPL(); }
        inline static float getMouseYPos() { return s_Instance->getMouseYPosIMPL(); }
    
    protected:
        virtual bool isKeyPressedIMPL(int keycode) = 0;
        virtual bool isMouseButtonPressedIMPL(int button) = 0;
        virtual float getMouseXPosIMPL() = 0;    
        virtual float getMouseYPosIMPL() = 0;
    private:
        static Input* s_Instance;
    };
}

#endif