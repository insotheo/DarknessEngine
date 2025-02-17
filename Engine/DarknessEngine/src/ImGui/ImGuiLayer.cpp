#include "ImGui/ImGuiLayer.hpp"

#include "Platform/OpenGL/imgui_impl_opengl3.h"
#include "Events/Event.hpp"
#include "Core/Application.h"

#include <imgui.h>
#include <GLFW/glfw3.h>

namespace DarknessEngine{
    ImGuiLayer::ImGuiLayer() : Layer("ImGuiLayer") {}

    ImGuiLayer::~ImGuiLayer(){

    }

    void ImGuiLayer::onAttach(){
        ImGui::CreateContext();
        ImGui::StyleColorsClassic();

        ImGuiIO& io = ImGui::GetIO();
        io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
        io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;

        ImGui_ImplOpenGL3_Init("#version 410");
    }

    void ImGuiLayer::onDetach(){
        
    }

    void ImGuiLayer::onUpdate(){  
        ImGuiIO& io = ImGui::GetIO();
        Application& app = Application::getInstance();

        io.DisplaySize = ImVec2((float)app.getWindowRef().getWidth(), (float)app.getWindowRef().getHeight());
        
        float time = (float)glfwGetTime();
        io.DeltaTime = m_Time > 0.0f ? (time - m_Time) : (1.f / 60.f);
        m_Time = time;
        
        ImGui_ImplOpenGL3_NewFrame();
        ImGui::NewFrame();

        static bool flag = true;
        ImGui::ShowDemoWindow(&flag);

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    }

    void ImGuiLayer::onEvent(Event& event){

    }
}