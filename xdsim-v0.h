#pragma once

#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>


#if (defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE))
typedef enum ComponentType {
#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && defined(XDSIM_GATE))
  ComponentType_Gate,
#endif
#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && defined(XDSIM_CONN))
  ComponentType_Connection,
#endif
#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && defined(XDSIM_DATA))
  ComponentType_Data,
#endif
} ComponentType;
#endif

#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && (defined(XDSIM_GATE) || defined(XDSIM_CONN)))
typedef enum Direction {
#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && (defined(XDSIM_GATE) || defined(XDSIM_CONN)))
  Direction_Right,
#endif
#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && (defined(XDSIM_GATE) || defined(XDSIM_CONN)))
  Direction_Up,
#endif
#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && (defined(XDSIM_GATE) || defined(XDSIM_CONN)))
  Direction_Left,
#endif
#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && (defined(XDSIM_GATE) || defined(XDSIM_CONN)))
  Direction_Down,
#endif
} Direction;
#endif

#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && (defined(XDSIM_GATE) || defined(XDSIM_CONN)))
typedef enum MenuInputIntegerStyle {
#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && (defined(XDSIM_GATE) || defined(XDSIM_CONN)))
  MenuInputIntegerStyle_Slider,
#endif
#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && (defined(XDSIM_GATE) || defined(XDSIM_CONN)))
  MenuInputIntegerStyle_TextBox,
#endif
#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && (defined(XDSIM_GATE) || defined(XDSIM_CONN)))
  MenuInputIntegerStyle_SliderAndTextBox,
#endif
} MenuInputIntegerStyle;
#endif

#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && (defined(XDSIM_GATE) || defined(XDSIM_CONN)))
typedef enum MenuInputFloatStyle {
#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && (defined(XDSIM_GATE) || defined(XDSIM_CONN)))
  MenuInputFloatStyle_Slider,
#endif
#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && (defined(XDSIM_GATE) || defined(XDSIM_CONN)))
  MenuInputFloatStyle_TextBox,
#endif
#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && (defined(XDSIM_GATE) || defined(XDSIM_CONN)))
  MenuInputFloatStyle_SliderAndTextBox,
#endif
} MenuInputFloatStyle;
#endif

#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && (defined(XDSIM_GATE) || defined(XDSIM_CONN)))
typedef enum MenuInputBooleanStyle {
#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && (defined(XDSIM_GATE) || defined(XDSIM_CONN)))
  MenuInputBooleanStyle_CheckBox,
#endif
} MenuInputBooleanStyle;
#endif

#if (defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE))
/**
 * A non-resizeable, null-terminated string
 */
typedef struct Str {
  const char *first;
  void (*drop)(char*);
} Str;
#endif

#if (defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE))
typedef struct ComponentIdent {
  struct Str package;
  struct Str component;
  uint16_t major;
  uint16_t minor;
  uint16_t patch;
} ComponentIdent;
#endif

#if (defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE))
/**
 * A non-resizeable array with length
 */
typedef struct Slice {
  const void *first;
  uint64_t length;
  void (*drop)(void*, uint64_t);
} Slice;
#endif

#if (defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE))
typedef struct ComponentHeader {
  struct ComponentIdent ident;
  enum ComponentType component_type;
  /**
   * [ Str ]
   */
  struct Slice authors;
  struct Str description;
  struct Str homepage;
} ComponentHeader;
#endif

#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && defined(XDSIM_CONN))
/**
 * Information for a Connection
 */
typedef struct ConnectionDefinition {
  /**
   * Definition schema version number
   */
  uint32_t version;
  /**
   * Data type the connection carries
   */
  struct ComponentIdent data_type;
} ConnectionDefinition;
#endif

#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && defined(XDSIM_CONN))
typedef void *ConnectionMut;
#endif

#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && (defined(XDSIM_GATE) || defined(XDSIM_CONN)))
typedef struct Graphic {
  /**
   * [ Element ]
   */
  struct Slice elements;
} Graphic;
#endif

#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && defined(XDSIM_CONN))
typedef const void *Connection;
#endif

#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && defined(XDSIM_CONN))
/**
 * if is NONE, then write NULL
 */
