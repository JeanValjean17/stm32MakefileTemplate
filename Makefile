#######################################
# binaries
#######################################
PREFIX = arm-none-eabi-
GCC_PATH = /home/jean/opt/gcc-arm-none-eabi-10.3-2021.10/bin

ifdef GCC_PATH
CC = $(GCC_PATH)/$(PREFIX)gcc
CXX = $(GCC_PATH)/$(PREFIX)g++
AS = $(GCC_PATH)/$(PREFIX)gcc -x assembler-with-cpp
CP = $(GCC_PATH)/$(PREFIX)objcopy
SZ = $(GCC_PATH)/$(PREFIX)size
else
CC = $(PREFIX)gcc
CXX = $(PREFIX)g++
AS = $(PREFIX)gcc -x assembler-with-cpp
CP = $(PREFIX)objcopy
SZ = $(PREFIX)size
endif

HEX = $(CP) -O ihex
BIN = $(CP) -O binary -S

CPU = -mcpu=cortex-m0plus

MCU = $(CPU) -mthumb


BUILD_DIR = build
OBJ_DIR = $(BUILD_DIR)/obj
BIN_DIR = $(BUILD_DIR)/bin

TARGET = DevBoard


C_SOURCES =  \
	src/main.cpp \
	src/system_stm32l0xx.c

ASM_SOURCES =  \
	src/startup_stm32l073xx.s

#OBJECT_NAMES = $(C_SOURCES:.cpp=.o) $(C_SOURCES:.c=.o) $(ASM_SOURCES:.s=.o)

#OBJECTS = $(patsubst %, $(OBJ_DIR)/%, $(OBJECT_NAMES))

OBJECTS =  \
	$(OBJ_DIR)/main.o \
	$(OBJ_DIR)/startup_stm32l073xx.o \
	$(OBJ_DIR)/system_stm32l0xx.o \


C_INCLUDES =  \
-Idrivers/cmsis \
-Idrivers/st

C_DEFS =  \
	-DSTM32L073xx

MOREFLAGS = -Wall -Wextra -Wpedantic -O0 -g3 -fdata-sections -ffunction-sections
CFLAGS = $(MCU) $(C_DEFS) $(C_INCLUDES) -std=c17 $(MOREFLAGS) 
CXXFLAGS = $(MCU) $(C_DEFS) $(C_INCLUDES) -std=c++17 -fno-rtti -fno-exceptions -fno-threadsafe-statics $(MOREFLAGS) 

#######################################
# LDFLAGS
#######################################
# link script
LDSCRIPT = STM32L073RZTX_FLASH.ld
LIBS = -lc -lm -lnosys 
LDFLAGS = $(MCU) -specs=nano.specs -T $(LDSCRIPT) $(LIBS) -Wl,-Map=$(BUILD_DIR)/$(TARGET).map,--cref -Wl,--gc-sections -Wl,--print-memory-usage -Wl,--start-group -lstdc++ -lsupc++ -Wl,--end-group  

##All C++ files
#$(OBJ_DIR)/main.o: src/main.cpp
#	mkdir -p $(OBJ_DIR)
#	$(CC) $(CFLAGS) -c -o $@ $^

##All C files

all: $(BIN_DIR)/$(TARGET).elf $(BIN_DIR)/$(TARGET).hex $(BIN_DIR)/$(TARGET).bin

## Linking
$(BIN_DIR)/$(TARGET).elf: $(OBJECTS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(LDFLAGS) $^ -o $@
	$(SZ) $@

$(BIN_DIR)/$(TARGET).hex: $(BIN_DIR)/$(TARGET).elf 
	$(HEX) $< $@

$(BIN_DIR)/$(TARGET).bin: $(BIN_DIR)/$(TARGET).elf 
	$(BIN) $< $@

## Compiling C++

$(OBJ_DIR)/%.o: src/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $^


## Compiling C

$(OBJ_DIR)/%.o: src/%.c
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $^	

## Compiling ASM

$(OBJ_DIR)/%.o: src/%.s
	@mkdir -p $(OBJ_DIR)
	$(AS) $(CXXFLAGS) -c -o $@ $^	







#######################################
# clean up
#######################################
clean:
	-rm -fR $(BUILD_DIR)
