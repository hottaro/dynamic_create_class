#ifndef __HOT_LOGIC_H__
#define __HOT_LOGIC_H__

#include <common.h>

public class Logic : public DynamicBase
{
public:
    virtual void print() {
        printf("i am base logic class!");
    }
    
public:
    virtual void do_something() {
        really_do_something();
    }
    
protected:
    /**
     * really do something in own class.
     */
    virtual void really_do_something() = 0;
    
};

#endif

