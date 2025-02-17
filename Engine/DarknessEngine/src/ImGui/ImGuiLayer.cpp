#include "ImGui/ImGuiLayer.hpp"

#include "Platform/OpenGL/imgui_impl_opengl3.h"
#include "Events/Event.hpp"
#include "Core/Application.h"
#include "ImGuiKeyTranslator.h"

#include <imgui.h>

#include <GLFW/glfw3.h>
#include <Glad/glad.h>

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
        EventDispatcher dispatcher(event);

        dispatcher.dispatch<MouseButtonPressedEvent>(std::bind(&ImGuiLayer::onMouseButtonPressedEvent, this, std::placeholders::_1));
        dispatcher.dispatch<MouseButtonReleasedEvent>(std::bind(&ImGuiLayer::onMouseButtonReleasedEvent, this, std::placeholders::_1));
        dispatcher.dispatch<MouseMovedEvent>(std::bind(&ImGuiLayer::onMouseMovedEvent, this, std::placeholders::_1));
        dispatcher.dispatch<MouseScrolledEvent>(std::bind(&ImGuiLayer::onMouseScrolledEvent, this, std::placeholders::_1));
        dispatcher.dispatch<KeyPressedEvent>(std::bind(&ImGuiLayer::onKeyPressedEvent, this, std::placeholders::_1));
        dispatcher.dispatch<KeyReleasedEvent>(std::bind(&ImGuiLayer::onKeyReleasedEvent, this, std::placeholders::_1));
        dispatcher.dispatch<KeyTypedEvent>(std::bind(&ImGuiLayer::onKeyTypedEvent, this, std::placeholders::_1));
        dispatcher.dispatch<WindowResizeEvent>(std::bind(&ImGuiLayer::onWindowResizeEvent, this, std::placeholders::_1));
    }

    bool ImGuiLayer::onMouseButtonPressedEvent(MouseButtonPressedEvent& event){
        ImGuiIO& io = ImGui::GetIO();
        io.MouseDown[event.getButton()] = true;

        return false; //for passing to the next
    }

    bool ImGuiLayer::onMouseButtonReleasedEvent(MouseButtonReleasedEvent& event){
        ImGuiIO& io = ImGui::GetIO();
        io.MouseDown[event.getButton()] = false;

        return false;
    }

    bool ImGuiLayer::onMouseMovedEvent(MouseMovedEvent& event){
        ImGuiIO& io = ImGui::GetIO();
        io.MousePos = ImVec2(event.getX(), event.getY());

        return false;
    }

    bool ImGuiLayer::onMouseScrolledEvent(MouseScrolledEvent& event){
        ImGuiIO& io = ImGui::GetIO();
        io.MouseWheel = event.getYOffset();
        io.MouseWheelH = event.getXOffset();

        return false;
    }

    bool ImGuiLayer::onKeyPressedEvent(KeyPressedEvent& event){
        ImGuiIO& io = ImGui::GetIO();
        io.AddKeyEvent(translateToImGuiKey(event.getKeyCode()), true);
        
        io.KeyCtrl = event.getKeyCode() == GLFW_KEY_LEFT_CONTROL || event.getKeyCode() == GLFW_KEY_RIGHT_CONTROL;
        io.KeyAlt = event.getKeyCode() == GLFW_KEY_LEFT_ALT || event.getKeyCode() == GLFW_KEY_RIGHT_ALT;
        io.KeyShift = event.getKeyCode() == GLFW_KEY_LEFT_SHIFT || event.getKeyCode() == GLFW_KEY_RIGHT_SHIFT;
        io.KeySuper = event.getKeyCode() == GLFW_KEY_LEFT_SUPER || event.getKeyCode() == GLFW_KEY_RIGHT_SUPER;

        return false;
    }

    bool ImGuiLayer::onKeyReleasedEvent(KeyReleasedEvent& event){
        ImGuiIO& io = ImGui::GetIO();
        io.AddKeyEvent(translateToImGuiKey(event.getKeyCode()), false);

        return false;
    }

    bool ImGuiLayer::onKeyTypedEvent(KeyTypedEvent& event){
        ImGuiIO& io = ImGui::GetIO();
        int c = event.getKeyCode();
        if(c > 0 && c < 0x10000){
            io.AddInputCharacter((unsigned int)c);
        }

        return false;
    }

    bool ImGuiLayer::onWindowResizeEvent(WindowResizeEvent& event){
        ImGuiIO& io = ImGui::GetIO();
        io.DisplaySize = ImVec2((float)event.getWidth(), (float)event.getHeight());
        io.DisplayFramebufferScale = ImVec2(1.f, 1.f);
        glViewport(0, 0, event.getWidth(), event.getHeight());

        return false;
    }
}