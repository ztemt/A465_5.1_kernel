#ifndef BUILD_LK
#include <linux/string.h>
#endif
#include "lcm_drv.h"

#ifdef BUILD_LK
	#include <mt_gpio.h>
#elif defined(BUILD_UBOOT)
	#include <asm/arch/mt_gpio.h>
#else
	#include <mach/mt_gpio.h>
#endif

#ifdef BUILD_LK
#include <stdio.h>
#include <string.h>
#else
#include <linux/string.h>
#include <linux/kernel.h>
#endif

//#define USE_LCM_THREE_LANE 1

#define _LCM_DEBUG_

#include <cust_gpio_usage.h>

// ---------------------------------------------------------------------------
//  Local Constants
// ---------------------------------------------------------------------------

#define FRAME_WIDTH  										(720)
#define FRAME_HEIGHT 										(1280)

#define REGFLAG_DELAY             							0XFEFF
#define REGFLAG_END_OF_TABLE      							0xFFFF   // END OF REGISTERS MARKER

#define LCM_DSI_CMD_MODE									0

#define LCM_ID_ILI9881C 0x9881
//#define GPIO_LCM_RST_PIN         (GPIO141 | 0x80000000)

// ---------------------------------------------------------------------------
//  Local Variables
// ---------------------------------------------------------------------------

static LCM_UTIL_FUNCS lcm_util = {0};

#define SET_RESET_PIN(v)    								(lcm_util.set_reset_pin((v)))
#define SET_GPIO_OUT(gpio_num,val)    						(lcm_util.set_gpio_out((gpio_num),(val)))


#define UDELAY(n) 											(lcm_util.udelay(n))
#define MDELAY(n) 											(lcm_util.mdelay(n))



//#define _SYNA_INFO_
//#define _SYNA_DEBUG_
//#define _LCM_DEBUG_
//#define _LCM_INFO_
/*
#ifdef _LCM_DEBUG_
#define lcm_debug(fmt, args...) printk(fmt, ##args)
#else
#define lcm_debug(fmt, args...) do { } while (0)
#endif

#ifdef _LCM_INFO_
#define lcm_info(fmt, args...) printk(fmt, ##args)
#else
#define lcm_info(fmt, args...) do { } while (0)
#endif
#define lcm_err(fmt, args...) printk(fmt, ##args) */

#ifdef _LCM_DEBUG_
  #ifdef BUILD_LK
  #define LCM_PRINT printf
  #else
  #define LCM_PRINT printk
  #endif
#else
	#define LCM_PRINT
#endif

// ---------------------------------------------------------------------------
//  Local Functions
// ---------------------------------------------------------------------------

#define dsi_set_cmdq_V2(cmd, count, ppara, force_update)	lcm_util.dsi_set_cmdq_V2(cmd, count, ppara, force_update)
#define dsi_set_cmdq(pdata, queue_size, force_update)		lcm_util.dsi_set_cmdq(pdata, queue_size, force_update)
#define wrtie_cmd(cmd)										lcm_util.dsi_write_cmd(cmd)
#define write_regs(addr, pdata, byte_nums)					lcm_util.dsi_write_regs(addr, pdata, byte_nums)
#define read_reg											lcm_util.dsi_read_reg()
#define read_reg_v2(cmd, buffer, buffer_size)   			lcm_util.dsi_dcs_read_lcm_reg_v2(cmd, buffer, buffer_size)    
       

static struct LCM_setting_table {
    unsigned cmd;
    unsigned char count;
    unsigned char para_list[64];
};

static struct LCM_setting_table lcm_initialization_setting[] = {
	
