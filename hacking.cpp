#include <iostream>
#include <unistd.h>
#include <string.h>
#include <cstdlib>  // for rand(), srand()
#include <ctime>    // for time()

using namespace std;

// Word array
const char* words_easy[] = {
    "ABOUT", "ABOVE", "ABUSE", "ACTOR", "ACUTE", "ADMIT", "ADOPT", "ADULT", "AFTER", "AGAIN",
    "AGENT", "AGREE", "AHEAD", "ALARM", "ALBUM", "ALERT", "ALIEN", "ALIGN", "ALIKE", "ALIVE",
    "ALLOW", "ALONE", "ALONG", "ALTER", "ANGER", "ANGLE", "ANGRY", "APART", "APPLE", "APPLY",
    "ARENA", "ARGUE", "ARISE", "ARRAY", "ASIDE", "ASSET", "AVOID", "AWAKE", "AWARD", "AWARE",
    "BADLY", "BAKER", "BASES", "BASIC", "BEACH", "BEGAN", "BEGIN", "BENCH", "BILLY", "BIRTH",
    "BLACK", "BLAME", "BLANK", "BLIND", "BLOCK", "BLOOD", "BOARD", "BOOST", "BOOTH", "BOUND",
    "BRAIN", "BRAND", "BRASS", "BRAVE", "BREAD", "BREAK", "BREED", "BRIEF", "BRING", "BROAD",
    "BROKE", "BROWN", "BUILD", "BUILT", "BUYER", "CABLE", "CALIF", "CARRY", "CATCH", "CAUSE",
    "CHAIN", "CHAIR", "CHAOS", "CHARM", "CHART", "CHASE", "CHEAP", "CHECK", "CHEST", "CHIEF",
    "CHILD", "CHINA", "CHOSE", "CIVIL", "CLAIM", "CLASS", "CLEAN", "CLEAR", "CLICK", "CLIMB",
    "CLOCK", "CLOSE", "COACH", "COAST", "COULD", "COUNT", "COURT", "COVER", "CRAFT", "CRASH",
    "CRAZY", "CREAM", "CRIME", "CROSS", "CROWD", "CROWN", "CRUDE", "CURVE", "CYCLE", "DAILY",
    "DANCE", "DATED", "DEALT", "DEATH", "DEBUG", "DELAY", "DEPTH", "DOING", "DOUBT", "DOZEN",
    "DRAFT", "DRAMA", "DRANK", "DRIVE", "DROVE", "DYING", "EAGER", "EARLY", "EARTH", "EIGHT",
    "ELITE", "EMPTY", "ENEMY", "ENJOY", "ENTER", "ENTRY", "EQUAL", "ERROR", "EVENT", "EVERY",
    "EXACT", "EXIST", "EXTRA", "FAITH", "FALSE", "FAULT", "FIBER", "FIELD", "FIFTH", "FIFTY",
    "FIGHT", "FINAL", "FIRST", "FIXED", "FLASH", "FLEET", "FLOOR", "FLUID", "FOCUS", "FORCE",
    "FORTH", "FORTY", "FORUM", "FOUND", "FRAME", "FRANK", "FRAUD", "FRESH", "FRONT", "FRUIT",
    "FULLY", "FUNNY", "GIANT", "GIVEN", "GLASS", "GLOBE", "GOING", "GRACE", "GRADE", "GRAIN",
    "GRAND", "GRANT", "GRASS", "GRAVE", "GREAT", "GREEN", "GROSS", "GROUP", "GROWN", "GUARD",
    "GUESS", "GUEST", "GUIDE", "HAPPY", "HARRY", "HEART", "HEAVY", "HENCE", "HENRY", "HORSE",
    "HOTEL", "HOUSE", "HUMAN", "IDEAL", "IMAGE", "INDEX", "INNER", "INPUT", "ISSUE", "JAPAN",
    "JIMMY", "JOINT", "JONES", "JUDGE", "KNOWN", "LABEL", "LARGE", "LASER", "LATER", "LAUGH",
    "LAYER", "LEARN", "LEASE", "LEAST", "LEAVE", "LEGAL", "LEVEL", "LEWIS", "LIGHT", "LIMIT",
    "LINKS", "LIVES", "LOCAL", "LOGIC", "LOOSE", "LOWER", "LUCKY", "LUNCH", "LYING", "MAGIC",
    "MAJOR", "MAKER", "MARCH", "MARIA", "MATCH", "MAYBE", "MAYOR", "MEANT", "MEDIA", "METAL",
    "MIGHT", "MINOR", "MINUS", "MIXED", "MODEL", "MONEY", "MONTH", "MORAL", "MOTOR", "MOUNT",
    "MOUSE", "MOUTH", "MOVED", "MOVIE", "MUSIC", "NEEDS", "NEVER", "NEWLY", "NIGHT", "NOISE",
    "NORTH", "NOTED", "NOVEL", "NURSE", "OCCUR", "OCEAN", "OFFER", "OFTEN", "ORDER", "OTHER",
    "OUGHT", "PAINT", "PANEL", "PAPER", "PARTY", "PEACE", "PETER", "PHASE", "PHONE", "PHOTO",
    "PIANO", "PIECE", "PILOT", "PITCH", "PLACE", "PLAIN", "PLANE", "PLANT", "PLATE", "POINT",
    "POUND", "POWER", "PRESS", "PRICE", "PRIDE", "PRIME", "PRINT", "PRIOR", "PRIZE", "PROOF",
    "PROUD", "PROVE", "QUEEN", "QUICK", "QUIET", "QUITE", "RADIO", "RAISE", "RANGE", "RAPID",
    "RATIO", "REACH", "READY", "REALM", "REBEL", "REFER", "RELAX", "REPAY", "REPLY", "RIGHT",
    "RIGID", "RIVAL", "RIVER", "ROBIN", "ROGER", "ROMAN", "ROUGH", "ROUND", "ROUTE", "ROYAL",
    "RURAL", "SCALE", "SCENE", "SCOPE", "SCORE", "SENSE", "SERVE", "SEVEN", "SHALL", "SHAPE",
    "SHARE", "SHARP", "SHEET", "SHELF", "SHELL", "SHIFT", "SHINE", "SHIRT", "SHOCK", "SHOOT",
    "SHORT", "SHOWN", "SIDES", "SIGHT", "SIMON", "SIXTH", "SIXTY", "SIZED", "SKILL", "SLEEP",
    "SLIDE", "SMALL", "SMART", "SMILE", "SMITH", "SMOKE", "SOLID", "SOLVE", "SORRY", "SOUND",
    "SOUTH", "SPACE", "SPARE", "SPEAK", "SPEED", "SPEND", "SPENT", "SPLIT", "SPOKE", "SPORT",
    "STAFF", "STAGE", "STAKE", "STAND", "START", "STATE", "STEAM", "STEEL", "STICK", "STILL",
    "STOCK", "STONE", "STOOD", "STORE", "STORM", "STORY", "STRIP", "STUCK", "STUDY", "STUFF",
    "STYLE", "SUGAR", "SUITE", "SUPER", "SWEET", "TABLE", "TAKEN", "TASTE", "TAXES", "TEACH",
    "TEETH", "TERRY", "TEXAS", "THANK", "THEFT", "THEIR", "THEME", "THERE", "THESE", "THICK",
    "THING", "THINK", "THIRD", "THOSE", "THREE", "THREW", "THROW", "THUMB", "TIGHT", "TIRED",
    "TITLE", "TODAY", "TOPIC", "TOTAL", "TOUCH", "TOUGH", "TOWER", "TRACK", "TRADE", "TRAIN",
    "TREAT", "TREND", "TRIAL", "TRIBE", "TRICK", "TRIED", "TRIES", "TRUCK", "TRULY", "TRUNK",
    "TRUST", "TRUTH", "TWICE", "UNCLE", "UNDUE", "UNION", "UNITY", "UNTIL", "UPPER", "UPSET",
    "URBAN", "USAGE", "USUAL", "VALID", "VALUE", "VIDEO", "VIRUS", "VISIT", "VITAL", "VOCAL",
    "VOICE", "WASTE", "WATCH", "WATER", "WHEEL", "WHERE", "WHICH", "WHILE", "WHITE", "WHOLE",
    "WHOSE", "WOMAN", "WOMEN", "WORLD", "WORRY", "WORSE", "WORST", "WORTH", "WOULD", "WRITE",
    "WRONG", "WROTE", "YOUNG", "YOURS", "YOUTH"
};

