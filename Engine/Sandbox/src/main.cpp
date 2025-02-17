#define DE_LOG_ENABLED

#include <DarknessEngine.h>
#include <ImGui/ImGuiLayer.hpp>

class TestLayer : public DarknessEngine::Layer{
public:
    TestLayer() : DarknessEngine::Layer("TestLayer") {}

    void onEvent(DarknessEngine::Event& e) override{
        if(e.isInCategory(DarknessEngine::EventCategory::EventCategoryKeyboard)){
            LOG_INFO(e.getStringDBG());
        }
    }
};

class Sandbox : public DarknessEngine::Application{
public:
    Sandbox(){
        pushLayer(new TestLayer());
        pushOverlay(new DarknessEngine::ImGuiLayer());
    }

    ~Sandbox(){

    }
};

DarknessEngine::Application* DarknessEngine::CreateApplication(){
    LOG_INFO("Hello, World!");
    return new Sandbox();
}