	/*
	Note :

	Data ID will depends on the following rule.
	
		count of parameters > 1	=> Data ID = 0x39
		count of parameters = 1	=> Data ID = 0x15
		count of parameters = 0	=> Data ID = 0x05

	Structure Format :

	{DCS command, count of parameters, {parameter list}}
	{REGFLAG_DELAY, milliseconds of time, {}},

	...

	Setting ending by predefined flag
	
	{REGFLAG_END_OF_TABLE, 0x00, {}}
	*/

//MTK6735  CMI5.0+ILI9881C
{0xFF,3,{0x98,0x81,0x03}},        
{0x01,1,{0x00}}, 
{0x02,1,{0x00}},    
{0x03,1,{0x53}},    
{0x04,1,{0x13}},   
{0x05,1,{0x13}},    
{0x06,1,{0x06}},   
{0x07,1,{0x00}},    
{0x08,1,{0x04}},    
{0x09,1,{0x00}},    
{0x0a,1,{0x00}},    
{0x0b,1,{0x00}},    
{0x0c,1,{0x00}},    
{0x0d,1,{0x00}},    
{0x0e,1,{0x00}},    
{0x0f,1,{0x00}},    
{0x10,1,{0x00}},    
{0x11,1,{0x00}},    
{0x12,1,{0x00}},    
{0x13,1,{0x00}},    
{0x14,1,{0x00}},    
{0x15,1,{0x00}},    
{0x16,1,{0x00}},    
{0x17,1,{0x00}},    
{0x18,1,{0x00}},    
{0x19,1,{0x00}},    
{0x1a,1,{0x00}},    
{0x1b,1,{0x00}},    
{0x1c,1,{0x00}},    
{0x1d,1,{0x00}},    
{0x1e,1,{0xC0}},   
{0x1f,1,{0x80}},   
{0x20,1,{0x04}},    
{0x21,1,{0x0B}},    
{0x22,1,{0x00}},    
{0x23,1,{0x00}},
{0x24,1,{0x00}},    
{0x25,1,{0x00}},   
{0x26,1,{0x00}},    
{0x27,1,{0x00}},    
{0x28,1,{0x55}},    
{0x29,1,{0x03}},    
{0x2A,1,{0x00}},    
{0x2B,1,{0x00}},    
{0x2C,1,{0x06}},   
{0x2D,1,{0x00}},    
{0x2E,1,{0x00}},    
{0x2F,1,{0x00}},    
{0x30,1,{0x00}},    
{0x31,1,{0x00}},   
{0x32,1,{0x00}},  
{0x33,1,{0x00}},    
{0x34,1,{0x04}},   
{0x35,1,{0x05}},   
{0x36,1,{0x05}},   
{0x37,1,{0x00}},   
{0x38,1,{0x3C}},    
{0x39,1,{0x00}},    
{0x3a,1,{0x40}},    
{0x3b,1,{0x40}},    
{0x3c,1,{0x00}},   
{0x3d,1,{0x00}},   
{0x3e,1,{0x00}},   
{0x3f,1,{0x00}}, 
{0x40,1,{0x00}},
{0x41,1,{0x00}},  
{0x42,1,{0x00}},
{0x43,1,{0x00}},
{0x44,1,{0x00}},
{0x50,1,{0x01}},
{0x51,1,{0x23}},
{0x52,1,{0x45}},
{0x53,1,{0x67}},
{0x54,1,{0x89}},
{0x55,1,{0xAB}},
{0x56,1,{0x01}},
{0x57,1,{0x23}},
{0x58,1,{0x45}},
{0x59,1,{0x67}},  
{0x5a,1,{0x89}},  
{0x5b,1,{0xAB}},  
{0x5c,1,{0xCD}},  
{0x5d,1,{0xEF}}, 
{0x5e,1,{0x01}}, 
{0x5f,1,{0x14}},  
{0x60,1,{0x15}},  
{0x61,1,{0x0C}},   
{0x62,1,{0x0D}},
{0x63,1,{0x0E}}, 
{0x64,1,{0x0F}},
{0x65,1,{0x10}},
{0x66,1,{0x11}},
{0x67,1,{0x08}},
{0x68,1,{0x02}},
{0x69,1,{0x0A}},
{0x6a,1,{0x02}},  
{0x6b,1,{0x02}},
{0x6c,1,{0x02}},
{0x6d,1,{0x02}},
{0x6e,1,{0x02}},
{0x6f,1,{0x02}},
{0x70,1,{0x02}},
{0x71,1,{0x02}},
{0x72,1,{0x06}},  
{0x73,1,{0x02}},
{0x74,1,{0x02}},   
{0x75,1,{0x14}},  
{0x76,1,{0x15}},  
{0x77,1,{0x11}},  
{0x78,1,{0x10}},  
{0x79,1,{0x0F}}, 
{0x7a,1,{0x0E}}, 
{0x7b,1,{0x0D}},   
{0x7c,1,{0x0C}},   
{0x7d,1,{0x06}},   
{0x7e,1,{0x02}},   
{0x7f,1,{0x0a}},   
{0x80,1,{0x02}},  
{0x81,1,{0x02}},   
{0x82,1,{0x02}},    
{0x83,1,{0x02}},   
{0x84,1,{0x02}},   
{0x85,1,{0x02}},   
{0x86,1,{0x02}},   
{0x87,1,{0x02}},   
{0x88,1,{0x08}},    
{0x89,1,{0x02}}, 
{0x8a,1,{0x02}},
  
  
    
//CMD_Page 4
    
{0xFF,3,{0x98,0x81,0x04}},
{0x6c,1,{0x15}},
{0x6e,1,{0x3b}}, 
{0x6f,1,{0x53}}, 
{0x3a,1,{0xa4}},
{0x8d,1,{0x15}}, 
{0x87,1,{0xba}}, 
{0xb2,1,{0xd1}},  
{0x26,1,{0x76}},
{0x88,1,{0x0B}}, //Add
    
 
    
//CMD_Page 1
    
{0xFF,3,{0x98,0x81,0x01}},
{0x22,1,{0x0A}}, 
{0x31,1,{0x00}}, 
{0x53,1,{0x79}},  
{0x55,1,{0x88}},  
{0x50,1,{0xa6}},   
{0x51,1,{0xA6}},   
{0x60,1,{0x14}},             //SDT 
{0xA0,1,{0x08}},             //VP255 Gamma P   
{0xA1,1,{0x1B}},             //VP251  
{0xA2,1,{0x28}},             //VP247  
{0xA3,1,{0x13}},            //VP243
{0xA4,1,{0x16}},             //VP239  
{0xA5,1,{0x29}},            //VP231   
{0xA6,1,{0x1e}},             //VP219  
{0xA7,1,{0x1f}},           //VP203  
{0xA8,1,{0x8b}},            //VP175   
{0xA9,1,{0x1e}},             //VP144
{0xAA,1,{0x2a}},             //VP111   
{0xAB,1,{0x7a}},             //VP80   
{0xAC,1,{0x1B}},             //VP52   
{0xAD,1,{0x1b}},             //VP36 
{0xAE,1,{0x4B}},           //VP24  
{0xAF,1,{0x21}},             //VP16   
{0xB0,1,{0x29}},             //VP12   
{0xB1,1,{0x53}},            //VP8   
{0xB2,1,{0x5c}},            //VP4   
{0xB3,1,{0x2C}},             //VP0  
{0xC0,1,{0x08}},             //VN255 GAMMA N  
{0xC1,1,{0x1B}},            //VN251  
{0xC2,1,{0x28}},           //VN247  
{0xC3,1,{0x13}},            //VN243  
{0xC4,1,{0x16}},            //VN239  
{0xC5,1,{0x29}},             //VN231  
{0xC6,1,{0x1e}},             //VN219   
{0xC7,1,{0x1f}},            //VN203   
{0xC8,1,{0x8b}},             //VN175   
{0xC9,1,{0x1e}},             //VN144  
{0xCA,1,{0x2a}},             //VN111   
{0xCB,1,{0x7a}},            //VN80   
{0xCC,1,{0x1A}},            //VN52   
{0xCD,1,{0x1b}},             //VN36   
{0xCE,1,{0x4B}},            //VN24   
{0xCF,1,{0x21}},             //VN16   
{0xD0,1,{0x29}},             //VN12  
{0xD1,1,{0x53}},             //VN8   
{0xD2,1,{0x5c}},             //VN4    
{0xD3,1,{0x2C}},             //VN0
//CMD_Page 0
   
{0xFF,3,{0x98,0x81,0x00}},   

// Sleep Out

{0x11,1,{0x00}},
//DEALY,120  
{REGFLAG_DELAY, 120, {}},
{0x29,1,{0x00}},

{REGFLAG_END_OF_TABLE, 0x00, {}}

};

