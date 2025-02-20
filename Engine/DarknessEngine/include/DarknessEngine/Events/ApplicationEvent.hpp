#ifndef DE_APPLICATION_EVENT_HPP
#define DE_APPLICATION_EVENT_HPP

#include "Event.hpp"

#include <sstream>

namespace DarknessEngine{
    class WindowCloseEvent : public Event{
    public:
        WindowCloseEvent() {}
        EVENT_CLASS_TYPE(WindowClose)
        EVENT_CLASS_CATEGORY(EventCategoryApp)
    };

    class WindowResizeEvent : public Event{
    public:
        WindowResizeEvent(unsigned int width, unsigned int height) : m_width(width), m_height(height) {}

        inline unsigned int getWidth() const { return m_width; }
        inline unsigned int getHeight() const { return m_height; }

        std::string getStrDBG() const override{
            std::stringstream s;
            s << "Window resize: (" << m_width << " ; " << m_height << ")";
            return s.str(); 
        }

        EVENT_CLASS_TYPE(WindowResize)
        EVENT_CLASS_CATEGORY(EventCategoryApp)
    private:
        unsigned int m_width, m_height;
    };

    class WindowGotFocusEvent : public Event{
    public:
        WindowGotFocusEvent() {}
        EVENT_CLASS_TYPE(WindowGotFocus)
        EVENT_CLASS_CATEGORY(EventCategoryApp)
    };

    class WindowLostFocusEvent : public Event{
    public:
        WindowLostFocusEvent() {}
        EVENT_CLASS_TYPE(WindowLostFocus)
        EVENT_CLASS_CATEGORY(EventCategoryApp)
    };

    class WindowMovedEvent : public Event{
    public:
        WindowMovedEvent(float xPos, float yPos) : m_x(xPos), m_y(yPos) {}

        inline float getX() const { return m_x; }
        inline float getY() const { return m_y; }

        std::string getStrDBG() const override{
            std::stringstream s;
            s << "Window moved: (" << m_x << " ; " << m_y << ")";
            return s.str(); 
        }

        EVENT_CLASS_TYPE(WindowMoved)
        EVENT_CLASS_CATEGORY(EventCategoryApp)
    private:
        float m_x, m_y;
    };

    class AppTickEvent : public Event{
    public:
        AppTickEvent() {}

        EVENT_CLASS_TYPE(AppTick)
        EVENT_CLASS_CATEGORY(EventCategoryApp)
    };

    class AppUpdateEvent : public Event{
    public:
        AppUpdateEvent() {}

        EVENT_CLASS_TYPE(AppUpdate)
        EVENT_CLASS_CATEGORY(EventCategoryApp)
    };

    class AppRenderEvent : public Event{
    public:
        AppRenderEvent() {}

        EVENT_CLASS_TYPE(AppRender)
        EVENT_CLASS_CATEGORY(EventCategoryApp)
    };

}

#endif