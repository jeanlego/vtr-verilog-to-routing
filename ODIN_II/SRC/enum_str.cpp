#include "odin_types.h"

const char* ieee_std_STR[] = {
    "1364-1995",
    "1364-2001-noconfig",
    "1364-2001",
    "1364-2005",
};

const char* file_extension_supported_STR[] = {
    ".v",
    ".vh",
};

const char* edge_type_e_STR[] = {
    "UNDEFINED_SENSITIVITY",
    "FALLING_EDGE_SENSITIVITY",
    "RISING_EDGE_SENSITIVITY",
    "ACTIVE_HIGH_SENSITIVITY",
    "ACTIVE_LOW_SENSITIVITY",
    "ASYNCHRONOUS_SENSITIVITY",
};

const char* constant_driver_STR[] = {
    "0_GND_0",
    "1_VCC_1",
    "X_GND_X", // same as 0
    "Z_PAD_Z",
};

const char* net_constant_STR[] = {
    "gnd",
    "vcc",
    "dc",
    "unconn",
};

const char* SINGLE_PORT_RAM_string = "single_port_ram";
const char* DUAL_PORT_RAM_string = "dual_port_ram";

#define SIMULATION_PREFIXED(name) \
    "GLOBAL_SIM" name

const char* simulation_default_clock_name = SIMULATION_PREFIXED("_BASE_CLK");
const char* simulation_const_names[] = {
    SIMULATION_PREFIXED("_GND"),
    SIMULATION_PREFIXED("_VCC"),
    SIMULATION_PREFIXED("_DC"),
    net_constant_STR[BitSpace::_z], // this is a restricted keyword for all the tools in the flow
};

const char* operation_list_STR[][2]
    = {
        {"NO_OP", "nOP"},
        {"MULTI_PORT_MUX", "nMUX"}, // port 1 = control, port 2+ = mux options
        {"FF_NODE", "FF"},
        {"BUF_NODE", "BUF"},
        {"INPUT_NODE", "IN"},
        {"OUTPUT_NODE", "OUT"},
        {"CONST_NODE", "CONST"},
        {"CLOCK_NODE", "CLK"},
        {"ADD", "ADD"},             // +
        {"MINUS", "MIN"},           // -
        {"BITWISE_NOT", "bNOT"},    // ~
        {"BITWISE_AND", "bAND"},    // &
        {"BITWISE_OR", "bOR"},      // |
        {"BITWISE_NAND", "bNAND"},  // ~&
        {"BITWISE_NOR", "bNOR"},    // ~|
        {"BITWISE_XNOR", "bXNOR"},  // ~^
        {"BITWISE_XOR", "bXOR"},    // ^
        {"LOGICAL_NOT", "lNOT"},    // !
        {"LOGICAL_OR", "lOR"},      // ||
        {"LOGICAL_AND", "lAND"},    // &&
        {"LOGICAL_NAND", "lNAND"},  // No Symbol
        {"LOGICAL_NOR", "lNOR"},    // No Symbol
        {"LOGICAL_XNOR", "lXNOR"},  // No symbol
        {"LOGICAL_XOR", "lXOR"},    // No Symbol
        {"MULTIPLY", "MUL"},        // *
        {"DIVIDE", "DIV"},          // /
        {"MODULO", "MOD"},          // %
        {"POWER", "POW"},           // **
        {"LT", "LT"},               // <
        {"GT", "GT"},               // >
        {"LOGICAL_EQUAL", "lEQ"},   // ==
        {"NOT_EQUAL", "lNEQ"},      // !=
        {"LTE", "LTE"},             // <=
        {"GTE", "GTE"},             // >=
        {"SR", "SR"},               // >>
        {"ASR", "ASR"},             // >>>
        {"SL", "SL"},               // <<
        {"ASL", "ASL"},             // <<<
        {"CASE_EQUAL", "cEQ"},      // ===
        {"CASE_NOT_EQUAL", "cNEQ"}, // !==
        {"ADDER_FUNC", "ADDER"},
        {"CARRY_FUNC", "CARRY"},
        {"MUX_2", "MUX_2"},
        {"BLIF_FUNCTION", "BLIFf"},
        {"NETLIST_FUNCTION", "NETf"},
        {"MEMORY", "MEM"},
        {"HARD_IP", "HARD"},
        {"GENERIC", "GEN"},   /*added for the unknown node type */
        {"CLOG2", "CL2"},     // $clog2
        {"UNSIGNED", "UNSG"}, // $unsigned
        {"SIGNED", "SG"},     // $signed
        {"ERROR OOB", "OOB"}  // should not reach this
};

const char* ids_STR[] = {
    "NO_ID",
    /* top level things */
    "FILE_ITEMS",
    "MODULE",
    "SPECIFY",
    /* VARIABLES */
    "INPUT",
    "OUTPUT",
    "INOUT",
    "WIRE",
    "REG",
    "GENVAR",
    "PARAMETER",
    "LOCALPARAM",
    "INITIAL",
    "PORT",
    /* OTHER MODULE ITEMS */
    "MODULE_ITEMS",
    "VAR_DECLARE",
    "VAR_DECLARE_LIST",
    "ASSIGN",
    /* OTHER MODULE AND FUNCTION ITEMS */
    "FUNCTION",
    /* OTHER FUNCTION ITEMS */
    "FUNCTION_ITEMS",
    "TASK",
    "TASK_ITEMS",
    /* primitives */
    "GATE",
    "GATE_INSTANCE",
    "ONE_GATE_INSTANCE",
    /* Module instances */
    "MODULE_CONNECT_LIST",
    "MODULE_CONNECT",
    "MODULE_PARAMETER_LIST",
    "MODULE_PARAMETER",
    "MODULE_NAMED_INSTANCE",
    "MODULE_INSTANCE",
    "MODULE_MASTER_INSTANCE",
    "ONE_MODULE_INSTANCE",
    /* Function instances*/
    "FUNCTION_NAMED_INSTANCE",
    "FUNCTION_INSTANCE",

    "TASK_NAMED_INSTANCE",
    "TASK_INSTANCE",
    /* Specify Items */
    "SPECIFY_ITEMS",
    "SPECIFY_PARAMETER",
    "SPECIFY_PAL_CONNECTION_STATEMENT",
    "SPECIFY_PAL_CONNECT_LIST",
    /* statements */
    "STATEMENT",
    "BLOCK",
    "NON_BLOCKING_STATEMENT",
    "BLOCKING_STATEMENT",
    "ASSIGNING_LIST",
    "CASE",
    "CASE_LIST",
    "CASE_ITEM",
    "CASE_DEFAULT",
    "ALWAYS",
    "IF",
    "FOR",
    "WHILE",
    /* Delay Control */
    "DELAY_CONTROL",
    "POSEDGE",
    "NEGEDGE",
    /* expressions */
    "TERNARY_OPERATION",
    "BINARY_OPERATION",
    "UNARY_OPERATION",
    /* basic primitives */
    "ARRAY_REF",
    "RANGE_REF",
    "CONCATENATE",
    "REPLICATE",
    /* basic identifiers */
    "IDENTIFIERS",
    "NUMBERS",
    /* C functions */
    "C_ARG_LIST",
    "DISPLAY",
    "FINISH",
    /* Hard Blocks */
    "HARD_BLOCK",
    "HARD_BLOCK_NAMED_INSTANCE",
    "HARD_BLOCK_CONNECT_LIST",
    "HARD_BLOCK_CONNECT",
    // EDDIE: new enum value for ids to replace MEMORY from operation_t
    "RAM",
    "ids_END"};