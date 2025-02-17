#ifndef DE_KEY_EVENT_HPP
#define DE_KEY_EVENT_HPP

#include "Event.hpp"

#include <sstream>

namespace DarknessEngine{
    class KeyEvent : public Event{
    public: 
        inline int getKeyCode() const { return m_KeyCode; }

        EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
    protected:
        KeyEvent(int keycode) : m_KeyCode(keycode) {}

        int m_KeyCode;
    };

    class KeyPressedEvent : public KeyEvent{
    public:
        KeyPressedEvent(int keycode, int repeatCount)
        : KeyEvent(keycode), m_RepeatCount(repeatCount)
        {}

        inline int getRepeatCount() const { return m_RepeatCount; }

        std::string getStringDBG() const override{
            std::stringstream s;
            s << "Key " << m_KeyCode << " pressed " << m_RepeatCount << " times.";
            return s.str();
        }

        EVENT_CLASS_TYPE(KeyPressed)
    private:
        int m_RepeatCount;
    };

    class KeyReleasedEvent : public KeyEvent{
    public:
        KeyReleasedEvent(int keycode) : KeyEvent(keycode) {}

        std::string getStringDBG() const override{
            std::stringstream s;
            s << "Key " << m_KeyCode << " released.";
            return s.str();
        }

        EVENT_CLASS_TYPE(KeyReleased)
    };

    class KeyTypedEvent : public KeyEvent{
    public:
        KeyTypedEvent(int keycode) : KeyEvent(keycode) {}

        std::string getStringDBG() const override{
            std::stringstream s;
            s << "Key " << m_KeyCode << " typed.";
            return s.str();
        }

        EVENT_CLASS_TYPE(KeyTyped)
    };
};

#endif