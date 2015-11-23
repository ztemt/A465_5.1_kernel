#ifndef _CUST_BATTERY_METER_TABLE_H
#define _CUST_BATTERY_METER_TABLE_H

#include <mach/mt_typedefs.h>

// ============================================================
// define
// ============================================================
#define BAT_NTC_10 0
#define BAT_NTC_47 1

#if (BAT_NTC_10 == 1)
#define RBAT_PULL_UP_R             16900	
#endif

#if (BAT_NTC_47 == 1)
#define RBAT_PULL_UP_R             61900	
#endif

#define RBAT_PULL_UP_VOLT          1800



// ============================================================
// ENUM
// ============================================================

// ============================================================
// structure
// ============================================================

// ============================================================
// typedef
// ============================================================
typedef struct _BATTERY_PROFILE_STRUC
{
    kal_int32 percentage;
    kal_int32 voltage;
} BATTERY_PROFILE_STRUC, *BATTERY_PROFILE_STRUC_P;

typedef struct _R_PROFILE_STRUC
{
    kal_int32 resistance; // Ohm
    kal_int32 voltage;
} R_PROFILE_STRUC, *R_PROFILE_STRUC_P;

typedef enum
{
    T1_0C,
    T2_25C,
    T3_50C
} PROFILE_TEMPERATURE;

// ============================================================
// External Variables
// ============================================================

// ============================================================
// External function
// ============================================================

// ============================================================
// <DOD, Battery_Voltage> Table
// ============================================================
#if (BAT_NTC_10 == 1)
    BATT_TEMPERATURE Batt_Temperature_Table[] = {
        {-20,68237},
        {-15,53650},
        {-10,42506},
        { -5,33892},
        {  0,27219},
        {  5,22021},
        { 10,17926},
        { 15,14674},
        { 20,12081},
        { 25,10000},
        { 30,8315},
        { 35,6948},
        { 40,5834},
        { 45,4917},
        { 50,4161},
        { 55,3535},
        { 60,3014}
    };
#endif

#if (BAT_NTC_47 == 1)
    BATT_TEMPERATURE Batt_Temperature_Table[] = {
        {-20,483954},
        {-15,360850},
        {-10,271697},
        { -5,206463},
        {  0,158214},
        {  5,122259},
        { 10,95227},
        { 15,74730},
        { 20,59065},
        { 25,47000},
        { 30,37643},
        { 35,30334},
        { 40,24591},
        { 45,20048},
        { 50,16433},
        { 55,13539},
        { 60,11210}        
    };
#endif

// T0 -10C
BATTERY_PROFILE_STRUC battery_profile_t0[] =
{
	{0  ,  4345},
	{1  ,  4313},
	{3  ,  4292},
	{4  ,  4270},
	{5  ,  4249},
	{7  ,  4231},
	{8  ,  4213},
	{9  ,  4196},
	{11 ,  4179},
	{12 ,  4163},
	{13 ,  4148},
	{14 ,  4133},
	{16 ,  4116},
	{17 ,  4104},
	{18 ,  4092},
	{20 ,  4079},
	{21 ,  4063},
	{22 ,  4043},
	{24 ,  4021},
	{25 ,  3999},
	{26 ,  3982},
	{28 ,  3966},
	{29 ,  3954},
	{30 ,  3942},
	{32 ,  3935},
	{33 ,  3925},
	{34 ,  3917},
	{36 ,  3908},
	{37 ,  3899},
	{38 ,  3890},
	{39 ,  3881},
	{41 ,  3873},
	{42 ,  3865},
	{43 ,  3857},
	{45 ,  3850},
	{46 ,  3843},
	{47 ,  3837},
	{49 ,  3831},
	{50 ,  3823},
	{51 ,  3818},
	{53 ,  3813},
	{54 ,  3808},
	{55 ,  3804},
	{57 ,  3800},
	{58 ,  3797},
	{59 ,  3794},
	{61 ,  3791},
	{62 ,  3788},
	{63 ,  3787},
	{64 ,  3784},
	{66 ,  3781},
	{67 ,  3779},
	{68 ,  3776},
	{70 ,  3774},
	{71 ,  3771},
	{72 ,  3767},
	{74 ,  3764},
	{75 ,  3760},
	{76 ,  3757},
	{78 ,  3753},
	{79 ,  3748},
	{80 ,  3744},
	{82 ,  3738},
	{83 ,  3732},
	{84 ,  3727},
	{86 ,  3721},
	{87 ,  3716},
	{88 ,  3709},
	{89 ,  3704},
	{91 ,  3699},
	{92 ,  3693},
	{93 ,  3684},
	{95 ,  3673},
	{96 ,  3652},
	{97 ,  3615},
	{99 ,  3552},
	{100,  3445},
	{100,  1507}

};      
        