static struct LCM_setting_table lcm_set_window[] = {
	{0x2A,	4,	{0x00, 0x00, (FRAME_WIDTH>>8), (FRAME_WIDTH&0xFF)}},
	{0x2B,	4,	{0x00, 0x00, (FRAME_HEIGHT>>8), (FRAME_HEIGHT&0xFF)}},
	{REGFLAG_END_OF_TABLE, 0x00, {}}
};


static struct LCM_setting_table lcm_sleep_out_setting[] = {
    // Sleep Out
	{0x11, 1, {0x00}},
  {REGFLAG_DELAY, 120, {}},

    // Display ON
	{0x29, 1, {0x00}},
	{REGFLAG_DELAY, 10, {}},
	
	{REGFLAG_END_OF_TABLE, 0x00, {}}
};


static struct LCM_setting_table lcm_sleep_in_setting[] = {
	// Display off sequence
	{0x28, 1, {0x00}},
	{REGFLAG_DELAY, 10, {}},

    // Sleep Mode On
	{0x10, 1, {0x00}},
	{REGFLAG_DELAY, 120, {}},

	{REGFLAG_END_OF_TABLE, 0x00, {}}
};
static void push_table(struct LCM_setting_table *table, unsigned int count, unsigned char force_update)
{
	unsigned int i;
	LCM_PRINT("%s %d\n", __func__,__LINE__);
    for(i = 0; i < count; i++) {
		
        unsigned cmd;
        cmd = table[i].cmd;
		
        switch (cmd) {
			
            case REGFLAG_DELAY :
                MDELAY(table[i].count);
                break;
				
            case REGFLAG_END_OF_TABLE :
                break;
				
            default:
				dsi_set_cmdq_V2(cmd, table[i].count, table[i].para_list, force_update);
       	}
    }
	
}


