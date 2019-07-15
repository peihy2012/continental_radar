#ifndef CANET_H_
#define CANET_H_

#include <cstring>
#include <cstdint>
#include <iostream>
#include <vector>
#include "protocol_data.h"

namespace canet {
using protocol_data::ProtocolData;

#define CANET_RAW_DATA8_LENGTH       13
#define CANET_FRAME_DATA8_LENGTH     16
#define CANET_FRAME_DATA16_LENGTH    8
#define CANET_FRAME_DATA32_LENGTH    4
#define CANET_FRAME_DATA64_LENGTH    2

template<typename MessageFrame>
struct Frame
{
// public:
    union {
        struct {
            MessageFrame msg;
            uint32_t id;
            uint32_t data_length        :4;
            uint32_t reserved_1         :2;
            uint32_t remote_request     :1;
            uint32_t frame_form         :1;
            uint32_t reserved_2         :24;
        };
        uint8_t  data8[CANET_FRAME_DATA64_LENGTH];
        uint32_t data32[CANET_FRAME_DATA32_LENGTH];
        uint64_t data64[CANET_FRAME_DATA8_LENGTH];
    };

};

template<typename DataFrame, typename RawData>
class CanetData : public ProtocolData<RawData>
{
public:
    CanetData(){}
    CanetData(const RawData data);
    CanetData(const RawData data, size_t size);
    ~CanetData(){}
    // CanetData<DataFrame, RawData>& init(const RawData data, size_t size);
    // int parse();
    // CanetData<DataFrame, RawData>& data();
    // void clear();
    virtual CanetData<DataFrame, RawData>& init(const RawData data, size_t size);
    virtual size_t read(const RawData data, size_t size) ;
    virtual size_t write(const RawData data, size_t size) ;
    virtual size_t parse() ;
    std::vector<DataFrame>& data() ;
    virtual void clear() ; 
private:
    std::vector<DataFrame> data_;
};

template<typename DataFrame, typename RawData>
CanetData<DataFrame, RawData>::CanetData(const RawData data)
{

    this->push_back(DataFrame(data));
}

template<typename DataFrame, typename RawData>
CanetData<DataFrame, RawData>::CanetData(const RawData data, size_t size)
{
    for (int i=0; i<size; i+=CANET_RAW_DATA8_LENGTH)
    {
        this->push_back(DataFrame(data+i));
    }
}

// template<typename DataFrame, typename RawData>
// ~CanetData()

template<typename DataFrame, typename RawData>
CanetData<DataFrame, RawData>& CanetData<DataFrame>::init(const RawData data, size_t size)
{
    return *this;
}

template<typename DataFrame, typename RawData>
size_t CanetData<DataFrame, RawData>::parse()
{
    return 0;
}

template<typename DataFrame, typename RawData>
std::vector<DataFrame>& CanetData<DataFrame, RawData>::data()
{
    return *this;
}

template<typename DataFrame, typename RawData>
void CanetData<DataFrame, RawData>::clear()
{

}



}

#endif // CANET_H_