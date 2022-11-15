#ifndef ROUTER_HPP
#define ROUTER_HPP
#include <iostream>

class Router
{
private:
    
public:
    Router();
    ~Router();
    uint32_t recevedData = 0;

    void sendDataToRouter(uint32_t &a_data);
    uint32_t sendDataFromRouterToComponent();
};

#endif // ROUTER_HPP