// ---------------------------------------------------------------------------
//  LCM Driver Implementations
// ---------------------------------------------------------------------------

static void lcm_set_util_funcs(const LCM_UTIL_FUNCS *util)
{
	LCM_PRINT("%s %d\n", __func__,__LINE__);
    memcpy(&lcm_util, util, sizeof(LCM_UTIL_FUNCS));
}


static void lcm_get_params(LCM_PARAMS *params)
{
  	LCM_PRINT("junTang %s %d\n", __func__,__LINE__);
	memset(params, 0, sizeof(LCM_PARAMS));

	params->type   = LCM_TYPE_DSI;

	params->width  = FRAME_WIDTH;
	params->height = FRAME_HEIGHT;

	// enable tearing-free
	 //params->dbi.te_mode 				= LCM_DBI_TE_MODE_VSYNC_ONLY;
	 //params->dbi.te_edge_polarity		= LCM_POLARITY_RISING;

#if (LCM_DSI_CMD_MODE)
	params->dsi.mode   = CMD_MODE;
#else
	params->dsi.mode   = BURST_VDO_MODE;
//	params->dsi.mode   = SYNC_PULSE_VDO_MODE;	
#endif
	
	// DSI
	/* Command mode setting */
#ifdef USE_LCM_THREE_LANE
	params->dsi.LANE_NUM				= LCM_THREE_LANE; 
#else
	params->dsi.LANE_NUM				= LCM_FOUR_LANE;
#endif
	//The following defined the fomat for data coming from LCD engine.
	params->dsi.data_format.color_order = LCM_COLOR_ORDER_RGB;
	params->dsi.data_format.trans_seq   = LCM_DSI_TRANS_SEQ_MSB_FIRST;
	params->dsi.data_format.padding     = LCM_DSI_PADDING_ON_LSB;
	params->dsi.data_format.format      = LCM_DSI_FORMAT_RGB888;

	// Highly depends on LCD driver capability.
	// Not support in MT6573
	params->dsi.packet_size=256;

	// Video mode setting		
	params->dsi.intermediat_buffer_num = 0;

	params->dsi.vertical_sync_active				= 6;// 3    2
	params->dsi.vertical_backporch					= 18;// 20   1
	params->dsi.vertical_frontporch					= 20; // 1  12
	params->dsi.vertical_active_line				= FRAME_HEIGHT; 

	params->dsi.horizontal_sync_active				= 50;// 50  2
	params->dsi.horizontal_backporch				= 80;
	params->dsi.horizontal_frontporch				= 70;
	params->dsi.HS_TRAIL                             =20;
	params->dsi.horizontal_active_pixel				= FRAME_WIDTH;

	params->dsi.PS=LCM_PACKED_PS_24BIT_RGB888;
	params->dsi.CLK_HS_POST=26;

#ifdef USE_LCM_THREE_LANE
    params->dsi.PLL_CLOCK = 250;//156;
#else
		params->dsi.PLL_CLOCK = 208;//156;
#endif
	
#if 1
    params->dsi.esd_check_enable =1;
	params->dsi.customization_esd_check_enable =1;
	params->dsi.lcm_esd_check_table[0].cmd = 0xAC;
	params->dsi.lcm_esd_check_table[0].count =1;
	params->dsi.lcm_esd_check_table[0].para_list[0] = 0x00;
#else
	params->dsi.cont_clock=1;
	params->dsi.clk_lp_per_line_enable = 0;
	params->dsi.esd_check_enable = 0;
	params->dsi.customization_esd_check_enable = 0;
	params->dsi.lcm_esd_check_table[0].cmd          = 0x53;
	params->dsi.lcm_esd_check_table[0].count        = 1;
	params->dsi.lcm_esd_check_table[0].para_list[0] = 0x24;
#endif
	params->dsi.ssc_disable = 1;
//	params->dsi.clk_lp_per_line_enable=1;
	// Bit rate calculation
	// params->dsi.pll_div1=0;		// fref=26MHz, fvco=fref*(div1+1)	(div1=0~63, fvco=500MHZ~1GHz)
	// params->dsi.pll_div2=1; 		// div2=0~15: fout=fvo/(2*div2)
	// params->dsi.fbk_div =11;    //fref=26MHz, fvco=fref*(fbk_div+1)*2/(div1_real*div2_real)

}
	


