#ifndef MERGE_H_INCLUDED
#define MERGE_H_INCLUDED
#include "queue.h"
template<typename T>
unsigned merge(queue<T> &in){
    queue<T> buff;
    T value;
    unsigned out(0);
    if(in.empty())out=1;
    else{
        while(!in.empty()){
            in.pop(value);
            if(value%2!=0)buff.push(value);
        }
        while(!buff.empty()){
            buff.pop(value);
            in.push(value);
        }
    }
    return out;
}

#endif // MERGE_H_INCLUDED