typedef struct ConnectionJunction {
  const struct ConnectionSegment *up;
  const struct ConnectionSegment *right;
  const struct ConnectionSegment *down;
  const struct ConnectionSegment *left;
} ConnectionJunction;
#endif

#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && defined(XDSIM_CONN))
typedef struct ConnectionSegment {
  /**
   * [ Vec2 ]
   */
  struct Slice path;
  /**
   * if is NONE, then write NULL
   */
  const struct ConnectionJunction *next;
} ConnectionSegment;
#endif

#if (defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE))
typedef const void *Data;
#endif

#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && defined(XDSIM_CONN))
/**
 * Details of a request to draw a `Connection`
 */
typedef struct ConnectionDrawRequest {
  /**
   * Path the connection takes
   */
  const struct ConnectionSegment *path;
  /**
   * Current value in the connection
   */
  Data data;
} ConnectionDrawRequest;
#endif

#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && (defined(XDSIM_GATE) || defined(XDSIM_CONN)))
typedef void *PropertiesMut;
#endif

#if (defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE))
typedef void *DataMut;
#endif

#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && (defined(XDSIM_GATE) || defined(XDSIM_CONN)))
typedef struct Vec2 {
  float x;
  float y;
} Vec2;
#endif

#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && defined(XDSIM_GATE))
/**
 * TODO: this will need to have a stable byte structure
 * probably need to tag repr(C) or something
 * I need to read the nomicon
 */
typedef struct GateDefinition {
  /**
   * The ordered input that the gate takes
   * [ GateIOEntry ]
   */
  struct Slice inputs;
  /**
   * The ordered output that the gate produces
   * [ GateIOEntry ]
   */
  struct Slice outputs;
  /**
   * The visual bounding box (dimension) of the gate
   * The bottom left corner is (0, 0), top right corner is (width, height)
   */
  struct Vec2 bounding_box;
} GateDefinition;
#endif

#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && defined(XDSIM_GATE))
typedef const void *Gate;
#endif

#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && defined(XDSIM_GATE))
typedef void *GateMut;
#endif

#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && defined(XDSIM_GATE))
/**
 * A single gate draw request
 */
typedef struct GateDrawRequest {
  /**
   * One of the four the gate is facing (rotation)
   */
  enum Direction direction;
  /**
   * The size of the bounding box previously provided
   */
  struct Vec2 dimension;
} GateDrawRequest;
#endif

#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && defined(XDSIM_GATE))
/**
 * A single gate tick request
 */
typedef struct GateTickRequest {
  /**
   * Inputs to the gate
   * [ *const Data ]
   */
  struct Slice inputs;
} GateTickRequest;
#endif

#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && (defined(XDSIM_GATE) || defined(XDSIM_CONN)))
typedef const void *Properties;
#endif

#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && (defined(XDSIM_GATE) || defined(XDSIM_CONN)))
/**
 * A menu is a list of MenuItems
 */
typedef struct Menu {
  /**
   * [ MenuItem ]
   */
  struct Slice items;
} Menu;
#endif

#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && (defined(XDSIM_GATE) || defined(XDSIM_CONN)))
typedef enum MenuInputValue_Tag {
#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && (defined(XDSIM_GATE) || defined(XDSIM_CONN)))
  MenuInputValue_String,
#endif
#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && (defined(XDSIM_GATE) || defined(XDSIM_CONN)))
  MenuInputValue_Integer,
#endif
#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && (defined(XDSIM_GATE) || defined(XDSIM_CONN)))
  MenuInputValue_Float,
#endif
#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && (defined(XDSIM_GATE) || defined(XDSIM_CONN)))
  MenuInputValue_Boolean,
#endif
} MenuInputValue_Tag;

typedef struct MenuInputValue {
  MenuInputValue_Tag tag;
  union {
#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && (defined(XDSIM_GATE) || defined(XDSIM_CONN)))
    struct {
      struct Str string;
    };
#endif
#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && (defined(XDSIM_GATE) || defined(XDSIM_CONN)))
    struct {
      int64_t integer;
    };
#endif
#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && (defined(XDSIM_GATE) || defined(XDSIM_CONN)))
    struct {
      double float_;
    };
#endif
#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && (defined(XDSIM_GATE) || defined(XDSIM_CONN)))
    struct {
      bool boolean;
    };
#endif
  };
} MenuInputValue;
#endif

