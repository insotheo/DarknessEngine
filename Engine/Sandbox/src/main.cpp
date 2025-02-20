#define DE_LOG_ENABLED

#include <DarknessEngine.h>
#include <imgui.h>

using namespace DarknessEngine;

class TestLayer : public Layer{
public:
    TestLayer() : Layer("TestLayer") {}

    void onUpdate() override{
        if(Input::isKeyPressed(DE_KEY_SPACE)){
            LOG_TRACE("Good jump!");
        }
    }

    void onImGuiDraw() override{
        ImGui::Begin("DBG");
        ImGui::TextUnformatted("Hello!");
        ImGui::End();
    }
};

class Sandbox : public Application{
public:
    Sandbox(){
        pushLayer(new TestLayer());
    }

    ~Sandbox(){

    }
};

DarknessEngine::Application* DarknessEngine::CreateApp(){
    LOG_INFO("Hello, World!");
    return new Sandbox();
}