#ifndef DE_MOUSE_EVENT_HPP
#define DE_MOUSE_EVENT_HPP

#include "Event.hpp"

#include <sstream>

namespace DarknessEngine{
    class MouseMovedEvent : public Event{
    public:
        MouseMovedEvent(float xPos, float yPos)
        : m_X(xPos), m_Y(yPos)
        {}

        inline float getX() const { return m_X; }
        inline float getY() const { return m_Y; }

        std::string getStringDBG() const override{
            std::stringstream s;
            s << "Mouse moved: (" << m_X << " ; " << m_Y << ")";
            return s.str();
        }

        EVENT_CLASS_TYPE(MouseMoved)
        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
    private:
        float m_X, m_Y;
    };

    class MouseScrolledEvent : public Event{
    public:
        MouseScrolledEvent(float xOffset, float yOffset)
        : m_XOffset(xOffset), m_YOffset(yOffset)
        {}

        inline float getXOffset() const { return m_XOffset; }
        inline float getYOffset() const { return m_YOffset; }

        std::string getStringDBG() const override{
            std::stringstream s;
            s << "Mouse scrolled: (" << m_XOffset << " ; " << m_YOffset << ")";
            return s.str();
        }

        EVENT_CLASS_TYPE(MouseScrolled)
        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

    private:
        float m_XOffset, m_YOffset;
    };

    class MouseButtonEvent : public Event{
    public:
        inline int getButton() const { return m_Button; }

        EVENT_CLASS_CATEGORY(EventCategoryMouseButton| EventCategoryInput)
    protected:
        MouseButtonEvent(int button) : m_Button(button) {}

        int m_Button;
    };

    class MouseButtonPressedEvent : public MouseButtonEvent{
    public:
        MouseButtonPressedEvent(int button) : MouseButtonEvent(button) {}

        std::string getStringDBG() const override {
            std::stringstream s;
            s << "Mouse button pressed: " << m_Button;
            return s.str();
        }

        EVENT_CLASS_TYPE(MouseButtonPressed)
    };

    class MouseButtonReleasedEvent : public MouseButtonEvent{
    public:
        MouseButtonReleasedEvent(int button) : MouseButtonEvent(button) {}

        std::string getStringDBG() const override {
            std::stringstream s;
            s << "Mouse button released: " << m_Button;
            return s.str();
        }

        EVENT_CLASS_TYPE(MouseButtonReleased)
    };
}

#endif