// T1 0C 
BATTERY_PROFILE_STRUC battery_profile_t1[] =
{
	{0  ,  4348},
	{1  ,  4323},
	{3  ,  4304},
	{4  ,  4285},
	{5  ,  4265},
	{7  ,  4253},
	{8  ,  4237},
	{9  ,  4221},
	{11 ,  4205},
	{12 ,  4193},
	{13 ,  4178},
	{14 ,  4164},
	{16 ,  4147},
	{17 ,  4137},
	{18 ,  4121},
	{20 ,  4108},
	{21 ,  4094},
	{22 ,  4086},
	{24 ,  4076},
	{25 ,  4062},
	{26 ,  4042},
	{28 ,  4020},
	{29 ,  3999},
	{30 ,  3980},
	{32 ,  3967},
	{33 ,  3958},
	{34 ,  3945},
	{36 ,  3937},
	{37 ,  3929},
	{38 ,  3919},
	{39 ,  3910},
	{41 ,  3901},
	{42 ,  3891},
	{43 ,  3882},
	{45 ,  3873},
	{46 ,  3866},
	{47 ,  3858},
	{49 ,  3851},
	{50 ,  3844},
	{51 ,  3838},
	{53 ,  3831},
	{54 ,  3825},
	{55 ,  3820},
	{57 ,  3815},
	{58 ,  3810},
	{59 ,  3806},
	{61 ,  3800},
	{62 ,  3795},
	{63 ,  3791},
	{64 ,  3788},
	{66 ,  3785},
	{67 ,  3782},
	{68 ,  3780},
	{70 ,  3778},
	{71 ,  3775},
	{72 ,  3773},
	{74 ,  3771},
	{75 ,  3764},
	{76 ,  3764},
	{78 ,  3758},
	{79 ,  3758},
	{80 ,  3748},
	{82 ,  3746},
	{83 ,  3739},
	{84 ,  3731},
	{86 ,  3724},
	{87 ,  3714},
	{88 ,  3706},
	{89 ,  3700},
	{91 ,  3696},
	{92 ,  3692},
	{93 ,  3686},
	{95 ,  3676},
	{96 ,  3651},
	{97 ,  3595},
	{99 ,  3505},
	{100,  3408},
	{100,  3332}

};           

// T2 25C
BATTERY_PROFILE_STRUC battery_profile_t2[] =
{
	{0  ,  4342},
	{1  ,  4323},
	{3  ,  4306},
	{4  ,  4291},
	{5  ,  4275},
	{7  ,  4261},
	{8  ,  4246},
	{9  ,  4231},
	{11 ,  4217},
	{12 ,  4202},
	{13 ,  4188},
	{14 ,  4174},
	{16 ,  4160},
	{17 ,  4146},
	{18 ,  4133},
	{20 ,  4119},
	{21 ,  4105},
	{22 ,  4092},
	{24 ,  4080},
	{25 ,  4072},
	{26 ,  4063},
	{28 ,  4047},
	{29 ,  4024},
	{30 ,  4004},
	{32 ,  3989},
	{33 ,  3979},
	{34 ,  3972},
	{35 ,  3965},
	{37 ,  3957},
	{38 ,  3947},
	{39 ,  3937},
	{41 ,  3925},
	{42 ,  3913},
	{43 ,  3900},
	{45 ,  3887},
	{46 ,  3875},
	{47 ,  3865},
	{49 ,  3857},
	{50 ,  3849},
	{51 ,  3842},
	{53 ,  3836},
	{54 ,  3830},
	{55 ,  3824},
	{56 ,  3819},
	{58 ,  3814},
	{59 ,  3809},
	{60 ,  3804},
	{62 ,  3800},
	{63 ,  3796},
	{64 ,  3792},
	{66 ,  3788},
	{67 ,  3785},
	{68 ,  3781},
	{70 ,  3778},
	{71 ,  3775},
	{72 ,  3772},
	{74 ,  3769},
	{75 ,  3766},
	{76 ,  3762},
	{77 ,  3758},
	{79 ,  3754},
	{80 ,  3749},
	{81 ,  3744},
	{83 ,  3738},
	{84 ,  3730},
	{85 ,  3721},
	{87 ,  3713},
	{88 ,  3701},
	{89 ,  3694},
	{91 ,  3692},
	{92 ,  3691},
	{93 ,  3689},
	{95 ,  3686},
	{96 ,  3675},
	{97 ,  3629},
	{98 ,  3555},
	{100,  3443},
	{100,  3205}

};     

