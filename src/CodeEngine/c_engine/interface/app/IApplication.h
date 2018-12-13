#ifndef CODEENGINE_C_ENGINE_INTERFACE_APP_IAPPLICATION_H_
#define CODEENGINE_C_ENGINE_INTERFACE_APP_IAPPLICATION_H_

class IApplication
{
private:
    /* data */
public:
    virtual ~IApplication() {}
    virtual int run(int, char*[]) = 0;
};

#endif