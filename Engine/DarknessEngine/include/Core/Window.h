#ifndef DE_WINDOW_H
#define DE_WINDOW_H

#include <string>
#include <functional>

#include "Events/Event.hpp"
#include "Events/ApplicationEvent.hpp"

namespace DarknessEngine{
    struct WindowProps{
        std::string _title;
        unsigned int _width;
        unsigned int _height;

        WindowProps(const std::string& title = "DarknessEngine's Window",
                    unsigned int width = 1280,
                    unsigned int height = 720)
        : _title(title), _width(width), _height(height)
        {}
    };

    class Window{
    public:
        using EventCallbackFunc = std::function<void(Event&)>;

        virtual ~Window() {}
        virtual void onUpdate() = 0;

        virtual unsigned int getWidth() const = 0;
        virtual unsigned int getHeight() const = 0;

        //attribs
        virtual void setEventCallback(const EventCallbackFunc& callback) = 0;
        virtual void setVSync(bool state) = 0; 
        virtual bool isVSync() const = 0;

        virtual void* getNative() const = 0;

        static Window* create(const WindowProps& props = WindowProps());
    };
}

#endif