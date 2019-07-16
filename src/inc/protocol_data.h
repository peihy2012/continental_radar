#ifndef PROTOCOL_DATA_H_
#define PROTOCOL_DATA_H_

#include <cstring>
#include <cstdint>
#include <iostream>
// #include <vector>

namespace protocol_data {

template<typename RawData>
class ProtocolData
{
public:
    ProtocolData();
    ProtocolData(const RawData data);
    ProtocolData(const RawData data, size_t size);
    ~ProtocolData();
    // virtual ProtocolData<RawData>& init(const RawData data, size_t size) = 0;
    virtual size_t read_from(const RawData data, size_t size) ;
    virtual size_t write_to(RawData data, size_t size) ;
    virtual size_t parse() ;
    // virtual ProtocolData<RawData>& data() = 0;
    virtual void clear() ; 
};

// template<typename T>
// ProtocolData<T>::ProtocolData(const char* data)
// {
//     this->push_back(T(data));
// }

// template<typename T>
// ProtocolData<T>::ProtocolData(const char* data, size_t size)
// {
// }

// template<typename T>
// ProtocolData<T>& ProtocolData<T>::init(const char* data, size_t size) 
// {
//     return *this;
// }

// template<typename T>
// int ProtocolData<T>::parse() 
// {
//     return 0;
// }

// template<typename T>
// ProtocolData<T>& ProtocolData<T>::data() 
// {
//     return *this;
// }

}
#endif // PROTOCOL_DATA_H_