#ifndef DE_APPLICATION_H
#define DE_APPLICATION_H

#include <memory>

#include "Window.h"
#include "Events/Event.hpp"
#include "Events/ApplicationEvent.hpp"
#include "Layer.h"
#include "LayerStack.h"

namespace DarknessEngine{
    class Application{
    public:
        Application();
        virtual ~Application();

        void run();
        void onEvent(Event& e);

        void pushLayer(Layer* layer);
        void pushOverlay(Layer* overlay);
    private:
        bool onWindowClose(WindowCloseEvent& e);

        std::unique_ptr<Window> m_Window;
        bool m_Running = true;
        LayerStack m_LayerStack;
    };

    Application* CreateApplication(); // on client
}

#endif