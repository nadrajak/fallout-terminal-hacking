#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <time.h>
#include <ctype.h>
#include <string.h>


// Predefined set of possible passwords
const char *WORDS_EASY[] = {
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

const size_t WORDS_EASY_COUNT = sizeof(WORDS_EASY) / sizeof(WORDS_EASY[0]);


// Constatns controlling the "hexdump" dimensions
const size_t MAX_GENERATED_WORDS = 28;
const size_t HEX_DIGITS = 4;
const size_t MAX_WORD_LENGTH = 15;

const size_t MAX_TRIES = 3;

// Timing constants (in microseconds)
const size_t TEXT_PRINT_DELAY      =   35000; 
const size_t GIBBERISH_PRINT_DELAY =   10000;
const size_t DRAMATIC_PAUSE_DELAY  = 1000000;

// Handle timing 
#ifdef _WIN32
#include <windows.h>
void delay_printing(size_t delay)
{
  // delay is in microseconds, Sleep is in milliseconds
  fflush(stdout);
  Sleep(delay / 1000);
}
#else
#include <unistd.h>
void delay_printing(size_t delay)
{
  fflush(stdout);
  usleep(delay);
}
#endif

void delayed_vprintf(size_t delay, const char *format, va_list args)
{
  // Calculate required buffer size
  va_list args_copy;
  va_copy(args_copy, args);
  size_t char_count = vsnprintf(NULL, 0, format, args_copy) + 1;  // +1 for null terminator
  va_end(args_copy);

  // Allocate buffer
  char * buffer = (char *)malloc(sizeof(char) * char_count);

  // Format string & print character by character
  vsnprintf(buffer, char_count, format, args);
  for (char *ptr = buffer; *ptr; ptr++) {
    printf("%c", *ptr);
    delay_printing(delay);
  }

  free(buffer);
}

void text_printf(const char *format, ...)
{
  va_list args;
  va_start(args, format);
  delayed_vprintf(TEXT_PRINT_DELAY, format, args);
  va_end(args);
}

void gibberish_printf(const char *format, ...)
{
  va_list args;
  va_start(args, format);
  delayed_vprintf(GIBBERISH_PRINT_DELAY, format, args);
  va_end(args);
}

// Returns a random char from given range (for 0-9 range = 10, offset = 48)
char random_char(int range, int offset)
  { return (char)((rand() % range) + offset); }

// Return a random gibberish character
char generate_random_gibberish()
{
  switch (rand() % 6) {
    case 0: return random_char(5, '!');  // Range: ! " # $ %
    case 1: return random_char(5, '&');  // Range: & ' ( ) *
    case 2: return random_char(4, '+');  // Range: + , - .
    case 3: return random_char(6, ':');  // Range: : ; < = > ?
    case 4: return random_char(5, '[');  // Range: [ \ ] ^ _
    case 5: return random_char(3, '{');  // Range: { | }
    default: return '?';  // Should never happen
  }
}

size_t generate_random_hex(size_t hex_digits)
{
    if (hex_digits <= 0 || hex_digits > 8) {
        hex_digits = 4;
    }

    size_t max = (1 << (4 * hex_digits)) - 1;
    size_t hex = rand() % max;

    return hex;
}

// Convert string to uppercase in place
void to_uppercase(char *str)
{
    for (char *ptr = str; *ptr; ptr++) {
        *ptr = toupper(*ptr);
    }
}

size_t likeness(const char *guess, const char *password)
{
  size_t result = 0;

  while (*guess && *password) {
    if (*guess == *password) {
      result++;
    }
    guess++;
    password++;
  }

  return result;
}


int main()
{
  srand(time(NULL));

  int tries = MAX_TRIES;

  const char *generated_words[MAX_GENERATED_WORDS];
  size_t generated_words_count = 0;

  // Print the welcome screen
  delay_printing(DRAMATIC_PAUSE_DELAY);
  text_printf("\n  ROBCO Industries (TM) Termlink");
  text_printf("\n  Password Required");

  // Dramatic pause
  delay_printing(DRAMATIC_PAUSE_DELAY);
  text_printf("\n\n");

  // Print the "hexdump"
  for (size_t i = 0; i < MAX_GENERATED_WORDS; ++i) {
    gibberish_printf("  0x%0*X ", HEX_DIGITS, generate_random_hex(HEX_DIGITS));
    
    const char *word = NULL;
    size_t word_length = 0;
    if (rand() % 2) {
      word = WORDS_EASY[rand() % WORDS_EASY_COUNT];
      word_length = strlen(word);
      // Check if selected word is not too long
      if (MAX_WORD_LENGTH <= word_length) {
        text_printf("\n  >FATAL ERROR: CORRUPTED PASSWORD.\n");
        return 1;
      }
      
      generated_words[generated_words_count] = word;
      generated_words_count++;
    }
    
    size_t word_start_pos = rand() % (MAX_WORD_LENGTH - word_length);
    size_t word_end_pos = word_start_pos + word_length;

    // Print leading gibberish
    for (size_t j = 0; j < word_start_pos; j++) {
        gibberish_printf("%c", generate_random_gibberish());
    }

    // Print the word
    if (word) {
      gibberish_printf("%s", word);
    }

    // Print trailing gibberish
    for (size_t j = word_end_pos; j < MAX_WORD_LENGTH; j++) {
        gibberish_printf("%c", generate_random_gibberish());
    }

    // Print appropriate whitespace
    gibberish_printf("%s", ((i % 2) ? "\n" : "  "));
  }

  // Dramatic pause 2
  delay_printing(DRAMATIC_PAUSE_DELAY);
  text_printf("\n");

  // Select the password password randomly from the pool of generated words
  if (generated_words_count == 0) {
    text_printf("  >FATAL ERROR: NO PASSWORDS GENERATED.\n");
    return 1;
  }
  const char *password = generated_words[rand() % generated_words_count];

  while (tries) {

    // Print attempts
    text_printf("  >Attempts Remaining:");
    for (int i = 0; i < tries; i += 1) {
      text_printf(" #");
    }
    text_printf("\n");

    // Print empty line
    text_printf("  >");

    // Take user input
    char guess[MAX_WORD_LENGTH + 1];
    if (fgets(guess, sizeof(guess), stdin) == NULL) {
      break;
    }

    // Check if the input includes the newline character
    size_t newline_pos = strcspn(guess, "\n");
    if (guess[newline_pos] != '\n') {
        // Input longer than buffer -- discard the rest
        int c;
        do { c = getchar(); } while (c != '\n' && c != EOF);
    } else {
        // Replace newline with null terminator
        guess[newline_pos] = '\0';
    }

    to_uppercase(guess);


    // Check if cheatcode used 
    if (strcmp(guess, "{*}") == 0) {
      tries = MAX_TRIES;
      text_printf("  >Tries Reset.\n");

      continue;
    } 

    // Check if password guess
    if (strcmp(guess, password) == 0) {
      text_printf("  >Password Accepted.\n");

      delay_printing(DRAMATIC_PAUSE_DELAY);
      text_printf("\n");

      text_printf("  Welcome to ROBCO Industries (TM) Termlink\n");
      text_printf("  Lada's Personal Computer Terminal\n");

      break;
    }
    
    // Decrease tries and check for lockout
    tries--;
    text_printf("  >Entry Denied.\n");
    if (!tries) {
      text_printf("  >Terminal Locked.\n\n");
      text_printf("  The password was %s :)\n", password);

      break;
    }
    
    // Give likeness feedback for the guess
    text_printf("  >Likeness=%u\n", likeness(guess, password));
  }

  text_printf("\n");
  
  return 0;
}
