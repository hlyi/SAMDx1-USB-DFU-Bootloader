##############################################################################
BUILD = build
BIN = D11boot

##############################################################################
.PHONY: all directory clean size

#DEVDEF =-D__SAMD11D14AM__
#DEVLINK = samd11d14
DEVDEF =-D__SAMD21E18A__
DEVLINK = samd21e18

CC = arm-none-eabi-gcc
OBJCOPY = arm-none-eabi-objcopy
SIZE = arm-none-eabi-size

ifeq ($(OS), Windows_NT)
  MKDIR = gmkdir
else
  MKDIR = mkdir
endif

ifeq ($(VERBOSE), 1)
Q=
else
Q=@
endif

CFLAGS += -W -Wall --std=gnu99 -Os -g3
CFLAGS += -Wno-address-of-packed-member
CFLAGS += -fno-diagnostics-show-caret
CFLAGS += -fdata-sections -ffunction-sections
CFLAGS += -funsigned-char -funsigned-bitfields
CFLAGS += -mcpu=cortex-m0plus -mthumb
CFLAGS += -MD -MP -MT $(BUILD)/$(*F).o -MF $(BUILD)/$(@F).d

LDFLAGS += -mcpu=cortex-m0plus -mthumb
LDFLAGS += -Wl,--gc-sections
LDFLAGS += -Wl,--script=../linker/$(DEVLINK).ld

INCLUDES += \
  -I../include \
  -I..

SRCS += \
  ../bootloader.c \
  ../usb_descriptors.c

DEFINES += \
  $(DEVDEF) \
  -DDONT_USE_CMSIS_INIT \
  -DSTARTUP_FROM_RESET

CFLAGS += $(INCLUDES) $(DEFINES)
ASFLAGS += $(CFLAGS)

OBJS = $(addprefix $(BUILD)/, $(notdir %/$(subst .c,.o, $(SRCS))))
OBJS += $(BUILD)/startup.o

all: directory $(BUILD)/$(BIN).elf $(BUILD)/$(BIN).hex $(BUILD)/$(BIN).bin size

$(BUILD)/$(BIN).elf: $(OBJS)
	@echo LD $@
	$(Q)$(CC) $(LDFLAGS) $(OBJS) $(LIBS) -o $@

$(BUILD)/$(BIN).hex: $(BUILD)/$(BIN).elf
	@echo OBJCOPY $@
	$(Q)$(OBJCOPY) -O ihex $^ $@

$(BUILD)/$(BIN).bin: $(BUILD)/$(BIN).elf
	@echo OBJCOPY $@
	$(Q)$(OBJCOPY) -O binary $^ $@

%.o:
	@echo CC $@
	$(Q)$(CC) $(CFLAGS) $(filter %/$(subst .o,.c,$(notdir $@)), $(SRCS)) -c -o $@

$(BUILD)/startup.o: ../startup.s
	@echo CC $@
	$(Q)$(CC) -x assembler-with-cpp $(ASFLAGS) -c -o $@ $<

directory:
	$(Q)$(MKDIR) -p $(BUILD)

size: $(BUILD)/$(BIN).elf
	@echo size:
	$(Q)$(SIZE) -t $^

clean:
	@echo clean
	$(Q)-rm -rf $(BUILD)

-include $(wildcard $(BUILD)/*.d)