#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && (defined(XDSIM_GATE) || defined(XDSIM_CONN)))
typedef enum PropertiesSetError_Tag {
#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && (defined(XDSIM_GATE) || defined(XDSIM_CONN)))
  PropertiesSetError_NotExist,
#endif
#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && (defined(XDSIM_GATE) || defined(XDSIM_CONN)))
  PropertiesSetError_Invalid,
#endif
} PropertiesSetError_Tag;

typedef struct PropertiesSetError {
  PropertiesSetError_Tag tag;
  union {
#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && (defined(XDSIM_GATE) || defined(XDSIM_CONN)))
    struct {
      struct Str invalid;
    };
#endif
  };
} PropertiesSetError;
#endif

#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && (defined(XDSIM_GATE) || defined(XDSIM_CONN)))
typedef enum MenuInputStringStyle_Tag {
#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && (defined(XDSIM_GATE) || defined(XDSIM_CONN)))
  MenuInputStringStyle_Inline,
#endif
#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && (defined(XDSIM_GATE) || defined(XDSIM_CONN)))
  MenuInputStringStyle_Multiline,
#endif
#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && (defined(XDSIM_GATE) || defined(XDSIM_CONN)))
  MenuInputStringStyle_Dropdown,
#endif
} MenuInputStringStyle_Tag;

#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && (defined(XDSIM_GATE) || defined(XDSIM_CONN)))
typedef struct MenuInputStringStyle_Inline_Body {
  struct Str placeholder;
} MenuInputStringStyle_Inline_Body;
#endif

#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && (defined(XDSIM_GATE) || defined(XDSIM_CONN)))
typedef struct MenuInputStringStyle_Multiline_Body {
  uint32_t max_lines;
  struct Str placeholder;
} MenuInputStringStyle_Multiline_Body;
#endif

#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && (defined(XDSIM_GATE) || defined(XDSIM_CONN)))
typedef struct MenuInputStringStyle_Dropdown_Body {
  /**
   * [ Str ]
   */
  struct Slice options;
} MenuInputStringStyle_Dropdown_Body;
#endif

typedef struct MenuInputStringStyle {
  MenuInputStringStyle_Tag tag;
  union {
#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && (defined(XDSIM_GATE) || defined(XDSIM_CONN)))
    MenuInputStringStyle_Inline_Body inline_;
#endif
#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && (defined(XDSIM_GATE) || defined(XDSIM_CONN)))
    MenuInputStringStyle_Multiline_Body multiline;
#endif
#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && (defined(XDSIM_GATE) || defined(XDSIM_CONN)))
    MenuInputStringStyle_Dropdown_Body dropdown;
#endif
  };
} MenuInputStringStyle;
#endif

#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && (defined(XDSIM_GATE) || defined(XDSIM_CONN)))
typedef enum MenuInput_Tag {
#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && (defined(XDSIM_GATE) || defined(XDSIM_CONN)))
  MenuInput_String,
#endif
#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && (defined(XDSIM_GATE) || defined(XDSIM_CONN)))
  MenuInput_Integer,
#endif
#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && (defined(XDSIM_GATE) || defined(XDSIM_CONN)))
  MenuInput_Float,
#endif
#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && (defined(XDSIM_GATE) || defined(XDSIM_CONN)))
  MenuInput_Boolean,
#endif
} MenuInput_Tag;

#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && (defined(XDSIM_GATE) || defined(XDSIM_CONN)))
typedef struct MenuInput_String_Body {
  struct MenuInputStringStyle style;
} MenuInput_String_Body;
#endif

#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && (defined(XDSIM_GATE) || defined(XDSIM_CONN)))
typedef struct MenuInput_Integer_Body {
  int64_t min;
  int64_t max;
  enum MenuInputIntegerStyle style;
} MenuInput_Integer_Body;
#endif

#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && (defined(XDSIM_GATE) || defined(XDSIM_CONN)))
typedef struct MenuInput_Float_Body {
  double min;
  double max;
  enum MenuInputFloatStyle style;
} MenuInput_Float_Body;
#endif

