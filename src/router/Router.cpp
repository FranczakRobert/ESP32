#include "Router.hpp"

Router::Router(/* args */)
{
}

Router::~Router()
{
}

void Router::sendDataToRouter(uint32_t &a_data)
{
    recevedData = a_data;
}
uint32_t Router::sendDataFromRouterToComponent()
{
    return recevedData;
}