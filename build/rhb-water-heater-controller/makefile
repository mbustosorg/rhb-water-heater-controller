DFLAGS=-DTEENSY 

PRODUCT_NAME=rhb-water-heater-controller
PROJECT_LOC=../../src/
PROJECT_LIB_LOC=../../../../teensy/lib/3.1/
VPATH=$(PROJECT_LOC)
OBJECT_DIR=./

include $(PROJECT_LIB_LOC)../../common/arm_common_31.txt

APP_CPP_SOURCES=rhb-water-heater-controller.cpp

APP_OBJECTS=$(addprefix $(OBJECT_DIR),$(APP_CPP_SOURCES:.cpp=.o))
LIB_OBJECTS=$(addprefix $(PROJECT_LIB_LOC),*.o)

default: build 

build: rhb-water-heater-controller_copy $(OBJECT_DIR)$(PRODUCT_NAME).hex
	@echo
	@echo Listing:
	@echo
	ls -l $(PRODUCT_NAME).hex 
	@echo
	@echo Size:
	@echo
	$(BIN)/arm-none-eabi-size $(PRODUCT_NAME).hex

$(OBJECT_DIR)$(PRODUCT_NAME).hex: $(OBJECT_DIR)$(PRODUCT_NAME).elf
	$(OBJCPY) -O ihex -j .eeprom --set-section-flags=.eeprom=alloc,load --no-change-warnings --change-section-lma .eeprom=0 $< $(OBJECT_DIR)$(PRODUCT_NAME).eep
	$(OBJCPY) -O ihex -R .eeprom $< $@

$(OBJECT_DIR)$(PRODUCT_NAME).elf: $(APP_OBJECTS) $(LIB_OBJECTS)
	$(CC) -Os -Wl,--gc-sections $(MCU) -mthumb -T$(CORES)mk20dx256.ld -o $@ $^ -L. -larm_cortexM4l_math -lm

rhb-water-heater-controller_copy: $(PROJECT_LOC)/rhb-water-heater-controller.cpp

$(OBJECT_DIR)%.o : %.c
	$(CC) $< $(CFLAGS) $(DFLAGS) $(INCLUDE) -c -o $@

$(OBJECT_DIR)%.o : %.cpp
	$(CXX) $< $(CXXFLAGS) $(DFLAGS) $(INCLUDE) -I$(PROJECT_LOC)XBee -c -o $@

clean:
    #Clear previous...
	rm -v $(APP_OBJECTS)
	rm -v *.d
	rm -v *.eep
	rm -v *.elf
	rm -v *.hex
