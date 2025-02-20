#ifndef DE_EVENT_HPP
#define DE_EVENT_HPP

#include "Core/Core.h"

#include <string>
#include <functional>

namespace DarknessEngine{
    enum class EventType{
        None = 0,
        WindowClose, WindowResize, WindowGotFocus, WindowLostFocus, WindowMoved,
        AppTick, AppUpdate, AppRender,
        KeyPressed, KeyReleased, KeyTyped,
        MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
    };

    enum EventCategory{
        None                        = 0,
        EventCategoryApp            = BIT(0),
        EventCategoryInput          = BIT(1),
        EventCategoryKeyboard       = BIT(2),
        EventCategoryMouse          = BIT(3),
        EventCategoryMouseButton    = BIT(4)
    };

    #define EVENT_CLASS_TYPE(type) static EventType getStaticType() { return EventType::##type; }\
                                    virtual EventType getEventType() const override { return getStaticType(); }\
                                    virtual const char* getName() const override { return #type; }

    #define EVENT_CLASS_CATEGORY(category) virtual int getCategoryFlags() const override { return category; }

    class Event{
        friend class EventDispatcher;
    public:
        virtual EventType getEventType() const = 0;
        virtual const char* getName() const = 0;
        virtual int getCategoryFlags() const = 0;
        virtual std::string getStrDBG() const { return getName(); }

        inline bool isInCategory(const EventCategory& category){
            return getCategoryFlags() & category;
        }

        inline bool isHandled() const { return m_handled; }
    protected:
        bool m_handled = false;
    };

    class EventDispatcher{
        template<typename T>
        using EventFunc = std::function<bool(T&)>;
    public:
        EventDispatcher(Event& event) : m_event(event){}

        template<typename T>
        bool dispatch(EventFunc<T> func){
            if(m_event.getEventType() == T::getStaticType()){
                m_event.m_handled = func(*(T*)&m_event);
                return true;
            }
            return false;
        }
    private:
        Event& m_event;
    };
}

#endif