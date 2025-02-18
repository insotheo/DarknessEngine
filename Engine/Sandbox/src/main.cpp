#define DE_LOG_ENABLED

#include <DarknessEngine.h>
#include <ImGui/ImGuiLayer.hpp>
#include <Core/Input.h>

class TestLayer : public DarknessEngine::Layer{
public:
    TestLayer() : DarknessEngine::Layer("TestLayer") {}

    void onUpdate() override{
        float x = DarknessEngine::Input::getMouseXPos();
        float y = DarknessEngine::Input::getMouseYPos();
        LOG_INFO("Mouse pos: " + std::to_string(x) + " ; " + std::to_string(y));
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