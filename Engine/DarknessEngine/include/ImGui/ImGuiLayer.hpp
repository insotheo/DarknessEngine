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
        void onImGuiDraw() override;

        void begin();
        void end();
    private:
        float m_time = 0.f;
    };
}

#endif