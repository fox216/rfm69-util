/*
	This file contains common message types for all 
	sensors and gateway nodes used in the RFM69 implementation
	Usage
	Link to project workspace
*/

#ifndef NodeMsg_h
#define NodeMsg_h

#if (ARDUINO < 100)
#include "WProgram.h"
#else
#include <Arduino.h>
#endif
 
#define MAX_NETWORK_SIZE 50

// Gateway Message Structure 
typedef struct {
  byte 				NodeID; 		// Address of target sensor 
  byte 				Method; 		// Message method (Example: Get / Set)
  byte				PayloadType; 	// Payload Dataytpe (Used to determine size and content of payload)
  byte  			MsgPayload[MAX_NETWORK_SIZE];
} _NodeMsg;
_NodeMsg nodeMsg;	// serial Message

/*
Supported Data Types Implemeted as Key Value Pairs
Msg#	Data Type Definition 			Optional Values in Payload		
____	_____________________			___________________________
1.		IO: IO Pin Location on Board  	[PIN ID]
2. 		Byte: Single Byte
3.		Boolean: 
4. 		Integer  						[Signed / unsigned flag]
6.		Long 		[Signed / Unsigned flag]
7.		Double 	
8.		Float 		[Analog ID]

*/

typedef struct {
	byte 	key;
	byte 	value;
} _Msg_1;
_Msg_1 msg_1;

typedef struct {
	byte 	key;
	byte 	value;
} _Msg_2;
_Msg_2 msg_2;

typedef struct {
	byte 	key;
	bool 	value;
} _Msg_3;
_Msg_3 msg_3;

typedef struct {
	byte 	key;
	int 	value;
} _Msg_4;
_Msg_4 msg_4;

typedef struct {
	byte 	key;
	const char* 	value;
} _Msg_5;
_Msg_5 msg_5;

typedef struct {
	byte 	key;
	long 	value;
} _Msg_6;
_Msg_6 msg_6;

typedef struct {
	byte 	key;
	double 	value;
} _Msg_7;
_Msg_7 msg_7;

typedef struct {
	byte 	key;
	float 	value;
} _Msg_8;
_Msg_8 msg_8;
/*

typedef enum {
	// INDEX of system message types
	// used to switch between message types
	heartbeat		= 10,
	zoneCtrl 		= 20,    	// Control individual Zone
	runProg 		= 30, 		// Control predefined groups of Zones
	sysCtrl 		= 40,		// System contol message (Override functions)
	sysStatus		= 50,		// System status callback
} MsgTypeIndex; 	




typedef struct {
  	byte 			MsgType; 	// Message type 
  	byte 			msg[MAX_NETWORK_SIZE]; 	// Message Payload
} Payload;
Payload payload;



	// Features
	// ------------------------------------------------
	// zoneCtrl: 	[I/O]Control single zone. Turn on single zone for default run time. 
	// runProg:	[I/O]Run predefined sprinkle program based on control character (Example: Front[f], Back[b])
	// sysCtrl:	[I/O]Pause / Resume system.
	// sysStatus:	[O] Send systems state Query System status.
	// sysConfig:	[I]Set system configuration vales . (Zone run time, Dwell time[Pause time between zones]) 
	// 			Returns sysStatus message.



typedef struct {
	// Name: zoneCtrl
	// MESSAGE TYPE = 10
	// MSG_SIZE = 2
	byte	zone;				// Zone to activate
	byte	cycleSelect;		// length of time zone should run (Predefined times)
} _zoneCtrl;
_zoneCtrl i_zoneCtrl; 			// inbound message
_zoneCtrl o_zoneCtrl; 			// outbound message

typedef struct {
	// Name: runProg
	// MESSAGE TYPE = 20
	// MSG_SIZE = 1
	//
	// Program Table
	// -----------------------------
	// A: [A]ll zones in ZoneList
	// F: [F]ront zones in f_zones
	// B: [B]ack zones in b_zones
	char 	program;			// Predefined set of zones in sequence
	byte	cycleSelect;
} _runProg;
_runProg	i_runProg;

typedef struct { 
	// Name: SprklMsg
	// MESSAGE TYPE = 
	// MSG_SIZE = 2 
	byte 		zone; 			// Sprinkler Zone to control
	byte		state;			// Duration of sprinkle time
} _SprklMsg;
_SprklMsg	i_SprklMsg;
_SprklMsg 	o_SprklMsg;

typedef struct {
	// _SysStatus
	// MESSAGE Type = 40
	// MSG_SIZE = 1
	//
	// Run State Table 
	// -------------------------
	// R: Set system state to [R]un, used to unpause sytem & and report status
	// P: [P]ause running program. (Note: Pause state will time out after 30 minutes. Updates to cancel -> idle)
	// I: Used to report state [I]dle state indicates sprinklers are off, system ready... (NOT SETABLE [word?])
	// C: [C]ancel running program, used to disable run. Note: Intermediate state used to reset system.
	char 	state;
	byte	cycleSelect;		// length of time zone should run (Predefined times)				
} _SysCtrl;
_SysCtrl	i_SysCtrl;


typedef struct {
	// _SysStatus
	// MESSAGE Type = 40
	// MSG_SIZE = 
	byte 	zone;  				// Current Zone
	char 	state;				// System State: (R: Run, P: Paused, I: Idle, C: Cancel) 
	char    progName;			// Current program
	//byte	runTime;			// ??? Zone run time
	byte	percComplete;		// Percent complete (Range: 0 - 100) 
} _SysStatus;
_SysStatus	o_SysStatus;


typedef struct {
	unsigned long 	mills; 		// [4] long Heartbeat
} _heartbeat;
_heartbeat	o_heartbeat;

*/
#endif

