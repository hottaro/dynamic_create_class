
#ifndef __HOT_COMMON_H__
#define __HOT_COMMON_H__

#include <stdio.h>
#include <map>

/**
 * temp dynamic class create.
 * @step 1: DYNAMIC_INIT (once will be ok)
 * @step 2: YNAMIC_REGISTER(class) outside code.
 * @step 3: dynamic_add(class), in code.
 * @step 4: dynamic_get(name, DynamicBase*) get and use.
 */
// init in main.cpp
#define DYNAMIC_INIT   \
std::map<std::string, void*>  g_dynmap;

// define in where need to use dynamic moudle.
#define DYNAMIC_USE  extern std::map<std::string, void*>  g_dynmap;
#define DYNAMIC_REGISTER( T )   DynamicBase*  new##T(){ return new T(); }

#define dyclass DynamicBase*
#define dynamic_add(T) g_dynmap.insert( std::map<std::string, void*>::value_type( std::string(#T), (void*)new##T ) )
#define dynamic_get(n, p) \
do{ \
pdyclass lp=(pdyclass)g_dynmap.find(n)->second; \
if(lp)p=lp();else{p=0;}\
}while(0)

class DynamicBase
{
public:
    virtual void print()=0;
};
typedef DynamicBase* (*pdyclass)();

#endif
