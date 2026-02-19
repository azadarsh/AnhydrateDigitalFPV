#pragma once

#include "../base/base.h"

#define IPC_CHANNEL_TYPE_ROUTER_TO_CENTRAL 70
#define IPC_CHANNEL_TYPE_CENTRAL_TO_ROUTER 71
#define IPC_CHANNEL_TYPE_ROUTER_TO_TELEMETRY 83
#define IPC_CHANNEL_TYPE_TELEMETRY_TO_ROUTER 84
#define IPC_CHANNEL_TYPE_ROUTER_TO_RC 68
#define IPC_CHANNEL_TYPE_RC_TO_ROUTER 69
#define IPC_CHANNEL_TYPE_ROUTER_TO_COMMANDS 77
#define IPC_CHANNEL_TYPE_COMMANDS_TO_ROUTER 78
#define IPC_CHANNEL_CSI_VIDEO_COMMANDS 81

#define IPC_CHANNEL_MAX_MSG_SIZE 1600

#define Anhydrate_PIPES_EXTRA_FLAGS O_NONBLOCK

#ifdef __cplusplus
extern "C" {
#endif 


int Anhydrate_init_ipc_channels();
void Anhydrate_clear_all_ipc_channels();

int Anhydrate_open_ipc_channel_write_endpoint(int nChannelType);
int Anhydrate_open_ipc_channel_read_endpoint(int nChannelType);

int Anhydrate_close_ipc_channel(int iChannelUniqueId);


int Anhydrate_ipc_channel_send_message(int iChannelUniqueId, u8* pMessage, int iLength);
u8* Anhydrate_ipc_try_read_message(int iChannelUniqueId, u8* pTempBuffer, int* pTempBufferPos, u8* pOutputBuffer);

int Anhydrate_ipc_get_read_continous_error_count();

#ifdef __cplusplus
}  
#endif 

