#ifndef DE_INPUT_H
#define DE_INPUT_H

namespace DarknessEngine{
    class Input{
    public:
        inline static bool isKeyPressed(int keycode) { return s_inst->isKeyPressed_impl(keycode); }
        inline static bool isMouseButtonPressed(int button) { return s_inst->isMouseButtonPressed_impl(button); }
        inline static float getMouseXPos() { return s_inst->getMouseXPos_impl(); }
        inline static float getMouseYPos() { return s_inst->getMouseYPos_impl(); }
    
    protected:
        virtual bool isKeyPressed_impl(int keycode) = 0;
        virtual bool isMouseButtonPressed_impl(int btn) = 0;
        virtual float getMouseXPos_impl() = 0;    
        virtual float getMouseYPos_impl() = 0;
    private:
        static Input* s_inst;
    };
}

#endif