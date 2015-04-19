最近碰到一个问题，需要使用通过类的名字在需要的时候创建此类。
但由于c++是静态语言，所以完全动态创建是不可能的。于是试着通过伪动态的方法实现，方法开源出来。不是最好的，但达到要求。
通过宏来伪装，用一个全局Map保存类名与创建类方法，通过二个父类实现逻辑和动态注册。

what it can do,

define a class and call it where we didn't know the really class.


to be modify...
