#ifndef CANET_H_
#define CANET_H_

#include <cstring>
#include <cstdint>
#include <iostream>
#include <deque>
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
public:
    // Frame() { data64[0] = 0; data64[1] = 0; }
    Frame() : data64_0(0), data64_1(0) {}
    Frame(const Frame<MessageFrame>& from ) 
        : data64_0(from.data64_0), data64_1(from.data64_1) {}
    Frame(const MessageFrame& from, uint32_t id_in, uint32_t len, uint32_t rr, uint32_t ff) 
        : msg(from),id(id_in), data_length(len), reserved_1(0), remote_request(rr), frame_form(ff), reserved_2(0) {}   
    Frame<MessageFrame>& operator=(const Frame<MessageFrame>& from) { 
        data64_0=from.data64_0; 
        data64_1=from.data64_1;
        return *this; 
    }

    void clear() { data64_0=0; data64_1=0; }

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
        uint8_t  data8[CANET_FRAME_DATA8_LENGTH];
        uint32_t data32[CANET_FRAME_DATA32_LENGTH];
        uint64_t data64[CANET_FRAME_DATA64_LENGTH];
        struct {
            uint64_t data64_0;
            uint64_t data64_1;
        };
    };

};

template<typename DataFrame>
class CanetData 
//: public ProtocolData<char*>
{
public:
    CanetData(){}
    CanetData(const DataFrame& frame);
    CanetData(const char* data);
    CanetData(const char* data, size_t size);
    ~CanetData() { data_.clear(); }

    size_t read_from(const char* data, size_t size) ;
    size_t write_to(char* data, size_t size) ;
    size_t parse() ;
    void clear() { data_.clear(); } 

    std::deque<DataFrame>& data() {return data_;}
    void push_back(DataFrame& frame) { data_.push_back(frame); }
    void create_frame(DataFrame& frame, char* data) ;
    void create_data(char* data, DataFrame& frame) ;

private:
    std::deque<DataFrame> data_;
};



template<typename DataFrame>
void CanetData<DataFrame>::create_frame(DataFrame& frame, char* data)
{
    char* ptr = reinterpret_cast<char*>(&frame);
    for(int i=0; i<CANET_RAW_DATA8_LENGTH; i++)
    {
        ptr[i] = data[CANET_RAW_DATA8_LENGTH-1-i];
    }
}

template<typename DataFrame>
void CanetData<DataFrame>::create_data(char* data, DataFrame& frame)
{
    char* ptr = reinterpret_cast<char*>(&frame);
    for(int i=0; i<CANET_RAW_DATA8_LENGTH; i++)
    {
        data[CANET_RAW_DATA8_LENGTH-1-i] = ptr[i];
    }
}

template<typename DataFrame>
CanetData<DataFrame>::CanetData(const DataFrame& frame)
{
    data_.push_back(frame);
}

template<typename DataFrame>
CanetData<DataFrame>::CanetData(const char* data)
{   
    DataFrame frame;
    create_frame(frame, data);
    data_.push_back(frame);
}

template<typename DataFrame>
CanetData<DataFrame>::CanetData(const char* data, size_t size)
{
    read_from(data, size);
}

template<typename DataFrame>  
size_t CanetData<DataFrame>::read_from(const char* data, size_t size)
{
    for (int i=0; i<size; i+=CANET_RAW_DATA8_LENGTH)
    {
        DataFrame frame;
        create_frame(frame, data+i);
        data_.push_back(frame);
    }
    return size;
}

template<typename DataFrame>
size_t CanetData<DataFrame>::write_to(char* data, size_t size)
{
    size_t len = data_.size();
    size = len<size ? len : size;
    for (int i=0; i<size; i+=CANET_RAW_DATA8_LENGTH)
    {
        create_data(data+i, data_.at(i/CANET_RAW_DATA8_LENGTH));
    }
    return size;
}

template<typename DataFrame>
size_t CanetData<DataFrame>::parse()
{
    return 0;
}


}

#endif // CANET_H_