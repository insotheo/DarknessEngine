#ifndef DE_IMGUI_KEY_TRANSLATOR_H
#define DE_IMGUI_KEY_TRANSLATOR_H

#include <imgui.h>
#include "Core/KeyCode.h"

inline ImGuiKey translateToImGuiKey(const int keycode){
    switch (keycode)
    {
        case DE_KEY_TAB: return ImGuiKey_Tab;
        case DE_KEY_LEFT: return ImGuiKey_LeftArrow;
        case DE_KEY_RIGHT: return ImGuiKey_RightArrow;
        case DE_KEY_UP: return ImGuiKey_UpArrow;
        case DE_KEY_DOWN: return ImGuiKey_DownArrow;
        case DE_KEY_PAGE_UP: return ImGuiKey_PageUp;
        case DE_KEY_PAGE_DOWN: return ImGuiKey_PageDown;
        case DE_KEY_HOME: return ImGuiKey_Home;
        case DE_KEY_END: return ImGuiKey_End;
        case DE_KEY_INSERT: return ImGuiKey_Insert;
        case DE_KEY_DELETE: return ImGuiKey_Delete;
        case DE_KEY_BACKSPACE: return ImGuiKey_Backspace;
        case DE_KEY_SPACE: return ImGuiKey_Space;
        case DE_KEY_ENTER: return ImGuiKey_Enter;
        case DE_KEY_ESCAPE: return ImGuiKey_Escape;
        case DE_KEY_APOSTROPHE: return ImGuiKey_Apostrophe;
        case DE_KEY_COMMA: return ImGuiKey_Comma;
        case DE_KEY_MINUS: return ImGuiKey_Minus;
        case DE_KEY_PERIOD: return ImGuiKey_Period;
        case DE_KEY_SLASH: return ImGuiKey_Slash;
        case DE_KEY_SEMICOLON: return ImGuiKey_Semicolon;
        case DE_KEY_EQUAL: return ImGuiKey_Equal;
        case DE_KEY_LEFT_BRACKET: return ImGuiKey_LeftBracket;
        case DE_KEY_BACKSLASH: return ImGuiKey_Backslash;
        case DE_KEY_RIGHT_BRACKET: return ImGuiKey_RightBracket;
        case DE_KEY_GRAVE_ACCENT: return ImGuiKey_GraveAccent;
        case DE_KEY_CAPS_LOCK: return ImGuiKey_CapsLock;
        case DE_KEY_SCROLL_LOCK: return ImGuiKey_ScrollLock;
        case DE_KEY_NUM_LOCK: return ImGuiKey_NumLock;
        case DE_KEY_PRINT_SCREEN: return ImGuiKey_PrintScreen;
        case DE_KEY_PAUSE: return ImGuiKey_Pause;
        case DE_KEY_KP_0: return ImGuiKey_Keypad0;
        case DE_KEY_KP_1: return ImGuiKey_Keypad1;
        case DE_KEY_KP_2: return ImGuiKey_Keypad2;
        case DE_KEY_KP_3: return ImGuiKey_Keypad3;
        case DE_KEY_KP_4: return ImGuiKey_Keypad4;
        case DE_KEY_KP_5: return ImGuiKey_Keypad5;
        case DE_KEY_KP_6: return ImGuiKey_Keypad6;
        case DE_KEY_KP_7: return ImGuiKey_Keypad7;
        case DE_KEY_KP_8: return ImGuiKey_Keypad8;
        case DE_KEY_KP_9: return ImGuiKey_Keypad9;
        case DE_KEY_KP_DECIMAL: return ImGuiKey_KeypadDecimal;
        case DE_KEY_KP_DIVIDE: return ImGuiKey_KeypadDivide;
        case DE_KEY_KP_MULTIPLY: return ImGuiKey_KeypadMultiply;
        case DE_KEY_KP_SUBTRACT: return ImGuiKey_KeypadSubtract;
        case DE_KEY_KP_ADD: return ImGuiKey_KeypadAdd;
        case DE_KEY_KP_ENTER: return ImGuiKey_KeypadEnter;
        case DE_KEY_KP_EQUAL: return ImGuiKey_KeypadEqual;
        case DE_KEY_LEFT_SHIFT: return ImGuiKey_LeftShift;
        case DE_KEY_LEFT_CONTROL: return ImGuiKey_LeftCtrl;
        case DE_KEY_LEFT_ALT: return ImGuiKey_LeftAlt;
        case DE_KEY_LEFT_SUPER: return ImGuiKey_LeftSuper;
        case DE_KEY_RIGHT_SHIFT: return ImGuiKey_RightShift;
        case DE_KEY_RIGHT_CONTROL: return ImGuiKey_RightCtrl;
        case DE_KEY_RIGHT_ALT: return ImGuiKey_RightAlt;
        case DE_KEY_RIGHT_SUPER: return ImGuiKey_RightSuper;
        case DE_KEY_MENU: return ImGuiKey_Menu;
        case DE_KEY_0: return ImGuiKey_0;
        case DE_KEY_1: return ImGuiKey_1;
        case DE_KEY_2: return ImGuiKey_2;
        case DE_KEY_3: return ImGuiKey_3;
        case DE_KEY_4: return ImGuiKey_4;
        case DE_KEY_5: return ImGuiKey_5;
        case DE_KEY_6: return ImGuiKey_6;
        case DE_KEY_7: return ImGuiKey_7;
        case DE_KEY_8: return ImGuiKey_8;
        case DE_KEY_9: return ImGuiKey_9;
        case DE_KEY_A: return ImGuiKey_A;
        case DE_KEY_B: return ImGuiKey_B;
        case DE_KEY_C: return ImGuiKey_C;
        case DE_KEY_D: return ImGuiKey_D;
        case DE_KEY_E: return ImGuiKey_E;
        case DE_KEY_F: return ImGuiKey_F;
        case DE_KEY_G: return ImGuiKey_G;
        case DE_KEY_H: return ImGuiKey_H;
        case DE_KEY_I: return ImGuiKey_I;
        case DE_KEY_J: return ImGuiKey_J;
        case DE_KEY_K: return ImGuiKey_K;
        case DE_KEY_L: return ImGuiKey_L;
        case DE_KEY_M: return ImGuiKey_M;
        case DE_KEY_N: return ImGuiKey_N;
        case DE_KEY_O: return ImGuiKey_O;
        case DE_KEY_P: return ImGuiKey_P;
        case DE_KEY_Q: return ImGuiKey_Q;
        case DE_KEY_R: return ImGuiKey_R;
        case DE_KEY_S: return ImGuiKey_S;
        case DE_KEY_T: return ImGuiKey_T;
        case DE_KEY_U: return ImGuiKey_U;
        case DE_KEY_V: return ImGuiKey_V;
        case DE_KEY_W: return ImGuiKey_W;
        case DE_KEY_X: return ImGuiKey_X;
        case DE_KEY_Y: return ImGuiKey_Y;
        case DE_KEY_Z: return ImGuiKey_Z;
        case DE_KEY_F1: return ImGuiKey_F1;
        case DE_KEY_F2: return ImGuiKey_F2;
        case DE_KEY_F3: return ImGuiKey_F3;
        case DE_KEY_F4: return ImGuiKey_F4;
        case DE_KEY_F5: return ImGuiKey_F5;
        case DE_KEY_F6: return ImGuiKey_F6;
        case DE_KEY_F7: return ImGuiKey_F7;
        case DE_KEY_F8: return ImGuiKey_F8;
        case DE_KEY_F9: return ImGuiKey_F9;
        case DE_KEY_F10: return ImGuiKey_F10;
        case DE_KEY_F11: return ImGuiKey_F11;
        case DE_KEY_F12: return ImGuiKey_F12;
        case DE_KEY_F13: return ImGuiKey_F13;
        case DE_KEY_F14: return ImGuiKey_F14;
        case DE_KEY_F15: return ImGuiKey_F15;
        case DE_KEY_F16: return ImGuiKey_F16;
        case DE_KEY_F17: return ImGuiKey_F17;
        case DE_KEY_F18: return ImGuiKey_F18;
        case DE_KEY_F19: return ImGuiKey_F19;
        case DE_KEY_F20: return ImGuiKey_F20;
        case DE_KEY_F21: return ImGuiKey_F21;
        case DE_KEY_F22: return ImGuiKey_F22;
        case DE_KEY_F23: return ImGuiKey_F23;
        case DE_KEY_F24: return ImGuiKey_F24;
        default: return ImGuiKey_None;
    }
}

#endif