const int easy_words = sizeof(words_easy) / sizeof(words_easy[0]);

const int kMaxTries     =  4;
const int kGibberishLen = 15;

const int kTextDelay      =   35000;
const int kGibberishDelay =   10000;
const int kTransferDelay  = 1000000; // 1 sec

const int kNumberOffset         = 48;
const int kCapitalLetterOffset  = 65;

// Returns a random char from given range (for 0-9 range = 10, offset = 48)
char randomChar(int range, int offset)
  { return (char)((rand() % range) + offset); }

// Pauses the programm for a given time
inline void pausePrint(int delay)
{
  fflush(stdout);
  usleep(delay);
}

// Prints a string, pausing between each char to emulate Fallout terminal look
inline void slowPrint(const char * str, int delay = kTextDelay)
{
  int len = strlen(str);
  for (int i = 0; i < len; i++) {
    cout << str[i];
    pausePrint(delay);
  }
}

inline void slowPrint(char c, int delay = kTextDelay)
{
    cout << c;
    pausePrint(delay);
}

void printRandomHex()
{
  slowPrint("0x", kGibberishDelay);
  for (int i = 0; i < 4; i += 1) {
    if (rand() % 2)
      slowPrint(randomChar(10, kNumberOffset), kGibberishDelay);
    else
      slowPrint(randomChar(6, kCapitalLetterOffset), kGibberishDelay);
  }
  slowPrint(' ', kGibberishDelay);
}

