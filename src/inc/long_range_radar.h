#ifndef LONG_RANGE_RADAR_H
#define LONG_RANGE_RADAR_H

#include <cstdint>

namespace conti_radar 
{

// #define CAN_FRAME_SIZE  13

enum Validity {
    Invalid = 0,
    Valid = 1,
} ;

enum Activation {
    Inactive = 0,
    Active = 1,
} ;

// In/Out ID Message Name Content Section 
enum SensorID {
    // Out   Control message for relay 7.6   
    SensorID_CollDetRelayCtrl = 0x8,
    // In  Radar sensor configuration 6.1 
    SensorID_RadarCfg = 0x200,
    // Out   Radar status 7.1 
    SensorID_RadarState = 0x201,
    // In   Cluster and Object filter configuration 6.2 
    SensorID_FilterCfg = 0x202,
    // Out   Filter status header 7.2 
    SensorID_FilterState_Header = 0x203,
    // Out   Filter configuration status 7.3 
    SensorID_FilterState_Cfg = 0x204,
    // In   Vehicle (sensor platform) speed 8.1 
    SensorID_SpeedInformation = 0x300,
    // In   Vehicle (sensor platform) yaw rate 8.2 
    SensorID_YawRateInformation = 0x301,
    // In   Collision detection configuration 6.3 
    SensorID_CollDetCfg = 0x400,
    // In   Collision detection region configuration 6.4 
    SensorID_CollDetRegionCfg = 0x401,
    // Out   Collision detection region status 7.5 
    SensorID_CollDetRegionState = 0x402,
    // Out   Collision detection status 7.4 
    SensorID_CollDetState = 0x408,
    // Out   Cluster status (list header) 9.1 
    SensorID_Cluster_0_Status = 0x600,
    // Out   Object status (list header) 10.1 
    SensorID_Obj_0_Status = 0x60A,
    // Out   Object general information 10.2 
    SensorID_Obj_1_General = 0x60B,
    // Out   Object quality information 10.3 
    SensorID_Obj_2_Quality = 0x60C,
    // Out   Object extended information 10.4 
    SensorID_Obj_3_Extended = 0x60D,
    // Out   Object collision detection warnings 10.5 
    SensorID_Obj_4_Warning = 0x60E,
    // Out   Software Version Identification 7.7 
    SensorID_VersionID = 0x700,
    // Out   Cluster general information 9.2 
    SensorID_Cluster_1_General = 0x701,
    // Out   Cluster quality information 9.3 
    SensorID_Cluster_2_Quality = 0x702,
} ;

enum FilterCfgIndex {
    FilterCfg_NofObj = 0x0,
    FilterCfg_Distance = 0x1,
    FilterCfg_Azimuth = 0x2,
    FilterCfg_VrelOncome = 0x3,
    FilterCfg_VrelDepart = 0x4,
    FilterCfg_RCS = 0x5,
    FilterCfg_Lifetime = 0x6,
    FilterCfg_Size = 0x7,
    FilterCfg_ProbExists = 0x8,
    FilterCfg_Y = 0x9,
    FilterCfg_X = 0xa,
    FilterCfg_VYRightLeft = 0xb,
    FilterCfg_VXOncome = 0xc,
    FilterCfg_VYLeftRight = 0xd,
    FilterCfg_VXDepart = 0xe,
} ;


// the following configures structs are constructed for little endian system
// 0x200
struct RadarCfg {
    RadarCfg& operator=(const RadarCfg& from){ 
        data64 = from.data64;
        return  *this;
    }
    union {
        uint64_t data64;
        struct {
            uint64_t reserved_1         :8;
            uint64_t RCS_Threshold_valid:1;
            uint64_t RCS_Threshold      :3;
            uint64_t reserved_2         :4;
            uint64_t CtrlRelay_valid    :1;
            uint64_t CtrlRelay          :1;
            uint64_t SendQuality        :1;
            uint64_t SendExtInfo        :1;
            uint64_t SortIndex          :3;
            uint64_t StoreInNVM         :1;
            uint64_t SensorID           :3;
            uint64_t OutputType         :2;
            uint64_t RadarPower         :3;
            uint64_t reserved_3         :14;
            uint64_t MaxDistance        :10;
            uint64_t MaxDistance_valid  :1;
            uint64_t SensorID_valid     :1;
            uint64_t RadarPower_valid   :1;
            uint64_t OutputType_valid   :1;
            uint64_t SendQuality_valid  :1;
            uint64_t SendExtInfo_valid  :1;
            uint64_t SortIndex_valid    :1;
            uint64_t StoreInNVM_valid   :1;
        };
    };

} ;
// 0x202
struct FilterCfg {
    FilterCfg& operator=(const FilterCfg& from){ 
        data64 = from.data64;
        return  *this;
    }
    union {
        uint64_t data64;
        struct {
            uint64_t reserved_1         :32;
            uint64_t Max                :12;
            uint64_t reserved_2         :4;
            uint64_t Min                :12;
            uint64_t reserved_3         :5;
            uint64_t Valid              :1;
            uint64_t Active             :1;
            uint64_t Index              :4;
            uint64_t Type               :1;
        };
    };

} ;
// 0x202
struct FilterCfgX {
    FilterCfgX& operator=(const FilterCfgX& from){ 
        data64 = from.data64;
        return  *this;
    }
    union {
        uint64_t data64;
        struct {
            uint64_t reserved_1         :32;
            uint64_t Max                :13;
            uint64_t reserved_2         :3;
            uint64_t Min                :13;
            uint64_t reserved_3         :4;
            uint64_t Valid              :1;
            uint64_t Active             :1;
            uint64_t Index              :4;
            uint64_t Type               :1;
        };
    };

} ;
// 0x600
struct Cluster_0_Status {
    Cluster_0_Status& operator=(const Cluster_0_Status& from){ 
        data64 = from.data64;
        return  *this;
    }
    union {
        uint64_t data64;
        struct {
            uint64_t reserved_1         :36;
            uint64_t InterfaceVersion   :4;
            uint64_t MeasCounter        :16;
            uint64_t NofClustersFar     :8;
            uint64_t NofClustersNear    :8;
        };
    };

} ;
// 0x701
struct Cluster_1_General {
    Cluster_1_General& operator=(const Cluster_1_General& from){ 
        data64 = from.data64;
        return  *this;
    }
    union {
        uint64_t data64;
        struct {
            uint64_t RCS                :8;
            uint64_t DynProp            :3;
            uint64_t reserved_1         :2;
            uint64_t VrelLat            :9;
            uint64_t VrelLong           :10;
            uint64_t DistLat            :10;
            uint64_t reserved_2         :1;
            uint64_t Cluster_DistLong   :13;
            uint64_t ID                 :8;
        };
    };

} ;

// 0x702
struct Cluster_2_Quality {
    Cluster_2_Quality& operator=(const Cluster_2_Quality& from){ 
        data64 = from.data64;
        return  *this;
    }
    union {
        uint64_t data64;
        struct {
            uint64_t reserved_1         :32;
            uint64_t AmbigState         :3;
            uint64_t InvalidState       :5;
            uint64_t Pdh0               :3;
            uint64_t reserved_2         :1;
            uint64_t VrelLat_rms        :5;
            uint64_t VrelLong_rms       :5;
            uint64_t DistLat_rms        :5;
            uint64_t DistLong_rms       :5;
            uint64_t ID                 :8;
        };
    };

} ;

struct Frame {
    Frame(){}
    Frame(Frame& from) : data64(from.data64){}
    Frame& operator=(const Frame& from){ 
        data64 = from.data64;
        return  *this;
    }
    union {
        RadarCfg            RadarCfg;
        FilterCfg           FilterCfg;
        FilterCfgX          FilterCfgX;
        Cluster_0_Status    Cluster_0_Status;
        Cluster_1_General   Cluster_1_General;
        Cluster_2_Quality   Cluster_2_Quality;
        
