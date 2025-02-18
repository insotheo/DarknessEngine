#ifndef DE_APPLICATION_H
#define DE_APPLICATION_H

#include <memory>

#include "Window.h"
#include "Events/Event.hpp"
#include "Events/ApplicationEvent.hpp"
#include "Layer.h"
#include "LayerStack.h"
#include "ImGui/ImGuiLayer.hpp"

namespace DarknessEngine{
    class Application{
    public:
        Application();
        virtual ~Application();

        void run();
        void onEvent(Event& e);

        void pushLayer(Layer* layer);
        void pushOverlay(Layer* overlay);

        inline static Application& getInstance() { return *s_Instance; }
        inline Window& getWindowRef() { return *m_Window; }
    private:
        bool onWindowClose(WindowCloseEvent& e);

        std::unique_ptr<Window> m_Window;
        ImGuiLayer* m_ImGuiLayer;
        bool m_Running = true;
        LayerStack m_LayerStack;
        
        static Application* s_Instance;
    };

    Application* CreateApplication(); // on client
}

#endif