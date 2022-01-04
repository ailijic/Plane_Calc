TARGET_EXEC ?= a.out

BUILD_DIR ?= ./build
SRC_DIRS ?= ./src
test_dir ?= ./test

SRCS := $(shell find $(SRC_DIRS) -name *.cpp -or -name *.c -or -name *.s)
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:.o=.d)
test_src := $(shell find $(test_dir) -name *.cpp -or -name *.c -or -name *.s)
test_obj := $(test_src:%=$(BUILD_DIR)/%.o)
test_dep := $(test_obj:.o=.d)

INC_DIRS := $(shell find $(SRC_DIRS) -type d)
INC_FLAGS := -I./include $(addprefix -I,$(INC_DIRS))

WARN_EXCLUDE := -Wno-newline-eof -Wno-c++98-compat-pedantic
WARN_FLAGS := -Weverything -Werror $(WARN_EXCLUDE)

CPPFLAGS ?= $(INC_FLAGS) $(WARN_FLAGS) -MMD -MP -O0 -g3 -ggdb
CFLAGS ?= #-std=gnu17
CXXFLAGS := #-std=gnu++2a 

LDFLAGS := -lm

CC := clang-8
CXX := clang++-8
LD := clang++-8

$(BUILD_DIR)/$(TARGET_EXEC): $(OBJS)
	$(LD) $(OBJS) -o $@ $(LDFLAGS)

# assembly
$(BUILD_DIR)/%.s.o: %.s
	$(MKDIR_P) $(dir $@)
	$(AS) $(ASFLAGS) -c $< -o $@

# c source
$(BUILD_DIR)/%.c.o: %.c
	$(MKDIR_P) $(dir $@)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

# c++ source
$(BUILD_DIR)/%.cpp.o: %.cpp
	$(MKDIR_P) $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

.PHONY: run
run: $(BUILD_DIR)/$(TARGET_EXEC)
	./$(BUILD_DIR)/$(TARGET_EXEC)

.PHONY: clean
clean:
	$(RM) -r $(BUILD_DIR)

-include $(DEPS)

MKDIR_P ?= mkdir -p