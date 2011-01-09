#pragma once
#include "..\CoreDefinitions.h"
#include <string.h>

/*
 Acromage: original copyright (c) 3DO

 		Arcomage v0.3.2
		by STiCK and GreatEmerald (2005-2010)

		This program was originally created as Individual Software Project
		at Charles University Prague, Czech Republic

		Since 2009 it became easier to access and its development was continued.

		http://stick.gk2.sk/projects/arcomage/

		This is a clone of Arcomage, a card game originally released by New World Computing
		and the 3DO Company as a part of Might and Magic VII: For Blood and Honor
		and re-released in 2001 as a stand-alone application.
		Since it didn't support any kind of modifications, this open source project
		aims to completely remake the original and make it more flexible.

        Original credits follow.
*/


namespace Arcomage
{
 struct Player
 {
  char         pName[32];
  unsigned int uTower;
  unsigned int uWall;

  unsigned int uQuarryLevel;
  unsigned int uNumBricks;

  unsigned int uMagicLevel;
  unsigned int uNumGems;

  unsigned int uDungeonLevel;
  unsigned int uNumRecruits;
 };

 struct Rules
 {
  unsigned int uTower;        // How much tower wins
  unsigned int uNumResources; // How much resources wins
  bool         bNoMoreCards;  // Highest tower wins when there are no more cards.
  unsigned int uGameTime;     // Highest tower wins when time elapses.
 };

 class Game
 {
  public:
    Result::Code Initialize(bool bSilent);

    Result::Code Play(Player *pPlayer1InitialConditions, Player *pPlayer2InitialConditions, Rules *pVictoryConditions);

  protected:
    struct Card
    {
     enum Domain
     {
      Earth = 0,
      Magic = 1,
      Life = 2
     };

     inline Card() {}
     inline Card(wchar_t *pCardName, unsigned int uNumCardsInDeck, Domain eCardDomain, unsigned int uCardCost):
       uNumInDeck(uNumCardsInDeck), eDomain(eCardDomain), uCost(uCardCost)
     {
      wcscpy(pName, pCardName);
     }

     wchar_t      pName[32];
     unsigned int uNumInDeck;
     Domain       eDomain;
     unsigned int uCost;
    };

    bool bNoSound;

    class cTexture *pTexture_Menu,
                   *pTexture_GameBackground,
                   *pTexture_CardDeck;

    Card           *pDeck,
                   *pEarthDeck,
                   *pMagicDeck,
                   *pLifeDeck;

    Rules           cGameRules;
    Player          cPlayer1State;
    unsigned int    pPlayer1Deck[6];
    Player          cPlayer2State;
    unsigned        pPlayer2Deck[6];
 };
};