#ifndef DE_KEY_EVENT_HPP
#define DE_KEY_EVENT_HPP

#include "Events/Event.hpp"

#include <sstream>

namespace DarknessEngine{
    class KeyEvent : public Event{
    public: 
        inline int getKeyCode() const { return m_keycode; }

        EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
    protected:
        KeyEvent(int keycode) : m_keycode(keycode) {}

        int m_keycode;
    };

    class KeyPressedEvent : public KeyEvent{
    public:
        KeyPressedEvent(int keycode, int repeatCount)
        : KeyEvent(keycode), m_RepeatCount(repeatCount)
        {}

        inline int getRepeatCount() const { return m_RepeatCount; }

        std::string getStrDBG() const override{
            std::stringstream s;
            s << "Key " << m_keycode << " pressed " << m_RepeatCount << " times.";
            return s.str();
        }

        EVENT_CLASS_TYPE(KeyPressed)
    private:
        int m_RepeatCount;
    };

    class KeyReleasedEvent : public KeyEvent{
    public:
        KeyReleasedEvent(int keycode) : KeyEvent(keycode) {}

        std::string getStrDBG() const override{
            std::stringstream s;
            s << "Key " << m_keycode << " released.";
            return s.str();
        }

        EVENT_CLASS_TYPE(KeyReleased)
    };

    class KeyTypedEvent : public KeyEvent{
    public:
        KeyTypedEvent(int keycode) : KeyEvent(keycode) {}

        std::string getStrDBG() const override{
            std::stringstream s;
            s << "Key " << m_keycode << " typed.";
            return s.str();
        }

        EVENT_CLASS_TYPE(KeyTyped)
    };
};

#endif