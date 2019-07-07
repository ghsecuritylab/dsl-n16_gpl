#ifndef __RTSTATE_H__
#define __RTSTATE_H__

enum {
	SW_MODE_NONE=0,
	SW_MODE_ROUTER,
	SW_MODE_REPEATER,
	SW_MODE_AP,
	SW_MODE_HOTSPOT
};

enum WAN_UNIT{
	WAN_UNIT_FIRST=0,
	WAN_UNIT_ATM=0,
	WAN_UNIT_PTM0=8,
	WAN_UNIT_PTM1,
	WAN_UNIT_SECOND,
	WAN_UNIT_ETH=10,
	WAN_UNIT_USB,
	WAN_UNIT_ETH_LAN,
	WAN_UNIT_MAX
};

enum {
	WAN_STATE_INITIALIZING=0,
	WAN_STATE_CONNECTING,
	WAN_STATE_CONNECTED,
	WAN_STATE_DISCONNECTED,
	WAN_STATE_STOPPED,
	WAN_STATE_DISABLED,
	WAN_STATE_STOPPING,
	WAN_STATE_USBMODEM_CONNECTING
};

enum {
	WAN_STOPPED_REASON_NONE=0,
	WAN_STOPPED_REASON_PPP_NO_ACTIVITY,
	WAN_STOPPED_REASON_PPP_AUTH_FAIL,
	WAN_STOPPED_REASON_DHCP_DECONFIG,
	WAN_STOPPED_REASON_INVALID_IPADDR,
	WAN_STOPPED_REASON_MANUAL,
	WAN_STOPPED_REASON_SYSTEM_ERR,
	WAN_STOPPED_REASON_IPGATEWAY_CONFLICT,
	WAN_STOPPED_REASON_METER_LIMIT,
	WAN_STOPPED_REASON_PINCODE_ERR,
	WAN_STOPPED_REASON_PPP_LACK_ACTIVITY
};

enum {
	NAT_STATE_INITIALIZING=0,
	NAT_STATE_REDIRECT,
	NAT_STATE_NORMAL,
	NAT_STATE_UPDATE
};

// the following state is maintained by wan duck

enum {
	WAN_AUXSTATE_NONE=0,		// STATE FOR NO ERROR or OK
	WAN_AUXSTATE_NOPHY,
	WAN_AUXSTATE_NO_INTERNET_ACTIVITY,
	WAN_AUXSTATE_PPP_AUTH_FAIL
};

enum Transfer_Mode{
	TMode_ADSL = 0,
	TMode_VDSL,
	TMode_Ether,
	TMode_USB
};

#ifdef RTCONFIG_IPV6
enum {
	WAN6_STATE_INITIALIZING=0,
	WAN6_STATE_CONNECTING,
	WAN6_STATE_CONNECTED,
	WAN6_STATE_DISCONNECTED,
	WAN6_STATE_STOPPED,
	WAN6_STATE_DISABLED
};

enum {
	WAN6_STOPPED_REASON_NONE=0,
	WAN6_STOPPED_REASON_DHCP_DECONFIG,
};
#endif

enum {
	AUTODET_STATE_INITIALIZING=0,
	AUTODET_STATE_CHECKING,
	AUTODET_STATE_FINISHED_OK,
	AUTODET_STATE_FINISHED_FAIL,
	AUTODET_STATE_FINISHED_NOLINK,
	AUTODET_STATE_FINISHED_NODHCP,
	AUTODET_STATE_FINISHED_WITHPPPOE
};


enum {
	LAN_STATE_INITIALIZING=0,
	LAN_STATE_CONNECTING,
	LAN_STATE_CONNECTED,
	LAN_STATE_DISCONNECTED,
	LAN_STATE_STOPPED,
	LAN_STATE_DISABLED
};

enum {
	LAN_STOPPED_REASON_NONE=0,
	LAN_STOPPED_REASON_DHCP_DECONFIG,
	LAN_STOPPED_REASON_SYSTEM_ERR
};

