#include "..\c18.h"
#include "..\_lod.h"
#include "..\memory_mng.h"
#include "..\data.h"
#include "..\GUI\Window.h"
#include "..\GUI\Font.h"

#include "Arcomage.h"
using namespace Arcomage;

Result::Code Game::Play(Player *pPlayer1InitialConditions, Player *pPlayer2InitialConditions, Rules *pVictoryConditions)
{
 Render_ClearAndPresent(pD3DRenderer, 0xFF000000);

 memcpy(&cGameRules, pVictoryConditions, sizeof(Rules));
 memcpy(&cPlayer1State, pPlayer1InitialConditions, sizeof(Player));
 memcpy(&cPlayer2State, pPlayer2InitialConditions, sizeof(Player));
 for (unsigned int i = 0; i < 6; ++i)
   pPlayer1Deck[i] = rand() % (34 * 3), pPlayer2Deck[i] = rand() % (34 * 3);

 while (true)
 {
  pD3DRenderer->BeginScene();
  {
   Render_DrawTransparentTexture(pD3DRenderer, 0, 0, pTexture_GameBackground);

   for (unsigned int i = 0; i < 6; ++i)
     Render_DrawTransparentRect(pD3DRenderer, 8 + 106 * i, 342,
                                96 + 96 * (pPlayer1Deck[i] % 34), 128 * (pPlayer1Deck[i] / 34),
                                96, 128, pTexture_CardDeck);
  }
  pD3DRenderer->EndScene();
  pD3DRenderer->Present();
 }

 return Result::Success;
}