static unsigned int lcm_compare_id(void)
{
	int array[4];
        char buffer[5];
        char id_high=0;
        char id_low=0;
        int id=0;
	unsigned char  lcd_id0 = 0;
	unsigned char  lcd_id1 = 0;

        SET_RESET_PIN(1);
        SET_RESET_PIN(0);
        MDELAY(25);       
        SET_RESET_PIN(1);
        MDELAY(50);      
       
        array[0]=0x00043902;
        array[1]=0x018198FF;
        dsi_set_cmdq(array, 2, 1);
        MDELAY(10);
 
        array[0]=0x00023700;
        dsi_set_cmdq(array, 1, 1);
    
        read_reg_v2(0x00, buffer,1);
        id_high = buffer[0];         //0x98
 
        read_reg_v2(0x01, buffer,1);
        id_low = buffer[0];          //0x81
 
        id =(id_high << 8) | id_low;

	LCM_PRINT("id ili9881c_hd720p_dsi_vdo_e535_hltqc id_high= 0x%08x\n", id_high);
	LCM_PRINT("id ili9881c_hd720p_dsi_vdo_e535_hltqc id_low= 0x%08x\n", id_low);
	LCM_PRINT("id ili9881c_hd720p_dsi_vdo_e535_hltqc id= 0x%08x\n", id);

	if(id != LCM_ID_ILI9881C)
		return 0;

	mt_set_gpio_mode(GPIO_LCD_ID0, GPIO_LCD_ID0_M_GPIO);
	mt_set_gpio_dir(GPIO_LCD_ID0, GPIO_DIR_IN);		
	mt_set_gpio_pull_enable(GPIO_LCD_ID0,GPIO_PULL_DISABLE);
	mt_set_gpio_pull_select(GPIO_LCD_ID0,GPIO_PULL_DOWN);
	MDELAY(1);

	mt_set_gpio_mode(GPIO_LCD_ID1, GPIO_LCD_ID1_M_GPIO);
	mt_set_gpio_dir(GPIO_LCD_ID1, GPIO_DIR_IN);		
	mt_set_gpio_pull_enable(GPIO_LCD_ID1,GPIO_PULL_DISABLE);
	mt_set_gpio_pull_select(GPIO_LCD_ID1,GPIO_PULL_DOWN);
	MDELAY(1);
	
	MDELAY(10);
	lcd_id0 =  mt_get_gpio_in(GPIO_LCD_ID0);
	lcd_id1 =  mt_get_gpio_in(GPIO_LCD_ID1);

	#if defined(BUILD_LK)
	printf("*******HLT ILI9881C QC************  lcd_id0=%d,lcd_id1=%d\n", lcd_id0,lcd_id1);
	#endif

	if((lcd_id0 ==1)&&(lcd_id1 == 0))
		return 1;
	else
		return 0;
        
}