#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && (defined(XDSIM_GATE) || defined(XDSIM_CONN)))
typedef struct MenuInput_Boolean_Body {
  enum MenuInputBooleanStyle style;
} MenuInput_Boolean_Body;
#endif

typedef struct MenuInput {
  MenuInput_Tag tag;
  union {
#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && (defined(XDSIM_GATE) || defined(XDSIM_CONN)))
    MenuInput_String_Body string;
#endif
#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && (defined(XDSIM_GATE) || defined(XDSIM_CONN)))
    MenuInput_Integer_Body integer;
#endif
#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && (defined(XDSIM_GATE) || defined(XDSIM_CONN)))
    MenuInput_Float_Body float_;
#endif
#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && (defined(XDSIM_GATE) || defined(XDSIM_CONN)))
    MenuInput_Boolean_Body boolean;
#endif
  };
} MenuInput;
#endif

#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && (defined(XDSIM_GATE) || defined(XDSIM_CONN)))
typedef enum MenuItemVariant_Tag {
#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && (defined(XDSIM_GATE) || defined(XDSIM_CONN)))
  /**
   * Can be fold/unfold to hide/reveal menu items
   */
  MenuItemVariant_Foldable,
#endif
#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && (defined(XDSIM_GATE) || defined(XDSIM_CONN)))
  MenuItemVariant_Text,
#endif
#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && (defined(XDSIM_GATE) || defined(XDSIM_CONN)))
  MenuItemVariant_Input,
#endif
} MenuItemVariant_Tag;

#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && (defined(XDSIM_GATE) || defined(XDSIM_CONN)))
typedef struct MenuItemVariant_Foldable_Body {
  struct Str title;
  /**
   * [ MenuItem ]
   */
  struct Slice items;
} MenuItemVariant_Foldable_Body;
#endif

#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && (defined(XDSIM_GATE) || defined(XDSIM_CONN)))
typedef struct MenuItemVariant_Text_Body {
  struct Str content;
} MenuItemVariant_Text_Body;
#endif

#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && (defined(XDSIM_GATE) || defined(XDSIM_CONN)))
typedef struct MenuItemVariant_Input_Body {
  struct Str id;
  struct MenuInput input_type;
} MenuItemVariant_Input_Body;
#endif

typedef struct MenuItemVariant {
  MenuItemVariant_Tag tag;
  union {
#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && (defined(XDSIM_GATE) || defined(XDSIM_CONN)))
    MenuItemVariant_Foldable_Body foldable;
#endif
#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && (defined(XDSIM_GATE) || defined(XDSIM_CONN)))
    MenuItemVariant_Text_Body text;
#endif
#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && (defined(XDSIM_GATE) || defined(XDSIM_CONN)))
    MenuItemVariant_Input_Body input;
#endif
  };
} MenuItemVariant;
#endif

#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && (defined(XDSIM_GATE) || defined(XDSIM_CONN)))
typedef struct MenuItem {
  struct Str tooltip;
  struct MenuItemVariant item_type;
} MenuItem;
#endif

#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && defined(XDSIM_GATE))
/**
 * Representing a single input or output connection that the gate take.
 * - name: the unique name of the input/output
 * - data_type: the type name of the input/output
 * - position: a point that is on the bounding box
 */
typedef struct GateIOEntry {
  struct Str name;
  struct ComponentIdent data_type;
  struct Vec2 position;
} GateIOEntry;
#endif

#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && (defined(XDSIM_GATE) || defined(XDSIM_CONN)))
/**
 * Enum representing the colour options available for gates
 */