        uint8_t             data8[8];
        uint32_t            data32[2];
        uint64_t            data64;
    };
} ;

// union CanFrameBuffer {
//     uint8_t data8[16];
//     uint16_t data16[8];
//     uint32_t data32[4];
//     uint64_t data64[2];
//     struct frame {
//         CanMessage CanMessage;
//         uint32_t sensor_id;
//         uint32_t data_length        :4;
//         uint32_t reserved_1         :2;
//         uint32_t remote_request     :1;
//         uint32_t frame_form         :1;
//         uint32_t reserved_2         :24;
//     } frame;
// } ;

struct ClusterParameter {
    double DistLong;
    double DistLat;
    double VrelLong;
    double VrelLat;
    double RCS;
    int DynProp;
    int DistLong_rms;
    int DistLat_rms;
    int VrelLong_rms;
    int VrelLat_rms;
    int Pdh0;
    int AmbigState;
    int InvalidState;

};

// class CanFrame {
// public:
//     CanFrame();
//     CanFrame(uint8_t *data);
//     ~CanFrame();
//     int read(const uint8_t *data);
//     int write(uint8_t *data);
//     void clear();
//     int parse();
//     SensorID getSensorID();
//     void setSensorID(SensorID id);
//     int getDataLength();
//     void setDataLength(int length);
//     Activation getRemoteRequest();
//     void setRemoteRequest(Activation act);
//     Activation getFrameForm();
//     void setFrameForm(Activation act);
// public:
//     CanFrameBUffer _buffer;

// };

} // namespace sensors

#endif // LONG_RANGE_RADAR_H
