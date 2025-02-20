#ifndef DE_MOUSE_EVENT_HPP
#define DE_MOUSE_EVENT_HPP

#include "Events/Event.hpp"

#include <sstream>

namespace DarknessEngine{
    class MouseMovedEvent : public Event{
    public:
        MouseMovedEvent(float xPos, float yPos)
        : m_x(xPos), m_y(yPos)
        {}

        inline float getX() const { return m_x; }
        inline float getY() const { return m_y; }

        std::string getStrDBG() const override{
            std::stringstream s;
            s << "Mouse moved: (" << m_x << " ; " << m_y << ")";
            return s.str();
        }

        EVENT_CLASS_TYPE(MouseMoved)
        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
    private:
        float m_x, m_y;
    };

    class MouseScrolledEvent : public Event{
    public:
        MouseScrolledEvent(float xOffset, float yOffset)
        : m_xOff(xOffset), m_yOff(yOffset)
        {}

        inline float getXOffset() const { return m_xOff; }
        inline float getYOffset() const { return m_yOff; }

        std::string getStrDBG() const override{
            std::stringstream s;
            s << "Mouse scrolled: (" << m_xOff << " ; " << m_yOff << ")";
            return s.str();
        }

        EVENT_CLASS_TYPE(MouseScrolled)
        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

    private:
        float m_xOff, m_yOff;
    };

    class MouseButtonEvent : public Event{
    public:
        inline int getButton() const { return m_btn; }

        EVENT_CLASS_CATEGORY(EventCategoryMouseButton| EventCategoryInput)
    protected:
        MouseButtonEvent(int button) : m_btn(button) {}

        int m_btn; //btn stands for button
    };

    class MouseButtonPressedEvent : public MouseButtonEvent{
    public:
        MouseButtonPressedEvent(int button) : MouseButtonEvent(button) {}

        std::string getStrDBG() const override {
            std::stringstream s;
            s << "Mouse button pressed: " << m_btn;
            return s.str();
        }

        EVENT_CLASS_TYPE(MouseButtonPressed)
    };

    class MouseButtonReleasedEvent : public MouseButtonEvent{
    public:
        MouseButtonReleasedEvent(int button) : MouseButtonEvent(button) {}

        std::string getStrDBG() const override {
            std::stringstream s;
            s << "Mouse button released: " << m_btn;
            return s.str();
        }

        EVENT_CLASS_TYPE(MouseButtonReleased)
    };
}

#endif