#ifndef _EC_SPORTS_PLAYER_H
#define _EC_SPORTS_PLAYER_H

// ********************************************
// Sports Tournament
class ECTournament
{
public:
  ECTournament(int mon, int mr) : month(mon), minRank(mr) {}
  int GetMonth() const { return month; }
  int GetMinRank() const { return minRank; }

private:
  int month;
  int minRank;
};

// ********************************************
// Generic player
class ECSportsPlayer
{
public:
  virtual bool CanPlay(ECTournament &tr) const
  {
    if( NegRule(tr) == true )
    {
      return false; 
    }
    return PosRule(tr);
  }

  //return true if there is a positive rule saying this player can play
  virtual bool PosRule(ECTournament &tr) const
  {
    return false;
  }

  // return true if there is a NEGATIVE rule saying this player can play
  virtual bool NegRule(ECTournament &tr) const
  {
    return false;
  }

};

// ********************************************
// Ranked player
class ECSportsPlayerRanked : public ECSportsPlayer
{
public:
  ECSportsPlayerRanked(int r) : r(r) {}

  virtual bool PosRule(ECTournament &tr) const
  {
    return r <= tr.GetMinRank();
  }

private:
  int r;
};
// ********************************************
// player decorate
class ECSportsPlayerDec : public ECSportsPlayer
{
public:
  ECSportsPlayerDec(ECSportsPlayer &p) : p(p) {}

  virtual bool PosRule(ECTournament &tr) const
  {
    return p.PosRule(tr);
  }
  
  virtual bool NegRule(ECTournament &tr) const
  {
    return p.NegRule(tr);
  }

private:
  ECSportsPlayer &p;

};

// ********************************************
// Wildcard player: qualify for any tournament 
class ECSportsPlayerWildcard : public ECSportsPlayerDec
{
public:
  ECSportsPlayerWildcard(ECSportsPlayer &playerOrig) : ECSportsPlayerDec(playerOrig) {}
  
  virtual bool PosRule(ECTournament &tr) const
  {
    return true;
  }
};

// ********************************************
// Displined player: cannot attend any tournament during the period of probation
class ECSportsPlayerDisciplined : public ECSportsPlayerDec
{
public:
  ECSportsPlayerDisciplined(ECSportsPlayer &playerOrig, int mStart, int mEnd) : ECSportsPlayerDec(playerOrig), ms(mStart), me(mEnd) {}

  virtual bool NegRule(ECTournament &tr) const
  { 
    if( ECSportsPlayerDec :: NegRule(tr) )
    {
      return true; 

    }

    return tr.GetMonth() >= ms && tr.GetMonth() <= me;
  }

private:
  int ms;
  int me;
};

// ********************************************
// Injured player: cannot attend any tournament during the period of injury(injury occurs at a single month) 
class ECSportsPlayerInjured : public ECSportsPlayerDec
{
public:
  ECSportsPlayerInjured(ECSportsPlayer &playerOrig, int m) : ECSportsPlayerDec(playerOrig), m(m) {}

  virtual bool NegRule(ECTournament &tr) const
  { 
    if( ECSportsPlayerDec :: NegRule(tr) )
    {
      return true; 

    }
    return tr.GetMonth() == m;
  }


private:
  int m;
};

#endif
