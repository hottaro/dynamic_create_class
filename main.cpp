#include <logic.h>

// init in main cpp. step <1/3>
DYNAMIC_INIT

class MyLogic : public Logic {
    
public:
    virtual void really_do_something()  {
        
        printf("i am the one in the back.");
    }
};

// register dynamic class. step <2/3>
DYNAMIC_REGISTER(MyLogic)

// if we use in other file, define below.
//DYNAMIC_USE

int main() {
    
    // add. step <3/3>
    dynamic_add(MyLogic);
    
    
    DynamicBase *obj;
    
    // get, class. of course we can get from where didn't know Mylogic class except its base class.
    // @see line:18
    dynamic_get(std::string("Mylogic"), obj);
    
    if (obj) {
        // here is the point, we just know the base class. Logic.
        Logic *lc = (Logic*)obj;
        
        lc->do_something(); // here, -----> will call really_do_something() in Mylogic class, where we didn't know the class name. MyLogic.
    }
    
    // very simple, have fun.
    
    reutnr 0;
}