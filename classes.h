#pragma once
#define OFFSET_CLIENTGAMECONTEXT 0x142CDB4D8
#define OFFSET_BFSERVERSETTINGS 0x142D88418


class ClientGameContext {
public:
	char pad_0000[120];
	class GameView* GameView; // 0x78
	static ClientGameContext* GetInstance() {
		return *(ClientGameContext**)OFFSET_CLIENTGAMECONTEXT;
	}
};

class GameView
{
public:
	char pad_0008[192]; //0x0008
	class FreeCamera* FreeCamera; //0x00C8
	char pad_00D0[4016]; //0x00D0

	virtual void Function0();
	virtual void Function1();
	virtual void Function2();
	virtual void Function3();
	virtual void Function4();
	virtual void Function5();
	virtual void Function6();
	virtual void Function7();
	virtual void Function8();
	virtual void Function9();
	virtual void Function10();
	virtual void Function11();
	virtual void Function12();
	virtual void Function13();
	virtual void Function14();
	virtual void Function15();
	virtual void Function16();
	virtual void Function17();
	virtual void Function18();
	virtual void Function19();
	virtual void SetFreeCameraMode(int freecammode);
	virtual void Function21();
	virtual void Function22();
	virtual void Function23();
	virtual void Function24();
	virtual void Function25();
	virtual void Function26();
	virtual void Function27();
	virtual void Function28();
	virtual void Function29();
	virtual void Function30();
	virtual void Function31();
	virtual void Function32();
	virtual void Function33();
	virtual void Function34();
	virtual void Function35();
	virtual void Function36();
	virtual void Function37();
	virtual void Function38();
	virtual void Function39();
	virtual void Function40();
	virtual void Function41();
	virtual void Function42();
	virtual void Function43();
	virtual void Function44();
	virtual void Function45();
	virtual void Function46();
	virtual void Function47();
	virtual void Function48();
	virtual void Function49();
	virtual void Function50();
	virtual void Function51();
	virtual void Function52();
	virtual void Function53();
}; //Size: 0x1080
static_assert(sizeof(GameView) == 0x1080);

class FreeCamera
{
public:
	char pad_0000[336]; //0x0000
	class FreecamData* FreecamData; //0x0150
	char pad_0158[816]; //0x0158
}; //Size: 0x0488
static_assert(sizeof(FreeCamera) == 0x488);

class FreecamData
{
public:
	char pad_0000[136]; //0x0000
}; //Size: 0x0088
static_assert(sizeof(FreecamData) == 0x88);

class BFServerSettings
{
public:
	class UISettings* UISettings; //0x0000
	char pad_0008[120]; //0x0008
	
	static BFServerSettings* GetInstance() {
		return (BFServerSettings*)OFFSET_BFSERVERSETTINGS;
	}
}; //Size: 0x0080
static_assert(sizeof(BFServerSettings) == 0x80);

class UISettings
{
public:
	char pad_0000[72]; //0x0000
	bool DrawEnable; //0x0048
	char pad_0049[63]; //0x0049
}; //Size: 0x0088
static_assert(sizeof(UISettings) == 0x88);
