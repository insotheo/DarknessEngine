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
        WindowResizeEvent(unsigned int width, unsigned int height) : m_Width(width), m_Height(height) {}

        inline unsigned int getWidth() const { return m_Width; }
        inline unsigned int getHeight() const { return m_Height; }

        std::string getStringDBG() const override{
            std::stringstream s;
            s << "Window resize: (" << m_Width << " ; " << m_Height << ")";
            return s.str(); 
        }

        EVENT_CLASS_TYPE(WindowResize)
        EVENT_CLASS_CATEGORY(EventCategoryApp)
    private:
        unsigned int m_Width, m_Height;
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
        WindowMovedEvent(float xPos, float yPos) : m_X(xPos), m_Y(yPos) {}

        inline float getX() const { return m_X; }
        inline float getY() const { return m_Y; }

        std::string getStringDBG() const override{
            std::stringstream s;
            s << "Window moved: (" << m_X << " ; " << m_Y << ")";
            return s.str(); 
        }

        EVENT_CLASS_TYPE(WindowMoved)
        EVENT_CLASS_CATEGORY(EventCategoryApp)
    private:
        float m_X, m_Y;
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