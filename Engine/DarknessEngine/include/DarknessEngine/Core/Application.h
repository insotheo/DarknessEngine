#ifndef DE_APPLICATION_H
#define DE_APPLICATION_H

#include <memory>

#include "Core/Window.h"
#include "Core/Layer.h"
#include "Core/LayerStack.h"

#include "Events/Event.hpp"
#include "Events/ApplicationEvent.hpp"

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

        inline static Application& getInstance() { return *s_inst; }
        inline Window& getWindowRef() { return *m_window; }
    private:
        bool onWindowClose(WindowCloseEvent& e);

        std::unique_ptr<Window> m_window;
        bool m_running = true;

        ImGuiLayer* m_imguiLayer;
        LayerStack m_layerStack;
        
        static Application* s_inst;
    };

    Application* CreateApp(); // on client
}

#endif