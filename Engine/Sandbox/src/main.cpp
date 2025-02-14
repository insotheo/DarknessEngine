#define DE_LOG_ENABLED

#include <DarknessEngine.h>

int main(){
    LOG_TRACE("Hello, World!");
    LOG_INFO("Hello, World!");
    LOG_WARN("Hello, World!");
    LOG_ERROR("Hello, World!");
    LOG_CORE_TRACE("Hello, World!");
    LOG_CORE_INFO("Hello, World!");
    LOG_CORE_WARN("Hello, World!");
    LOG_CORE_ERROR("Hello, World!");
    return 0;
}