static void lcm_init(void)
{
	unsigned int data_array[16];
	LCM_PRINT(" %s %d\n", __func__,__LINE__);
	SET_RESET_PIN(1);
	MDELAY(10);
    SET_RESET_PIN(0);
	MDELAY(20);//50
    SET_RESET_PIN(1);
	MDELAY(100);//100
  //lcm_compare_id();
	//lcm_init_registers();
	//data_array[0] = 0x00352500;
	//dsi_set_cmdq(&data_array, 1, 1);
	push_table(lcm_initialization_setting,sizeof(lcm_initialization_setting)/sizeof(lcm_initialization_setting[0]),1);
	push_table(lcm_sleep_out_setting, sizeof(lcm_sleep_out_setting) / sizeof(struct LCM_setting_table), 1);
}


static void lcm_suspend(void)
{
//	LCM_PRINT("%s %d\n", __func__,__LINE__);
//	SET_GPIO_OUT(GPIO_LCM_RST_PIN,1); 	
//	MDELAY(1);	
//	SET_GPIO_OUT(GPIO_LCM_RST_PIN,1); 
    push_table(lcm_sleep_in_setting, sizeof(lcm_sleep_in_setting) / sizeof(struct LCM_setting_table), 1);
	SET_RESET_PIN(1);
	MDELAY(20);//50
    SET_RESET_PIN(0);
	MDELAY(20);//50
    SET_RESET_PIN(1);
	MDELAY(100);//100
//	push_table(lcm_sleep_in_setting, sizeof(lcm_sleep_in_setting) / sizeof(struct LCM_setting_table), 1);
    
//	SET_GPIO_OUT(GPIO_LCM_PWR_EN,0);//Disable LCM Power
}



static void lcm_resume(void)
{
//	LCM_PRINT("%s %d\n", __func__,__LINE__);
//	SET_GPIO_OUT(GPIO_LCM_RST_PIN,1);  //Enable LCM Power
	lcm_init();
//	push_table(lcm_sleep_out_setting, sizeof(lcm_sleep_out_setting) / sizeof(struct LCM_setting_table), 1);
}

static void lcm_update(unsigned int x, unsigned int y,
                       unsigned int width, unsigned int height)
{
	LCM_PRINT("%s %d\n", __func__,__LINE__);
	unsigned int x0 = x;
	unsigned int y0 = y;
	unsigned int x1 = x0 + width - 1;
	unsigned int y1 = y0 + height - 1;

	unsigned char x0_MSB = ((x0>>8)&0xFF);
	unsigned char x0_LSB = (x0&0xFF);
	unsigned char x1_MSB = ((x1>>8)&0xFF);
	unsigned char x1_LSB = (x1&0xFF);
	unsigned char y0_MSB = ((y0>>8)&0xFF);
	unsigned char y0_LSB = (y0&0xFF);
	unsigned char y1_MSB = ((y1>>8)&0xFF);
	unsigned char y1_LSB = (y1&0xFF);

	unsigned int data_array[16];

	data_array[0]= 0x00053902;
	data_array[1]= (x1_MSB<<24)|(x0_LSB<<16)|(x0_MSB<<8)|0x2a;
	data_array[2]= (x1_LSB);
	data_array[3]= 0x00000000;
	data_array[4]= 0x00053902;
	data_array[5]= (y1_MSB<<24)|(y0_LSB<<16)|(y0_MSB<<8)|0x2b;
	data_array[6]= (y1_LSB);
	data_array[7]= 0x00000000;
	data_array[8]= 0x002c3909;

	dsi_set_cmdq(&data_array, 9, 0);

}

LCM_DRIVER ili9881c_hd720p_dsi_vdo_e535_hltqc_lcm_drv = 
{
    .name			= "ili9881c_hd720p_dsi_vdo_e535_hltqc",
	.set_util_funcs = lcm_set_util_funcs,
	.get_params     = lcm_get_params,
	.init           = lcm_init,
	.suspend        = lcm_suspend,
	.resume         = lcm_resume,
	.compare_id     = lcm_compare_id,
#if (LCM_DSI_CMD_MODE)
	.set_backlight	= lcm_setbacklight,
    .update         = lcm_update,
#endif
};
