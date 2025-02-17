#ifndef DE_APPLICATION_H
#define DE_APPLICATION_H

#include <memory>

#include "Window.h"
#include "Events/Event.hpp"
#include "Events/ApplicationEvent.hpp"

namespace DarknessEngine{
    class Application{
    public:
        Application();
        virtual ~Application();

        void run();
        void onEvent(Event& e);
    private:
        bool onWindowClose(WindowCloseEvent& e);

        std::unique_ptr<Window> m_Window;
        bool m_Running = true;
    };

    Application* CreateApplication(); // on client
}

#endif