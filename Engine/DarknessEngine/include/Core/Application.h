#ifndef DE_APPLICATION_H
#define DE_APPLICATION_H

#include <memory>

#include "Window.h"

namespace DarknessEngine{
    class Application{
    public:
        Application();
        virtual ~Application();

        void run();
    private:
        std::unique_ptr<Window> m_Window;
        bool m_Running = true;
    };

    Application* CreateApplication(); // on client
}

#endif