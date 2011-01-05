#pragma once

#pragma pack(push, 1)


#define SPELLBUFF_FEATHERFALL 5
#define SPELLBUFF_FLY         7
#define SPELLBUFF_WATERWALK  15
#define SPELLBUFF_TORCHLIGHT 16
#define SPELLBUFF_WIZARDEYE  19

struct SpellBuff
{
 union
 {
  __int64 qword_000000;
  struct
  {
   int dword_000000;
   int dword_000004;
  };
  struct
  {
   char  byte_000000;
   char  byte_000001;
   char  byte_000002;
   char  byte_000003;
   char  byte_000004;
   char  byte_000005;
   char  byte_000006;
   char  byte_000007;
  };
 };
 unsigned short word_000008;
 unsigned short word_00000A; // looks like caster mastery
 unsigned short word_00000C;
 unsigned char  byte_00000E;
 char byte_00000F;
};
//sizeof = 10









struct Spell_data
{
 unsigned short uNormalLevelMana;   // word @ 000000
 unsigned short uExpertLevelMana;   // word @ 000002
 unsigned short uMasterLevelMana;   // word @ 000004
 unsigned short uMagisterLevelMana; // word @ 000006
 unsigned short word08;
 unsigned short word0A;
 unsigned short word0C;
 unsigned short word10;
 unsigned char	byte11;
 unsigned char	byte12;
 unsigned char	byte13;
 unsigned char	byte14;
}; 
//size of 14


struct SpellInfo
{
 unsigned char *pSpellName;                 // ptr   @ 000000  unk_5CC030
 unsigned char *pSpellNameShort;            // ptr   @ 000004  unk_5CC034
 unsigned char *pSpellDescription;          // ptr   @ 000008  unk_5CC038
 unsigned char *pSpellBasicSkillDesc;       // ptr   @ 00000Ñ  unk_5CC03C
 unsigned char *pSpellExpertSkillDesc;      // ptr   @ 000010  unk_5CC040
 unsigned char *pSpellMasterSkillDesc;      // ptr   @ 000014  unk_5CC044
 unsigned char *pSpellGrandmasterSkillDesc; // ptr   @ 000018  unk_5CC048
 unsigned int   uSpellSchool;               // dword @ 00001C  unk_5CC04c
 int            dword_000020;							     //unk_5CC050
};
//sizeof = 24


struct CSpellStats
{
 struct SpellInfo pSpellInfos[100]; //[9][11] struct @ 000000	 unk_5CC030
};
//sizeof ~ ?
void CSpellStats_ctor(struct CSpellStats *_this);
//char *__thiscall sub_45384A(void *_this)
void CSpellStats_Initialize(struct CSpellStats *_this);
















#pragma pack(pop)