void randomGib()
{
  switch (rand() % 6) {
    case 0: cout << randomChar(5, 33);
      break;
    case 1: cout << randomChar(5, 38);
      break;
    case 2: cout << randomChar(4, 43);
        break;
    case 3: cout << randomChar(6, 58);
      break;
    case 4: cout << randomChar(5, 91);
      break;
    case 5: cout << randomChar(3, 123);
      break;
  }
}

const char * giberrish(int len)
{
  bool should_print = rand()%2;
  const char * word = NULL;
  int word_len = 0;
  bool printed = false;

  if (should_print) {
    word = words_easy[rand() % easy_words];
    word_len = strlen(word);
  }

  for (int i = 0; i < (len - word_len); i++) {
    if (    should_print
        &&  !printed
        &&  (rand()%5 == 1 || i == (len - word_len - 1))) {

      slowPrint(word, kGibberishDelay);
      printed = true;
    }
    randomGib();
    pausePrint(kGibberishDelay);
  }

  return word;
}

int loadDifficulty()
{
  int difficulty = 0;
  while (difficulty < 1 || difficulty > 3) {
    cout << "Choose Difficulty (1-3): ";
    cin >> difficulty;
    if (!cin) {
      static int count = 0;
      count++;
      cin.clear();
      cin.ignore(256, '\n');
    }
  }
  return difficulty;
}

int checkLikeness(const char * correct, const char * guess)
{
  int likeness = 0;
  const char * correctPtr = correct;
  const char * guessPtr = guess;
  int len = strlen(correct);
  int guess_len = strlen(guess);
  
  // Only check up to the shorter length to avoid buffer overrun
  int min_len = (len < guess_len) ? len : guess_len;

  for (int i = 0; i < min_len; i++, correctPtr++, guessPtr++)
    if (*correctPtr == *guessPtr)
      likeness += 1;

  return likeness;
}

int main()
{
  srand(time(NULL));

  // int difficulty = 0;
  int likeness = 0;
  int tries = kMaxTries;

  const char * word_array[28];
  const char * word = NULL;
  char guess[16];
  const char * correct = NULL;
  int index = 0;
  
  pausePrint(kTransferDelay);
  slowPrint('\n');

  slowPrint("Welcome to ROBCO Industries (TM) Termlink\n"
            "Password Required");
  pausePrint(kTransferDelay);
  slowPrint("\n\n");

  for (int i = 0; i < 28; i += 1) {
    printRandomHex();
    word = giberrish(kGibberishLen);
    if (word)
      word_array[index++] = word;
    slowPrint(((i % 2) ? "\n" : "  "), kGibberishDelay);
  }
  pausePrint(kTransferDelay);

  slowPrint("\n>Attempts Remaining:");
  for (int i = 0; i < kMaxTries; i += 1)
    slowPrint(" #");
  slowPrint('\n');

  correct = word_array[rand() % index];

  while (tries) {
    slowPrint('>');
    // Safer input with length limit
    if (scanf("%15s", guess) != 1) {
      continue;
    }
    
    // Convert input to uppercase
    for (int i = 0; guess[i] != '\0'; i++) {
      guess[i] = toupper(guess[i]);
    }
    
    likeness = checkLikeness(correct, guess);
    if (likeness == (int)strlen(correct) && strlen(guess) == strlen(correct)) {
      slowPrint(">Password Accepted.\n\n"
                "Welcome to ROBCO Industries (TM) Termlink\n"
                "Lada's Personal Computer Terminal\n");
      break;
    }
    if (!strcmp("{*}", guess)) {
      tries = kMaxTries;
      slowPrint(">Attempts Reset.\n");
      continue;
    } else {
      tries -= 1;
      slowPrint(">Entry Denied.\n");
      if (!tries) {
        slowPrint("\nTerminal Locked.\n");
        slowPrint("The password was ");
        slowPrint(correct);
        slowPrint(" :)\n");
        return 1;
      }
      slowPrint(">Likeness="); 
      slowPrint((char)(likeness + '0'));
      slowPrint("\n>Attempts Remaining:");
      for (int i = 0; i < tries; i += 1)
        slowPrint(" #");
      slowPrint('\n');
    }
  }

  return 0;
}