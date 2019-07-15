#include <cstdint>
#include <iostream>
#include <string>

#include "long_range_radar.h"
#include "protocol_data.h"
#include "canet.h"

int main(int argc, char** argv)
{
    unsigned char buffer[13];
    for(int i=0; i<12; i++)
    {
        buffer[i] = 'a'+i;
    }
    buffer[12] = 0;
    canet::Frame<conti_radar::Frame> radar_frame;
    radar_frame.msg.Cluster_2_Quality.AmbigState = 0;
    radar_frame.msg.FilterCfg.Index = 0;

    protocol_data::ProtocolData<unsigned char*> proto;
    proto.push_back(buffer);
    conti_radar::SensorID sensor_id;
    conti_radar::RadarCfg radar_cfg;

    std::cout << "template class test." << std::endl;
    // for(auto it : proto)
    {
        char* t = (char*)proto.at(0);
        std::string str(t);
        //(static_cast<char*>(buffer));
        std::cout << "string " <<  str << std::endl;
    }
    return 0;
}