Result::Code Game::Initialize(bool bSilent)
{
 bNoSound = bSilent;

 pTexture_GameBackground = MemAlloc(cTexture, 1);
 pTexture_GameBackground->cTexture_Load(L".\\data\\override\\arcomage\\game_bg0.png");

 pTexture_CardDeck = MemAlloc(cTexture, 1);
 pTexture_CardDeck->cTexture_Load(L".\\data\\override\\arcomage\\deck.png");

 pDeck = MemAlloc(Card, 34 * 3);

 pEarthDeck = pDeck;
 pEarthDeck[0] = Card(L"Brick Shortage", -1, Card::Domain::Earth, 0);
 pEarthDeck[1] = Card(L"Lucky Cache", -1, Card::Domain::Earth, 0);
 pEarthDeck[2] = Card(L"Friendly Terrain", -1, Card::Domain::Earth, 1);
 pEarthDeck[3] = Card(L"Miners", -1, Card::Domain::Earth, 3);
 pEarthDeck[4] = Card(L"Mother Lode", -1, Card::Domain::Earth, 4);
 pEarthDeck[5] = Card(L"Dwarven Miners", -1, Card::Domain::Earth, 7);
 pEarthDeck[6] = Card(L"Work Overtime", -1, Card::Domain::Earth, 2);
 pEarthDeck[7] = Card(L"Copping the Tech", -1, Card::Domain::Earth, 5);
 pEarthDeck[8] = Card(L"Basic Wall", -1, Card::Domain::Earth, 2);
 pEarthDeck[9] = Card(L"Sturdy Wall", -1, Card::Domain::Earth, 3);
 pEarthDeck[10] = Card(L"Innovations", -1, Card::Domain::Earth, 2);
 pEarthDeck[11] = Card(L"Foundations", -1, Card::Domain::Earth, 3);
 pEarthDeck[12] = Card(L"Tremors", -1, Card::Domain::Earth, 7);
 pEarthDeck[13] = Card(L"Secret Room", -1, Card::Domain::Earth, 8);
 pEarthDeck[14] = Card(L"Earthquake", -1, Card::Domain::Earth, 0);
 pEarthDeck[15] = Card(L"Big Wall", -1, Card::Domain::Earth, 5);
 pEarthDeck[16] = Card(L"Collapse!", -1, Card::Domain::Earth, 4);
 pEarthDeck[17] = Card(L"New Equipment", -1, Card::Domain::Earth, 6);
 pEarthDeck[18] = Card(L"Strip Mine", -1, Card::Domain::Earth, 0);
 pEarthDeck[19] = Card(L"Reinforced Wall", -1, Card::Domain::Earth, 8);
 pEarthDeck[20] = Card(L"Porticulus", -1, Card::Domain::Earth, 9);
 pEarthDeck[21] = Card(L"Crystal Rocks", -1, Card::Domain::Earth, 9);
 pEarthDeck[22] = Card(L"Harmonic Ore", -1, Card::Domain::Earth, 11);
 pEarthDeck[23] = Card(L"Mondo Wall", -1, Card::Domain::Earth, 13);
 pEarthDeck[24] = Card(L"Focused Designs", -1, Card::Domain::Earth, 15);
 pEarthDeck[25] = Card(L"Great Wall", -1, Card::Domain::Earth, 16);
 pEarthDeck[26] = Card(L"Rock Launcher", -1, Card::Domain::Earth, 18);
 pEarthDeck[27] = Card(L"Dragon's Heart", -1, Card::Domain::Earth, 24);
 pEarthDeck[28] = Card(L"Forced Labor", -1, Card::Domain::Earth, 7);
 pEarthDeck[29] = Card(L"Rock Garden", -1, Card::Domain::Earth, 1);
 pEarthDeck[30] = Card(L"Flood Water", -1, Card::Domain::Earth, 6);
 pEarthDeck[31] = Card(L"Barracks", -1, Card::Domain::Earth, 10);
 pEarthDeck[32] = Card(L"Battlements", -1, Card::Domain::Earth, 14);
 pEarthDeck[33] = Card(L"Shift", -1, Card::Domain::Earth, 17);

 pMagicDeck = pDeck + 34;
 pMagicDeck[0] = Card(L"Quartz", -1, Card::Domain::Magic, 1);
 pMagicDeck[1] = Card(L"Smoky Quartz", -1, Card::Domain::Magic, 2);
 pMagicDeck[2] = Card(L"Amethyst", -1, Card::Domain::Magic, 3);
 pMagicDeck[3] = Card(L"Spell Weavers", -1, Card::Domain::Magic, 3);
 pMagicDeck[4] = Card(L"Prism", -1, Card::Domain::Magic, 2);
 pMagicDeck[5] = Card(L"Lodestone", -1, Card::Domain::Magic, 5);
 pMagicDeck[6] = Card(L"Solar Flare", -1, Card::Domain::Magic, 4);
 pMagicDeck[7] = Card(L"Crystal Matrix", -1, Card::Domain::Magic, 6);
 pMagicDeck[8] = Card(L"Gemstone Flaw", -1, Card::Domain::Magic, 2);
 pMagicDeck[9] = Card(L"Ruby", -1, Card::Domain::Magic, 3);
 pMagicDeck[10] = Card(L"Gem Spear", -1, Card::Domain::Magic, 4);
 pMagicDeck[11] = Card(L"Power Burn", -1, Card::Domain::Magic, 3);
 pMagicDeck[12] = Card(L"Harmonic Vibe", -1, Card::Domain::Magic, 7);
 pMagicDeck[13] = Card(L"Parity", -1, Card::Domain::Magic, 7);
 pMagicDeck[14] = Card(L"Emerald", -1, Card::Domain::Magic, 6);
 pMagicDeck[15] = Card(L"Pearl of Wisdom", -1, Card::Domain::Magic, 9);
 pMagicDeck[16] = Card(L"Shatterer", -1, Card::Domain::Magic, 8);
 pMagicDeck[17] = Card(L"Crumblestone", -1, Card::Domain::Magic, 7);
 pMagicDeck[18] = Card(L"Sapphire", -1, Card::Domain::Magic, 10);
 pMagicDeck[19] = Card(L"Discord", -1, Card::Domain::Magic, 5);
 pMagicDeck[20] = Card(L"Fire Ruby", -1, Card::Domain::Magic, 13);
 pMagicDeck[21] = Card(L"Quarry's Help", -1, Card::Domain::Magic, 4);
 pMagicDeck[22] = Card(L"Crystal Shield", -1, Card::Domain::Magic, 12);
 pMagicDeck[23] = Card(L"Empathy Gem", -1, Card::Domain::Magic, 14);
 pMagicDeck[24] = Card(L"Diamond", -1, Card::Domain::Magic, 16);
 pMagicDeck[25] = Card(L"Sanctuary", -1, Card::Domain::Magic, 15);
 pMagicDeck[26] = Card(L"Lava Jewel", -1, Card::Domain::Magic, 17);
 pMagicDeck[27] = Card(L"Dragon's Eye", -1, Card::Domain::Magic, 21);
 pMagicDeck[28] = Card(L"Crystallize", -1, Card::Domain::Magic, 8);
 pMagicDeck[29] = Card(L"Bag of Baulbles", -1, Card::Domain::Magic, 0);
 pMagicDeck[30] = Card(L"Rainbow", -1, Card::Domain::Magic, 0);
 pMagicDeck[31] = Card(L"Apprentice", -1, Card::Domain::Magic, 5);
 pMagicDeck[32] = Card(L"Lightning Shard", -1, Card::Domain::Magic, 11);
 pMagicDeck[33] = Card(L"Phase Jewel", -1, Card::Domain::Magic, 18);

 pLifeDeck = pDeck + 34 + 34;
 pLifeDeck[0] = Card(L"Mad Cow Disease", -1, Card::Domain::Life, 0);
 pLifeDeck[1] = Card(L"Faerie", -1, Card::Domain::Life, 1);
 pLifeDeck[2] = Card(L"Moody Goblins", -1, Card::Domain::Life, 1);
 pLifeDeck[3] = Card(L"Minotaur", -1, Card::Domain::Life, 3);
 pLifeDeck[4] = Card(L"Elven Scout", -1, Card::Domain::Life, 2);
 pLifeDeck[5] = Card(L"Goblin Mob", -1, Card::Domain::Life, 3);
 pLifeDeck[6] = Card(L"Goblin Archers", -1, Card::Domain::Life, 4);
 pLifeDeck[7] = Card(L"Shadow Faerie", -1, Card::Domain::Life, 6);
 pLifeDeck[8] = Card(L"Orc", -1, Card::Domain::Life, 3);
 pLifeDeck[9] = Card(L"Dwarves", -1, Card::Domain::Life, 5);
 pLifeDeck[10] = Card(L"Little Snakes", -1, Card::Domain::Life, 6);
 pLifeDeck[11] = Card(L"Troll Trainer", -1, Card::Domain::Life, 7);
 pLifeDeck[12] = Card(L"Tower Gremlin", -1, Card::Domain::Life, 8);
 pLifeDeck[13] = Card(L"Full Moon", -1, Card::Domain::Life, 0);
 pLifeDeck[14] = Card(L"Slasher", -1, Card::Domain::Life, 5);
 pLifeDeck[15] = Card(L"Ogre", -1, Card::Domain::Life, 6);
 pLifeDeck[16] = Card(L"Rabid Sheep", -1, Card::Domain::Life, 6);
 pLifeDeck[17] = Card(L"Imp", -1, Card::Domain::Life, 5);
 pLifeDeck[18] = Card(L"Spizzer", -1, Card::Domain::Life, 8);
 pLifeDeck[19] = Card(L"Werewolf", -1, Card::Domain::Life, 9);
 pLifeDeck[20] = Card(L"Corrosion Cloud", -1, Card::Domain::Life, 11);
 pLifeDeck[21] = Card(L"Unicorn", -1, Card::Domain::Life, 9);
 pLifeDeck[22] = Card(L"Elven Archers", -1, Card::Domain::Life, 10);
 pLifeDeck[23] = Card(L"Succubus", -1, Card::Domain::Life, 14);
 pLifeDeck[24] = Card(L"Rock Stompers", -1, Card::Domain::Life, 11);
 pLifeDeck[25] = Card(L"Thief", -1, Card::Domain::Life, 12);
 pLifeDeck[26] = Card(L"Stone Giant", -1, Card::Domain::Life, 15);
 pLifeDeck[27] = Card(L"Vampire", -1, Card::Domain::Life, 17);
 pLifeDeck[28] = Card(L"Dragon", -1, Card::Domain::Life, 25);
 pLifeDeck[29] = Card(L"Spearman", -1, Card::Domain::Life, 2);
 pLifeDeck[30] = Card(L"Gnome", -1, Card::Domain::Life, 2);
 pLifeDeck[31] = Card(L"Berserk", -1, Card::Domain::Life, 4);
 pLifeDeck[32] = Card(L"Warlord", -1, Card::Domain::Life, 13);
 pLifeDeck[33] = Card(L"Pegasus Lancer", -1, Card::Domain::Life, 18);

 return Result::Success;
}
