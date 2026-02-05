BUILD_TYPE ?= RELEASE

DEBUG_FLAGS = -Wall -Wextra -pedantic -Og -g -gstabs+ -ggdb
RELEASE_FLAGS = -O3 -flto

INCLUDE_PATH = include
BUILD_PATH = build
OBJECT_BUILD_PATH = build/objects

SOURCE_PATH = source
SOURCE_SOURCES = $(wildcard $(INTERFACEIO_PATH)/*.c)
SOURCE_OBJECT_BUILD_PATH = $(OBJECT_BUILD_PATH)/source
SOURCE_OBJECTS = $(addprefix $(OBJECT_BUILD_PATH)/,$(patsubst %.c,%.o,$(patsubst source/%,%,$(SOURCE_SOURCES))))

TEST_PATH = source/test
TEST_SOURCES = $(wildcard $(TEST_PATH)/*.c)
TEST_OBJECT_BUILD_PATH = $(OBJECT_BUILD_PATH)/test
TEST_OBJECTS = $(addprefix $(OBJECT_BUILD_PATH)/,$(patsubst %.c,%.o,$(patsubst source/%,%,$(TEST_SOURCES))))

all : main

.PHONY : folders clean

folders:
	mkdir -p $(OBJECT_BUILD_PATH)
	mkdir -p $(SOURCE_OBJECT_BUILD_PATH)
	mkdir -p $(TEST_OBJECT_BUILD_PATH)

$(SOURCE_OBJECTS) : %.o :
	gcc $($(BUILD_TYPE)_FLAGS) -I $(INCLUDE_PATH) -c $(patsubst $(OBJECT_BUILD_PATH)/%,source/%,$*.c) -o $@

$(TEST_OBJECTS) : %.o :
	gcc $($(BUILD_TYPE)_FLAGS) -I $(INCLUDE_PATH) -c $(patsubst $(OBJECT_BUILD_PATH)/%,source/%,$*.c) -o $@

OPERATOR_SYSTEM ?= WINDOWS
EXECUTABLE_SUFFIX := .exe

ifeq ($(OPERATOR_SYSTEM),LINUX)
EXECUTABLE_SUFFIX := $(NULL)
endif

main : folders $(SOURCE_OBJECTS) $(TEST_OBJECTS)
	gcc $($(BUILD_TYPE)_FLAGS) -I $(INCLUDE_PATH) $(OBJECT_BUILD_PATH)/test/main.o $(SOURCE_OBJECTS) -o main$(EXECUTABLE_SUFFIX)

clean :
	rm -rf build
	rm -f main.exe
