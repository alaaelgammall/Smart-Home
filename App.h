#ifndef APP_H
#define APP_H

typedef struct ST_accountsDB_t
{
	u8 UserNameSaved[10];
	u8 PasswordSaved[10];
}ST_accountsDB_t;

void App_Int (void) ;
u8 StringCompare(u8 *StrDefault, u8 *Str, u8 SizeofDefault);
u8 StringLength(u8 *StrDefault);
void SmartHome (void) ;

#endif
