#ifndef DE_CORE_H
#define DE_CORE_H

#define BIT(x) (1 << x)

#ifdef DE_CONFIG_DEBUG
#define DE_ASSERT(x, msg) if(!(x)) { __debugbreak(); } 
#else
#define DE_ASSERT(x, msg)
#endif


#endif