// T3 50C
BATTERY_PROFILE_STRUC battery_profile_t3[] =
{
	{0  ,  4337},
	{1  ,  4321},
	{3  ,  4305},
	{4  ,  4290},
	{5  ,  4275},
	{7  ,  4260},
	{8  ,  4246},
	{9  ,  4231},
	{11 ,  4216},
	{12 ,  4203},
	{13 ,  4188},
	{15 ,  4173},
	{16 ,  4159},
	{17 ,  4147},
	{19 ,  4133},
	{20 ,  4119},
	{21 ,  4105},
	{23 ,  4092},
	{24 ,  4079},
	{25 ,  4065},
	{27 ,  4053},
	{28 ,  4040},
	{29 ,  4028},
	{31 ,  4016},
	{32 ,  4004},
	{33 ,  3993},
	{34 ,  3983},
	{36 ,  3972},
	{37 ,  3962},
	{38 ,  3952},
	{40 ,  3941},
	{41 ,  3930},
	{42 ,  3919},
	{44 ,  3905},
	{45 ,  3890},
	{46 ,  3877},
	{48 ,  3866},
	{49 ,  3859},
	{50 ,  3851},
	{52 ,  3845},
	{53 ,  3838},
	{54 ,  3832},
	{56 ,  3825},
	{57 ,  3819},
	{58 ,  3815},
	{60 ,  3810},
	{61 ,  3805},
	{62 ,  3801},
	{64 ,  3796},
	{65 ,  3792},
	{66 ,  3788},
	{68 ,  3785},
	{69 ,  3781},
	{70 ,  3776},
	{72 ,  3771},
	{73 ,  3762},
	{74 ,  3753},
	{76 ,  3749},
	{77 ,  3743},
	{78 ,  3738},
	{80 ,  3733},
	{81 ,  3729},
	{82 ,  3724},
	{84 ,  3718},
	{85 ,  3708},
	{86 ,  3700},
	{88 ,  3689},
	{89 ,  3681},
	{90 ,  3679},
	{92 ,  3678},
	{93 ,  3677},
	{94 ,  3674},
	{95 ,  3666},
	{97 ,  3628},
	{98 ,  3562},
	{99 ,  3466},
	{100,  3303},
	{100,  3082}

};           

// battery profile for actual temperature. The size should be the same as T1, T2 and T3
BATTERY_PROFILE_STRUC battery_profile_temperature[] =
{
  {0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },  
	{0  , 0 }, 
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },  
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 }
};    

