#pragma once

#pragma pack(push, 1)


#define SPELLBUFF_FEATHERFALL 5
#define SPELLBUFF_FLY         7
#define SPELLBUFF_WATERWALK  15
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





#pragma pack(pop)