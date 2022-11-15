#include <stdio.h>
#include <unistd.h>
#include <cstdio>

class DataTransfer
{
public:
    virtual ~DataTransfer();

    void virtual sendDataToRouter(uint32_t &a_data) = 0; 
    uint32_t virtual sendDataFromRouterToComponent() = 0;
};

