#define DE_LOG_ENABLED

#include <DarknessEngine.h>
#include <ImGui/ImGuiLayer.hpp>

using namespace DarknessEngine;

class TestLayer : public Layer{
public:
    TestLayer() : Layer("TestLayer") {}

    void onUpdate() override{
        if(Input::isKeyPressed(DE_KEY_SPACE)){
            LOG_TRACE("Good jump!");
        }
    }
};

class Sandbox : public Application{
public:
    Sandbox(){
        pushLayer(new TestLayer());
        pushOverlay(new ImGuiLayer());
    }

    ~Sandbox(){

    }
};

DarknessEngine::Application* DarknessEngine::CreateApplication(){
    LOG_INFO("Hello, World!");
    return new Sandbox();
}