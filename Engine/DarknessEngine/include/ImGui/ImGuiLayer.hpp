#ifndef DE_IMGUI_LAYER_HPP
#define DE_IMGUI_LAYER_HPP

#include "Core/Layer.h"

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
        float m_Time = 0.f;
    };
}

#endif