typedef enum Colour_Tag {
#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && (defined(XDSIM_GATE) || defined(XDSIM_CONN)))
  /**
   * The primary colour of the gates (in a light theme, this would be black)
   */
  Colour_Fg,
#endif
#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && (defined(XDSIM_GATE) || defined(XDSIM_CONN)))
  /**
   * The background colour (in a light theme, this would be white)
   */
  Colour_Bg,
#endif
#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && (defined(XDSIM_GATE) || defined(XDSIM_CONN)))
  /**
   * Success colour (e.g. counter output in denary)
   */
  Colour_Success,
#endif
#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && (defined(XDSIM_GATE) || defined(XDSIM_CONN)))
  /**
   * Info colour (e.g. counter output in denary)
   */
  Colour_Info,
#endif
#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && (defined(XDSIM_GATE) || defined(XDSIM_CONN)))
  /**
   * Warn colour (e.g. potential incorrect operation)
   */
  Colour_Warn,
#endif
#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && (defined(XDSIM_GATE) || defined(XDSIM_CONN)))
  /**
   * Error colour (e.g. a FSM not enabled)
   */
  Colour_Error,
#endif
#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && (defined(XDSIM_GATE) || defined(XDSIM_CONN)))
  Colour_Black,
#endif
#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && (defined(XDSIM_GATE) || defined(XDSIM_CONN)))
  Colour_Blue,
#endif
#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && (defined(XDSIM_GATE) || defined(XDSIM_CONN)))
  Colour_Cyan,
#endif
#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && (defined(XDSIM_GATE) || defined(XDSIM_CONN)))
  Colour_Green,
#endif
#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && (defined(XDSIM_GATE) || defined(XDSIM_CONN)))
  Colour_Grey,
#endif
#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && (defined(XDSIM_GATE) || defined(XDSIM_CONN)))
  Colour_Magenta,
#endif
#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && (defined(XDSIM_GATE) || defined(XDSIM_CONN)))
  Colour_Red,
#endif
#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && (defined(XDSIM_GATE) || defined(XDSIM_CONN)))
  Colour_White,
#endif
#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && (defined(XDSIM_GATE) || defined(XDSIM_CONN)))
  Colour_Yellow,
#endif
#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && (defined(XDSIM_GATE) || defined(XDSIM_CONN)))
  Colour_Transparent,
#endif
#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && (defined(XDSIM_GATE) || defined(XDSIM_CONN)))
  /**
   * Arbitrary RGBA colour
   */
  Colour_Rgba,
#endif
#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && (defined(XDSIM_GATE) || defined(XDSIM_CONN)))
  /**
   * A named colour from a palette
   *
   * A palette is a customisable set of colours
   * multiple gates/connections can share the same palette
   */
  Colour_Named,
#endif
} Colour_Tag;

#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && (defined(XDSIM_GATE) || defined(XDSIM_CONN)))
typedef struct Colour_Rgba_Body {
  float r;
  float g;
  float b;
  float a;
} Colour_Rgba_Body;
#endif

#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && (defined(XDSIM_GATE) || defined(XDSIM_CONN)))
typedef struct Colour_Named_Body {
  /**
   * Name of the palette
   */
  struct Str palette;
  /**
   * Name of the colour within the palette
   */
  struct Str name;
} Colour_Named_Body;
#endif

typedef struct Colour {
  Colour_Tag tag;
  union {
#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && (defined(XDSIM_GATE) || defined(XDSIM_CONN)))
    Colour_Rgba_Body rgba;
#endif
#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && (defined(XDSIM_GATE) || defined(XDSIM_CONN)))
    Colour_Named_Body named;
#endif
  };
} Colour;
#endif

#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && (defined(XDSIM_GATE) || defined(XDSIM_CONN)))
typedef struct StrokeStyle {
  struct Colour colour;
} StrokeStyle;
#endif

#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && (defined(XDSIM_GATE) || defined(XDSIM_CONN)))
typedef struct FillStyle {
  struct Colour colour;
} FillStyle;
#endif

#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && (defined(XDSIM_GATE) || defined(XDSIM_CONN)))
typedef enum Element_Tag {
#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && (defined(XDSIM_GATE) || defined(XDSIM_CONN)))
  Element_Line,
#endif
#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && (defined(XDSIM_GATE) || defined(XDSIM_CONN)))
  Element_Rect,
#endif
} Element_Tag;

#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && (defined(XDSIM_GATE) || defined(XDSIM_CONN)))
typedef struct Element_Line_Body {
  /**
   * [ Vec2 ]
   */
  struct Slice points;
  struct StrokeStyle stroke;
} Element_Line_Body;
#endif