// ============================================================
// <Rbat, Battery_Voltage> Table
// ============================================================
// T0 -10C
R_PROFILE_STRUC r_profile_t0[] =
{
	{1585,  4345},
	{1585,  4313},
	{1582,  4292},
	{1557,  4270},
	{1527,  4249},
	{1500,  4231},
	{1475,  4213},
	{1447,  4196},
	{1417,  4179},
	{1402,  4163},
	{1382,  4148},
	{1360,  4133},
	{1337,  4116},
	{1327,  4104},
	{1312,  4092},
	{1305,  4079},
	{1287,  4063},
	{1270,  4043},
	{1245,  4021},
	{1220,  3999},
	{1205,  3982},
	{1192,  3966},
	{1190,  3954},
	{1182,  3942},
	{1187,  3935},
	{1182,  3925},
	{1180,  3917},
	{1180,  3908},
	{1175,  3899},
	{1172,  3890},
	{1170,  3881},
	{1170,  3873},
	{1170,  3865},
	{1167,  3857},
	{1167,  3850},
	{1170,  3843},
	{1170,  3837},
	{1170,  3831},
	{1170,  3823},
	{1172,  3818},
	{1177,  3813},
	{1180,  3808},
	{1187,  3804},
	{1192,  3800},
	{1197,  3797},
	{1205,  3794},
	{1212,  3791},
	{1220,  3788},
	{1235,  3787},
	{1245,  3784},
	{1252,  3781},
	{1267,  3779},
	{1277,  3776},
	{1295,  3774},
	{1312,  3771},
	{1332,  3767},
	{1355,  3764},
	{1377,  3760},
	{1407,  3757},
	{1435,  3753},
	{1465,  3748},
	{1500,  3744},
	{1530,  3738},
	{1570,  3732},
	{1610,  3727},
	{1650,  3721},
	{1692,  3716},
	{1727,  3709},
	{1772,  3704},
	{1812,  3699},
	{1857,  3693},
	{1905,  3684},
	{1962,  3673},
	{2022,  3652},
	{2095,  3615},
	{2197,  3552},
	{2385,  3445},
	{2385,  1507}

};      

// T1 0C
R_PROFILE_STRUC r_profile_t1[] =
{
	{755 ,  4348},
	{755 ,  4323},
	{757 ,  4304},
	{747 ,  4285},
	{735 ,  4265},
	{732 ,  4253},
	{725 ,  4237},
	{712 ,  4221},
	{702 ,  4205},
	{700 ,  4193},
	{692 ,  4178},
	{690 ,  4164},
	{675 ,  4147},
	{682 ,  4137},
	{670 ,  4121},
	{665 ,  4108},
	{652 ,  4094},
	{662 ,  4086},
	{665 ,  4076},
	{665 ,  4062},
	{647 ,  4042},
	{632 ,  4020},
	{612 ,  3999},
	{597 ,  3980},
	{592 ,  3967},
	{592 ,  3958},
	{585 ,  3945},
	{587 ,  3937},
	{585 ,  3929},
	{580 ,  3919},
	{575 ,  3910},
	{572 ,  3901},
	{567 ,  3891},
	{562 ,  3882},
	{562 ,  3873},
	{565 ,  3866},
	{562 ,  3858},
	{562 ,  3851},
	{560 ,  3844},
	{562 ,  3838},
	{565 ,  3831},
	{565 ,  3825},
	{572 ,  3820},
	{575 ,  3815},
	{575 ,  3810},
	{577 ,  3806},
	{582 ,  3800},
	{585 ,  3795},
	{592 ,  3791},
	{597 ,  3788},
	{602 ,  3785},
	{607 ,  3782},
	{615 ,  3780},
	{625 ,  3778},
	{632 ,  3775},
	{640 ,  3773},
	{652 ,  3771},
	{647 ,  3764},
	{667 ,  3764},
	{670 ,  3758},
	{692 ,  3758},
	{700 ,  3748},
	{730 ,  3746},
	{752 ,  3739},
	{777 ,  3731},
	{807 ,  3724},
	{835 ,  3714},
	{872 ,  3706},
	{910 ,  3700},
	{967 ,  3696},
	{1040,  3692},
	{1127,  3686},
	{1237,  3676},
	{1365,  3651},
	{1477,  3595},
	{1615,  3505},
	{1647,  3408},
	{1457,  3332}

};     

