#include <iostream>

unsigned int DJBHash(const char* str, unsigned int length){
    unsigned int hash = 5381;
    unsigned int i = 0;
    for (i = 0; i < length; ++str, ++i){
        hash = ((hash * 33) + hash) + (*str);
    }
    return hash;
}

int main(){
    char test[5] = "test";
    std::cout << DJBHash(test, 5) << std::endl;
}
