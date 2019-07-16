#ifndef CONTI_RADAR_H_
#define CONTI_RADAR_H_

#include <cstring>
#include <cstdint>
#include <iostream>
#include <deque>
#include "canet.h"
#include "long_range_radar.h"


#include <cstdlib>
#include <string>
#include <sstream>
#include <cstdint>

// #include "ros/ros.h"
// #include "ros/time.h"
// #include "std_msgs/String.h"
// #include "std_msgs/Header.h"
// #include "ivsensorlrr/ivsensorlrrobj.h"
// #include "ivsensorlrr/radarobject.h"
// #include "ivsensorlrr/ivsensorlrrcluster.h"
// #include "ivsensorlrr/radarcluster.h"
// #include <visualization_msgs/MarkerArray.h>
// #include "boost_udp.h"

namespace conti_radar 
{

class ContiRadar 
{
public:
    ContiRadar() {}
    ~ContiRadar(){}
    void init();
    void process();
    void run();
private:
    char buffer[1024];
    canet::CanetData<canet::Frame<conti_radar::Frame>> canet_;
    RadarCfg                        radar_cfg_;
    FilterCfg                       filter_cfg_;
    FilterCfgX                      filter_cfg_x_;
    Cluster_0_Status                cluster_status_;
    std::deque<Cluster_1_General>   cluster_general_;
    std::deque<Cluster_2_Quality>   cluster_quality_;
};

void ContiRadar::init()
{
    // radar config
    radar_cfg_.data64 = 0;
    radar_cfg_.MaxDistance_valid = 1;
    radar_cfg_.SensorID_valid = 0;
    radar_cfg_.RadarPower_valid = 0;
    radar_cfg_.OutputType_valid = 1;
    radar_cfg_.SendQuality_valid = 1;
    radar_cfg_.SendExtInfo_valid = 1;
    radar_cfg_.SortIndex_valid = 1;
    radar_cfg_.StoreInNVM_valid = 1;
    radar_cfg_.CtrlRelay_valid = 0;
    radar_cfg_.RCS_Threshold_valid = 1;

    radar_cfg_.MaxDistance = 100;
    // radar_cfg_.SensorID = 0;
    radar_cfg_.OutputType = 2;
    // radar_cfg_.RadarPower = 0;
    // radar_cfg_.CtrlRelay = 0;
    radar_cfg_.SendQuality = 1;
    radar_cfg_.SendExtInfo = 1;
    radar_cfg_.SortIndex = 1;
    radar_cfg_.StoreInNVM = 1;
    radar_cfg_.RCS_Threshold = 1;

    // filter config
    filter_cfg_.Valid = 1;
    filter_cfg_.Active = 1;
    filter_cfg_.Index = 1;
    filter_cfg_.Type = 1;
    filter_cfg_.Min = 5;
    filter_cfg_.Max = 2000;

    // 
    conti_radar::Frame conti_cfg();
    // canet_.push_back(canet::Frame(,));
}

void ContiRadar::process()
{

}

void ContiRadar::run()
{

}


} // namespace conti_radar 

#endif // CONTI_RADAR_H_