// T2 25C
R_PROFILE_STRUC r_profile_t2[] =
{
	{201,  4342},
	{201,  4323},
	{200,  4306},
	{202,  4291},
	{203,  4275},
	{202,  4261},
	{202,  4246},
	{202,  4231},
	{201,  4217},
	{202,  4202},
	{205,  4188},
	{207,  4174},
	{205,  4160},
	{206,  4146},
	{208,  4133},
	{212,  4119},
	{213,  4105},
	{215,  4092},
	{216,  4080},
	{222,  4072},
	{229,  4063},
	{228,  4047},
	{221,  4024},
	{221,  4004},
	{220,  3989},
	{223,  3979},
	{228,  3972},
	{231,  3965},
	{231,  3957},
	{229,  3947},
	{228,  3937},
	{223,  3925},
	{217,  3913},
	{207,  3900},
	{198,  3887},
	{193,  3875},
	{187,  3865},
	{186,  3857},
	{184,  3849},
	{183,  3842},
	{183,  3836},
	{183,  3830},
	{183,  3824},
	{185,  3819},
	{185,  3814},
	{185,  3809},
	{187,  3804},
	{189,  3800},
	{189,  3796},
	{190,  3792},
	{190,  3788},
	{192,  3785},
	{191,  3781},
	{192,  3778},
	{192,  3775},
	{191,  3772},
	{191,  3769},
	{191,  3766},
	{190,  3762},
	{188,  3758},
	{188,  3754},
	{188,  3749},
	{189,  3744},
	{194,  3738},
	{193,  3730},
	{192,  3721},
	{194,  3713},
	{194,  3701},
	{196,  3694},
	{198,  3692},
	{206,  3691},
	{216,  3689},
	{229,  3686},
	{241,  3675},
	{240,  3629},
	{254,  3555},
	{293,  3443},
	{293,  3205}

}; 

// T3 50C
R_PROFILE_STRUC r_profile_t3[] =
{
	{120,  4337},
	{120,  4321},
	{117,  4305},
	{122,  4290},
	{120,  4275},
	{117,  4260},
	{120,  4246},
	{122,  4231},
	{120,  4216},
	{122,  4203},
	{122,  4188},
	{122,  4173},
	{125,  4159},
	{125,  4147},
	{125,  4133},
	{127,  4119},
	{127,  4105},
	{130,  4092},
	{127,  4079},
	{127,  4065},
	{132,  4053},
	{130,  4040},
	{132,  4028},
	{132,  4016},
	{132,  4004},
	{137,  3993},
	{140,  3983},
	{142,  3972},
	{145,  3962},
	{145,  3952},
	{147,  3941},
	{147,  3930},
	{147,  3919},
	{140,  3905},
	{132,  3890},
	{127,  3877},
	{120,  3866},
	{122,  3859},
	{120,  3851},
	{122,  3845},
	{122,  3838},
	{120,  3832},
	{120,  3825},
	{120,  3819},
	{125,  3815},
	{127,  3810},
	{127,  3805},
	{130,  3801},
	{127,  3796},
	{130,  3792},
	{132,  3788},
	{132,  3785},
	{132,  3781},
	{132,  3776},
	{130,  3771},
	{125,  3762},
	{122,  3753},
	{125,  3749},
	{122,  3743},
	{122,  3738},
	{122,  3733},
	{125,  3729},
	{125,  3724},
	{125,  3718},
	{122,  3708},
	{125,  3700},
	{125,  3689},
	{120,  3681},
	{120,  3679},
	{127,  3678},
	{130,  3677},
	{135,  3674},
	{140,  3666},
	{135,  3628},
	{140,  3562},
	{152,  3466},
	{207,  3303},
	{207,  3082}

}; 

// r-table profile for actual temperature. The size should be the same as T1, T2 and T3
R_PROFILE_STRUC r_profile_temperature[] =
{
  {0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },  
	{0  , 0 }, 
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },  
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 }
};    

// ============================================================
// function prototype
// ============================================================
int fgauge_get_saddles(void);
BATTERY_PROFILE_STRUC_P fgauge_get_profile(kal_uint32 temperature);

int fgauge_get_saddles_r_table(void);
R_PROFILE_STRUC_P fgauge_get_profile_r_table(kal_uint32 temperature);

#endif	//#ifndef _CUST_BATTERY_METER_TABLE_H

