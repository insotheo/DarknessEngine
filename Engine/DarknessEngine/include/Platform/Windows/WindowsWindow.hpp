#ifndef DE_WINDOWS_WINDOW_HPP
#define DE_WINDOWS_WINDOW_HPP

#include "pch.h"

#include "Core/Window.h"

#include "Renderer/GraphicsContext.h"

#include <GLFW/glfw3.h>

namespace DarknessEngine{
    class WindowsWindow : public Window{
    public:
        WindowsWindow(const WindowProps& props);
        virtual ~WindowsWindow();

        void onUpdate() override;

        inline unsigned int getWidth() const override { return m_data._width; }
        inline unsigned int getHeight() const override { return m_data._height; }

        inline void setEventCallback(const EventCallbackFunc& callback) override { m_data._eventCallback = callback; }
        void setVSync(bool state) override;
        bool isVSync() const override; 
        
        inline void* getNative() const override { return m_window; }

    private:
        virtual void init(const WindowProps& props);
        virtual void shutdown();

    private:
        GLFWwindow* m_window;
        GraphicsContext* m_ctx;

        struct WindowData{
            std::string _title;
            unsigned int _width;
            unsigned int _height;
            bool VSync;

            EventCallbackFunc _eventCallback;
        };

        WindowData m_data;
    };
}

#endif