#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && (defined(XDSIM_GATE) || defined(XDSIM_CONN)))
typedef struct Element_Rect_Body {
  struct Vec2 pos;
  struct Vec2 size;
  struct StrokeStyle stroke;
  struct FillStyle fill;
} Element_Rect_Body;
#endif

typedef struct Element {
  Element_Tag tag;
  union {
#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && (defined(XDSIM_GATE) || defined(XDSIM_CONN)))
    Element_Line_Body line;
#endif
#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && (defined(XDSIM_GATE) || defined(XDSIM_CONN)))
    Element_Rect_Body rect;
#endif
  };
} Element;
#endif

#if (defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE))
struct ComponentHeader component_header(void);
#endif

#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && defined(XDSIM_CONN))
const struct ConnectionDefinition *conn_def(void);
#endif

#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && defined(XDSIM_CONN))
/**
 * You must not store the pointer to the slice, the slice will be dropped
 * You must malloc for the struct manually
 */
ConnectionMut conn_deserialize(struct Slice bytes);
#endif

#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && defined(XDSIM_CONN))
struct Graphic conn_draw(Connection conn, const struct ConnectionDrawRequest *request);
#endif

#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && defined(XDSIM_CONN))
void conn_drop(ConnectionMut conn);
#endif

#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && defined(XDSIM_CONN))
PropertiesMut conn_props(ConnectionMut conn);
#endif

#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && defined(XDSIM_CONN))
struct Slice conn_serialize(Connection conn);
#endif

#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && defined(XDSIM_DATA))
Data data_default(void);
#endif

#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && defined(XDSIM_DATA))
/**
 * You must not store the pointer to the slice, the slice will be dropped
 * You must malloc for the struct manually
 */
Data data_deserialize(struct Slice bytes);
#endif

#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && defined(XDSIM_DATA))
void data_drop(DataMut data);
#endif

#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && defined(XDSIM_DATA))
struct Slice data_serialize(Data data);
#endif

#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && defined(XDSIM_GATE))
struct GateDefinition gate_def(Gate gate);
#endif

#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && defined(XDSIM_GATE))
GateMut gate_deserialize(struct Slice bytes);
#endif

#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && defined(XDSIM_GATE))
struct Graphic gate_draw(Gate gate, const struct GateDrawRequest *request);
#endif

#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && defined(XDSIM_GATE))
void gate_drop(GateMut conn);
#endif

#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && defined(XDSIM_GATE))
PropertiesMut gate_props(GateMut gate);
#endif

#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && defined(XDSIM_GATE))
struct Slice gate_serialize(Gate gate);
#endif

#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && defined(XDSIM_GATE))
/**
 * returns [ Data ]
 * individual Data must be malloced
 * it will be freed by the program
 * in this particular case, slice.drop should only drop the slice
 * and not the individual Data
 */
struct Slice gate_tick(GateMut gate, const struct GateTickRequest *request);
#endif

#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && (defined(XDSIM_GATE) || defined(XDSIM_CONN)))
/**
 * You must not store the pointer to the slice, the slice will be dropped
 * You must malloc for the struct manually
 * Return NULL if deserialisation failed
 */
Properties props_deserialize(struct Slice bytes);
#endif

#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && (defined(XDSIM_GATE) || defined(XDSIM_CONN)))
struct Menu props_get_menu(Properties props);
#endif

#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && (defined(XDSIM_GATE) || defined(XDSIM_CONN)))
struct MenuInputValue props_get_option(Properties props,
                                       const struct Str *id);
#endif

#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && (defined(XDSIM_GATE) || defined(XDSIM_CONN)))
/**
 * returns [u8]
 */
struct Slice props_serialize(Properties props);
#endif

#if ((defined(XDSIM_CONN) || defined(XDSIM_DATA) || defined(XDSIM_GATE)) && (defined(XDSIM_GATE) || defined(XDSIM_CONN)))
/**
 * ID and value will be dropped after passing to it
 * props must not store the pointers to them
 * return NULL if no errors
 * props will be dropped after passing to it
 * slice must not store pointers to it
 */
const struct PropertiesSetError *props_set_option(PropertiesMut props,
                                                  const struct Str *id,
                                                  const struct MenuInputValue *value);
#endif