#if defined(CONFIG_BCMWL5) || (defined(RTCONFIG_RALINK) && defined(RTCONFIG_WIRELESSREPEATER))
enum { 
	WLC_STATE_INITIALIZING=0,
	WLC_STATE_CONNECTING,
	WLC_STATE_CONNECTED,
	WLC_STATE_STOPPED
};

enum { 
	WLC_STOPPED_REASON_NONE=0,
	WLC_STOPPED_REASON_NO_SIGNAL,
	WLC_STOPPED_REASON_AUTH_FAIL,
	WLC_STOPPED_REASON_MANUAL
};

enum { 
	WLCSCAN_STATE_INITIALIZING=0,
	WLCSCAN_STATE_2G,
	WLCSCAN_STATE_5G,
	WLCSCAN_STATE_FINISHED,
	WLCSCAN_STATE_STOPPED
};

#endif



// the following state is maintained by wan duck
#define WEBREDIRECT_FLAG_NOLINK 1
#define WEBREDIRECT_FLAG_NOINTERNET 2

// the following flag is used for noticing service that will be invoked after getting lan ip
#define INVOKELATER_DMS	1

#ifdef RTCONFIG_USB
enum {
	USB_HOST_NONE=0,
	USB_HOST_OHCI,
	USB_HOST_EHCI,
	USB_HOST_XHCI
};

enum {
	APPS_AUTORUN_INITIALIZING=0,
	APPS_AUTORUN_CHECKING_DISK,
	APPS_AUTORUN_CREATING_SWAP,
	APPS_AUTORUN_EXECUTING,
	APPS_AUTORUN_FINISHED
};

enum {
	APPS_INSTALL_INITIALIZING=0,
	APPS_INSTALL_CHECKING_PARTITION,
	APPS_INSTALL_CHECKING_SWAP,
	APPS_INSTALL_DOWNLOADING,
	APPS_INSTALL_INSTALLING,
	APPS_INSTALL_FINISHED
};

enum {
	APPS_REMOVE_INITIALIZING=0,
	APPS_REMOVE_REMOVING,
	APPS_REMOVE_FINISHED
};

enum {
	APPS_SWITCH_INITIALIZING=0,
	APPS_SWITCH_STOPPING_APPS,
	APPS_SWITCH_STOPPING_SWAP,
	APPS_SWITCH_CHECKING_PARTITION,
	APPS_SWITCH_EXECUTING,
	APPS_SWITCH_FINISHED
};

enum {
	APPS_STOP_INITIALIZING=0,
	APPS_STOP_STOPPING,
	APPS_STOP_REMOVING_SWAP,
	APPS_STOP_FINISHED
};

enum {
	APPS_ENABLE_INITIALIZING=0,
	APPS_ENABLE_SETTING,
	APPS_ENABLE_FINISHED
};

enum {
	APPS_UPDATE_INITIALIZING=0,
	APPS_UPDATE_UPDATING,
	APPS_UPDATE_FINISHED
};

enum {
	APPS_UPGRADE_INITIALIZING=0,
	APPS_UPGRADE_DOWNLOADING,
	APPS_UPGRADE_REMOVING,
	APPS_UPGRADE_INSTALLING,
	APPS_UPGRADE_FINISHED
};

enum {
	APPS_ERROR_NO=0,
	APPS_ERROR_INPUT,
	APPS_ERROR_MOUNT,
	APPS_ERROR_POOLSIZE,
	APPS_ERROR_BASEAPPS,
	APPS_ERROR_NET,
	APPS_ERROR_SERVER,
	APPS_ERROR_FILE,
	APPS_ERROR_NONINSTALL,
	APPS_ERROR_REMOVE,
	APPS_ERROR_DISKIO
};

enum {
	DISKMON_IDLE=0,
	DISKMON_START,
	DISKMON_UMOUNT,
	DISKMON_SCAN,
	DISKMON_REMOUNT,
	DISKMON_FINISH,
	DISKMON_FORCE_STOP
};

#define DISKMON_FREQ_DISABLE 0
#define DISKMON_FREQ_MONTH 1
#define DISKMON_FREQ_WEEK 2
#define DISKMON_FREQ_DAY 3

