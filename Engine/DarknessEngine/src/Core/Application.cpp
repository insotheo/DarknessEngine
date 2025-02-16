#include "pch.h"

#include "Core/Application.h"

#include "Events/ApplicationEvent.hpp"
#include "Core/Log.h"

namespace DarknessEngine{

    Application::Application(){
    }

    Application::~Application(){
    }

    void Application::run(){
        WindowResizeEvent event(1280, 720);
        Log::trace(event.getStringDBG(), "TEST");
        while(true){}
    }

}