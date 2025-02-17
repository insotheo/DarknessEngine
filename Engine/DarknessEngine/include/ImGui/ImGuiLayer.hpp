#ifndef DE_IMGUI_LAYER_HPP
#define DE_IMGUI_LAYER_HPP

#include "Core/Layer.h"

#include "Events/ApplicationEvent.hpp"
#include "Events/KeyEvent.hpp"
#include "Events/MouseEvent.hpp"

namespace DarknessEngine{
    class ImGuiLayer : public Layer{
    public:
        ImGuiLayer();
        ~ImGuiLayer();

        void onAttach() override;
        void onDetach() override;
        void onUpdate() override;
        void onEvent(Event& event) override;
    private:
        bool onMouseButtonPressedEvent(MouseButtonPressedEvent& event);
        bool onMouseButtonReleasedEvent(MouseButtonReleasedEvent& event);
        bool onMouseMovedEvent(MouseMovedEvent& event);
        bool onMouseScrolledEvent(MouseScrolledEvent& event);
        bool onKeyPressedEvent(KeyPressedEvent& event);
        bool onKeyReleasedEvent(KeyReleasedEvent& event);
        bool onKeyTypedEvent(KeyTypedEvent& event);
        bool onWindowResizeEvent(WindowResizeEvent& event);

        float m_Time = 0.f;
    };
}

#endif