#define DISKMON_SAFE_RANGE 10 // min.
#define DISKMON_DAY_HOUR 24
#define DISKMON_HOUR_SEC 3600

#define MAX_USB_PORT 3
#define MAX_USB_HUB_PORT 6
#define MAX_USB_DISK_NUM 26
#define MAX_USB_PART_NUM 16
#define MAX_USB_PRINTER_NUM 10
#define MAX_USB_TTY_NUM 10
#endif

// the following definition is for wans_cap
#define WANSCAP_DSL	0x01
#define WANSCAP_WAN	0x02
#define WANSCAP_LAN	0x04
#define WANSCAP_2G	0x08
#define WANSCAP_5G	0x10
#define WANSCAP_USB	0x20

// the following definition is for wans_dualwan
#define WANS_DUALWAN_IF_NONE 	0
#define WANS_DUALWAN_IF_DSL	1
#define WANS_DUALWAN_IF_WAN	2
#define WANS_DUALWAN_IF_LAN	3
#define WANS_DUALWAN_IF_USB	4
#define WANS_DUALWAN_IF_2G	5
#define WANS_DUALWAN_IF_5G	6

// the following definition is for free_caches()
#define FREE_MEM_NONE  "0"
#define FREE_MEM_PAGE  "1"
#define FREE_MEM_INODE "2"
#define FREE_MEM_ALL   "3"

#define is_routing_enabled() 1//tmp, sw_mode=1 only currently	(nvram_get_int("sw_mode")==SW_MODE_ROUTER||nvram_get_int("sw_mode")==SW_MODE_HOTSPOT)
#define is_nat_enabled()     ((nvram_get_int("sw_mode")==SW_MODE_ROUTER||nvram_get_int("sw_mode")==SW_MODE_HOTSPOT)&&nvram_get_int("wan0_nat_x")==1)
#define is_lan_connected()   (nvram_get_int("lan_state")==LAN_STATE_CONNECTED)
#ifdef RTCONFIG_WIRELESSWAN
#define is_wirelesswan_enabled() (nvram_get_int("sw_mode")==SW_MODE_HOTSPOT)
#endif
#define is_apmode_enabled() (nvram_get_int("sw_mode")==SW_MODE_AP)
// todo: multiple wan

int wan_primary_ifunit(void);
int wan_secondary_ifunit(void);
int get_wan_primary_ifunit(void);
int getTransferMode(void);
extern char *get_wan_ifname_ex(int unit, char *wan_ifname);
extern char *get_wan_primary_ifname(char *ifname);
extern char *get_wan_secondary_ifname(char *ifname);
extern char *get_first_connected_public_wan_ifname(char *ifname);
extern int is_wan_connect(int unit);
extern int get_wan_state(int unit);
extern int get_wan_unit(char *ifname);
extern int get_wan_unit_ex(const char *ifname, int *unit, int *subunit);
extern char *get_wan_ifname(int unit);
extern int get_wanports_status(int wan_unit);
extern char *get_usb_ehci_port(int port);
extern char *get_usb_ohci_port(int port);
extern int get_usb_port_number(const char *usb_port);
extern int get_usb_port_host(const char *usb_port);
extern int get_cur_lanwan_port(void);
extern int set_lanwan_if(int from, int to);
#ifdef RTCONFIG_DUALWAN
extern void set_wanscap_support(char *feature);
extern void add_wanscap_support(char *feature);
extern int get_wans_dualwan(void);
extern int get_dualwan_by_unit(int unit);
extern int get_dualwan_primary(void);
extern int get_dualwan_secondary(void);
int wan_primary_pvcunit(void);
int wan_secondary_pvcunit(void);
extern int is_running_as_second_wan(int unit);
#endif
int get_pvcunit_by_dualwan(int wans_dualwan_if);
int get_dualwan_by_pvcunit(int pvcunit);

#if (defined(TCSUPPORT_WAN_ETHER) || defined(TCSUPPORT_WAN_PTM)) && defined(TCSUPPORT_MULTISERVICE_ON_WAN)
#define MAX_SERVICE_NUM	8
#else
#define MAX_SERVICE_NUM	1
#endif
int isMultiSerPVC(int pvc);

#endif
