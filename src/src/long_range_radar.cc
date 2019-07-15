#include <cstdint>
#include <iostream>
#include <string>
#include <cstring>
// #include <cstdlib>

#include "long_range_radar.h"

// namespace sensors {
// //
// CanFrame::CanFrame()
// {
//     clear();
// }
// //
// CanFrame::CanFrame(uint8_t *data)
// {
//     clear();
//     read(data);
// }
// //
// CanFrame::~CanFrame()
// {
// }
// //
// void CanFrame::clear()
// {
//     _buffer.data64[0] = 0;
//     _buffer.data64[1] = 0;
// }
// //
// int CanFrame::read(const uint8_t *data)
// {
//     // change big endian to little endian
//     for(int idx = 0; idx < CAN_FRAME_SIZE; idx++)
//     {
//         _buffer.data8[idx] = data[CAN_FRAME_SIZE-idx-1];
//     }
//     return 0;
// }
// //
// int CanFrame::write(uint8_t *data)
// {
//     // change little endian to big endian
//     for(int idx = 0; idx < CAN_FRAME_SIZE; idx++)
//     {
//         data[CAN_FRAME_SIZE-idx-1] = _buffer.data8[idx];
//     }
//     return 0;
// }
// //
// int CanFrame::parse()
// {
//     if(_buffer.frame.sensor_id = 0)
//     {
//         std::cout << "empty CanFrame." << std::endl;
//         return -1;
//     }
//     switch (_buffer.frame.sensor_id)
//     {
//         // Out   Control message for relay 7.6   
//         case SensorID_CollDetRelayCtrl : // 0x8,

//             break;
//         // Out   Radar status 7.1 
//         case SensorID_RadarState : // 0x201,
        
//             break;
//         // Out   Filter status header 7.2 
//         case SensorID_FilterState_Header : // 0x203,
        
//             break;
//         // Out   Filter configuration status 7.3 
//         case SensorID_FilterState_Cfg : // 0x204,
        
//             break;
//         // Out   Collision detection region status 7.5 
//         case SensorID_CollDetRegionState : // 0x402,
        
//             break;
//         // Out   Collision detection status 7.4 
//         case SensorID_CollDetState : // 0x408,
        
//             break;
//         // Out   Cluster status (list header) 9.1 
//         case SensorID_Cluster_0_Status : // 0x600,
        
//             break;
//         // Out   Object status (list header) 10.1 
//         case SensorID_Obj_0_Status : // 0x60A,
        
//             break;
//         // Out   Object general information 10.2 
//         case SensorID_Obj_1_General : // 0x60B,
        
//             break;
//         // Out   Object quality information 10.3 
//         case SensorID_Obj_2_Quality : // 0x60C,
        
//             break;
//         // Out   Object extended information 10.4 
//         case SensorID_Obj_3_Extended : // 0x60D,
        
//             break;
//         // Out   Object collision detection warnings 10.5 
//         case SensorID_Obj_4_Warning : // 0x60E,
        
//             break;
//         // Out   Software Version Identification 7.7 
//         case SensorID_VersionID : // 0x700,
        
//             break;
//         // Out   Cluster general information 9.2 
//         case SensorID_Cluster_1_General : // 0x701,
        
//             break;
//         // Out   Cluster quality information 9.3 
//         case SensorID_Cluster_2_Quality : // 0x702,
        
//             break;
        
//         default:
//             break;
//     }
//     return 0;
// }
// //
// SensorID CanFrame::getSensorID()
// {
//     return (SensorID)_buffer.frame.sensor_id;
// }
// void CanFrame::setSensorID(SensorID id)
// {
//     _buffer.frame.sensor_id = id;
// }
// //
// int CanFrame::getDataLength()
// {
//     return _buffer.frame.data_length;
// }
// //
// void CanFrame::setDataLength(int length)
// {
//     _buffer.frame.data_length = length;
// }
// //
// Activation CanFrame::getRemoteRequest()
// {
//     return (Activation)_buffer.frame.remote_request;
// }
// //
// void CanFrame::setRemoteRequest(Activation act)
// {
//     _buffer.frame.remote_request = act;
// }
// //
// Activation CanFrame::getFrameForm()
// {
//     return (Activation)_buffer.frame.frame_form;
// }
// //
// void CanFrame::setFrameForm(Activation act)
// {
//     _buffer.frame.frame_form = act;
// }


// }  // namespace sensors
