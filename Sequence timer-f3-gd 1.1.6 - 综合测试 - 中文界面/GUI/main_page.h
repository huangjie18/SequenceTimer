#ifndef __MAIN_PAGE_H
#define __MAIN_PAGE_H
#include "sys.h"
void main_page_activity(void);
void main_page_action(void);
void main_page_encoder_action(void);
void  EncoderToAll(void);
void EncoderMain(u8* p);
void EncoderChanState(u8* SubAnchor);
void EncoderDelay(u8* SubAnchor);
void EncoderSwitch(u8 *SubAnchor);
void EncoderDate(u8 *SubAnchor);
void EncoderReset(u8 *SubAnchor);
void EncoderIP(u8 *SubAnchor);
void EncoderAUZ(u8 *SubAnchor);
void EncoderKeyboard(u8 *SubAnchor);
void EncoderPWD(u8 *SubAnchor);
void EncoderUVOV(u8 *SubAnchor);
void EncoderTimer(u8 *SubAnchor);
void EncoderTimerSub(void);
#endif


